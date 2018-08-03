/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:39:27 by mshkliai          #+#    #+#             */
/*   Updated: 2018/04/02 16:20:41 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	spacing(char const *str)
{
	size_t	i;
	size_t	buf;

	i = 0;
	buf = ft_strlen(str);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[buf - 1] == '\t' || str[buf - 1] == '\n' || str[buf - 1] == ' ')
		buf--;
	return (buf - i);
}

char			*ft_strtrim(char const *s)
{
	char	*end;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (spacing(s) == 0)
	{
		if (!(end = (char*)malloc(sizeof(*end) * ft_strlen(s))))
			return (NULL);
		*end = '\0';
		return (end);
	}
	if ((spacing(s) == ft_strlen(s)) && i == 0)
	{
		if (!(end = ft_strdup(s)))
			return (NULL);
		return (end);
	}
	if (!(end = ft_strsub(s, i, spacing(s))))
		return (NULL);
	return (end);
}
