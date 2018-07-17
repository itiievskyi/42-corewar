/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:01:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/17 09:01:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		tab[] = {0, 0, 0};
	char	ch;
	int		pause;

	pause = 1;
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	halfdelay(1);
	i = (argc == 1 ? 3 : atoi(argv[1]));
	while (tab[0] < i)
	{
		tab[1] = 0;
		while (tab[1] < 3)
		{
			tab[2] = 0;
			while (tab[2] < 3)
			{
				mvprintw(0, 0, "phase = %d\tstep = %d\titer = %d", tab[0], tab[1], tab[2]);
				mvprintw(1, 0, "What the fuck?!");
				ch = getch();
				if (!pause && ch == ' ')
					pause = 1;
				else
					ch = 0;
				while (pause)
				{
					ch = getch();
					if (ch == ' ')
						pause = 0;
				}
				refresh();
				usleep( 100000 );
				tab[2]++;
			}
			tab[1]++;
		}
		tab[0]++;
	}
	mvprintw(3, 0, "Press any key to quit");
	refresh();
	usleep( 150000 );
	getch();
	endwin();
	return (0);
}
