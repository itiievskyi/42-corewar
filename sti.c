/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:02:10 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/25 17:57:58 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		sti(unsigned char *map, t_pc **pc1)
{
	int		i;
	t_pc *pc;
	int		size_tmp;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_sti(get_map(map, pc->size + 1))))
	{
	i = red_arg(map, pc, 3);
		set_bit(pc->size + (((short)(pc->arg[1] + pc->arg[2])) % IDX_MOD), map, pc->arg[0], pc);
//	printf("sti \n");
//	printf("reg n = %u\nreg = %u", get_map(map, (pc->size + 1)) - 1, pc->reg[get_map(map, pc->size + 1) - 1]);
//	printf("pc size : %d\n", pc->size + (short)(pc->arg[1] + pc->arg[2]) % (IDX_MOD));
//	printf("arg1 = %u\narg2 =%u\narg3 =%u\n",pc->arg[0], pc->arg[1], pc->arg[2]);
	}
	pc->size += size_tmp;
	pc->command = 0;
}
