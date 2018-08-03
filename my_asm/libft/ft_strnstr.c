/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:13:52 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/27 16:24:14 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		k = 0;
		if (str[i] == str2[j] && i <= (n - 1))
		{
			while (str2[j])
			{
				if (str2[j] == str[i + j] && (i + j) < n)
					k++;
				j++;
			}
		}
		if (k == j && j > 0 && ft_strlen(str2) <= n)
			return ((char*)str + i);
		i++;
	}
	return (0);
}
