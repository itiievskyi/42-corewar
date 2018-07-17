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

static void	print_canvas(int x, int y)
{
	start_color();
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(1, COLOR_GREY, COLOR_GREY);
	attron(COLOR_PAIR(1) | A_BOLD);
	while (y++ < 5)
	{
		x = 0;
		while (x < 194)
			mvprintw(y, x++, "*");
	}
	y--;
	while (y++ < 73)
	{
		mvprintw(y, 0, "*");
		mvprintw(y, 193, "*");
	}
	x = 0;
	while (x < 194)
		mvprintw(y, x++, "*");
	init_pair(2, COLOR_WHITE, COLOR_GREY);
	attron(COLOR_PAIR(2));
	mvprintw(3, 100, "COREWAR!");
	mvprintw(4, 89, "by averemiy, mshkliai, itiievsk");
	attron(COLOR_PAIR(init_pair(3, COLOR_MAGENTA, COLOR_GREY) + 2));
	attroff(COLOR_PAIR(3) | A_BOLD);
}

static void	to_buffer(unsigned char *tab)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 7;
	while (i < 4096)
	{
		x = 3;
		while (x < 192)
		{
			mvprintw(y, x, "%.2X ", tab[i++]);
			x += 3;
		}
		mvprintw(y, x - 1, "\n");
		y++;
	}
}

void		print_ncurses(unsigned char *tab)
{
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	to_buffer(tab);
	print_canvas(0, 0);
	refresh();
	getch();
	endwin();
}
