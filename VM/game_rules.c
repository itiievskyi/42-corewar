/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:07:55 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 03:03:26 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					count_live(t_player *p, t_pc *pc)
{
	int				res;

	res = 0;
	while (pc != NULL)
	{
		res += pc->left_live;
		pc = pc->next;
	}
	while (p != NULL)
	{
		res += p->p_live;
		p = p->next;
	}
	return (res);
}

int					check_cycle(int count, int j, int cycle, t_player *p1)
{
	int				res;

	res = 0;
	res += count;
	if (res >= 21 && j % cycle == 0)
		return (0);
	if (j % cycle == 0)
	{
		while (p1 != NULL)
		{
			p1->p_live = 0;
			p1 = p1->next;
		}
	}
	return (j);
}

void				minus_live(t_pc *pc)
{
	while (pc != NULL)
	{
		pc->left_live = 0;
		pc->live--;
		pc = pc->next;
	}
}

int					delete_one_pc(t_pc **pc, t_pc *tmp, t_pc *cur, t_pc *pre)
{
	if (*pc && (*pc)->live <= 0)
	{
		tmp = (*pc);
		*pc = (*pc)->next;
		free(tmp);
		return (1);
	}
	if (!(*pc))
		return (0);
	cur = (*pc)->next;
	pre = (*pc);
	while (cur != NULL && pre != NULL)
	{
		if (cur->live <= 0)
		{
			tmp = cur;
			pre->next = cur->next;
			free(tmp);
			return (1);
		}
		pre = cur;
		cur = cur->next;
	}
	return (0);
}

void				delete_pc(t_player *p, t_pc **pc_1)
{
	int				i;
	t_pc			*cur;
	t_pc			*pre;
	t_pc			*tmp;

	cur = NULL;
	pre = NULL;
	tmp = NULL;
	while (p != NULL)
	{
		p->p_live = 0;
		p = p->next;
	}
	i = -1;
	minus_live((*pc_1));
	while (1)
	{
		if (!(delete_one_pc(pc_1, tmp, cur, pre)))
			break ;
	}
}
