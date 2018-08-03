/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:16:51 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/16 10:23:33 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	command_in_end(t_champ **a, t_command *command)
{
	t_command	*start;

	if (!(*a)->cmds)
	{
		command->next = (*a)->cmds;
		(*a)->cmds = command;
	}
	else
	{
		start = (*a)->cmds;
		while (start->next)
			start = start->next;
		start->next = command;
		command->next = 0;
	}
}
