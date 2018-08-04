/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_field.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:02:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/20 15:02:38 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_players_lives(t_player *p)
{
	int i;

	i = -1;
	while (p && ++i < 4)
	{
		mvprintw(9 + 6 * i, 230, "Last live: %-7d", p->last_live);
		if (p->p_live >= 0)
			mvprintw(11 + 6 * i, 230, "Period lives: %-6d", p->p_live);
		p = p->next;
	}
}

static void	write_changes(t_ncurse *crwr, t_pc *temp, int i)
{
	int		x;
	int		y;

	x = 4;
	y = 9;
	mvprintw(y + i / 64, (x + (i % 64 * 3)), "%.2X ", crwr->tab[i]);
	if (get_player(crwr, temp) > 0)
	{
		crwr->chng[i] = 10 * get_player(crwr, temp);
		check_highlites(crwr, temp, "write_change");
	}
}

void		print_changes(t_ncurse *crwr, t_pc *pc)
{
	int		i;
	int		j;
	t_pc	*temp;

	temp = pc;
	while (temp)
	{
		attron(COLOR_PAIR(10 * get_player(crwr, temp)) | A_BOLD);
		if (temp->size >= 0 && temp->size < 4096)
			check_highlites(crwr, temp, "write");
		j = -1;
		if (temp->change >= 0)
		{
			while (++j < 4)
			{
				i = (temp->change + j) % 4096;
				write_changes(crwr, temp, i);
			}
			temp->change = -1;
		}
		temp = temp->next;
		crwr->proc++;
		attroff(A_BOLD);
	}
	check_highlites(crwr, temp, "print");
}

void		print_field_start(t_ncurse *crwr, int i, int y, int x)
{
	int		p;

	p = 1;
	while (i < 4096 && crwr && (x = 4))
	{
		while (x < 195)
		{
			if (i >= (4096 / crwr->players * p))
				p++;
			if (i < crwr->sizes[p - 1] + (4096 / crwr->players * (p - 1)))
			{
				attron(COLOR_PAIR(10 * p));
				crwr->chng[i] = 10 * p;
			}
			else
			{
				attroff(COLOR_PAIR(10 * p));
				attron(COLOR_PAIR(2));
			}
			mvprintw(y, x, "%.2X ", crwr->tab[i++]);
			x += 3;
		}
		y++;
	}
}
