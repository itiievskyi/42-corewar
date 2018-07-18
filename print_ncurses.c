/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:00:32 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/17 13:00:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ncurses.h"

static void	to_buffer(unsigned char *tab)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 9;
	attrset(A_DIM);
	while (i < 4096)
	{
		x = 4;
		while (x < 195)
		{
			mvprintw(y, x, "%.2X ", tab[i++]);
			x += 3;
		}
		y++;
	}
	attroff(A_DIM);
}

void		print_ncurses(unsigned char *tab)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	print_canvas(0, 0);
	to_buffer(tab);
	refresh();
//	usleep ( 500000 );
	getch();
	endwin();
}
