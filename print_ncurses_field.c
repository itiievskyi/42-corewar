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

static int	get_player(t_ncurse *crwr, t_pc *pc)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (pc->parent == crwr->ids[i])
			break ;
		i++;
	}
	return (i + 1);
}

void		print_changes(t_ncurse *crwr, t_pc *pc)
{
	int i;
	int j;
	int x;
	int y;
	t_pc	*temp;

	temp = pc;
	x = 4;
	y = 9;
	while (temp)
	{
		attron(COLOR_PAIR(10 * get_player(crwr, temp)) | A_BOLD);
		j = 0;
		if (temp->change >= 0)
		{
			while (++j < 5)
			{
				i = (temp->change + j) % 4096 - 1;
				mvprintw(y + i / 64,
					(x + (i % 64 * 3)), "%.2X ",
					crwr->tab[i]);
			}
		}
		temp = temp->next;
		crwr->proc++;
		attroff(A_BOLD);
	}
}

void		print_field_start(t_ncurse *crwr, int i, int y, int x)
{
	int		p;

	p = 1;
	while (i < 4096 && crwr)
	{
		x = 4;
		while (x < 195)
		{
			if (i >= (4096 / crwr->players * p))
				p++;
			if (i < crwr->sizes[p - 1] + (4096 / crwr->players * (p - 1)))
				attron(COLOR_PAIR(10 * p));
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
	mvprintw(38, 239, "%02d", crwr->proc);
}
