/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:07:55 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/24 14:36:40 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_cycle(t_player *p, int j, int cycle)
{
	if (p->p_live > 21 && j % cycle == 0)
	{
		p->p_live = 0;
		return (0);
	}
	return (j);
}

void		minus_live(t_pc *pc)
{
	while (pc != NULL)
	{
		pc->live--;
		pc = pc->next;
	}
}

void		delete_pc(t_pc **pc_1, int j)
{
	int		i;

	i = -1;
	minus_live((*pc_1));
	while (++i < j)
		delete_one_pc(pc_1);
}

void		delete_one_pc(t_pc **pc)
{
	t_pc	*tmp;
	t_pc	*cur;
	t_pc	*pre;

//	printf("%d\n", (*pc)->live);
	if ((*pc)->live <= 0)
	{
		tmp = (*pc);
		*pc = (*pc)->next;
		free(tmp);
		return ;
	}
	cur = (*pc)->next;
	pre = (*pc);
	while (cur != NULL && pre != NULL)
	{
		if (cur->live <= 0)
		{
			tmp = cur;
			pre->next = cur->next;
			free(tmp);
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}
