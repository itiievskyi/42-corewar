/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:39:14 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 09:10:43 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int			lld_helper(unsigned char *map, t_pc *pc)
{
	int					size;
	unsigned int		k;

	size = pc->size + ((short)(take_arg(map, 2, pc->size + 2)));
	k = take_arg(map, 4, size);
	if (k == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
	return (k);
}

void					lld(unsigned char *map, t_pc **pc1)
{
	int					i;
	t_pc				*pc;
	int					size_tmp;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_ld_lld(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 2)) != -1)
	{
		pc->arg[0] = -1;
		i = red_arg(map, pc, 2);
		if (bit_mask(1, get_map(map, pc->size + 1)) == 3)
		{
			pc->reg[get_map(map, i - 1) - 1] = pc->arg[0];
			(pc->arg[0] == 0) ? (pc->carry = 1)
				: (pc->carry = 0);
		}
		else
			pc->reg[get_map(map, i - 1) - 1] = lld_helper(map, pc);
	}
	pc->size += size_tmp;
	pc->command = 0;
}
