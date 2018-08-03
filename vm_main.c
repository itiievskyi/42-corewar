/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/03 14:40:39 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"



int			pars(char **argv, int argc, t_player **p, t_rule *rule)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++i < argc)
	{
		if (!(ft_strcmp(argv[i], "-n")))
		{
			if (create_with_number(p, argc - 1, i, argv))
				return (1);
			i += 2;
		}
		else if (!(ft_strcmp(argv[i], "-a")) || !(ft_strcmp(argv[i], "-v")))
			(!ft_strcmp(argv[i], "-a")) ? (rule->aff = 1) : (rule->visual = 1);
		else if (!(ft_strcmp(argv[i], "-dump")))
		{
			if (read_dump(rule, argv, argc - 1, i))
				return (1);
			i += 2;
		}
		else
			if (try_to_read(p, argv[i], j--))
				return (1);
	}
	return (0);
}

void	init_rule(t_rule *rule)
{
	rule->visual = 0;
	rule->dump = 0;
	rule->i = 0;
	rule->c = CYCLE_TO_DIE;
	rule->aff = 0;
	rule->j = 0;
}

void	free_all(t_player *p, t_pc *pc)
{
	t_player *p1;
	t_pc *pc1;

	while (p != NULL)
	{
		p1 = p;
		if (p1->p_name)
			free(p1->p_name);
		if (p1->p_comment)
			free(p1->p_comment);
		if (p1->p_code)
			free(p1->p_code);
		p = p->next;
		free(p1);
	}
	while (pc != NULL)
	{
		pc1 = pc;
		pc = pc->next;
		free(pc1);
	}
}

int		main(int argc, char **argv)
{
	unsigned char map[MEM_SIZE];
	int i;
	t_rule *rule;
	t_player *p;
	t_pc *pc;

	i = 0;
	p = NULL;
	pc = NULL;
	rule = (t_rule *)malloc(sizeof(t_rule));
	init_rule(rule);
	while (++i < MEM_SIZE)
		map[i] = 0;
	if (pars(argv, argc, &p, rule))
		return ((0 * ft_printf("ERROR\n") + 1));
	if ((pc = create_pc(p, rule)) == NULL)
		return ((0 * ft_printf("ERROR\n") + 1));
	if (rule->visual == 1)
		rule->check_dump = 0;
	put_in_map(p, map);
	solve(p, map, pc, rule);
	system("leaks crwr");
	return (0);
}
