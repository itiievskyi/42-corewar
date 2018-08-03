/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:46:32 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/28 16:50:52 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rtsdup(const char *str)
{
	char	*mass;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	if (!(mass = (char*)malloc(sizeof(*mass) * j + 1)))
		return (0);
	while (j--)
	{
		mass[i] = str[j];
		i++;
	}
	mass[i] = '\0';
	return (mass);
}
