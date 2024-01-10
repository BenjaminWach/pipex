# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 15:29:03 by bwach             #+#    #+#              #
#    Updated: 2024/01/10 15:48:38 by bwach            ###   ########.fr        #
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

#FILES AND PATH
HEADER_SRCS	=	pipex.h 
HEADER_DIR	=	inc/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	pipex.c fork.c msg_error.c clean_all.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=		
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

UTIL_SRCS	=	pipex_utils.c pipex_utils2.c pipex_utils3.c
UTIL_DIR	=	utils/
UTILS 		=	$(addprefix $(UTIL_DIR), $(UTIL_SRCS))\
				gnl/get_next_line_utils.c gnl/get_next_line.c
OBJ_U		=	$(UTILS:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
	@${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ_U) $(OBJ_M)
	@$(CC) $(OBJ_U) $(OBJ_M) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all: $(NAME)

norminette: | $(SRC) 
	@$(PRINTF) "$(CYAN)\nCheck with dat Norminette: $(BIN) $(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(MPATH_DIR) $(UTIL_DIR)/*.c
	@norminette -R CheckDefine $(MPATH_DIR) $(UTIL_DIR)/*.c
	@echo "$(CYAN)\nNorminette done and validated faggot 🤣\n $(DEFAULT)"

bonus:	$(OBJ_U) $(OBJ_B)
	@$(CC) $(OBJ_U) $(OBJ_B) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJ_M)
	@$(RM) $(OBJ_U)
	@$(RM) $(OBJ_B)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:	clean
	@$(RM) $(NAME)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean bonus re