/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 11:29:42 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/03 12:16:48 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static	void	check_lenth(char *line, int size)
{
	if ((int)ft_strlen(line) - 2 > size)
	{
		ft_strdel(&line);
		if (size == 2048)
			out_error(BIG_COMM, 0);
		out_error(BIG_NAME, 0);
	}
}

static void		remove_newline(char **line)
{
	char	*buf;

	buf = ft_strndup(*line, ft_strlen(*line) - 1);
	ft_strdel(line);
	*line = ft_strdup(buf);
	ft_strdel(&buf);
}

static int		checker_end(char *line, int len2, char **line2)
{
	if (line[len2 + len_to(line + len2, '"') - 1] == '"')
	{
		remove_newline(line2);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int				copy_to(char *line, char **line2, int len, int size)
{
	int			len2;
	char		*buf;
	int			check;

	len2 = 0;
	check = 0;
	if (len == 1)
		while (line[len2] && line[len2] != '"')
			len2++;
	if (len == 1)
		len2++;
	if (len_to(line + len2, '"') == 1)
		*line2 = join_free(*line2, "", 0);
	else
	{
		buf = ft_strndup(line + len2, len_to(line + len2, '"') - 1);
		*line2 = join_free(*line2, buf, 1);
	}
	check_lenth(*line2, size);
	if (checker_end(line, len2, line2) == 1)
		return (1);
	ft_strdel(&line);
	return (0);
}
