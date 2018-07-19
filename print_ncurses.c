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

static void	check_pause(int i, int pause)
{
	char ch;

	ch = '\0';
	attron(COLOR_PAIR(5));
	mvaddstr(65, 208, "The game is running...");
	if (pause == 0)
	{
		halfdelay( 1 );
		if ((ch = getch()) == ' ')
			pause = 1;
		ch = '\0';
	}
	if (i == 0 || pause)
	{
		while (ch != ' ')
			ch = getch();
		ch = '\0';
	}
	if (i == 49)
	{
		while (ch != 'q')
			ch = getch();
	}
}

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
	static int	i;

	setlocale(LC_ALL, "en_US.UTF-8");
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	print_canvas(0, 0);
	to_buffer(tab);
	refresh();
	check_pause(i++, 0);
	usleep ( 200000 );
	endwin();
}
