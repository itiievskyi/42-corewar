/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:13:20 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 03:16:40 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			zjmp(unsigned char *map, t_pc **pc1)
{
	int			tmp3;
	t_pc		*pc;

	pc = (*pc1);
	tmp3 = 0;
	if (pc->carry == 1)
	{
		tmp3 = ((short)take_arg(map, 2, pc->size + 1)) % IDX_MOD;
		pc->size += tmp3;
		pc->size = set_place(pc->size);
		pc->command = 0;
	}
	else
	{
		pc->size += get_size(map, pc->command, pc->size);
		pc->command = 0;
	}
}
