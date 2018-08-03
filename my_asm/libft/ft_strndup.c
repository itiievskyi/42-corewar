/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:21:33 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/29 13:27:47 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *str, size_t n)
{
	size_t	i;
	char	*mass;

	if (!(mass = (char*)malloc(sizeof(*mass) * n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		mass[i] = str[i];
		i++;
	}
	mass[i] = '\0';
	return (mass);
}
