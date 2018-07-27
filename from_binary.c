/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:04:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/26 12:50:48 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	take_arg(unsigned char *map, int size, int stand)
{
//	printf("take\n");
	//only stand NOW in argument
	int	i;
	unsigned int arr[size];
	unsigned int	tmp;
	int j;
	int test;

	test = 0;
	//printf("map stand: %d stand : %d\n", map[stand], stand);
	j = 0;
	i = -1;
	tmp = 0;
	while (++i < size)
		arr[i] = get_map(map, stand + i);
	while (--i >= 0)
	{
		test = arr[j];
//		printf("ar = %u\n", arr[j]);
		test = test << (i * 8);
		tmp += test;
		j++;
	}
	//printf("unsigned = %u\n", tmp);
	return (tmp);
}

int		set_place(int place)
{
	if (place >= MEM_SIZE)
		return (set_place(place - MEM_SIZE));
	if (place < 0)
		return (set_place(MEM_SIZE + place));
	return (place);
}

void	set_bit(int place, unsigned char *map, unsigned int number, t_pc *pc)
{
	int i;
	unsigned int arr[4];
	int k;

	i = 0;
	while (i < 4)
	{
		arr[i] = number;
		number = number >> 8;
		i++;
	}
	k = 0;
	pc->change = set_place(place);
	while (--i >= 0)
	{
		map[set_place(place + k)] = arr[i];
		k++;
	}
}

int			find_weight(int arg, int cmd)
{
	if (arg == 3)
		return (op_tab[cmd].label);
	if (arg == 2)
		return (2);
	if (arg == 1)
		return (1);
	return(0);
}
