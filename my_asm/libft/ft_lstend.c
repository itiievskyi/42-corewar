/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:41:42 by mshkliai          #+#    #+#             */
/*   Updated: 2018/04/01 14:02:22 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list **alst, t_list *end)
{
	t_list	*list;

	list = *alst;
	if (!alst || !end)
		return ;
	while (list->next)
		list = list->next;
	list->next = end;
	end->next = NULL;
}
