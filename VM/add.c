/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:08:42 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 02:33:45 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add(unsigned char *map, t_pc **pc1)
{
	int				tmp1;
	int				tmp2;
	int				tmp3;
	unsigned int	tmp4;
	t_pc			*pc;

	pc = (*pc1);
	if (!(c_c_add_sub(get_map(map, pc->size + 1))))
	{
		tmp4 = 0;
		tmp1 = take_arg(map, 1, pc->size + 2);
		tmp2 = take_arg(map, 1, pc->size + 3);
		tmp3 = take_arg(map, 1, pc->size + 4);
		if (tmp1 >= 1 && tmp1 <= 16 && tmp2 >= 1 && tmp2 <= 16
				&& tmp3 >= 1 && tmp3 <= 16)
		{
			tmp4 = pc->reg[tmp1 - 1] + pc->reg[tmp2 - 1];
			pc->reg[tmp3 - 1] = tmp4;
			(tmp4 == 0) ? (pc->carry = 1) :
				(pc->carry = 0);
		}
	}
	pc->size += get_size(map, pc->command, pc->size);
	pc->command = 0;
}
