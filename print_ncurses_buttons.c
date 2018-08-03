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

static void	button_action(t_ncurse *crwr, char ch, int *debug)
{
	static int	pause;

	crwr->pause != 0 ? pause = crwr->pause : pause;
	if (ch == '+' && pause < 4)
		pause += 1;
	else if (ch == '-' && pause > -5)
		pause -= 1;
	else if (ch == 'h' || ch == 'H')
		print_help(crwr);
	else if (ch == 's' || ch == 'S')
		*debug = 1;
	else if (ch == 'm' || ch == 'M')
		print_music(crwr);
	if (*debug == 1)
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(62 - 1, 202, "Press SPACE to resume or 's' for the next step");
		attron(COLOR_PAIR(5) | A_BOLD);
		mvaddstr(60 - 1, 202, "Debug mod ON             ");
	}
	crwr->pause = pause;
	attron(COLOR_PAIR(5) | A_BOLD);
	mvprintw(37 - 1, 202, "The current game speed modifier: % 2d", pause);
}

void		check_pause(t_ncurse *crwr, int pause, char ch, int *debug)
{
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(62 - 1, 202, "Press SPACE to pause the game                  ");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(60 - 1, 202, "The game is running...");
	if (crwr->win == 0 && pause == 0)
	{
		nodelay(stdscr, TRUE);
		if ((ch = getch()) == ' ' || ch == 'h')
			pause = 1;
		button_action(crwr, ch, debug);
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
			button_action(crwr, (ch = getch()), debug);
			if (ch == 's' || ch == 'S')
				break ;
		}
	}
}

void		step_by_step(int *debug, t_ncurse *crwr)
{
	char		ch;
	char		*pause;

	ch = '\0';
	pause = (char*)malloc(sizeof(char) * 2);
	mvinnstr(36, 235, pause, 2);
	crwr->pause = ft_atoi(pause);
	mvprintw(37 - 1, 235, "% 2d", crwr->pause);
	if (*debug == 1)
	{
		halfdelay(10000);
		while (ch != 's' && ch != ' ' && ch != 'S')
		{
			if ((ch = getch()) == 'h' || ch == 'H')
				print_help(crwr);
			else if (ch == '+' && crwr->pause < 4 && (crwr->pause += 1) < 100)
				mvprintw(37 - 1, 235, "% 2d", crwr->pause);
			else if (ch == '-' && crwr->pause > -5 && (crwr->pause -= 1) < 100)
				mvprintw(37 - 1, 235, "% 2d", crwr->pause);
		}
		if (ch == ' ')
			*debug = 0;
	}
	free(pause);
}
