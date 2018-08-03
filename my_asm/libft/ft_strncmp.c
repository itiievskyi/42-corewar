/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:32:31 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/27 14:24:49 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t				i;
	unsigned	char	*st;
	unsigned	char	*st2;

	i = 0;
	st = (unsigned char*)str;
	st2 = (unsigned char*)str2;
	while (i < n && (st2[i] || st[i]))
	{
		if (*(st + i) != *(st2 + i))
			return (*(st + i) - *(st2 + i));
		i++;
	}
	return (0);
}
