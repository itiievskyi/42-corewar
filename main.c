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

int		main()
{
	static t_ncurse	*crwr;
	unsigned char	tab[4096];
	int				i;

	crwr = (t_ncurse*)malloc(sizeof(t_ncurse));
	crwr->players = 4;
	crwr->names = (char**)malloc(sizeof(char*) * 4);
	crwr->names[0] = ft_strdup("jumper");
	crwr->names[1] = ft_strdup("Gagnant");
	crwr->names[2] = ft_strdup("Survivor");
	crwr->names[3] = ft_strdup("jumper");
	ft_bzero(tab, 4096);
	while (crwr->step < 50)
	{
		for( i = 0 ; i < 325 ; i++ )
		{
			tab[i] = (unsigned char)rand() % 255;
		}
		for( i = 1024 ; i < 1500 ; i++ )
		{
			tab[i] = (unsigned char)rand() % 255;
		}
		for( i = 2048 ; i < 2373 ; i++ )
		{
			tab[i] = (unsigned char)rand() % 255;
		}
		for( i = 3072 ; i < 3600 ; i++ )
		{
			tab[i] = (unsigned char)rand() % 255;
		}
		if (crwr->step == 49)
			crwr->win = 2;
		print_ncurses(tab, crwr);
		(crwr->step)++;
	}
	return 0;
}
