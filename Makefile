# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:22:58 by russelenc         #+#    #+#              #
#    Updated: 2023/02/07 17:16:49 by russelenc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src

SRC = ft_lst.c algo3.c ft_push.c ft_reverse_rotate.c \
		ft_rotate.c ft_swap.c parsing.c general_utils.c main.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
SRCCO = $(SRCS:.c=.o)
CFLAGS =  -Wall -Werror -Wextra
CC = cc
CO = gcc


all: $(NAME)

$(NAME) : $(SRCCO)
	$(CO) -o $(NAME) $(SRCCO)
	
%.o : %.c 
	$(CO) $(CFLAG) -c $< -o $@ 

all: $(NAME)

clean: 
	rm -f $(SRCCO) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re