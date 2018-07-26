/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_finish.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:50:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/20 13:50:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ncurses.h"

static void	print_winner(int winner)
{
	if (winner == 1)
	{
		mvaddstr(9, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗   ╗");
		mvaddstr(10, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝   ║");
		mvaddstr(11, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═   ╩");
	}
	else if (winner == 2)
	{
		mvaddstr(9 + 6 * 1, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╔═╗");
		mvaddstr(10 + 6 * 1, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝  ╔═╝");
		mvaddstr(11 + 6 * 1, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═  ╚═╝");
	}
	else if (winner == 3)
	{
		mvaddstr(9 + 6 * 2, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╔═╗");
		mvaddstr(10 + 6 * 2, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝   ═╣");
		mvaddstr(11 + 6 * 2, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═  ╚═╝");
	}
	else if (winner == 4)
	{
		mvaddstr(9 + 6 * 3, 202, "╔═╗╦  ╔═╗╦ ╦╔═╗╦═╗  ╦ ╦");
		mvaddstr(10 + 6 * 3, 202, "╠═╝║  ╠═╣╚╦╝║╣ ╠╦╝  ╚═╣");
		mvaddstr(11 + 6 * 3, 202, "╩  ╩═╝╩ ╩ ╩ ╚═╝╩╚═    ╩");
	}
}

void		print_finish(t_ncurse *crwr, int i, char ch)
{
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(48, 218, "The winner is:");
	mvaddstr(52, 214, "Thank you for playing!");
	attron(COLOR_PAIR(10 * (crwr->win)) | A_BOLD);
	mvprintw(50, 200 + ((50 - ft_strlen(crwr->names[crwr->win - 1])) / 2),
		"%s", crwr->names[crwr->win - 1]);
	nodelay(stdscr, TRUE);
	while (i++ < 10000 && ch != 'q')
	{
		if (ch == 'h')
			print_help();
		i % 2 == 0 ? attron(COLOR_PAIR(10 * (crwr->win)) | A_BOLD) :
			attron(COLOR_PAIR(5) | A_BOLD);
		refresh();
		print_winner(crwr->win);
		attroff(COLOR_PAIR(10 * (crwr->win)) | COLOR_PAIR(5) | A_BOLD);
		usleep(100000);
		attron(COLOR_PAIR(7) | A_BOLD);
		mvaddstr(67, 202, "Press 'q' to quit the game         ");
		attron(COLOR_PAIR(5) | A_BOLD);
		mvaddstr(65, 202, "The game is over...    ");
		ch = getch();
	}
	print_music(crwr);
}
