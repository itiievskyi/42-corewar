/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:13:38 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 15:09:43 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		live(unsigned char *map, t_player *p, t_pc *pc)
{
	unsigned int tmp;

	tmp = take_arg(map, 4, pc->size + 1);
//	printf("%u\n %u\n", tmp, pc->reg[0]);
	// fix for many players
	if (tmp == pc->reg[0])
	{
//		printf("d===================================================================\n");
		p->p_live++;
	}
//	printf("in live\n");
	if (pc->live < 2)
	{
//		printf("in if\n");
		pc->live++;
//		printf("pc->live %d\n", pc->live);
	}
	pc->size += get_size(map, pc->command, pc->size);
	pc->command = 0;
}
