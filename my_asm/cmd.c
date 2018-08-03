/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:25:24 by mshkliai          #+#    #+#             */
/*   Updated: 2018/07/21 13:59:01 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_asm.h"

void	cmd(char *line)
{
	int	i;

	i = 0;
	trimmer(line, ';', COMMENT_CHAR);
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			break ;
		else if (line[i] != ' ' && line[i] != '\t')
			out_error("Lexical Error", line);
		i++;
	}
}
