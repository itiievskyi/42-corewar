/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:36:51 by mshkliai          #+#    #+#             */
/*   Updated: 2018/04/08 16:02:25 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*end;

	if (!lst || !f)
		return (NULL);
	lst2 = f(lst);
	end = lst2;
	while (lst->next)
	{
		lst = lst->next;
		lst2->next = f(lst);
		lst2 = lst2->next;
	}
	return (end);
}
