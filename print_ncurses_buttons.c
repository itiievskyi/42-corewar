/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_buttons.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:43:47 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/27 10:43:49 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	button_action(t_ncurse *crwr, char ch)
{
	if (ch == '+' && crwr->pause < 4)
		crwr->pause += 1;
	else if (ch == '-' && crwr->pause > -4)
		crwr->pause -= 1;
	else if (ch == 'h' || ch == 'H')
		print_help();
	else if (ch == 's' || ch == 'S')
		crwr->debug = 1;
	if (crwr->debug == 1)
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(62 - 1, 202, "Press SPACE to resume or 's' for the next step");
		attron(COLOR_PAIR(5) | A_BOLD);
		mvaddstr(60 - 1, 202, "Debug mod ON             ");
	}
}

void		check_pause(t_ncurse *crwr, int pause, char ch)
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(62 - 1, 202, "Press SPACE to pause the game                  ");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(60 - 1, 202, "The game is running...");
	mvprintw(37 - 1, 202, "The current game speed modifier: % 2d", crwr->pause);
	if (crwr->win == 0 && pause == 0)
	{
		nodelay(stdscr, TRUE);
		if ((ch = getch()) == ' ' || ch == 'h')
			pause = 1;
		button_action(crwr, ch);
		if (ch == 'h' || ch == 'H')
			pause = 0;
		ch = '\0';
	}
	if ((!crwr->step || pause) && !mvaddstr(59, 202, "The game is paused... "))
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(61, 202, "Press SPACE to resume the game                ");
		while (ch != ' ')
		{
			button_action(crwr, (ch = getch()));
			if (ch == 's' || ch == 'S')
				break ;
		}
	}
}

void		step_by_step(t_ncurse *crwr)
{
	char	ch;

	ch = '\0';
	if (crwr->debug == 1)
	{
		halfdelay(10000);
		while (ch != 's' && ch != ' ' && ch != 'S')
			ch = getch();
		if (ch == ' ')
			crwr->debug = 0;
	}
}
