/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:12:34 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/22 17:26:47 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int n, size_t num)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ptr;
	while (i < num)
		*(str + i++) = n;
	return (ptr);
}
