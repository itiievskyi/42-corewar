/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:00:55 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/27 17:20:45 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (!(substr = (char*)malloc(sizeof(*substr) * len + 1)))
		return (NULL);
	ft_strncpy(substr, (s + start), len);
	*(substr + len) = '\0';
	return (substr);
}
