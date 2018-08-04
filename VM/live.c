/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:13:38 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 04:16:54 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				live(unsigned char *map, t_player *p, t_pc *pc)
{
	unsigned int	tmp;
	int				j;

	j = 0;
	tmp = take_arg(map, 4, pc->size + 1);
	while (p)
	{
		if (p->p_id == tmp)
		{
			p->pc_id = pc->id;
			j = 1;
			p->last_live = p->i;
			p->p_live++;
		}
		p = p->next;
	}
	if (!j)
		pc->left_live++;
	if (pc->live < 2)
		pc->live++;
	pc->size += get_size(map, pc->command, pc->size);
	pc->command = 0;
}
