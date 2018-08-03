/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:00:32 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/24 16:40:12 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *srd1, const void *srd2, int c, size_t n)
{
	size_t				i;
	unsigned	char	*str1;
	unsigned	char	*str2;

	str1 = (unsigned char*)srd1;
	str2 = (unsigned char*)srd2;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (srd1 + 1 + i);
		i++;
	}
	return (NULL);
}
