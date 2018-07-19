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

void	print_ncurses(unsigned char *tab);

int		main()
{
	unsigned char	tab[4096];
	int				i;
	int				step;

	step = 0;
	while (step++ < 50)
	{
		for( i = 0 ; i < 4096 ; i++ )
		{
			tab[i] = (unsigned char)rand() % 255;
		}
		print_ncurses(tab);
	}
	return 0;
}
