/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:14:33 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/22 17:28:10 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)ptr)[i] != ((unsigned char*)ptr2)[i])
			return (((unsigned char*)ptr)[i] - ((unsigned char*)ptr2)[i]);
		i++;
	}
	return (0);
}
