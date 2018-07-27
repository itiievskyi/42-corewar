/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:30:23 by averemiy          #+#    #+#             */
/*   Updated: 2018/07/27 14:26:37 by averemiy         ###   ########.fr       */
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
		}
		else
			if (try_to_read(p, argv[i], j--))
				return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	unsigned char *map;
	int i;
	t_rule *rule;
	t_player *p;
	t_pc *pc;

	map = (unsigned char *)malloc(sizeof(unsigned char) * 4096);
	i = 0;
	p = NULL;
	pc = NULL;
	rule = (t_rule *)malloc(sizeof(t_rule));
	while (++i < MEM_SIZE)
		map[i] = 0;
	i = 0;
	if (pars(argv, argc, &p, rule))
	{
//		printf("ERROR\n");
		return (1);
	}
//	else
//		printf("all good\n");
	if ((pc = create_pc(p)) == NULL)
	{
//		printf("ERROR in pc\n");
		return (1);
	}
//	else
//		printf("all good2\n");
	put_in_map(p, map);
	solve(p, map, pc);
	return (0);
}
