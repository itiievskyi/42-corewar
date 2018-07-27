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

static void	print_changes(t_ncurse *crwr)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 4;
	y = 9;
	while (crwr->changes[i])
	{
		mvprintw(y + crwr->changes[i] / 64,
				(x + (crwr->changes[i] / 64 * 3)), "%.2X ",
				crwr->tab[crwr->changes[i]]);
		i++;
	}
}

static void	to_buffer(t_ncurse *crwr)
{
	attron(COLOR_PAIR(4) | A_BOLD);
	mvprintw(38, 210, "%05d", crwr->step);
	attroff(COLOR_PAIR(4) | A_BOLD);
	if (crwr->step == 0)
	{
		print_field_start(crwr, 0, 9, 0);
		return ;
	}
	else
		print_changes(crwr);
}

void		print_ncurses(t_ncurse *crwr)
{
	if (crwr->debug == 1)
		step_by_step(crwr);
	nodelay(stdscr, TRUE);
	if (!crwr->step)
	{
		print_music(crwr);
		signal(SIGINT, sighandler);
		setlocale(LC_ALL, "en_US.UTF-8");
		initscr();
		print_template(0, 0, crwr);
	}
	init_colors();
	to_buffer(crwr);
	check_pause(crwr, 0, '\0');
	refresh();
	if (crwr->win > 0)
	{
		print_finish(crwr, 0, '\0');
		endwin();
	}
	usleep(20000 - crwr->pause * 5000);
}
