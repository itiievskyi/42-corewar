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

static void	print_finish(t_ncurse *crwr, int i)
{
	while (i++ < 1000)
	{
		i % 2 == 0 ? attron(COLOR_PAIR(10 * (crwr->win)) | A_BOLD) :
			attron(COLOR_PAIR(5) | A_BOLD);
		usleep ( 2000 );
		mvaddstr(9, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗   ╗");
		mvaddstr(10, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝   ║");
		mvaddstr(11, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═   ╩");
		mvaddstr(9 + 6 * 1, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╔═╗");
		mvaddstr(10 + 6 * 1, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝  ╔═╝");
		mvaddstr(11 + 6 * 1, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═  ╚═╝");
		mvaddstr(9 + 6 * 2, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╔═╗");
		mvaddstr(10 + 6 * 2, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝   ═╣");
		mvaddstr(11 + 6 * 2, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═  ╚═╝");
		mvaddstr(9 + 6 * 3, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╦ ╦");
		mvaddstr(10 + 6 * 3, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝  ╚═╣");
		mvaddstr(11 + 6 * 3, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═    ╩");
		attroff(COLOR_PAIR(10 * (crwr->win + 1)) | COLOR_PAIR(5) | A_BOLD);
	}
}

static void	check_pause(t_ncurse *crwr, int pause, char ch)
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
	if ((!crwr->step || pause) && !mvaddstr(65, 202, "The game is paused... "))
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(67, 202, "Press SPACE to resume the game");
		while (ch != ' ')
			ch = getch();
		ch = '\0';
	}
	if (crwr->win != 0 && !(mvaddstr(65, 202, "The game is over...    ")) &&
		!(attron(COLOR_PAIR(7) | A_BOLD)) &&
		!(mvaddstr(67, 202, "Press 'q' to quit the game         ")))
		while (ch != 'q')
			ch = getch();
}

static void	to_buffer(unsigned char *tab, t_ncurse *crwr)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 9;
	while (i < 4096 && crwr)
	{
		x = 4;
		while (x < 195)
		{
			mvprintw(y, x, "%.2X ", tab[i++]);
			x += 3;
		}
		y++;
	}
}

void		print_ncurses(unsigned char *tab, t_ncurse *crwr)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	initscr();
	start_color();
	init_colors();
	curs_set(0);
	cbreak();
	noecho();
	if (crwr->step == 0)
		print_template(0, 0, crwr);
	to_buffer(tab, crwr);
	if (crwr->win > 0)
		print_finish(crwr, 0);
	refresh();
	check_pause(crwr, 0, '\0');
	usleep ( 200000 );
	endwin();
}
