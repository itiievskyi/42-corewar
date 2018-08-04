# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:08:44 by mshkliai          #+#    #+#              #
#    Updated: 2018/08/03 16:21:06 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

all: $(NAME)

SRC = add.c aff.c and.c bit_mask.c check_codage_patern2.c \
	  check_codage_patern.c create_players.c fork.c from_binary.c \
	  game_rules.c help_solver.c ld.c ldi.c lfork.c live.c lld.c lldi.c \
	  map_function.c op.c pars.c print_ncurses.c print_ncurses_buttons.c \
	  print_ncurses_field.c print_ncurses_finish.c print_ncurses_forcequit.c \
	  print_ncurses_help.c print_ncurses_highlights.c \
	  print_ncurses_template.c print_ncurses_utils.c reader.c solver.c \
	  st.c sti.c sub.c vm_main.c xor.c zjmp.c or.c help_main.c

FLAGS = -Wall -Werror -Wextra

NCURSES = -lpanel -lncurses

END = \033[0m

GREEN = \033[0;32m

RED = \033[0;31m

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

$(NAME): $(OBJ)
	@cd libft && make
	@gcc -o $(NAME) $(FLAGS) $(NCURSES) $(OBJ) $(LIBFT) && \
		echo "\033[1;33m				Virtual Machine COMPILED$(END)"

$(OBJ): %.o: %.c
	@gcc -c $< -o $@ $(FLAGS) \
		&& echo "$(GREEN)$< \033[1;34m--> $(RED)$@$(END)$(END)$(END)"

clean:
	@rm -f $(OBJ)
	@cd libft && \
	echo "\033[0;36mRemoved .o files$(END)" && make fclean
	
fclean: clean
	@rm -f $(NAME) && echo "\033[1;31mRemoved $(NAME)$(END)"

re: fclean all

.PHONY:all clean fclean re
