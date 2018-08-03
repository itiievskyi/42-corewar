/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:31:28 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/03 12:46:51 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	negative(int *i, int *size, int *b)
{
	if (*i < 0)
	{
		*i *= -1;
		*size = 1;
		*b = 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str1;
	int		n2;
	int		size;
	int		b;

	b = 0;
	size = 0;
	n2 = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative(&n, &size, &b);
	while (n2 /= 10)
		size++;
	if (!(str1 = ft_strnew(size + 1)))
		return (0);
	if (b > 0)
		str1[0] = '-';
	while (size + 1 - b)
	{
		str1[size--] = n % 10 + '0';
		n /= 10;
	}
	str1[ft_strlen(str1)] = '\0';
	return (str1);
}
