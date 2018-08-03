/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_asm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:38:24 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 15:09:08 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ASM_H
# define LIST_ASM_H

# define UK "Unknown command"
# define TD "extra characters near 't_ind'"
# define NO_VALUE(val) val == 4 ? "No name" : "No comment"
# define BIG_COMM "Champion comment too long (Max length 2048)"
# define BIG_NAME "Champion name too long (Max length 128)"

# define STR_COMP "r%0123456789:"
# define G "\e[32m"
# define C "\e[0m\n"

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "op.h"
# include <fcntl.h>

typedef struct			s_label
{
	char				*name;
	struct s_label		*next;
}						t_label;

typedef struct			s_arg
{
	int					binary;
	int					size;
	unsigned int		value;
	char				*name_label;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_command
{
	char				*name;
	int					codage;
	int					count_args;
	int					label_size;
	int					args[3];
	int					opcode;
	t_label				*labels;
	int					number_byte;
	t_arg				*inst;
	struct s_command	*next;
}						t_command;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	t_command			*cmds;
	struct s_champ		*next;
}						t_champ;

t_command				g_operations[17];
int						g_a;

int						width(int i, int sym);
int						get_next_line(const int fd, char **line);
unsigned int			atoi_for_arg(const char *str);
void					matrix_del(char **matrix);
char					*join_free(char *line, char *line2, int flag);
void					arg_in_end(t_arg **a, t_arg *b);
void					out_error(char *line, char *error);
void					trimmer(char *line, char c, char c2);
void					cmd(char *line);
int						copy_to(char *line, char **line2, int len, int size);
char					**comment_name(int fd, t_champ **a);
void					write_bytes(int fd, int a, int count_bytes);
void					check_name_label(char *line);
void					parse_command(char *line, t_champ **a, t_label *labels);
char					**split_for_args(char *line);
void					command_in_end(t_champ **a, t_command *command);
int						parse_arg(char *line, t_command **b, int command);
void					parse_arg_dir(char *line, int c, int i, t_command **b);
void					parse_arg_ind(char *line, int c, int i, t_command **b);
void					validation(int fd, t_champ **a);
void					full_values(int fd, t_champ **a);
int						size_code(t_champ *a);
void					write_in_file(t_champ *a, char **av);
int						size_command(t_command *command);
void					flag_a(t_champ *a);
int						len_to(char *str, char c);

#endif
