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

static void	check_pause(int i, int pause, char ch)
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(67, 202, "Press SPACE to pause the game ");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(65, 202, "The game is running...");
	if (pause == 0)
	{
		halfdelay( 1 );
		if ((ch = getch()) == ' ')
			pause = 1;
		ch = '\0';
	}
	if (i == 0 || pause)
	{
		mvaddstr(65, 202, "The game is paused... ");
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(67, 202, "Press SPACE to resume the game");
		while (ch != ' ')
			ch = getch();
		ch = '\0';
	}
	if (i == 49 && !(mvaddstr(65, 213, "The game is over...    ")) &&
		!(attron(COLOR_PAIR(7) | A_BOLD)) &&
		!(mvaddstr(67, 202, "Press 'q' to quit the game         ")))
		while (ch != 'q')
			ch = getch();
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
	start_color();
	init_colors();
	curs_set(0);
	cbreak();
	noecho();
	print_canvas(0, 0);
	to_buffer(tab);
	refresh();
	check_pause(i++, 0, '\0');
	usleep ( 200000 );
	endwin();
}

void		init_colors(void)
{
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(1, COLOR_GREY, COLOR_GREY);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);
	attroff(A_DIM);
}
