/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:00:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/02 13:12:43 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c, int size);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
wchar_t			*ft_wstrdup(wchar_t *src);

typedef struct	s_params
{
	const char	*str;
	size_t		length;
	char		convert;
	int			width;
	size_t		index;
	size_t		ret_point;
	char		*data;
	char		mod;
	int			prec;
	int			hash;
	int			zero;
	int			space;
	int			minus;
	char		plus;
	int			apostrophe;
	int			error;
	int			p;
}				t_params;

t_params		*ft_get_struct(const char *fmt);
void			ft_check_pad(t_params *par, int *ret);
void			ft_get_param(t_params *par, va_list arg);
void			check_err_conv(t_params *par, const char c);
void			ft_write(const char *c, int *ret, int size);
void			ft_write_string(const char *s, int index, int *ret);
void			ft_write_free_string(t_params *par, int index, int *ret);
void			ft_write_wstring(unsigned char *s, int *ret, int len);
void			ft_printf_char(t_params *par, va_list arg, int *ret);
void			ft_printf_c_err(t_params *par, int *ret);
void			ft_printf_string(t_params *par, va_list arg, int *ret, int a);
void			ft_wchar_err(int *len, int num, t_params *par, int *index);
void			ft_printf_wchar(t_params *par, va_list arg, int *ret);
void			ft_printf_wstr(t_params *par, va_list arg, int *ret, int len);
unsigned char	*get_wlength(int *len, int index, t_params *par, va_list arg);
void			ft_printf_i(t_params *par, va_list arg, int *ret, int len);
void			ft_put_sign(t_params *par, int *ret, int *a);
uintmax_t		ft_get_num(t_params *par, uintmax_t n, intmax_t s, va_list arg);
uintmax_t		ft_get_uint(t_params *par, uintmax_t n, va_list arg);
int				ft_putnum(uintmax_t num, int *ret, t_params *par);
void			ft_place_int(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_place_oct(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_place_hex(t_params *par, int *ret, int *a, uintmax_t num);
void			ft_int_pad(t_params *par, int *ret, int *a);
int				ft_puthex(uintmax_t num, int *ret, t_params *par);
int				ft_putoct(uintmax_t num, int *ret, t_params *par);
void			ft_printf_hex(t_params *par, va_list arg, int *ret, int a);
void			ft_printf_oct(t_params *par, va_list arg, int *ret, int a);
void			ft_printf_double(t_params *par, va_list arg, int *ret, int a);

#endif
