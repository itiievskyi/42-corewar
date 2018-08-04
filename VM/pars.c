/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:23:49 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 11:37:53 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		had_letter(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str <= '9' && *str >= '0')
			str++;
		else
			return (1);
	}
	return (0);
}

int				read_dump(t_rule *rule, char **argv, int argc, int *i)
{
	rule->check_dump = 1;
	if (*i + 1 > argc || had_letter(argv[*i + 1]))
		return (1);
	else
		rule->dump = ft_atoi(argv[*i + 1]);
	*i += 1;
	return (0);
}

int				create_with_number(t_player **p, int argc, int *i, char **argv)
{
	int			number;
	t_player	*tmp;
	t_player	*test;

	tmp = NULL;
	test = (*p);
	if ((*i + 2) > argc || had_letter(argv[*i + 1]))
		return (1);
	number = ft_atoi(argv[*i + 1]);
	if (!(tmp = read_p_from_f(argv[*i + 2], number)))
		return (1);
	else
	{
		if (*p == NULL)
			*p = tmp;
		else
		{
			while (test->next != NULL)
				test = test->next;
			test->next = tmp;
		}
	}
	*i += 2;
	return (0);
}

int				try_to_read(t_player **p, char *str, int nbr)
{
	t_player	*tmp;
	t_player	*test;

	tmp = NULL;
	test = (*p);
	if (!(tmp = read_p_from_f(str, nbr)))
		return (1);
	else
	{
		if (*p == NULL)
			*p = tmp;
		else
		{
			while (test->next != NULL)
				test = test->next;
			test->next = tmp;
		}
	}
	return (0);
}
