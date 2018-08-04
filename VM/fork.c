/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:23:12 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 04:04:55 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		copy_pc(t_pc *pc1, t_pc *pc2, int stand, unsigned char *map)
{
	int		i;

	i = -1;
	while (++i < 16)
		pc1->reg[i] = pc2->reg[i];
	i = -1;
	while (++i < 3)
		pc1->arg[i] = 0;
	pc1->size = set_place(stand);
	pc1->carry = pc2->carry;
	pc1->parent = pc2->parent;
	pc1->live = pc2->live;
	pc1->cicles = 0;
	pc1->command = 0;
	pc1->change = -1;
	pc1->left_live = 0;
	pc1->aff = pc2->aff;
	pc2->size += get_size(map, pc2->command, pc2->size);
	pc2->command = 0;
}

void		fork_1(unsigned char *map, t_pc *pc, t_pc **main)
{
	int		i;
	t_pc	*new_pc;

	i = (((short)take_arg(map, 2, pc->size + 1)) % IDX_MOD);
	new_pc = (t_pc *)malloc(sizeof(t_pc));
	copy_pc(new_pc, pc, i + pc->size, map);
	new_pc->id = (*main)->id + 1;
	new_pc->next = *main;
	*main = new_pc;
}
