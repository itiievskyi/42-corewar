/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:44:26 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 15:14:41 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					ld(unsigned char *map, t_pc **pc1)
{
	int					i;
	unsigned int		tmp;
	unsigned int		k;
	t_pc				*pc;
	int					size_tmp;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_ld_lld(get_map(map, pc->size + 1))))
	{
		k = -1;
		pc->arg[0] = -1;
		i = red_arg(map, pc, 2);
		if (bit_mask(1, get_map(map, pc->size + 1)) == 3)
		{
			if (get_map(map, i - 1) >= 1 && get_map(map, i - 1) <= 16)
				pc->reg[get_map(map, i - 1) - 1] = pc->arg[0];
			(pc->arg[0] == 0) ? (pc->carry = 1) : (pc->carry = 0);
		}
		else
		{
			tmp = pc->arg[0];
			tmp = tmp % IDX_MOD;
			k = take_arg(map, 4, pc->size + tmp);
			(k == 0) ? (pc->carry = 1) : (pc->carry = 0);
			pc->reg[get_map(map, i - 1) - 1] = k;
		}
//		printf("n ==== %u\n", pc->reg[get_map(map, i - 1) - 1]);
//		printf("ld\n");
	}
	pc->size += size_tmp;
	pc->command = 0;
}
