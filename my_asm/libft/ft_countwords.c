/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:38:45 by mshkliai          #+#    #+#             */
/*   Updated: 2018/03/28 16:42:01 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(char const *str, char c)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
}
