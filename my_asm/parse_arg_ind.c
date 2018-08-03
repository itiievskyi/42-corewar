/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:35:38 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/22 15:54:06 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	arg_label(char *line, int c, int i, t_arg **arg)
{
	if (i + 1 == g_operations[c].count_args
			&& ft_strchr(line, COMMENT_CHAR))
		(*arg)->name_label =
			ft_strndup(line + 1, len_to(line + 1, COMMENT_CHAR) - 1);
	else
		(*arg)->name_label = ft_strdup(line + 1);
	check_name_label((*arg)->name_label);
	(*arg)->value = -1;
}

void		parse_arg_ind(char *line, int c, int i, t_command **b)
{
	int		j;
	t_arg	*a;

	j = 0;
	trimmer(line, ';', COMMENT_CHAR);
	a = (t_arg*)malloc(sizeof(t_arg));
	if (line[0] == LABEL_CHAR)
		arg_label(line, c, i, &a);
	else
	{
		line[0] == '-' ? j += 1 : 0;
		while (line[j] && ft_isdigit(line[j]))
			j++;
		i + 1 != g_operations[c].count_args
			&& line[j] ? out_error(TD, line) : 0;
		i + 1 == g_operations[c].count_args ? cmd(line + j) : 0;
		a->value = atoi_for_arg(line);
		a->name_label = 0;
	}
	a->size = IND_SIZE;
	a->binary = 3;
	arg_in_end(&(*b)->inst, a);
}
