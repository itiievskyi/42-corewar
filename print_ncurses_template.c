/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_template.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:52:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/18 13:52:49 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_team(void)
{
	attron(COLOR_PAIR(6) | A_BOLD);
	mvaddstr(3, 90 + 10, "   ┌─┐┬  ┬┌─┐┬─┐┌─┐┌┬┐┬┬ ┬   ");
	mvaddstr(4, 90 + 10, "★  ├─┤└┐┌┘├┤ ├┬┘├┤ ││││└┬┘ ★");
	mvaddstr(5, 90 + 10, "   ┴ ┴ └┘ └─┘┴└─└─┘┴ ┴┴ ┴    ");
	attroff(A_BOLD);
	mvaddstr(3, 115 + 10 + 6, "│  ┌┬┐┌─┐┬ ┬┬┌─┬  ┬┌─┐┬");
	mvaddstr(4, 115 + 10 + 6, "│  │││└─┐├─┤├┴┐│  │├─┤│");
	mvaddstr(5, 115 + 10 + 6, "│  ┴ ┴└─┘┴ ┴┴ ┴┴─┘┴┴ ┴┴");
	mvaddstr(3, 140 + 10 + 6, "│  ┬┌┬┐┬┬┌─┐┬  ┬┌─┐┬┌─");
	mvaddstr(4, 140 + 10 + 6, "│  │ │ ││├┤ └┐┌┘└─┐├┴┐");
	mvaddstr(5, 140 + 10 + 6, "│  ┴ ┴ ┴┴└─┘ └┘ └─┘┴ ┴");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(1, 207, " _     _____ ____ _____ _   _ ____  ");
	mvaddstr(2, 207, "| |   | ____/ ___| ____| \\ | |  _ \\ ");
	mvaddstr(3, 207, "| |   |  _|| |  _|  _| |  \\| | | | |");
	mvaddstr(4, 207, "| |___| |__| |_| | |___| |\\  | |_| |");
	mvaddstr(5, 207, "|_____|_____\\____|_____|_| \\_|____/ ");
	attron(COLOR_PAIR(7) | A_BOLD);
	mvaddstr(1 + 50, 207 + 5, " _   _ _____ _     ____  ");
	mvaddstr(2 + 50, 207 + 5, "| | | | ____| |   |  _ \\ ");
	mvaddstr(3 + 50, 207 + 5, "| |_| |  _| | |   | |_) |");
	mvaddstr(4 + 50, 207 + 5, "|  _  | |___| |___|  __/ ");
	mvaddstr(5 + 50, 207 + 5, "|_| |_|_____|_____|_|    ");
	mvaddstr(69, 202, "Press CTRL+C to exit at any time");
	attroff(COLOR_PAIR(7) | A_BOLD);
}

static void	print_header(void)
{
	attron(COLOR_PAIR(4));
	mvprintw(1, 22, "%S",
	L" ██████╗ ██████╗ ██████╗ ███████╗██╗    ██╗ █████╗ ██████╗ ");
	mvprintw(2, 22, "%S",
	L"██╔════╝██╔═══██╗██╔══██╗██╔════╝██║    ██║██╔══██╗██╔══██╗");
	mvprintw(3, 22, "%S",
	L"██║     ██║   ██║██████╔╝█████╗  ██║ █╗ ██║███████║██████╔╝");
	mvprintw(4, 22, "%S",
	L"██║     ██║   ██║██╔══██╗██╔══╝  ██║███╗██║██╔══██║██╔══██╗");
	mvprintw(5, 22, "%S",
	L"╚██████╗╚██████╔╝██║  ██║███████╗╚███╔███╔╝██║  ██║██║  ██║");
	mvprintw(6, 22, "%S",
	L" ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvprintw(3, 88, "%s", "┌┐ ┬ ┬");
	mvprintw(4, 88, "%s", "├┴┐└┬┘");
	mvprintw(5, 88, "%s", "└─┘ ┴ ");
	mvaddstr(71, 202, "The project is prepared for 42School's project");
	mvaddstr(72, 202, "COREWAR in 2018. All rights reserved, cheaters");
	mvprintw(37 - 1, 202, "The current game speed modifier:  0");
	attroff(COLOR_PAIR(5) | A_BOLD);
	print_team();
}

static void	print_players(t_ncurse *crwr, int i, int len)
{
	attron(COLOR_PAIR(5) | A_BOLD);
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
	attroff(COLOR_PAIR(5) | A_BOLD);
	while (++i < 4)
	{
		if (crwr->players > i && (len = ft_strlen(crwr->names[i])))
		{
			attron(COLOR_PAIR(10 * (i + 1)) | A_BOLD);
			mvprintw(13 + i * 6, 200 + ((50 - len) / 2), "%s", crwr->names[i]);
			attroff(COLOR_PAIR(10 * (i + 1)) | A_BOLD);
		}
		else
			mvprintw(13 + i * 6, 202, "Player was not set :(");
	}
}

static void	print_misc(t_ncurse *crwr)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		mvprintw(9 + 6 * i, 230, "Last live: %-5d", 0);
		mvprintw(11 + 6 * i, 230, "Period lives: %-5d", 0);
	}
	attron(COLOR_PAIR(5) | A_BOLD);
	mvaddstr(39 - 1, 202, "Cycle : ");
	mvaddstr(39 - 1, 227, "Processes : ");
	mvprintw(41 - 1, 202, "CYCLE_TO_DIE : %-4d", crwr->to_die);
	mvprintw(41 - 1, 227, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(43 - 1, 202, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(43 - 1, 227, "MAX_CHECKS : %d", MAX_CHECKS);
	mvprintw(38, 239, "%-6d", crwr->proc);
	attroff(COLOR_PAIR(5) | A_BOLD);
	attron(COLOR_PAIR(40) | A_BOLD);
	mvaddstr(65, 202, "Press 'h' to toggle Help, 'm' to toggle music ♫");
	mvaddstr(67, 202, "Press '+' or '-' to change the speed");
	mvaddstr(63, 202, "Press 's' to manage with DEBUG mod");
	attroff(COLOR_PAIR(40) | A_BOLD);
	print_music(crwr);
}

void		print_template(int x, int y, t_ncurse *crwr)
{
	start_color();
	curs_set(0);
	cbreak();
	noecho();
	attron(COLOR_PAIR(1) | A_BOLD);
	while (x < 252)
		mvprintw(y, x++, "*");
	x = 0;
	while (x < 252)
		mvprintw(7, x++, "*");
	while (y++ < 73)
	{
		mvprintw(y, 0, "*");
		mvprintw(y, 198, "*");
		mvprintw(y, 251, "*");
		if ((y == 50 || y == 57 || y == 34) && (x = 198))
			while (x < 252)
				mvprintw(y, x++, "*");
	}
	x = 0;
	while (x < 252)
		mvprintw(y, x++, "*");
	print_header();
	print_players(crwr, -1, 0);
	print_misc(crwr);
}
