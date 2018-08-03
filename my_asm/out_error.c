/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:13:37 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 16:39:46 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	out_error(char *line, char *error)
{
	int	i;

	i = -1;
	if (error)
		ft_printf("-> \e[31m %s\n\e[0m", error);
	ft_putstr(line);
	write(1, "\n", 1);
	exit(0);
}
