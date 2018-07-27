/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:39:46 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 15:14:38 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		st(unsigned char *map, t_pc **pc1)
{
	int		i;
	t_pc	*pc;
	int		size_tmp;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_st(get_map(map, pc->size + 1))))
	{
		i = red_arg(map, pc, 1);
		if (bit_mask(2, get_map(map, pc->size + 1)) == 1)
		{
//			printf("in if");
			if (get_map(map, pc->size + 3) >= 1 && get_map(map, pc->size + 2) <= 16)
				pc->reg[get_map(map, pc->size + 2) - 1] = pc->arg[0];
		}
		else
		{
//		printf("me : %d\n", pc->size + (((short)take_arg(map, 2, pc->size + 3)) % IDX_MOD));
			set_bit(pc->size + (((short)take_arg(map, 2, pc->size + 3)) % IDX_MOD), map, pc->arg[0], pc);
		}
	}
//	printf("nst = %u\n", pc->arg[0]);
//	printf("st\n");
	pc->size += size_tmp;
	pc->command = 0;
}
