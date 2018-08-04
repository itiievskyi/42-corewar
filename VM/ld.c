/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:44:26 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 02:37:24 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void				carry_stand(t_pc *pc, unsigned int tmp)
{
	if (tmp == 0)
		pc->carry = 1;
	else
		pc->carry = 0;
}

void					ld(unsigned char *map, t_pc **pc1)
{
	int					i;
	t_pc				*pc;
	int					size_tmp;

	pc = (*pc1);
	size_tmp = get_size(map, pc->command, pc->size);
	if (!(c_c_ld_lld(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 2)) != -1)
	{
		pc->arg[0] = -1;
		i = red_arg(map, pc, 2);
		pc->reg[get_map(map, i - 1) - 1] = pc->arg[0];
		carry_stand(pc, pc->arg[0]);
	}
	pc->size += size_tmp;
	pc->command = 0;
}
