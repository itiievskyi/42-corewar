/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:17:01 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 14:22:25 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void        init_pc(t_pc **tmp, int parent, int stand)
{
    int        i;
    t_pc    *pc;

    i = 0;
	pc = (t_pc *)malloc(sizeof(t_pc));
    while (i++ < 16)
        pc->reg[i] = 0;
    i = -1;
    while (++i < 3)
        pc->arg[i] = 0;
    pc->reg[0] = -1;
    pc->carry = 0;
    pc->parent = parent;
    pc->live = 1;
	pc->change = -1;
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

int			count_player(t_player *p)
{
	int		i;

	i = 0;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}

t_pc		*create_pc(t_player *p)
{
	int		i;
	int		j;
	t_pc	*pc;

	pc = NULL;
	j = -1;
	i = count_player(p);
	if (i == 0 || i > 4)
		return (NULL);
	while (++j < i)
	{
		p->stand = (j * (64 / i)) * 64;
		init_pc(&pc, p->p_id, ((j * (64 / i)) * 64));
		p = p->next;
	}
	return (pc);
}
