# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 11:31:11 by mshkliai          #+#    #+#              #
#    Updated: 2018/08/03 16:19:34 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

all: $(NAME)

SRC = atoi_for_arg.c matrix_del.c join_free.c arg_in_end.c out_error.c \
	  trimmer.c cmd.c copy_to.c comment_name.c write_bytes.c \
	  check_name_label.c parse_command.c split_for_args.c command_in_end.c \
	  parse_arg.c parse_arg_dir.c parse_arg_ind.c validation.c full_values.c \
	  size_code.c write_in_file.c size_command.c flag_a.c global_variables.c \
	  width.c len_to.c get_next_line.c main.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

PRINTF = ./printf/libftprintf.a

END = \033[0m

$(NAME): $(OBJ)
	@cd printf &&\
	echo "\033[1;32mCompiling \033[1;35mPRINTF...$(END)$(END)" && make
	@cd libft && \
	echo "\033[1;32mCompiling \033[1;35mLIBFT...$(END)$(END)" && make
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) && \
		echo "\033[1;33m				ASM COMPILED$(END)"

$(OBJ): %.o: %.c
	@gcc -c $< -o $@ $(FLAGS)\
		&& echo "\033[0;32m$< \033[1;34m--> \033[0;31m$@$(END)$(END)$(END)"

clean:
	@rm -f $(OBJ)
	@cd libft && make fclean
	@cd printf && make fclean
	
fclean: clean
	@rm -f $(NAME) && echo "\033[1;31mRemoved $(NAME)$(END)"

re: fclean all

.PHONY:all clean fclean re
