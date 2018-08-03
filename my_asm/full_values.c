/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:12:00 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/22 15:55:18 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	ft_what_byte(t_champ **a)
{
	t_command	*start;
	t_arg		*arg;
	int			i;

	i = 0;
	start = (*a)->cmds;
	while (start)
	{
		start->number_byte = i;
		arg = start->inst;
		while (arg)
		{
			i += arg->size;
			arg = arg->next;
		}
		i += start->codage + 1;
		start = start->next;
	}
}

static int	find_label(t_champ *a, char *name, int num)
{
	t_command	*start;
	t_label		*label;
	int			i;

	i = -1;
	start = a->cmds;
	while (start && i == -1)
	{
		label = start->labels;
		while (label && i == -1)
		{
			if (!ft_strcmp(label->name, name))
				i = start->number_byte;
			label = label->next;
		}
		start = start->next;
	}
	i == -1 ? ft_printf("Label \e[1;33m%s\e[0m doesn't", name) : 0;
	i == -1 ? out_error(" exist", 0) : 0;
	if (num > i)
		i = -(num - i);
	else
		i -= num;
	return (i);
}

static void	parse_codage(t_command **c)
{
	t_arg	*args;
	int		codage;
	int		i;

	codage = 0;
	i = -1;
	args = (*c)->inst;
	while (++i < 3)
	{
		if (args)
		{
			codage += args->binary;
			args = args->next;
		}
		codage <<= 2;
	}
	(*c)->codage = codage;
}

static void	check_commands(t_command *a)
{
	t_command	*start;
	int			count;

	count = 0;
	start = a;
	while (start)
	{
		start = start->next;
		count++;
	}
	if (!count)
		out_error("No commands", 0);
}

void		full_values(int fd, t_champ **a)
{
	t_command	*start;
	t_arg		*arg;

	validation(fd, a);
	check_commands((*a)->cmds);
	ft_what_byte(a);
	start = (*a)->cmds;
	while (start)
	{
		arg = start->inst;
		if (start->codage)
			parse_codage(&start);
		while (arg)
		{
			if ((int)arg->value == -1 && arg->name_label)
				arg->value =
					find_label(*a, arg->name_label, start->number_byte);
			arg = arg->next;
		}
		start = start->next;
	}
}
