/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:57:41 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/26 18:36:50 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str, const char *str2, size_t size)
{
	size_t	buf;
	size_t	buf2;

	buf = ft_strlen(str);
	buf2 = ft_strlen(str2);
	if (size <= buf)
		return (size + buf2);
	if (size - ft_strlen(str) > buf2)
		ft_strcat(str, str2);
	if (size - ft_strlen(str) <= buf2)
		ft_strncat(str, str2, size - ft_strlen(str) - 1);
	return (buf + buf2);
}
