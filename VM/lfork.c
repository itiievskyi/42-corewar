/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 17:39:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 04:05:19 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lfork_1(unsigned char *map, t_pc *pc, t_pc **main)
{
	int			i;
	t_pc		*new_pc;

	i = (((short)take_arg(map, 2, pc->size + 1)));
	new_pc = (t_pc *)malloc(sizeof(t_pc));
	copy_pc(new_pc, pc, i + pc->size, map);
	new_pc->id = (*main)->id + 1;
	new_pc->next = *main;
	*main = new_pc;
}
