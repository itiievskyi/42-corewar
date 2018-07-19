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

#include "print_ncurses.h"

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
	mvaddstr(1 + 56, 207 + 5, " _   _ _____ _     ____  ");
	mvaddstr(2 + 56, 207 + 5, "| | | | ____| |   |  _ \\ ");
	mvaddstr(3 + 56, 207 + 5, "| |_| |  _| | |   | |_) |");
	mvaddstr(4 + 56, 207 + 5, "|  _  | |___| |___|  __/ ");
	mvaddstr(5 + 56, 207 + 5, "|_| |_|_____|_____|_|    ");
	attroff(COLOR_PAIR(7) | A_BOLD);
}

static void	print_header(void)
{
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);
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
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(5) | A_BOLD);
	mvprintw(3, 88, "%s", "┌┐ ┬ ┬");
	mvprintw(4, 88, "%s", "├┴┐└┬┘");
	mvprintw(5, 88, "%s", "└─┘ ┴ ");
	attroff(COLOR_PAIR(5) | A_BOLD);
	print_team();
}

void		print_canvas(int x, int y)
{
	start_color();
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(1, COLOR_GREY, COLOR_GREY);
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
		if ((y == 56 || y == 63) && (x = 198))
			while (x < 252)
				mvprintw(y, x++, "*");
	}
	x = 0;
	while (x < 252)
		mvprintw(y, x++, "*");
	print_header();
	attroff(COLOR_PAIR(1) | A_BOLD);
}
