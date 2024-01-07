# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 15:29:03 by bwach             #+#    #+#              #
#    Updated: 2023/12/25 19:04:57 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f

SRC = pipex.c \
	fork.c \
	msg_error.c \
	clean_all.c \
	pipex_utils.c pipex_utils2.c \
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation done"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)
	@echo "Cleaning done"

re: fclean all

.PHONY: all clean fclean re