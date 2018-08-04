/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:16:08 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/04 10:54:45 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

static void	all_champs(int fd, t_champ **a)
{
	t_champ	*b;
	t_champ	*start;

	b = 0;
	b = (t_champ*)malloc(sizeof(t_champ));
	b->cmds = 0;
	full_values(fd, &b);
	close(fd);
	if (!b->cmds)
		out_error("No commands!", 0);
	if (!*a)
	{
		b->next = *a;
		*a = b;
	}
	else
	{
		start = *a;
		while (start->next)
			start = start->next;
		start->next = b;
		b->next = 0;
	}
	close(fd);
}

static void	print_usage(void)
{
	ft_printf("Usage: ./asm [-a] [*] <champion.s>\n");
	ft_printf("    -a : Instead of creating a .cor file, outputs a stripped ");
	ft_printf("and annotated version of the code to the standard output\n");
	ft_printf("     * : Compiling a several <champions.s> at once, ");
	ft_printf("but all files must be valid\n");
	exit(0);
}

int			main(int ac, char **av)
{
	t_champ	*a;
	int		fd;
	int		i;

	a = 0;
	i = 0;
	ac == 1 ? print_usage() : 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-a") && ++i)
			g_a = 1;
		if (g_a && i == ac)
			break ;
		fd = open(av[i], O_RDONLY);
		fd == -1 ? ft_printf("Can't read source file ") : 0;
		fd == -1 ? out_error(av[i], 0) : 0;
		all_champs(fd, &a);
	}
	if (!g_a)
		write_in_file(a, av);
	else if (g_a && ac == 2)
		print_usage();
	else if (g_a)
		flag_a(a);
	return (0);
}
