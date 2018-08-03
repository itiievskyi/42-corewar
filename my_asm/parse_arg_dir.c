/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:52:32 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/22 15:54:40 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	arg_dir_label(char *line, int c, int i, t_command **b)
{
	char	*buff;
	t_arg	*a;

	trimmer(line, ';', COMMENT_CHAR);
	if (i + 1 == g_operations[c].count_args
			&& ft_strchr(line, COMMENT_CHAR))
		buff = ft_strndup(line + 2, len_to(line + 2, COMMENT_CHAR) - 1);
	else
		buff = ft_strdup(line + 2);
	check_name_label(buff);
	a = (t_arg*)malloc(sizeof(t_arg));
	a->size = g_operations[c].label_size;
	a->value = -1;
	a->binary = 2;
	a->name_label = ft_strdup(buff);
	arg_in_end(&(*b)->inst, a);
	ft_strdel(&buff);
}

void		parse_arg_dir(char *line, int c, int i, t_command **b)
{
	int		j;
	t_arg	*a;

	if (line[1] == LABEL_CHAR)
		arg_dir_label(line, c, i, b);
	else
	{
		j = 1;
		if (!ft_isdigit(line[1]) && line[1] != '-')
			out_error("bad value for '%'", line);
		if (line[1] == '-')
			j++;
		while (line[j] && ft_isdigit(line[j]))
			j++;
		if (i + 1 != g_operations[c].count_args && line[j] != 0)
			out_error("extra characters near 't_ind'", line);
		if (i + 1 == g_operations[c].count_args)
			cmd(line + j);
		a = (t_arg*)malloc(sizeof(t_arg));
		a->size = g_operations[c].label_size;
		a->value = atoi_for_arg(line + 1);
		a->name_label = 0;
		a->binary = 2;
		arg_in_end(&(*b)->inst, a);
	}
}
