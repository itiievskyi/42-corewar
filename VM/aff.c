/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:09 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 05:55:56 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			aff(unsigned char *map, t_pc **pc1)
{
	int			i;
	t_pc		*pc;
	int			tmp_size;
	char		c;

	pc = (*pc1);
	tmp_size = get_size(map, pc->command, pc->size);
	if (!(c_c_aff(get_map(map, pc->size + 1))) &&
			(i = red_arg(map, pc, 1) != -1) && pc->aff == 1)
	{
		ft_putstr("Aff: ");
		c = pc->arg[0] % 256;
		ft_putchar(c);
		ft_putchar('\n');
	}
	pc->size += tmp_size;
	pc->command = 0;
}
