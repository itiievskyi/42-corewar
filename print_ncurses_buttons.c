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

#include "print_ncurses.h"

static void	button_action(t_ncurse *crwr, char ch)
{
	if (ch == '+' && crwr->pause < 4)
		crwr->pause += 1;
	else if (ch == '-' && crwr->pause > -4)
		crwr->pause -= 1;
	else if (ch == 'h')
		print_help();
}

char		check_pause(t_ncurse *crwr, int pause, char ch)
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(67, 202, "Press SPACE to pause the game ");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(65, 202, "The game is running...");
	mvprintw(37, 202, "The current game speed modifier: % 2d", crwr->pause);
	if (crwr->win == 0 && pause == 0)
	{
		nodelay(stdscr, TRUE);
		if ((ch = getch()) == ' ' || ch == 'h')
			pause = 1;
		button_action(crwr, ch);
		if (ch == 'h')
			pause = 0;
		ch = '\0';
	}
	if ((!crwr->step || pause) && !mvaddstr(65, 202, "The game is paused... "))
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(67, 202, "Press SPACE to resume the game");
		while (ch != ' ')
			if ((ch = getch()) == 'h')
				print_help();
		ch = '\0';
	}
	return (ch);
}
