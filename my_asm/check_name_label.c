/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:54:46 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/21 12:45:30 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	check_name_label(char *line)
{
	char	*start;

	start = line;
	while (*start)
	{
		if (!ft_strchr(LABEL_CHARS, *start))
		{
			ft_printf("'%c' is forbidden in label-name\n", *start);
			out_error("", line);
		}
		start++;
	}
}
