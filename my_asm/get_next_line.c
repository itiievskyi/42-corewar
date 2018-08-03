/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:06:21 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 14:15:36 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static size_t	l(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char		*join_free(char *buf, char *str, int i)
{
	char	*str3;

	if (!str)
		return (NULL);
	if (i == 1)
	{
		if (ft_strlen(str) == 0)
			return (buf);
		str3 = NULL;
		if (buf != NULL)
			str3 = ft_strdup(buf);
		else
			str3 = ft_strdup("");
		ft_strdel(&buf);
		buf = ft_strjoin(str3, str);
		ft_strdel(&str3);
	}
	else
	{
		ft_strdel(&buf);
		buf = ft_strdup(str);
	}
	return (buf);
}

static void		cut(char **line, t_list **lst, int *ret)
{
	char	buf[l(*line) + 1];
	size_t	n;

	if (*ret == 0 && !*line)
		*ret = 0;
	else
		*ret = 1;
	if (!*line || !*lst)
		return ;
	n = l(*line);
	if (ft_strlen((*lst)->content))
		ft_strclr((*lst)->content);
	if (n == ft_strlen(*line))
		return ;
	(*lst)->content = join_free((*lst)->content, *line + 1 + n, 0);
	ft_strncpy(buf, *line, n);
	buf[n] = '\0';
	*line = join_free(*line, buf, 0);
}

static void		finding(t_list **lst, size_t fd)
{
	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		if ((*lst)->content_size == fd)
			return ;
		*lst = (*lst)->next;
	}
	if ((*lst)->content_size == fd)
		return ;
	else
	{
		ft_strclr((*lst)->content);
		ft_lstend(lst, ft_lstnew("", 1));
		(*lst)->content_size = fd;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			*str;
	int				ret;
	t_list			*blist;

	str = NULL;
	ret = 0;
	if (BUFF_SIZE < 0 || !line || fd < 0 || (ret = read(fd, str, 0)) < 0)
		return (-1);
	if (!lst)
		ft_lstadd(&lst, ft_lstnew("", 0));
	blist = lst;
	finding(&lst, (size_t)fd);
	str = ft_strnew(BUFF_SIZE);
	*line = NULL;
	*line = join_free(*line, lst->content, 1);
	while (ft_strlen(str) == l(str) && (ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		*line = join_free(*line, str, 1);
	}
	cut(line, &lst, &ret);
	ft_strdel(&str);
	lst = blist;
	return (ret);
}
