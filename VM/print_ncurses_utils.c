/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:42:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/20 10:42:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_colors(void)
{
	attroff(COLOR_PAIR(1) | COLOR_PAIR(5) | COLOR_PAIR(7) | A_BOLD);
	attroff(COLOR_PAIR(4) | COLOR_PAIR(6) | A_STANDOUT);
	attroff(COLOR_PAIR(10) | COLOR_PAIR(20) | COLOR_PAIR(30) | COLOR_PAIR(40));
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(1, COLOR_GREY, COLOR_GREY);
	init_pair(2, COLOR_GREY, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(30, COLOR_CYAN, COLOR_BLACK);
	init_pair(40, COLOR_YELLOW, COLOR_BLACK);
	init_pair(50, COLOR_GREY, COLOR_BLACK);
}

void		print_music(t_ncurse *crwr)
{
	if (!crwr->win)
	{
		system("#!/bin/sh\n\
				if pkill -0 -x 'afplay' 2>/dev/null \n\
				then\n\
				pkill -9 afplay & \n\
				else \n\
				afplay ./VM/music.mp3 & \n\
				fi");
	}
	else if (crwr->win)
	{
		system("#!/bin/sh\n\
				pkill -9 'afplay'");
	}
}

int			get_player(t_ncurse *crwr, t_pc *pc)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (pc->parent == crwr->ids[i])
			break ;
		i++;
	}
	if (i < 4 && i >= 0)
		return (i + 1);
	return (0);
}

int			get_player_byid(t_ncurse *crwr, int id)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((unsigned int)id == crwr->ids[i])
			break ;
		i++;
	}
	if (i < 4 && i >= 0)
		return (i + 1);
	return (0);
}
