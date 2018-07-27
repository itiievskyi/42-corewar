/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_mask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:53:59 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/26 12:02:36 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			bit_mask(int stand, int size)
{
	int		bit_mask;

	if (stand == 1)
		bit_mask = 192;
	else
		(stand == 2) ? (bit_mask = 48) : (bit_mask = 12);
	if ((size & bit_mask) == (bit_mask - (bit_mask / 3)))
		return (3);
	if ((size & bit_mask) == bit_mask)
		return (2);
	if ((size & bit_mask) == (bit_mask / 3))
		return (1);
	return (0);
}

int				red_arg(unsigned char *map, t_pc *pc, int size)
{
	int		i;
	int		tmp;
	int		jump;

	i = -1;
	jump = pc->size + 2;
	while (++i < size)
	{
		tmp = bit_mask(i + 1, map[pc->size + 1]);
		if (tmp == 1)
		{
//			printf("1\n");
			pc->arg[i] = pc->reg[get_map(map, jump) - 1];
			jump += 1;
	//		printf("1\n");
		}
		else if (tmp == 2)
		{
		//printf("2\n");
		//	printf("get = : %d\n", take_arg(map, 2, jump));
			pc->arg[i] = take_arg(map, 4, pc->size + (take_arg(map, 2, jump) % IDX_MOD));
			jump += 2;
		}
		else if (tmp == 3)
		{
		//	printf("3\n");
			pc->arg[i] = take_arg(map, op_tab[get_map(map, pc->size)].label, jump);
			jump += op_tab[get_map(map, pc->size)].label;
		//	printf("3\n");
		}
	}
	return (jump);
}
