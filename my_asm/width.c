/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:03:29 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 13:19:19 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

int	width(int i, int sym)
{
	char	str[4096];
	int		res;

	res = 0;
	while (i > 0)
	{
		if (i < 4095)
		{
			ft_memset(str, sym, i);
			str[i] = '\0';
			res += i;
			ft_putstr(str);
			break ;
		}
		ft_memset(str, sym, 4095);
		str[4095] = '\0';
		ft_putstr(str);
		ft_strclr(str);
		res += 4095;
		i -= 4095;
	}
	return (res);
}
