/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:21:30 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/26 19:13:54 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		k = 0;
		if (str[i] == str2[j])
		{
			while (str2[j])
			{
				if (str[i + j] == str2[j])
					k++;
				j++;
			}
		}
		if (k == j && (k > 0 && j > 0))
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
