/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:20:07 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/03 12:46:27 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					n;
	long	long	int	res;

	res = 0;
	n = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		*str == '-' ? n -= 2 : n + 0;
		str++;
	}
	if (*str < '0' && *str > '9')
		return (0);
	while (*str != '\0' && ft_isdigit(*str))
	{
		if (n == 1 && res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (n * res);
}
