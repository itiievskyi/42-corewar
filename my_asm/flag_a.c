/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:07:47 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 12:46:41 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	print_args(t_command *command)
{
	t_arg	*args;

	args = command->inst;
	while (args)
	{
		if (args->binary == 1)
			g_a += ft_printf("r%d    ", args->value);
		if (args->binary == 2)
		{
			if (args->name_label)
				g_a += ft_printf("%%:%s   ", args->name_label);
			else
				g_a += ft_printf("%%%d       ", args->value);
		}
		if (args->binary == 3)
		{
			if (args->name_label)
				g_a += ft_printf(":%s     ", args->name_label);
			else
				g_a += ft_printf("%d    ", args->value);
		}
		args = args->next;
	}
	g_a = width(60 - g_a, ' ') + ft_printf("|\n");
}

static void	print_label(t_arg *arg, t_command *commands, int byte)
{
	t_command	*start;
	t_label		*label;
	int			i;

	i = g_a;
	start = commands;
	while (start)
	{
		label = start->labels;
		while (label)
		{
			if (!ft_strcmp(label->name, arg->name_label))
				g_a += ft_printf("{%d-->%d}  ", byte, start->number_byte);
			if (g_a > i)
				break ;
			label = label->next;
		}
		if (g_a > i)
			break ;
		start = start->next;
	}
}

static void	print_values(t_command *command, t_champ *a)
{
	t_arg	*args;

	g_a = ft_printf("|") + width(9, ' ') + ft_printf("<%d", command->opcode);
	if (command->codage)
		g_a += ft_printf("->%d>  ", command->codage);
	else
		g_a += ft_printf(">         ");
	args = command->inst;
	while (args)
	{
		if (args->name_label)
			print_label(args, a->cmds, command->number_byte);
		else
			g_a += ft_printf("[%d]    ", args->value);
		args = args->next;
	}
	width(60 - g_a, ' ');
	ft_printf("|\n");
}

static void	print_command(t_command *command, t_champ *a)
{
	t_label	*labels;

	labels = command->labels;
	if (labels && (g_a = ft_printf("|")))
		while (labels)
		{
			g_a += ft_printf("%d       %s:",
					command->number_byte, labels->name);
			width(60 - g_a, ' ');
			ft_printf("|\n");
			labels = labels->next;
		}
	g_a = ft_printf("|%d (%d)       %s    ", command->number_byte,
			size_command(command), command->name);
	print_args(command);
	print_values(command, a);
}

void		flag_a(t_champ *a)
{
	t_command	*start;

	g_a = 0;
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", size_code(a));
	ft_printf("Name : %s\"\n", a->name);
	ft_printf("Comment : %s\"\n\n", a->comment);
	width(61, '_');
	ft_printf("\n");
	start = a->cmds;
	while (start)
	{
		print_command(start, a);
		start = start->next;
		width(61, '-');
		ft_printf("\n");
	}
	ft_printf("\n%sInstruction: <opcode->codage of command>%s\n", G, C);
	ft_printf("%s             {byte of arg-->byte on that specifies", G);
	ft_printf(" label%s\n", C);
	ft_printf("%s             [value of arg]%s\n", G, C);
	ft_printf("%s             (weigth of commands)%s\n", G, C);
}
