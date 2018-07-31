/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:24:58 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 14:24:28 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_map(unsigned char *map, int coord)
{
	if (coord < 0)
		return (get_map(map, 4096 + coord));
	if (coord >= 4096)
		return (get_map(map, coord - 4096));
	return (map[coord]);
}

int		yes(t_pc *pc, int i)
{
	while (pc != NULL)
	{
		if (pc->size == i)
			return (1);
		pc = pc->next;
	}
	return (0);
}
void	print_map(unsigned char *map, t_pc *pc, t_player *p, int y)
{
	int				i;
	static t_ncurse	*crwr;

	if (pc && y != -3) {}
	i = -1;
	crwr = (t_ncurse*)malloc(sizeof(t_ncurse));
	crwr->players = count_player(p);
	crwr->names = (char**)malloc(sizeof(char*) * 4);
	while (++i < crwr->players)
	{
		crwr->names[i] = ft_strdup((const char*)(p->p_name));
		crwr->sizes[i] = p->p_size;
		crwr->ids[i] = p->p_id;
		p = p->next;
	}
	crwr->step = y;
	crwr->pause = 0;
	crwr->tab = map;
	print_ncurses(crwr, pc);
}

void		put_in_map(t_player *p, unsigned char *map)
{
	int		i;
	int		k;

	while (p != NULL)
	{
		i = 0;
		k = p->stand;
		while (i < p->p_size)
		{
			map[k] = p->p_code[i];
			i++;
			k++;
		}
		p = p->next;
	}
}
