/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:15:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/24 11:17:43 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_manual_text(WINDOW **win)
{
	wattron(*win, COLOR_PAIR(40) | A_BOLD);
	mvwaddstr(*win, 4 + 1, 5, "Cycles");
	mvwaddstr(*win, 8 + 1, 5, "Processes");
	mvwaddstr(*win, 12 + 1, 5, "CYCLE_TO_DIE");
	mvwaddstr(*win, 16 + 1, 5, "CYCLE_DELTA");
	mvwaddstr(*win, 20 + 1, 5, "NBR_LIVE");
	mvwaddstr(*win, 24 + 1, 5, "MAX_CHECKS");
	wattron(*win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(*win, 4 + 1, 20, "Shows the current cycle.");
	mvwaddstr(*win, 4 + 2, 20, "The first cycle is 0.");
	mvwaddstr(*win, 8 + 1, 20, "Shows how many processes are now running.");
	mvwaddstr(*win, 8 + 2, 20, "Includes processes of all players");
	mvwaddstr(*win, 12 + 1, 20,
	"The number of cycles to check until the prosses died.");
	mvwaddstr(*win, 12 + 2, 20,
	"The default value is 1536. Could be changed (reduced) by CYCLE_DELTA.");
	mvwaddstr(*win, 16 + 1, 20,
	"The number of cycles to substract from CYCLE_TO_DIE if the the process");
	mvwaddstr(*win, 16 + 2, 20, "signalised 'live' more than 21 times.");
	mvwaddstr(*win, 20 + 1, 20,
	"Shows the number of 'live' responses form the processes required to");
	mvwaddstr(*win, 20 + 2, 20, "reduce CYCLE_TO_DIE by CYCLE_DELTA.");
	mvwaddstr(*win, 24 + 1, 20,
	"The maximum checks to perform until CYCLE_TO_DIE will be reduced by");
	mvwaddstr(*win, 24 + 2, 20, "CYCLE_DELTA if NBR_LIVE was not used");
}

static void	init_win(WINDOW **win)
{
	int		startx;
	int		starty;
	int		height;
	int		width;
	float	center;

	*win = newwin(HELP_LINES, HELP_COLS, 64 / 2 - 15 + 8, 198 / 2 - 51);
	getbegyx(*win, starty, startx);
	getmaxyx(*win, height, width);
	box(*win, 0, 0);
	mvwaddch(*win, 2, 0, ACS_LTEE);
	mvwhline(*win, 2, 1, ACS_HLINE, width - 2);
	mvwaddch(*win, 2, width - 1, ACS_RTEE);
	center = width / 2;
	wattron(*win, COLOR_PAIR(6) | A_BOLD);
	mvwaddstr(*win, 1, center - 14, "COREWAR Visualization Manual");
	wattron(*win, COLOR_PAIR(7) | A_BOLD);
	mvwaddstr(*win, height - 1, center - 21,
		" Press 'h' to quit manual and resume the game ");
	print_manual_text(win);
}

void		print_help(t_ncurse *crwr)
{
	int				ch;
	WINDOW			*help_win;

	PANEL * help_panel;
	init_win(&help_win);
	help_panel = new_panel(help_win);
	update_panels();
	doupdate();
	while ((ch = getch()) != 'h' && ch != 'H')
	{
		if (ch == 'm' || ch == 'M')
			print_music(crwr);
		update_panels();
		doupdate();
		ch = '\0';
	}
	hide_panel(help_panel);
	free(help_panel);
}
