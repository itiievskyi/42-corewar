/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:18:01 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 15:41:47 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static int	comparison(char *line)
{
	char	*start;
	int		i;

	start = line;
	while (*start && (*start == '\t' || *start == ' '))
		start++;
	if (*start == COMMENT_CHAR || *start == ';')
		return (0);
	while (*start)
	{
		i = -1;
		while (STR_COMP[++i])
			if (*start == STR_COMP[i])
				return (1);
		start++;
	}
	return (0);
}

static int	add_label(char *line, t_label **b)
{
	t_label	*label;
	char	*start;
	int		i;
	char	*buff;

	trimmer(line, '\t', ' ');
	start = line;
	i = -1;
	while (*start && *start == ' ')
		start++;
	while (start[++i] && start[i] != LABEL_CHAR)
		if (!ft_strchr(line, LABEL_CHAR) || start[i] == ' ' ||
				start[i] == '%' || start[i] == '#' || start[i] == ';')
			return (0);
	buff = ft_strndup(start, len_to(start, LABEL_CHAR) - 1);
	label = (t_label*)malloc(sizeof(t_label));
	label->name = ft_strtrim(buff);
	!ft_strlen(label->name) ? out_error("No label name", line) : 0;
	ft_strdel(&buff);
	check_name_label(label->name);
	label->next = *b;
	*b = label;
	return (len_to(line, LABEL_CHAR));
}

static void	label_in_end_of_file(t_champ **a, t_label *label)
{
	t_command	*b;

	b = (t_command*)malloc(sizeof(t_command));
	b->name = ft_strdup("-1");
	b->labels = label;
	b->inst = 0;
	command_in_end(a, b);
}

static void	parse_this(char **mass, t_champ **a, int *index)
{
	t_label			*labels;
	int				i;
	char			*line;

	labels = 0;
	i = *index - 1;
	while (mass[++i])
	{
		line = mass[i];
		line += add_label(line, &labels);
		if (ft_strlen(line) && !comparison(line))
			cmd(line);
		else if (ft_strlen(line))
			break ;
	}
	*index = i;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	ft_strlen(line) && (i == (int)ft_strlen(line) || !comparison(line)) ?
		cmd(line) : parse_command(line, a, labels);
	if (labels && (i == (int)ft_strlen(line) || !comparison(line)))
		label_in_end_of_file(a, labels);
}

void		validation(int fd, t_champ **a)
{
	char	**mass;
	int		i;

	i = 0;
	mass = comment_name(fd, a);
	while (mass[i])
	{
		if (!comparison(mass[i]))
			cmd(mass[i]);
		else
			parse_this(mass, a, &i);
		if (!mass[i])
			break ;
		i++;
	}
	matrix_del(mass);
}
