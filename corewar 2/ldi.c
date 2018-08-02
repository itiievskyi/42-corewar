/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:49 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/01 18:31:32 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				ldi(unsigned char *map, t_pc **pc1)
{
	int				i;
	t_pc			*pc;
	int				tmp_size;
	unsigned int	tmp;
	int				j;

	pc = (*pc1);
	tmp_size = get_size(map, pc->command, pc->size);
	if (!(c_c_ldi_lldi(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 3)) != -1)
	{
		j = (((short)(pc->arg[0] + pc->arg[1])) % IDX_MOD) + pc->size;
		tmp = take_arg(map, 4, j);
		pc->reg[get_map(map, i - 1) - 1] = tmp;
	}
	pc->size += tmp_size;
	pc->command = 0;
}
