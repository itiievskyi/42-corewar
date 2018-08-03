/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_in_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:23:09 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/13 13:10:59 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	arg_in_end(t_arg **a, t_arg *b)
{
	t_arg	*start;

	start = *a;
	if (!*a)
	{
		b->next = *a;
		*a = b;
	}
	else
	{
		while (start->next)
			start = start->next;
		start->next = b;
		b->next = 0;
	}
}
