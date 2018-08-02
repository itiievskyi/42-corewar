/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:13:38 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/02 11:25:28 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				live(unsigned char *map, t_player *p, t_pc *pc)
{
	unsigned int	tmp;

	tmp = take_arg(map, 4, pc->size + 1);
	while (p)
	{
		if (p->p_id == tmp)
		{
			p->last_live = p->i;
			p->p_live++;
		}
		p = p->next;
	}
	if (pc->live < 2)
		pc->live++;
	pc->size += get_size(map, pc->command, pc->size);
	pc->command = 0;
}
