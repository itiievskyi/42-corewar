/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:11:21 by mshkliai          #+#    #+#             */
/*   Updated: 2018/08/02 13:19:45 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 1

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *ptr, int n, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *srd1, const void *srd2, int c, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memmove(void *src1, const void *src2, size_t n);
void				*ft_memchr(const void *srd, int val, size_t n);
int					ft_memcmp(const void *ptr, const void *ptr2, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *str1, const char *str2);
char				*ft_strncpy(char *str, const char *str2, size_t num);
char				*ft_strcat(char *str, const char *str2);
char				*ft_strncat(char *str, const char *str2, size_t n);
size_t				ft_strlcat(char *str, const char *str2, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strcmp(const char *str, const char *str2);
int					ft_strncmp(const char *str, const char *str2, size_t n);
int					ft_atoi(const char *srd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str, const char *str2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putrts(char *str);
int					ft_countwords(char const *str, char c);
char				*ft_rtsdup(const char *str);
void				ft_strlen_fd(char *str, int fd);
char				*ft_strndup(char const *str, size_t n);
void				ft_lstend(t_list **alst, t_list *end);

#endif
