/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:24:58 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 06:10:27 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					get_map(unsigned char *map, int coord)
{
	if (coord < 0)
		return (get_map(map, 4096 + coord));
	if (coord >= 4096)
		return (get_map(map, coord - 4096));
	return (map[coord]);
}

int					yes(t_pc *pc, int i)
{
	while (pc != NULL)
	{
		if (pc->size == i)
			return (1);
		pc = pc->next;
	}
	return (0);
}

void				print_map(unsigned char *map, t_pc *pc,\
		t_player *p, t_rule *r)
{
	int				i;
	static t_ncurse	*crwr;

	p->last_live == 2147483647 ? 0 : print_players_lives(p);
	if (r->i - 1 == 0)
	{
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
	}
	if ((crwr->to_die = r->c) > -100 && p)
		p->last_live == 2147483647 ?
		crwr->win = get_player_byid(crwr, p->p_id) : 0;
	crwr->step = r->i - 1;
	crwr->pause = 0;
	crwr->tab = map;
	print_ncurses(crwr, pc);
}

void				put_in_map(t_player *p, unsigned char *map, t_rule *rule)
{
	int				i;
	int				k;
	t_player		*p1;

	p1 = p;
	if (rule->visual == 0 && (i = 1) == 1)
	{
		ft_printf("Introducting contestants ...\n");
		while (p1 != NULL)
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
					i++, p1->p_size, p1->p_name, p1->p_comment);
			p1 = p1->next;
		}
	}
	while (p != NULL)
	{
		i = -1;
		k = p->stand;
		while (++i < p->p_size)
			map[k++] = p->p_code[i];
		p = p->next;
	}
}
