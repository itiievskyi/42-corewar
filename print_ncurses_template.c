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
	mvprintw(3, 90 + 10, "%s", "   ┌─┐┬  ┬┌─┐┬─┐┌─┐┌┬┐┬┬ ┬   ");
	mvprintw(4, 90 + 10, "%s", "★  ├─┤└┐┌┘├┤ ├┬┘├┤ ││││└┬┘ ★");
	mvprintw(5, 90 + 10, "%s", "   ┴ ┴ └┘ └─┘┴└─└─┘┴ ┴┴ ┴    ");
	attroff(A_BOLD);
	mvprintw(3, 115 + 10 + 6, "%s", "│  ┌┬┐┌─┐┬ ┬┬┌─┬  ┬┌─┐┬");
	mvprintw(4, 115 + 10 + 6, "%s", "│  │││└─┐├─┤├┴┐│  │├─┤│");
	mvprintw(5, 115 + 10 + 6, "%s", "│  ┴ ┴└─┘┴ ┴┴ ┴┴─┘┴┴ ┴┴");
	mvprintw(3, 140 + 10 + 6, "%s", "│  ┬┌┬┐┬┬┌─┐┬  ┬┌─┐┬┌─");
	mvprintw(4, 140 + 10 + 6, "%s", "│  │ │ ││├┤ └┐┌┘└─┐├┴┐");
	mvprintw(5, 140 + 10 + 6, "%s", "│  ┴ ┴ ┴┴└─┘ └┘ └─┘┴ ┴");
	attron(COLOR_PAIR(5) | A_BOLD);
	mvprintw(1, 207, "%s", " _     _____ ____ _____ _   _ ____  ");
	mvprintw(2, 207, "%s", "| |   | ____/ ___| ____| \\ | |  _ \\ ");
	mvprintw(3, 207, "%s", "| |   |  _|| |  _|  _| |  \\| | | | |");
	mvprintw(4, 207, "%s", "| |___| |__| |_| | |___| |\\  | |_| |");
	mvprintw(5, 207, "%s", "|_____|_____\\____|_____|_| \\_|____/ ");
	attron(COLOR_PAIR(7) | A_BOLD);
	mvprintw(1 + 56, 207 + 5, "%s", " _   _ _____ _     ____  ");
	mvprintw(2 + 56, 207 + 5, "%s", "| | | | ____| |   |  _ \\ ");
	mvprintw(3 + 56, 207 + 5, "%s", "| |_| |  _| | |   | |_) |");
	mvprintw(4 + 56, 207 + 5, "%s", "|  _  | |___| |___|  __/ ");
	mvprintw(5 + 56, 207 + 5, "%s", "|_| |_|_____|_____|_|    ");
	attroff(COLOR_PAIR(7) | A_BOLD);
}

static void	print_header(void)
{
	init_color(COLOR_BLACK, 0, 0, 0);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
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
	attroff(COLOR_PAIR(3) | A_BOLD);
}
