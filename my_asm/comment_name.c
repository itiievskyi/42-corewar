/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:18:31 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 16:58:03 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static int	is_comment(char *line)
{
	char	*start;

	start = line;
	while (*start && (*start == ' ' || *start == '\t'))
		start++;
	if (*start == COMMENT_CHAR || *start == ';')
		return (1);
	return (0);
}

static char	*write_in_str(char *line, int fd, int size)
{
	int		i;
	int		j;
	char	*buff;

	j = 4;
	buff = ft_strdup("\"");
	size == COMMENT_LENGTH ? j = 7 : 0;
	line[len_to(line, '.') + j] != ' ' && line[len_to(line, '.') + j] != '"'
		&& line[len_to(line, '.') + j] != '\t' ? out_error(UK, 0) : 0;
	i = len_to(line, '.') + j - 1;
	while (line[++i] && line[i] != '"')
		line[i] != ' ' && line[i] != '\t' ?
			out_error("Lexical error", line) : 0;
	if (!ft_strchr(line, '"'))
		out_error(NO_VALUE(j), line);
	i = 0;
	while (!copy_to(line, &buff, ft_strlen(buff), size))
	{
		i += get_next_line(fd, &line);
		if (!line)
			out_error("No '\"' symbol", buff);
	}
	!i ? cmd(line + len_to(line, '"') + ft_strlen(buff))
		: cmd(line + len_to(line, '"'));
	return (buff);
}

static char	*parse(int fd, int size, char *command)
{
	char	*line;
	char	*start;
	char	*end;
	int		error;

	while ((error = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strstr(line, command))
			cmd(line);
		else if (ft_strstr(line, command) && !is_comment(line))
			break ;
		ft_strdel(&line);
	}
	!error ? out_error("File is empty", 0) : 0;
	error == -1 ? out_error("No .s file, it's directory", 0) : 0;
	!line ? out_error(NO_VALUE(size), 0) : 0;
	start = line;
	while (*start && (*start == ' ' || *start == '\t'))
		start++;
	if (ft_strncmp(start, command, len_to(start, ' ') - 1) &&
			ft_strncmp(start, command, len_to(start, '\t') - 1)
			&& ft_strncmp(start, command, len_to(start, '"') - 1))
		out_error(UK, start);
	end = write_in_str(line, fd, size);
	return (end);
}

char		**comment_name(int fd, t_champ **a)
{
	char	*line;
	char	*end;
	char	**mass;

	end = ft_memalloc(1);
	(*a)->name = parse(fd, PROG_NAME_LENGTH, NAME_CMD_STRING);
	(*a)->comment = parse(fd, COMMENT_LENGTH, COMMENT_CMD_STRING);
	while (get_next_line(fd, &line))
		end = join_free(end, line, 1);
	mass = ft_strsplit(end, '\n');
	ft_strdel(&end);
	return (mass);
}
