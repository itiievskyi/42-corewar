/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_forcequit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:18:56 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/25 14:18:59 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ncurses.h"

static void	force_quit(int signum)
{
	system("clear");
	system("pkill -9 'afplay'");
	ft_printf("You have pressed Ctrl+C. Shame on you!");
	exit(signum);
}

static void	print_manual_text(WINDOW **win)
{
	wattron(*win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(*win, 4 + 1, 5, "You're going to quit the game!");
	mvwaddstr(*win, 6 + 1, 5, "Is that a problem?");
	wattron(*win, COLOR_PAIR(7) | A_BOLD);
	mvwaddstr(*win, 8 + 1, 5, "YES!");
	wattron(*win, COLOR_PAIR(5) | A_BOLD);
	mvwaddstr(*win, 10 + 1, 5, "We did our best to make this fucking VM run!");
	mvwaddstr(*win, 12 + 1, 5, "And now what?! You just quit!");
	mvwaddstr(*win, 14 + 1, 5, "Ok, let's talk like adults.");
	mvwaddstr(*win, 16 + 1, 5, "If your have balls, just press 'n' and watch.");
	mvwaddstr(*win, 18 + 1, 5,
		"Otherwise, press 'n' and run as far as you can.");
}

static void	init_quit_win(WINDOW **win)
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
	mvwaddstr(*win, 1, center - 14, "Are you sure you want to quit???");
	wattron(*win, COLOR_PAIR(7) | A_BOLD);
	mvwaddstr(*win, height - 5, center - 22,
		"Press 'n' to resume the game or 'y' to quit");
	print_manual_text(win);
}

void		sighandler(int signum)
{
	WINDOW			*quit_win = NULL;
	PANEL			*quit_panel;
	t_panel_data	panel_data;
	t_panel_data	*temp;
	int				ch;

	init_quit_win(&quit_win);
	quit_panel = new_panel(quit_win);
	panel_data.hide = FALSE;
	set_panel_userptr(quit_panel, &panel_data);
	update_panels();
	doupdate();
	while((ch = getch()) != 'N' && ch != 'n')
	{
		if (ch == 'y' || ch == 'Y')
			force_quit(signum);
		update_panels();
		doupdate();
		ch = '\0';
	}
	temp = (t_panel_data *)panel_userptr(quit_panel);
	temp->hide = TRUE;
}
