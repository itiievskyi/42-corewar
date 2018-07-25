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

static char	check_pause(t_ncurse *crwr, int pause, char ch)
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(67, 202, "Press SPACE to pause the game ");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(65, 202, "The game is running...");
	if (crwr->win == 0 && pause == 0)
	{
		halfdelay(1);
		if ((ch = getch()) == ' ' || ch == 'h')
			pause = 1;
		if (ch == 'h')
		{
			print_help();
			pause = 0;
		}
		ch = '\0';
	}
	if ((!crwr->step || pause) && !mvaddstr(65, 202, "The game is paused... "))
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(67, 202, "Press SPACE to resume the game");
		while (ch != ' ')
			ch = getch();
		ch = '\0';
	}
	return (ch);
}

static void	to_buffer(t_ncurse *crwr)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 9;
	attron(COLOR_PAIR(4) | A_BOLD);
	mvprintw(39, 210, "%05d", crwr->step);
	attroff(COLOR_PAIR(4) | A_BOLD);
	if (crwr->step == 0)
	{
		print_field_start(crwr, 0, 9, 0);
		return ;
	}
	while (i < 4096 && crwr)
	{
		x = 4;
		while (x < 195)
		{
			mvprintw(y, x, "%.2X ", crwr->tab[i++]);
			x += 3;
		}
		y++;
	}
}

void		print_ncurses(t_ncurse *crwr)
{
	if (!crwr->step)
		print_music(crwr);
	signal(SIGINT, sighandler);
	setlocale(LC_ALL, "en_US.UTF-8");
	initscr();
	start_color();
	init_colors();
	curs_set(0);
	cbreak();
	noecho();
	if (crwr->step == 0)
		print_template(0, 0, crwr);
	to_buffer(crwr);
	if (crwr->win > 0)
		print_finish(crwr, 0, '\0');
	refresh();
	check_pause(crwr, 0, '\0');
	usleep(200000);
	endwin();
}
