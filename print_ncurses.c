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

static void	print_changes(t_ncurse *crwr, t_pc *pc)
{
	int i;
	int j;
	int x;
	int y;
	t_pc	*temp;

	temp = pc;
	x = 4;
	y = 9;
	while (temp)
	{
		j = 0;
		if (temp->change >= 0)
		{
			while (++j < 5)
			{
				i = (temp->change + j) % 4096;
				mvprintw(y + crwr->changes[i] / 64,
					(x + (crwr->changes[i] / 64 * 3)), "%.2X ",
					crwr->tab[crwr->changes[i]]);
					i++;
			}
		}
		temp = temp->next;
	}
}

static void	to_buffer(t_ncurse *crwr, t_pc *pc)
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
		print_changes(crwr, pc);
}

void		print_ncurses(t_ncurse *crwr, t_pc *pc)
{
	if (crwr->debug == 1)
		step_by_step(crwr);
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
	check_pause(crwr, 0, '\0');
	refresh();
	if (crwr->win > 0)
	{
		print_finish(crwr, 0, '\0');
		endwin();
	}
	usleep(20000 - crwr->pause * 5000);
}
