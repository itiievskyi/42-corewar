/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:12:22 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/25 19:11:14 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str, const char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(str2) == 0)
		return (str);
	while (str[i])
		i++;
	while (str2[j])
	{
		str[j + i] = str2[j];
		j++;
	}
	str[j + i] = '\0';
	return (str);
}
