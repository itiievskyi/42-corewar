/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:23:42 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/04 09:46:23 by mshkliai         ###   ########.fr       */
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

static int			check_magic(char *str)
{
	int				i;
	int				fd;
	unsigned char	buf[BUF_SIZE + 1];
	unsigned int	magic[4];

	i = -1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	while (read(fd, buf, BUF_SIZE) > 0 && ++i < 4)
		magic[i] = (unsigned int)buf[0];
	if (magic[0] != 0 || magic[1] != 234 ||
			magic[2] != 131 || magic[3] != 243)
		return (1);
	return (0);
}

static int			check_name(char *str)
{
	int				i;

	i = ft_strlen(str);
	if (i >= 5)
	{
		if (str[i - 1] == 'r' && str[i - 2] == 'o' &&
			str[i - 3] == 'c' && str[i - 4] == '.')
			return (0);
	}
	return (1);
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
	free(size);
	return (res);
}

t_player			*read_p_from_f(char *name, int id)
{
	int				fd;
	t_player		*p;
	unsigned int	*tmp;
	int				cm;
	int				pn;

	cm = COMMENT_LENGTH + 1;
	pn = PROG_NAME_LENGTH + 1;
	tmp = NULL;
	p = (t_player *)malloc(sizeof(t_player));
	p->p_name = (unsigned char *)malloc(sizeof(unsigned char) * (pn));
	p->p_code = (unsigned int *)malloc(sizeof(unsigned int) * CHAMP_MAX_SIZE);
	p->p_comment = (unsigned char *)malloc(sizeof(unsigned char) * (cm));
	p->p_id = id;
	p->next = NULL;
	if (check_name(name) || check_magic(name))
		return (NULL);
	fd = open(name, O_RDONLY);
	if (fd >= 0 && (p->last_live = 0) == 0)
	{
		tmp = read_all(fd, p, 0, 0);
		p->p_size = read_size(tmp);
		return (p);
	}
	return (NULL);
}
