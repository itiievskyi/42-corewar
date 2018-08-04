/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:04:39 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 06:32:21 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			get_command(unsigned char *map, t_pc *pc)
{
	if (get_map(map, pc->size) <= 0 || get_map(map, pc->size) > 16)
	{
		pc->cicles = -1;
		pc->size++;
	}
	else
	{
		pc->size = set_place(pc->size);
		pc->command = get_map(map, pc->size);
		pc->cicles = (g_tab[pc->command]).cicles - 1;
	}
}

int				get_size(unsigned char *map, int cmd, int size)
{
	int			tmp;
	int			res;

	res = 0;
	if ((g_tab[cmd]).codage > 0)
	{
		tmp = get_map(map, size + 1);
		res += find_weight(bit_mask(1, tmp), cmd);
		if (cmd != 16)
			res += find_weight(bit_mask(2, tmp), cmd);
		if (cmd != 3 && cmd != 2 && cmd != 13 && cmd != 16)
			res += find_weight(bit_mask(3, tmp), cmd);
		return (res + 2);
	}
	return (g_tab[cmd].label + 1);
}

void			do_command(unsigned char *map, t_pc *pc, \
		void (**f)(unsigned char *, t_pc **))
{
	f[pc->command](map, &pc);
}

void			print_dump(t_player *p, unsigned char *map, t_pc *pc, t_rule *r)
{
	t_player	*p1;
	int			j;
	int			i;

	j = 0;
	i = 0;
	p1 = p;
	ft_printf("0x0000 : ");
	while (++i <= MEM_SIZE)
	{
		ft_printf("%02x ", map[i - 1]);
		if (i % 64 == 0 && i != 0)
		{
			ft_printf("\n");
			(i < MEM_SIZE) ? ft_printf("0x%04x : ", i) : 0;
		}
	}
	free_all(p, pc, r);
}
