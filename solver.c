/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:55:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 15:09:26 by averemiy         ###   ########.fr       */
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
	// before 16 -> printf!!!
}

void		get_command(unsigned char *map, t_pc *pc)
{
	if (get_map(map, pc->size) <= 0 || get_map(map, pc->size) >= 16)
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
		res += find_weight(bit_mask(2, tmp), cmd);
		if (cmd != 3 && cmd != 2 && cmd != 13)
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
//		printf("number=%d, pc->size=%u, pc->command=%u\n", j, pc->size, pc->command);
		/*
		int i;
		i = -1;
		while(++i < 16)
			printf("pc[%d]reg[%d] = %u---", j, i, pc->reg[i]);
		*/
		//printf("reg9 = %u reg 10 = %u\n", pc->reg[9], pc->reg[10]);
		pc = pc->next;
		j++;
	}
	return (j);
}

void		solve(t_player *p, unsigned char *map, t_pc *pc_1)
{
	void		(*functions[17])(unsigned char *, t_pc **);
	t_pc		*tmp;
	int			cycle_to_die;

	cycle_to_die = CYCLE_TO_DIE;
	init_function(functions);
	int j = 1;
	int y = 1;

	while (1)
	{
		tmp = pc_1;
		while (tmp != NULL)
		{
			if (tmp->command == 0)
				get_command(map, tmp);
			if (tmp->cicles == 0)
			{
				if (tmp->command == 12)
					fork_1(map, tmp, &pc_1);
				else if (tmp->command == 15)
					printf("");
				else if (tmp->command == 16)
					printf("");
				else if (tmp->command == 1)
					live(map, p, tmp);
				else
					do_command(map, tmp, functions);
			}
			if (tmp->cicles > 0)
				tmp->cicles--;
			tmp = tmp->next;
		}
//		printf("j = %d\ny = %d\n", j, y);
//		printf("cicles = %d\n", cycle_to_die);
		int k = get_n_p(pc_1);
//		printf("process = %d\n", k);
		if (j % cycle_to_die == 0)
		{
			delete_pc(&pc_1, k);
			tmp = pc_1;
		}
		if (j / cycle_to_die == MAX_CHECKS || !(j = check_cycle(p, j, cycle_to_die)))
		{
				cycle_to_die -= CYCLE_DELTA;
				j = 0;
		}
		if (cycle_to_die <= 0 || pc_1 == NULL)
		{
//			printf("game_over\n");
			break;
		}
		print_map(map, pc_1, p, y - 1);
		j++;
		y++;
	}
}
