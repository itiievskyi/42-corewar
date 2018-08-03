/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:35:46 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/29 15:43:34 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str2[j] && j < n)
	{
		str[i + j] = str2[j];
		j++;
		str[i + j] = '\0';
	}
	if (j < n)
	{
		while ((i + j) < n)
		{
			str[i + j] = 0;
			i++;
		}
	}
	return (str);
}
