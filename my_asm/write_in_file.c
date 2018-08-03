/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:15:50 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 14:58:51 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void		write_name_comment(int fd, t_champ *a)
{
	int		i;

	i = 0;
	write_bytes(fd, COREWAR_EXEC_MAGIC, 4);
	while (a->name[++i])
		write_bytes(fd, a->name[i], 1);
	while (++i < 134)
		write_bytes(fd, 0, 1);
	write_bytes(fd, size_code(a), 4);
	i = 0;
	while (a->comment[++i])
		write_bytes(fd, a->comment[i], 1);
	while (++i < 2054)
		write_bytes(fd, 0, 1);
}

static void		writing_command(int fd, t_champ *a)
{
	t_command	*command;
	t_arg		*arg;

	command = a->cmds;
	while (command)
	{
		if (ft_strcmp(command->name, "-1"))
		{
			arg = command->inst;
			write_bytes(fd, command->opcode, 1);
			if (command->codage)
				write_bytes(fd, command->codage, 1);
			while (arg)
			{
				write_bytes(fd, arg->value, arg->size);
				arg = arg->next;
			}
		}
		command = command->next;
	}
}

static void		writer(t_champ *a, char *line)
{
	char	*file_name;
	int		fd;
	int		size_file;

	size_file = ft_strlen(line) - 1;
	while (line[size_file] && line[size_file] != '.')
		size_file--;
	if (size_file == -1)
		file_name = ft_strdup(".cor");
	else
		file_name = ft_strndup(line, size_file);
	file_name = join_free(file_name, ".cor", 0);
	file_name[ft_strlen(file_name) - 1] = 0;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write_name_comment(fd, a);
	writing_command(fd, a);
	ft_printf("Writing output program to %s\n", file_name);
	close(fd);
	ft_strdel(&file_name);
}

void			write_in_file(t_champ *a, char **av)
{
	int		i;
	t_champ	*start;

	i = 0;
	start = a;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "-a"))
		{
			writer(start, av[i]);
			start = start->next;
		}
	}
}
