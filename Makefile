# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/03 16:09:03 by mshkliai          #+#    #+#              #
#    Updated: 2018/08/03 16:29:25 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd my_asm && make && mv asm ..
	@cd VM && make && mv corewar ..

clean:
	@cd my_asm && make clean
	@cd VM && make clean

fclean: clean
	@rm -f asm corewar && \
		echo "\033[0;36mVirtual Machine and ASM removed\033[0m"

re: fclean all

.PHONY:all clean fclean re
