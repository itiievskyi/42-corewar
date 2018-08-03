/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:38:53 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/22 15:53:48 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	available_args(int command, int index, int *av_args)
{
	if (g_operations[command].args[index] == 3)
	{
		av_args[0] = T_DIR;
		av_args[1] = T_REG;
	}
	else if (g_operations[command].args[index] == 6)
	{
		av_args[0] = T_DIR;
		av_args[1] = T_IND;
	}
	else if (g_operations[command].args[index] == 5)
	{
		av_args[0] = T_REG;
		av_args[1] = T_IND;
	}
	g_operations[command].args[index] == 7 ? av_args[0] = -1 : 0;
	g_operations[command].args[index] == T_DIR ? av_args[0] = T_DIR : 0;
	g_operations[command].args[index] == T_REG ? av_args[0] = T_REG : 0;
	g_operations[command].args[index] == T_IND ? av_args[0] = T_IND : 0;
	av_args[2] = 0;
}

static int	check_valid_arg(char *line, int command, int index)
{
	int		av_args[4];
	int		arg;
	int		i;

	arg = -1;
	available_args(command, index, av_args);
	line[0] == DIRECT_CHAR ? arg = T_DIR : 0;
	line[0] == 'r' ? arg = T_REG : 0;
	ft_isdigit(line[0]) || (line[0] == '-' && ft_isdigit(line[1]))
			|| line[0] == LABEL_CHAR ? arg = T_IND : 0;
	arg == -1 ? out_error("No valid arg", line) : 0;
	i = -1;
	while (++i < 3 && av_args[i])
		if (arg == av_args[i] || av_args[0] == -1)
			break ;
	!av_args[i] ? out_error("This command can't contain this arg", line) : 0;
	return (arg);
}

static void	parse_arg_reg(char *line, int command, int index, t_command **b)
{
	int			i;
	t_arg		*a;

	i = 1;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (index + 1 != g_operations[command].count_args && line[i] != 0)
		out_error("extra characters near 'r'", line);
	index + 1 == g_operations[command].count_args ? cmd(line + i) : 0;
	if (i > 3)
		out_error("So big value for 'r'", line);
	a = (t_arg*)malloc(sizeof(t_arg));
	a->size = 1;
	a->value = ft_atoi(line + 1);
	a->name_label = 0;
	a->binary = 1;
	arg_in_end(&(*b)->inst, a);
}

int			parse_arg(char *line, t_command **b, int command)
{
	int		i;
	char	**args;
	int		valid;

	args = split_for_args(line);
	(*b)->inst = 0;
	i = -1;
	while (args[++i])
	{
		trimmer(args[i], ';', COMMENT_CHAR);
		if (args[i][0] == COMMENT_CHAR)
			break ;
		valid = check_valid_arg(args[i], command, i);
		if (valid == T_REG)
			parse_arg_reg(args[i], command, i, b);
		else if (valid == T_IND)
			parse_arg_ind(args[i], command, i, b);
		else
			parse_arg_dir(args[i], command, i, b);
	}
	matrix_del(args);
	return (1);
}
