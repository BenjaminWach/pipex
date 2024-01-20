# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 15:29:03 by bwach             #+#    #+#              #
#    Updated: 2024/01/20 16:27:20 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN   = \033[0;36m
GREEN = \033[0;32m
RED = \033[0;31m
DEFAULT = \033[0m

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
PRINTF = printf
BIN = pipex

#Example of args
ARGS1 = infile.txt "ls -l" "wc -l" outfile.txt
ARGS2 = infile.txt "grep a1" "wc -w" outfile.txt
ARGS3 = infile.txt "cat" "rev" outfile.txt

#Example for bonus
ARGSB1 = infile.txt "ls -l" "grep a" "wc -l" outfile.txt
ARGSB2 = here_doc l "grep a" "wc -l" outfile.txt

#FILES AND PATH
HEADER_SRCS	=	pipex.h pipex_bonus.h 
HEADER_DIR	=	inc/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	pipex.c fork.c msg_error.c clean_all.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	pipex_bonus.c heredoc_bonus.c clean_bonus.c files_bonus.c \
				error_bonus.c childs_bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

UTIL_SRCS	=	pipex_utils.c pipex_utils2.c pipex_utils3.c get_next_line.c get_next_line_utils.c
UTIL_DIR	=	utils/
UTILS 		=	$(addprefix $(UTIL_DIR), $(UTIL_SRCS))
OBJ_U		=	$(UTILS:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
	@${CC} ${FLAGS} -c $< -o $@

all: $(NAME) #$(MAKE) norminette
	
norminette:
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(MPATH_DIR) $(UTIL_DIR)/*.c
	@norminette -R CheckDefine $(MPATH_DIR) $(UTIL_DIR)/*.c
	@echo "$(CYAN)\nNorminette done and validated faggot 🤣\n $(DEFAULT)"

$(NAME): $(OBJ_U) $(OBJ_M)
	@echo "$(CYAN)\n         COMPILING $(NAME)          \n$(DEFAULT)"
	@echo "$(GREEN)-------------------------------------\n$(DEFAULT)"
	@$(CC) $(OBJ_U) $(OBJ_M) -o $(NAME)
	@echo -e: "$(GREEN)\t$(NAME) created!\n $(DEFAULT)"

bonus:	$(OBJ_U) $(OBJ_B)
	@$(CC) $(OBJ_U) $(OBJ_B) -o $(NAME)
	@echo -e:"$(GREEN)$(NAME) bonus created!$(DEFAULT)"

run1: $(NAME)
	@./$(NAME) $(ARGS1)
	@echo ./$(NAME) $(ARGS1)

run2: $(NAME)
	@./$(NAME) $(ARGS2)
	@echo ./$(NAME) $(ARGS2)

run3: $(NAME)
	@./$(NAME) $(ARGS3)
	@echo ./$(NAME) $(ARGS3) 

runb1: bonus
	@./$(NAME) $(ARGSB1)
	@echo ./$(NAME) $(ARGSB1)

runb2: bonus
	@./$(NAME) $(ARGSB2)
	@echo ./$(NAME) $(ARGSB2)

clean:
	@$(RM) $(OBJ_M)
	@$(RM) $(OBJ_U)
	@$(RM) $(OBJ_B)
	@echo -e: "$(RED)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) outfile.txt .here_doc
	@echo -e: "$(RED)all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean bonus re
