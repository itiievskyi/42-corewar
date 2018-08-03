# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:51:09 by itiievsk          #+#    #+#              #
#    Updated: 2018/08/03 12:20:00 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

HEADER = ft_printf.h

SOURCES =	ft_printf.c\
			ft_write.c\
			ft_strchr.c\
			ft_printf_strings.c\
			ft_printf_params.c\
			ft_atoi.c\
			ft_printf_struct.c\
			ft_strlen.c\
			ft_printf_chars.c\
			ft_strdup.c\
			ft_printf_unicode.c\
			ft_bzero.c\
			ft_memset.c\
			ft_wstrdup.c\
			ft_printf_utils.c\
			ft_printf_ints.c\
			ft_strnchr.c\
			ft_printf_hex.c\
			ft_printf_oct.c\
			ft_printf_double.c\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette $(HEADER)
	@echo
	norminette $(SOURCES)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
