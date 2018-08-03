/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:40:26 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/22 17:26:31 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char			*srd1;
	const	char	*srd2;
	size_t			i;

	i = 0;
	srd1 = str1;
	srd2 = str2;
	while (i < n)
	{
		srd1[i] = srd2[i];
		i++;
	}
	return (str1);
}
