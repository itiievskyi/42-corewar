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

#include "print_ncurses.h"

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
				attron(COLOR_PAIR(10 * p) | A_BOLD);
			else
				attroff(COLOR_PAIR(10 * p) | A_BOLD);
			mvprintw(y, x, "%.2X ", crwr->tab[i++]);
			x += 3;
		}
		y++;
	}
}
