/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:18:25 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/21 16:30:10 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void		write_bytes(int fd, int a, int count_bytes)
{
	int				j;
	unsigned char	mass[count_bytes];

	j = count_bytes;
	while (count_bytes--)
	{
		mass[count_bytes] = (unsigned char)a;
		a >>= 8;
	}
	while (++count_bytes < j)
		write(fd, &mass[count_bytes], 1);
}
