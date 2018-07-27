/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:52:49 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/25 18:21:45 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ldi(unsigned char *map, t_pc **pc1)
{
	int		i;
	t_pc	*pc;
	int		tmp_size;

	pc = (*pc1);
	tmp_size = get_size(map, pc->command, pc->size);
	if (!(c_c_ldi_lldi(get_map(map, pc->size + 1))))
	{
//		printf("ldi\n");
		i = red_arg(map, pc, 3);
//		printf("after\n");
//		printf("1arg in ldi = %u\n2nd arf in ldi = %u\n", pc->arg[0], pc->arg[1]);
		pc->reg[get_map(map, i - 1) - 1] = take_arg(map, 4, ((short)(pc->arg[0] + pc->arg[1]) % IDX_MOD) + pc->size);
	}
	pc->size += tmp_size;
	pc->command = 0;
}
