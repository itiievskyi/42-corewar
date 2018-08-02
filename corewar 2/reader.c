/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:23:42 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/01 19:04:19 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int		*read_all(int fd, t_player *p, int k, int j)
{
	int				i;
	int				l;
	unsigned char	buf[BUF_SIZE + 1];
	unsigned int	*size1;
	int				c;

	i = 0;
	l = 0;
	c = 0;
	size1 = (unsigned int *)malloc(sizeof(unsigned int) * 4);
	while (read(fd, buf, BUF_SIZE) > 0)
	{
		if (i >= 4 && i <= 132)
			p->p_name[j++] = buf[0];
		if (i >= 136 && i <= 139)
			size1[l++] = (unsigned int)buf[0];
		if (i >= 140 && i <= 2186)
			p->p_comment[k++] = (unsigned char)buf[0];
		if (i >= 2192 && i <= 2874)
			p->p_code[c++] = (int)(buf[0]);
		i++;
	}
	p->p_name[j] = '\0';
	p->p_comment[k] = '\0';
	return (size1);
}

int					read_size(unsigned int *size)
{
	int				i;
	int				j;
	int				res;

	j = 4;
	i = 0;
	while (--j >= 0)
	{
		res += size[i];
		res = res << (j * 8);
		i++;
	}
	return (res);
}

t_player			*read_p_from_f(char *name, int id)
{
	int				fd;
	unsigned char	*name1;
	unsigned char	*comment;
	unsigned int	*code;
	unsigned int	*tmp;

	tmp = NULL;
	name1 = (unsigned char *)malloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
	code = (unsigned int *)malloc(sizeof(unsigned int) * CHAMP_MAX_SIZE);
	comment = (unsigned char *)malloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
	t_player	*p;
	p = (t_player *)malloc(sizeof(t_player));
	p->p_name = name1;
	p->p_comment = comment;
	p->p_code = code;
	p->p_id = id;
	p->next = NULL;
	fd = open(name, O_RDONLY);
	if (fd >= 0)
	{
		tmp = read_all(fd, p, 0, 0);
		p->p_size = read_size(tmp);
		return (p);
	}
	return (NULL);
}
