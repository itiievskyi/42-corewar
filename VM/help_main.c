/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:55:57 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 06:31:23 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			error_vm(t_player *p, t_pc *pc, t_rule *rule)
{
	ft_printf("ERROR\n");
	free_all(p, pc, rule);
	return (1);
}

void		game_minus_cicle(t_rule *r)
{
	r->c -= CYCLE_DELTA;
	r->j = 0;
}

void		add_i(t_player *p, int i)
{
	while (p != NULL)
	{
		p->i = i;
		p = p->next;
	}
}

int			check_size(t_player *p)
{
	while (p != NULL)
	{
		p->pc_id = -1;
		if (p->p_size > CHAMP_MAX_SIZE)
			return (1);
		p = p->next;
	}
	return (0);
}

void		init_function(void (**f)(unsigned char *, t_pc **))
{
	f[11] = &sti;
	f[9] = &zjmp;
	f[6] = &and;
	f[3] = &st;
	f[2] = &ld;
	f[8] = &xor;
	f[4] = &add;
	f[5] = &sub;
	f[14] = &lldi;
	f[10] = &ldi;
	f[7] = &or;
	f[13] = &lld;
	f[16] = &aff;
}
