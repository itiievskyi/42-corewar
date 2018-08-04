/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:17:01 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 04:52:55 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		init_pc2(t_pc *pc, t_rule *r)
{
	pc->change = -1;
	pc->left_live = 0;
	(r->aff == 1) ? (pc->aff = 1) :
		(pc->aff = 0);
	pc->carry = 0;
	pc->live = 1;
	pc->id = r->id++;
}

void			init_pc(t_pc **tmp, unsigned int parent, int stand, t_rule *r)
{
	int			i;
	t_pc		*pc;

	i = 0;
	pc = (t_pc *)malloc(sizeof(t_pc));
	while (i++ < 16)
		pc->reg[i] = 0;
	i = -1;
	while (++i < 3)
		pc->arg[i] = 0;
	pc->reg[0] = parent;
	init_pc2(pc, r);
	pc->parent = parent;
	pc->cicles = 0;
	pc->command = 0;
	pc->size = stand;
	pc->next = NULL;
	if ((*tmp) == NULL)
		*tmp = pc;
	else
	{
		pc->next = (*tmp);
		*tmp = pc;
	}
}

int				count_player(t_player *p)
{
	int			i;

	i = 0;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}

t_pc			*create_pc(t_player *p, t_rule *r)
{
	int			i;
	int			j;
	t_pc		*pc;
	int			del;

	pc = NULL;
	j = -1;
	i = count_player(p);
	(i % 2 == 0) ? (del = 4096) :
		(del = 4095);
	if (i == 0 || i > 4)
		return (NULL);
	while (++j < i)
	{
		p->stand = (j * (del / i));
		init_pc(&pc, p->p_id, ((j * (del / i))), r);
		p = p->next;
	}
	return (pc);
}
