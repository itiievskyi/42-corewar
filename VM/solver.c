/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:55:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/03 19:35:47 by averemiy         ###   ########.fr       */
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

void		game_minus_cicle(t_rule *r)
{
	r->c -= CYCLE_DELTA;
	r->j = 0;
}

void		add_i(t_player *p, int i)
{
	while (p != NULL)
	{
		p->i = i;
		p = p->next;
	}
}

void			game_over(t_player *p, t_pc *pc, unsigned char *map, t_rule *r)
{
	t_player	*p_win;
	t_player	*p1;

	p_win = p;
	p1 = p;
	while (p != NULL)
	{
		if (p->last_live > p_win->last_live)
			p_win = p;
		p = p->next;
	}
	p_win->last_live = 2147483647;
	print_map(map, pc, p_win, r);
	free_all(p1, pc);
}

void		print_dump(t_player *p, unsigned char *map, t_pc *pc)
{
	t_player *p1;
	int		j;
	int		i;

	j = 0;
	i = 0;
	p1 = p;
	ft_printf("Introducting contestants ...\n");
	while (p1 != NULL && j++)
	{
		ft_printf("* Player %d, weighing %d, %s (%s) !\n", \
				j, p1->p_size, p1->p_name, p1->p_comment);
		p1 = p1->next;
	}
	ft_printf("0x0000 : ");
	while (++i <= MEM_SIZE)
	{
		ft_printf("%02x ", map[i - 1]);
		if (i % 64 == 0 && i != 0 )
		{
			ft_printf("\n");
			(i < MEM_SIZE) ? ft_printf("0x%04x : ", i) : 0;
		}
	}
	free_all(p, pc);
}

void		p_win(t_player *p, t_pc *pc)
{
	t_player 	*p1;
	t_player 	*win;

	p1 = p;
	while (p1 != NULL)
	{
		ft_printf("%s (%d)\n", p1->p_name, p1->p_id);
		p1 = p1->next;
	}
	win = p;
	p1 = p;
	while (p != NULL)
	{
		if (p->last_live > win->last_live)
			win = p;
		p = p->next;
	}
	ft_printf("Win %s (%d)\n", win->p_name, win->p_id);
	free_all(p1, pc);
}

void		solve(t_player *p, unsigned char *map, t_pc *pc_1, t_rule *r)
{
	void		(*functions[17])(unsigned char *, t_pc **);

	init_function(functions);
	while (1 && (++(r->j)) > -1 && (++(r->i)) > -1)
	{
		//printf("i= %d\nj = %d\nc = %d\n", r->i, r->j, r->c);
		add_i(p, r->i);
		do_all(p, map, &pc_1, functions);
		if (r->j / r->c == MAX_CHECKS ||
				!(r->j = check_cycle(count_live(p, pc_1), r->j, r->c, p)))
			game_minus_cicle(r);
		if (r->j % r->c == 0)
			delete_pc(p, &pc_1);
		if (r->c <= 0 || !pc_1)
		{
			(r->visual) ? game_over(p, pc_1, map, r) : p_win(p, pc_1);
			break;
		}
		if (r->visual)
		//	r->visual++;
		//if (r->i >= 100)
		//	break;
			print_map(map, pc_1, p, r);
		if (r->check_dump == 1 && !r->visual && r->dump == (unsigned int)r->i)
		{
			print_dump(p, map, pc_1);
			break ;
		}
	}
}
