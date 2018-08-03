/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:18:30 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/22 15:52:56 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static int	find_command(char *line)
{
	int		i;
	char	*name;
	char	symb;
	char	*buff;

	symb = ' ';
	i = -1;
	trimmer(line, '\t', ' ');
	while (line[++i])
		if (line[i] == DIRECT_CHAR || line[i] == ' ')
			break ;
	line[i] == DIRECT_CHAR ? symb = DIRECT_CHAR : 0;
	buff = ft_strndup(line, len_to(line, symb) - 1);
	name = ft_strtrim(buff);
	i = -1;
	while (symb != -1 && g_operations[++i].name)
		if (!ft_strcmp(g_operations[i].name, name))
			symb = -1;
	ft_strdel(&buff);
	ft_strdel(&name);
	if (symb == -1)
		return (i);
	out_error("Invalid command", line);
	return (-1);
}

static int	ft_count_args(t_command *command)
{
	t_arg	*args;
	int		count_args;

	args = command->inst;
	count_args = 0;
	while (args)
	{
		count_args++;
		args = args->next;
	}
	return (count_args);
}

static void	manage_args(t_command *command, int num_com, char *line)
{
	int	no_nice_count;

	no_nice_count = ft_count_args(command);
	if (g_operations[num_com].count_args > no_nice_count)
		out_error("Too few args", line);
	if (g_operations[num_com].count_args < no_nice_count)
		out_error("Too many args", line);
	if (!no_nice_count)
		out_error("0 args", line);
}

static void	parse_commas(char *line, int command)
{
	char	*start;
	int		count;
	char	**mass;

	count = 1;
	start = line;
	while (*start && *start != ';' && *start != COMMENT_CHAR)
	{
		if (*start == SEPARATOR_CHAR)
			count++;
		start++;
	}
	if (count > g_operations[command].count_args)
		out_error("Extra ','", line);
	if (count < g_operations[command].count_args)
		out_error("Too few ','", line);
	mass = ft_strsplit(line, SEPARATOR_CHAR);
	count = -1;
	while (count != -2 && mass[++count] && !ft_strchr(mass[count], ';')
			&& !ft_strchr(mass[count], COMMENT_CHAR))
		if (ft_countwords(mass[count], ' ') > 1 ||
				ft_countwords(mass[count], '\t') > 1)
			count = -2;
	matrix_del(mass);
	count == -2 ? out_error("Bad commas", line) : 0;
}

void		parse_command(char *line, t_champ **a, t_label *labels)
{
	int			command;
	t_command	*b;

	if (!ft_strlen(line))
		return ;
	while (*line && (*line == '\t' || *line == ' '))
		line++;
	command = find_command(line);
	line += ft_strlen(g_operations[command].name);
	b = (t_command*)malloc(sizeof(t_command));
	parse_commas(line, command);
	b->name = ft_strdup(g_operations[command].name);
	b->inst = 0;
	b->codage = g_operations[command].codage;
	parse_arg(line, &b, command);
	manage_args(b, command, line);
	b->labels = labels;
	b->opcode = g_operations[command].opcode;
	command_in_end(a, b);
}
