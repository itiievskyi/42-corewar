/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:12:01 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/20 12:12:18 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

int		size_code(t_champ *a)
{
	int			size;
	t_command	*command;
	t_arg		*arg;

	size = 0;
	command = a->cmds;
	while (command)
	{
		if (ft_strcmp(command->name, "-1"))
		{
			size++;
			if (command->codage)
				size++;
			arg = command->inst;
			while (arg)
			{
				size += arg->size;
				arg = arg->next;
			}
		}
		command = command->next;
	}
	return (size);
}
