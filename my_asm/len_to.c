/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:52:18 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 14:29:11 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len_to(char *str, char c)
{
	int	i;

	i = 0;
	c == '%' ? i += 1 : i + 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i + 1);
}
