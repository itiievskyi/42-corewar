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
# include <panel.h>
# include <string.h>

# define COLOR_GREY 8

# define HELP_LINES 30
# define HELP_COLS 103

typedef struct		s_ncurse
{
	int				win;
	int				players;
	int				step;
	int				proc;
	int				pause;
	int				help;
	int				quit;
	char			**names;
	int				sizes[4];
	int				changes[5];
	unsigned char	*tab;
}					t_ncurse;
void				print_ncurses(t_ncurse *crwr);
void				init_colors(void);
void				print_template(int x, int y, t_ncurse *crwr);
void				print_finish(t_ncurse *crwr, int i, char ch);
void				print_field_start(t_ncurse *crwr, int i, int y, int x);
void				print_help(void);
void				print_music(t_ncurse *crwr);
void				sighandler(int signum);
void				print_check_buttons(t_ncurse *crwr, char ch);
char				check_pause(t_ncurse *crwr, int pause, char ch);
#endif
