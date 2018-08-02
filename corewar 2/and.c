/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:12:56 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/01 17:56:22 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		and(unsigned char *map, t_pc **pc1)
{
	int		jump;
	t_pc	*pc;
	int		i;

	pc = (*pc1);
	if (!(c_c_and_or_xor(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 3)) != -1)
	{
		jump = red_arg(map, pc, 2);
		pc->reg[get_map(map, jump) - 1] = pc->arg[0] & pc->arg[1];
		if (!(pc->arg[0] & pc->arg[1]))
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->size += get_size(map, pc->command, pc->size);
	pc->command = 0;
}
