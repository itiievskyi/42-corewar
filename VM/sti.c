/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:02:10 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 10:48:01 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				sti(unsigned char *map, t_pc **pc1)
{
	int				i;
	t_pc			*pc;
	int				size_tmp;
	unsigned int	j;
	int				k;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_sti(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 3)) != -1)
	{
		if (bit_mask(2, get_map(map, pc->size + 1)) == 1)
		{
			j = (short)(pc->arg[1] + pc->arg[2]);
			set_bit(pc, pc->size + (j % IDX_MOD), map, pc->arg[0]);
		}
		else
		{
			k = (short)(pc->arg[1] + pc->arg[2]);
			set_bit(pc, pc->size + (k % IDX_MOD), map, pc->arg[0]);
		}
	}
	pc->size += size_tmp;
	pc->command = 0;
}
