/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:57:14 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/24 18:06:52 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str, const char *str2, size_t num)
{
	size_t i;

	i = 0;
	if (ft_strlen(str2) == 0)
		ft_memset(str, '\0', num);
	while (i < num && str2[i])
	{
		str[i] = str2[i];
		i++;
	}
	if (i < num)
		ft_memset(str + i, '\0', num - i);
	if (ft_strlen(str) == num)
		str[i] = '\0';
	return (str);
}
