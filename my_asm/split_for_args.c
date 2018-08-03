/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_for_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:39:29 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/10 13:46:06 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static	int	length_w(char const *str)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (str[i] == ',' || str[i] == '\t' || str[i] == ' ')
		i++;
	while ((str[i] != ',' && str[i] != '\t' && str[i] != ' ') && str[i])
	{
		length++;
		i++;
	}
	return (length);
}

static int	countwords(char const *str)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != ',')
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i])
				i++;
			count++;
		}
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == ',') && str[i])
			i++;
	}
	return (count);
}

char		**split_for_args(char *line)
{
	int		i;
	int		j;
	int		k;
	char	**end;

	if (!line || !(end = (char **)malloc(sizeof(*end)
					* countwords(line) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < countwords(line))
	{
		k = 0;
		if (!(end[i] = ft_strnew(length_w(&line[j]))))
			return (NULL);
		while (line[j] == '\t' || line[j] == ' ' || line[j] == ',')
			j++;
		while (line[j] != '\t' && line[j] != ' ' && line[j] != ',' && line[j])
			end[i][k++] = line[j++];
		end[i][k] = '\0';
		i++;
	}
	end[i] = 0;
	return (end);
}
