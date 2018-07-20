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

#ifndef PRINT_NCURSES_H
# define PRINT_NCURSES_H
# include <stdio.h>
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# include "./libft/libft.h"
# include "op.h"

# define COLOR_GREY 8

typedef struct		s_ncurse
{
	int				win;
	int				players;
	int				step;
	int				proc;
	char			**names;
	int				sizes[4];
	unsigned char	*tab;
}					t_ncurse;
void				print_ncurses(t_ncurse *crwr);
void				init_colors(void);
void				print_template(int x, int y, t_ncurse *crwr);
void				print_finish(t_ncurse *crwr, int i);
void				print_field_start(t_ncurse *crwr, int i, int y, int x);
#endif
