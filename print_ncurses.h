/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:51:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/17 14:51:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:49:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/06/07 09:49:40 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NCURSES_H
# define PRINT_NCURSES_H
# include <stdio.h>
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define COLOR_GREY 8

typedef struct		s_ncurse
{
	int				win;
	int				players;
	unsigned char	*tab;
}					t_ncurse;
void				print_ncurses(unsigned char *tab);
#endif
