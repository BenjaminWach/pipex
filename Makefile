# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 15:29:03 by bwach             #+#    #+#              #
#    Updated: 2024/01/09 14:26:36 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN   = \033[0;36m
DEFAULT = \033[0m

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
PRINTF = printf
BIN = pipex

SRC = pipex.c \
	fork.c \
	msg_error.c \
	clean_all.c \
	pipex_utils.c pipex_utils2.c pipex_utils3.c\
	bonus.c here_doc.c\
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation done"

norminette: | $(SRC) 
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_FILES) $(LIBFT_DIR)/*.c
	@norminette -R CheckDefine $(LIBFT_DIR)/*.c
	@echo "$(CYAN)\tNorminette done and validated faggot 🤣\n $(DEFAULT)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaning done"

re: fclean all

.PHONY: all clean fclean re