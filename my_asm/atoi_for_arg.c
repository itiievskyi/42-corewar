/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:13:39 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/21 18:30:42 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

unsigned int	atoi_for_arg(const char *str)
{
	int				n;
	unsigned	int	res;

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
		res = res * 10 + (*str - '0');
		str++;
	}
	return (n * res);
}
