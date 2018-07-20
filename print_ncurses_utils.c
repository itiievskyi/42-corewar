/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:42:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/20 10:42:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ncurses.h"

void		init_colors(void)
{
	attroff(COLOR_PAIR(1) | COLOR_PAIR(5) | COLOR_PAIR(7) | A_BOLD);
	init_color(COLOR_GREY, 500, 500, 500);
	init_pair(1, COLOR_GREY, COLOR_GREY);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(30, COLOR_CYAN, COLOR_BLACK);
	init_pair(40, COLOR_YELLOW, COLOR_BLACK);
	
}
