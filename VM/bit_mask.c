/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_mask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:53:59 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 03:18:13 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				bit_mask(int stand, int size)
{
	int			bit_mask;

	if (stand == 1)
		bit_mask = 192;
	else
		(stand == 2) ? (bit_mask = 48)
			: (bit_mask = 12);
	if ((size & bit_mask) == (bit_mask - (bit_mask / 3)))
		return (3);
	if ((size & bit_mask) == bit_mask)
		return (2);
	if ((size & bit_mask) == (bit_mask / 3))
		return (1);
	return (0);
}

static int		jumper(int tmp, unsigned char *map, t_pc *pc)
{
	if (tmp == 1)
		return (1);
	if (tmp == 2)
		return (2);
	if (tmp == 3)
		return (g_tab[get_map(map, pc->size)].label);
	return (0);
}

int				red_arg(unsigned char *map, t_pc *pc, int size)
{
	int			i;
	int			tmp;
	int			jump;

	i = -1;
	jump = pc->size + 2;
	while (++i < size)
	{
		tmp = bit_mask(i + 1, map[set_place(pc->size + 1)]);
		if (tmp == 1)
		{
			if ((get_map(map, jump)) < 1 || get_map(map, jump) > 16)
				return (-1);
			pc->arg[i] = pc->reg[get_map(map, jump) - 1];
		}
		else if (tmp == 2)
			pc->arg[i] = take_arg(map, 4, \
					pc->size + (((short)(take_arg(map, 2, jump))) % IDX_MOD));
		else if (tmp == 3)
			pc->arg[i] = take_arg(map, \
					g_tab[get_map(map, pc->size)].label, jump);
		jump += jumper(tmp, map, pc);
	}
	return (jump);
}
