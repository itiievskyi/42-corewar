/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:39:46 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 03:17:16 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		st(unsigned char *map, t_pc **pc1)
{
	int		i;
	t_pc	*pc;
	int		size_tmp;
	int		j;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_st(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 2)) != -1)
	{
		if (bit_mask(2, get_map(map, pc->size + 1)) == 1)
			pc->reg[get_map(map, pc->size + 3) - 1] = pc->arg[0];
		else
		{
			j = (short)take_arg(map, 2, pc->size + 3);
			set_bit(pc, pc->size + (j % IDX_MOD), map, pc->arg[0]);
		}
	}
	pc->size += size_tmp;
	pc->command = 0;
}
