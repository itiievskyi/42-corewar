/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:55:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/02 13:42:51 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_function(void (**f)(unsigned char *, t_pc **))
{
	f[11] = &sti;
	f[9] = &zjmp;
	f[6] = &and;
	f[3] = &st;
	f[2] = &ld;
	f[8] = &xor;
	f[4] = &add;
	f[5] = &sub;
	f[14] = &lldi;
	f[10] = &ldi;
	f[7] = &or;
	f[13] = &lld;
	f[16] = &aff;
}

void		get_command(unsigned char *map, t_pc *pc)
{
	if (get_map(map, pc->size) <= 0 || get_map(map, pc->size) > 16)
	{
		pc->cicles = -1;
		pc->size++;
	}
	else
	{
		pc->size = set_place(pc->size);
		pc->command = get_map(map, pc->size);
		pc->cicles = (op_tab[pc->command]).cicles - 1;
	}
}

int			get_size(unsigned char *map, int cmd, int size)
{
	int		tmp;
	int		res;

	res = 0;
	if ((op_tab[cmd]).codage > 0)
	{
		tmp = get_map(map, size + 1);
		res += find_weight(bit_mask(1, tmp), cmd);
		if (cmd != 16)
			res += find_weight(bit_mask(2, tmp), cmd);
		if (cmd != 3 && cmd != 2 && cmd != 13 && cmd != 16)
			res += find_weight(bit_mask(3, tmp), cmd);
		return (res + 2);
	}
	return (op_tab[cmd].label + 1);
}

void			do_command(unsigned char *map, t_pc *pc, void (**f)(unsigned char *, t_pc **))
{
	f[pc->command](map, &pc);
}

int			get_n_p(t_pc *pc)
{
	int		j;

	j = 0;
	while (pc != NULL)
	{
		//printf("number=%d, pc->size=%u, pc->command=%u\n", j, pc->size, pc->command);
		pc = pc->next;
		j++;
	}
	return (j);
}

void		print_live(t_player *p)
{
	int i;

	i = 1;
	while (p != NULL)
	{
		printf("name :%s%d life = %d\n", p->p_name, i, p->p_live);
		p = p->next;
		i++;
	}
}

void		do_all(t_player *p, unsigned char *map, t_pc **pc_1, void (**functions)(unsigned char *, t_pc **))
{
	t_pc	*tmp;

	tmp = (*pc_1);
	while (tmp != NULL)
	{
		if (tmp->command == 0)
			get_command(map, tmp);
		if (tmp->cicles == 0)
		{
			if (tmp->command == 12)
				fork_1(map, tmp, pc_1);
			else if (tmp->command == 15)
				lfork_1(map, tmp, pc_1);
			else if (tmp->command == 1)
				live(map, p, tmp);
			else
				do_command(map, tmp, functions);
		}
		if (tmp->cicles > 0)
			tmp->cicles--;
		tmp = tmp->next;
	}
}

void		game_minus_cicle(int *j, int *cycle_to_die)
{
	*cycle_to_die -= CYCLE_DELTA;
	*j = 0;
}

void		add_i(t_player *p, int i)
{
	while (p != NULL)
	{
		p->i = i;
		p = p->next;
	}
}

void			game_over(t_player *p, t_pc *pc, unsigned char *map, int i)
{
	t_player	*p_win;

	p_win = p;
	while (p != NULL)
	{
		if (p->last_live > p_win->last_live)
			p_win = p;
		p = p->next;
	}
	exit (1);
}

void		solve(t_player *p, unsigned char *map, t_pc *pc_1)
{
	void		(*functions[17])(unsigned char *, t_pc **);
	int			c;
	int			j;
	int			i;

	c = CYCLE_TO_DIE;
	init_function(functions);
	j = 0;
	i = 0;
	while (1 && ++j > -1 && ++i > -1)
	{
		add_i(p, i);
		do_all(p, map, &pc_1, functions);
		if (j / c == MAX_CHECKS ||
				!(j = check_cycle(count_live(p, pc_1, map), j, c, p)))
			game_minus_cicle(&j, &c);
		if (j % c == 0)
			delete_pc(p, &pc_1);
		if (c <= 0 || pc_1 == NULL)
		{
			game_over(p, pc_1, map, i);
			break;
		}
		print_map(map, pc_1, p, i);
	}
}
