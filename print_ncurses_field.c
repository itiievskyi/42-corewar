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

void		check_highlites(t_ncurse *crwr, t_pc *temp, char *cmd)
{
	static int	s[4096];
	int			i;
	int x;
	int y;

	x = 4;
	y = 9;
	if (ft_strequ(cmd, "write"))
	{
		i = (temp->size) % 4096;
		s[i] = get_player(crwr, temp) * 10;
	}
	if (ft_strequ(cmd, "print"))
	{
		mvprintw(80, 90, "%.2X ", 0);
		i = -1;
		while (++i < 4096)
		{
			if (s[i] > 0)
			{
				attron(COLOR_PAIR(s[i]) | A_STANDOUT);
				mvprintw(y + i / 64, (x + (i % 64 * 3)), "%.2X", crwr->tab[i]);
				attroff(COLOR_PAIR(s[i]) | A_STANDOUT);
				s[i] *= -1;
			}
			else if (s[i] < 0)
			{
				attron(COLOR_PAIR(s[i] * (-1)));
				mvprintw(y + i / 64, (x + (i % 64 * 3)), "%.2X", crwr->tab[i]);
				attroff(COLOR_PAIR(s[i] * (-1)));
				s[i] = 0;
			}
		}
	}
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
	int k = 0;
	while (temp)
	{
		attron(COLOR_PAIR(10 * get_player(crwr, temp)) | A_BOLD);
		if (temp->size >= 0 && temp->size < 4096)
			check_highlites(crwr, temp, "write");
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
		mvprintw(78 + k, 10, "Player = %d", get_player(crwr, temp));
		mvprintw(78 + k, 40, "size = %d", temp->size);
		mvprintw(78 + k, 70, "change = %d", temp->change);
		k++;
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
