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

#include "vm.h"

static void	to_buffer(t_ncurse *crwr, t_pc *pc)
{
	crwr->proc = 0;
	attron(COLOR_PAIR(4) | A_BOLD);
	mvprintw(38, 210, "%05d", crwr->step);
	attroff(COLOR_PAIR(4) | A_BOLD);
	if (crwr->step == 0)
	{
		print_field_start(crwr, 0, 9, 0);
		return ;
	}
	else
		print_changes(crwr, pc);
	mvprintw(38, 239, "%02d", crwr->proc);
}

void		print_ncurses(t_ncurse *crwr, t_pc *pc)
{
	static int	debug;

	if (debug == 1)
		step_by_step(crwr, &debug);
	nodelay(stdscr, TRUE);
	if (!crwr->step)
	{
		printf("%d\n", crwr->players);
		print_music(crwr);
		signal(SIGINT, sighandler);
		setlocale(LC_ALL, "en_US.UTF-8");
		initscr();
		print_template(0, 0, crwr);
	}
	init_colors();
	to_buffer(crwr, pc);
	check_pause(crwr, 0, '\0', &debug);
	refresh();
	if (crwr->win > 0)
	{
		print_finish(crwr, 0, '\0');
		endwin();
	}
	usleep(20000 - crwr->pause * 5000);
}
