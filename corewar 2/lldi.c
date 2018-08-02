/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:57:56 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/01 18:39:46 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lldi(unsigned char *map, t_pc **pc1)
{
	int				i;
	t_pc			*pc;
	unsigned int	res;
	int				tmp_size;

	pc = (*pc1);
	tmp_size = get_size(map, pc->command, pc->size);
	res = 0;
	if (!(c_c_ldi_lldi(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 3)) != -1)
	{
		res = take_arg(map, 4, ((short)(pc->arg[0] + pc->arg[1])) + pc->size);
		pc->reg[get_map(map, i - 1) - 1] = res;
		if (res == 0)
			pc->carry = 1;
		else
			pc->carry = 0;
	}
	pc->size += tmp_size;
	pc->command = 0;
}
