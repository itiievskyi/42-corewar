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

#include "print_ncurses.h"

void		print_help(void)
{
	SCREEN *help;

	help = newterm(NULL, stdout, stdin);
	set_term(help);
	initscr();
}
