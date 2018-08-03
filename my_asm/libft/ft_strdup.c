/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:03:10 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/24 17:40:46 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*mass;
	int		i;

	i = 0;
	if (!(mass = (char*)malloc(sizeof(*mass) * ft_strlen(str) + 1)))
		return (0);
	while (str[i])
	{
		mass[i] = str[i];
		i++;
	}
	mass[i] = '\0';
	return (mass);
}
