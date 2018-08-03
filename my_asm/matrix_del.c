/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:43:42 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/16 18:03:13 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	matrix_del(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ft_strdel(&matrix[i]);
	free(matrix);
	matrix = 0;
}
