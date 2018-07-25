/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:03:08 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/17 13:03:11 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ncurses.h"
#include <time.h>

int		main()
{
	static t_ncurse	*crwr;
	unsigned char	tab[4096];
	int				i;
	int				p;

	crwr = (t_ncurse*)malloc(sizeof(t_ncurse));
	crwr->players = 4;
	crwr->names = (char**)malloc(sizeof(char*) * 4);
	crwr->names[0] = ft_strdup("jumper");
	crwr->names[1] = ft_strdup("Gagnant");
	crwr->names[2] = ft_strdup("Survivor");
	crwr->names[3] = ft_strdup("jumper");
	ft_bzero(tab, 4096);
	crwr->sizes[0] = 325;
	crwr->sizes[1] = 80;
	crwr->sizes[2] = 680;
	crwr->sizes[3] = 325;
	crwr->tab = tab;
	while (crwr->step < 50)
	{
//		signal(SIGINT, sighandler);
		p = 0;
		while (p < crwr->players)
		{
			for(i = 0 + (4096 / crwr->players) * p;
				i < crwr->sizes[p] + ((4096 / crwr->players) * p); i++)
			{
				crwr->tab[i] = (unsigned char)rand() % 255;
			}
			p++;
		}
		if (crwr->step == 49)
			crwr->win = time(NULL) % (crwr->players) + 1;
		print_ncurses(crwr);
		(crwr->step)++;
	}
	return 0;
}
