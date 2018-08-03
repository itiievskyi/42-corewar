/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:08:51 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/27 09:28:02 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str, const char *str2)
{
	int					i;
	unsigned	char	*st;
	unsigned	char	*st2;

	st = (unsigned char*)str;
	st2 = (unsigned char*)str2;
	i = 0;
	while (*(st + i) || *(st2 + i))
	{
		if (*(st + i) != *(st2 + i))
			return (*(st + i) - *(st2 + i));
		i++;
	}
	return (0);
}
