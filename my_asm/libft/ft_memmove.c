/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:28:27 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/29 18:19:52 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *src1, const void *src2, size_t n)
{
	char			*str1;
	const	char	*str2;

	if (!src1 && !src2)
		return (0);
	str1 = (char*)src1;
	str2 = (char*)src2;
	if (str1 < str2)
		ft_memcpy(str1, str2, n);
	else
		while (n)
		{
			str1[n - 1] = str2[n - 1];
			n--;
		}
	return (src1);
}
