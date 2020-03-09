# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 19:43:43 by kkinzers          #+#    #+#              #
#    Updated: 2019/01/28 20:13:56 by kkinzers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_DIR = ./libft

SRC = cut.c fillit.c main.c map.c validator.c

SRCO = $(SRC:.c=.o)

HEADER = fillit.h
HEADER_FLAGS = -I $(HEADER)

FLAGS = -Wall -Wextra -Werror

LIB = $(LIB_DIR)libft.a
LIB_FLAGS = -lft -L $(LIB_DIR)

all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)
$(NAME): $(LIB) $(SRCO)
	@gcc $(SRCO) $(LIB_FLAGS) -o $(NAME)
%.o: %.c
	gcc -c $< -o $@ -I $(HEADER)
clean:
	@rm -f $(SRCO)
	@make clean -C $(LIB_DIR)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
re: fclean all
