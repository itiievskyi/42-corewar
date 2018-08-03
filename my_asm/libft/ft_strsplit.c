/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 09:38:27 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/29 15:33:16 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	length_w(char const *str, char c)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		length++;
		i++;
	}
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**end;

	if (!s || !(end = (char **)malloc(sizeof(*end)
					* (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if (!(end[i] = ft_strnew(length_w(&s[j], c))))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			end[i][k++] = s[j++];
		end[i][k] = '\0';
		i++;
	}
	end[i] = 0;
	return (end);
}
