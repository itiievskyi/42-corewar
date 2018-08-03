/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:54:23 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/26 15:49:57 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *srd, int val, size_t n)
{
	size_t				i;
	unsigned	char	*str;
	unsigned	char	c;

	i = 0;
	c = (unsigned char)val;
	str = (unsigned char*)srd;
	while (i < n)
	{
		if (str[i] == c)
		{
			return (&str[i]);
			break ;
		}
		i++;
	}
	return (NULL);
}
