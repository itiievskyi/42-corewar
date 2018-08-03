/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:45:23 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/20 12:46:51 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

int	size_command(t_command *command)
{
	int		size;
	t_arg	*args;

	size = 1;
	if (command->codage)
		size++;
	args = command->inst;
	while (args)
	{
		size += args->size;
		args = args->next;
	}
	return (size);
}
