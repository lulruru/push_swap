# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:22:58 by russelenc         #+#    #+#              #
#    Updated: 2023/03/07 19:05:29 by russelenc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
VIOLET	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#NAME
NAME = push_swap
CHECK_NAME = checker

#DIR
SRC_DIR = src
OBJ_PATH = ./objs/


 #src
CHECK_SRC = ft_lst.c algo3.c ft_push.c ft_reverse_rotate.c \
				ft_rotate.c ft_swap.c parsing.c general_utils.c checker_main.c \
				big_algo.c cost.c index.c ft_move_cost.c checker_bonus.c \
				get_next_line.c get_next_line_utils.c 

SRC = ft_lst.c algo3.c ft_push.c ft_reverse_rotate.c \
		ft_rotate.c ft_swap.c parsing.c general_utils.c main.c \
		big_algo.c cost.c index.c ft_move_cost.c





#obj
SRCCO = $(SRCS:.c=.o)
CHECK_CO = $(CHECK_SRCS:.c=.o)


 #srcs
SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
CHECK_SRCS = $(addprefix $(SRC_DIR)/, $(CHECK_SRC))


 #compil
CFLAGS =  -Wall -Werror -Wextra
#CC = cc
GCC = gcc $(CFLAGS)


all: $(NAME) 


$(NAME) : $(SRCCO)
	@echo "$(RED)█ ▄▄   ▄      ▄▄▄▄▄    ▄  █        ▄▄▄▄▄    ▄ ▄   ██   █ ▄▄  \n█   █   █    █     ▀▄ █   █       █     ▀▄ █   █  █ █  █   █ \n█▀▀▀ █   █ ▄  ▀▀▀▀▄   ██▀▀█     ▄  ▀▀▀▀▄  █ ▄   █ █▄▄█ █▀▀▀  \n█    █   █  ▀▄▄▄▄▀    █   █      ▀▄▄▄▄▀   █  █  █ █  █ █     \n █   █▄ ▄█               █                 █ █ █     █  █    \n  ▀   ▀▀▀               ▀                   ▀ ▀     █    ▀   \n                                                   ▀                   "
	@echo "$(VIOLET)Building push_swap ..."
	@$(GCC) $(SRCCO) -o $@
	@echo "$(BLUE)push_swap done."
	

$(CHECK_NAME) : $(CHECK_CO)
	@echo "$(BLUE)▄█▄     ▄  █ ▄███▄   ▄█▄    █  █▀ ▄███▄   █▄▄▄▄ \n█▀ ▀▄  █   █ █▀   ▀  █▀ ▀▄  █▄█   █▀   ▀  █  ▄▀ \n█   ▀  ██▀▀█ ██▄▄    █   ▀  █▀▄   ██▄▄    █▀▀▌  \n█▄  ▄▀ █   █ █▄   ▄▀ █▄  ▄▀ █  █  █▄   ▄▀ █  █  \n▀███▀     █  ▀███▀   ▀███▀    █   ▀███▀     █   \n         ▀                   ▀             ▀    "                                            
	@echo "$(VIOLET)Building checker..."
	@$(GCC) $(CHECK_CO) -o $@
	@echo "$(BLUE)checker done."
	
%.o : %.c 
	@$(GCC) $(CFLAG) -c $< -o $@

clean: 
	rm -f $(SRCCO) 
	rm -f $(CHECK_CO) 

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECK_NAME)

re: fclean all

.PHONY: all clean fclean re