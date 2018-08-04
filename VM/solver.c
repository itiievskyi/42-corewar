/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:55:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 06:34:03 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			do_all(t_player *p, unsigned char *map, \
		t_pc **pc_1, void (**functions)(unsigned char *, t_pc **))
{
	t_pc	*tmp;

	tmp = (*pc_1);
	while (tmp != NULL)
	{
		if (tmp->command == 0)
			get_command(map, tmp);
		if (tmp->cicles == 0)
		{
			if (tmp->command == 12)
				fork_1(map, tmp, pc_1);
			else if (tmp->command == 15)
				lfork_1(map, tmp, pc_1);
			else if (tmp->command == 1)
				live(map, p, tmp);
			else
				do_command(map, tmp, functions);
		}
		if (tmp->cicles > 0)
			tmp->cicles--;
		tmp = tmp->next;
	}
}

void			game_over(t_player *p, t_pc *pc, unsigned char *map, t_rule *r)
{
	t_player	*p_win;
	t_player	*p1;

	p_win = p;
	p1 = p;
	while (p != NULL)
	{
		if (p->last_live > p_win->last_live)
			p_win = p;
		if (p->last_live == p_win->last_live)
			(p->pc_id < p_win->pc_id) ? (p_win = p) :
				(0);
		p = p->next;
	}
	p_win->last_live = 2147483647;
	print_map(map, pc, p_win, r);
	free_all(p1, pc, r);
}

int				contestant(t_player *win, t_player *all)
{
	int			j;

	j = 1;
	while (all != NULL)
	{
		if (all->p_id == win->p_id)
			return (j);
		j++;
		all = all->next;
	}
	return (j);
}

void			p_win(t_player *p, t_pc *pc, t_rule *r)
{
	t_player	*p1;
	t_player	*win;

	win = p;
	p1 = p;
	while (p != NULL)
	{
		if (p->last_live > win->last_live)
			win = p;
		if (p->last_live == win->last_live)
			(p->pc_id < win->pc_id) ? (win = p) :
				(0);
		p = p->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", contestant(win, p1),
			win->p_name, win->p_id);
	free_all(p1, pc, r);
}

void			solve(t_player *p, unsigned char *map, t_pc *pc_1, t_rule *r)
{
	void		(*functions[17])(unsigned char *, t_pc **);

	init_function(functions);
	while (1 && (++(r->j)) > -1 && (++(r->i)) > -1)
	{
		add_i(p, r->i);
		do_all(p, map, &pc_1, functions);
		if (r->j / r->c == MAX_CHECKS ||
				!(r->j = check_cycle(count_live(p, pc_1), r->j, r->c, p)))
			game_minus_cicle(r);
		if (r->j % r->c == 0)
			delete_pc(p, &pc_1);
		if (r->c <= 0 || !pc_1)
		{
			(r->visual) ? game_over(p, pc_1, map, r) : p_win(p, pc_1, r);
			break ;
		}
		if (r->visual)
			print_map(map, pc_1, p, r);
		if (r->check_dump == 1 && r->dump == (unsigned int)r->i)
		{
			print_dump(p, map, pc_1, r);
			break ;
		}
	}
}
