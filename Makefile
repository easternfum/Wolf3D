# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:28:59 by kfum              #+#    #+#              #
#    Updated: 2022/10/05 11:08:02 by kfum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

# Directories
INC_PATH = ./include
SRC_PATH = ./src/

# Flags
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
MINILIB = -I /usr/local/include -L /usr/local/lib -l mlx -l ft -framework OpenGL -framework Appkit
INC_LIB = -Llibft

# Files to compile
FILES = graphic init movement raycast window wolf

# Files
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FILES)))
LIB_MLX = libft/libft.a

all : $(NAME)
.SILENT : $(OBJS)

libft/libft.a :
	@echo "$(GREEN)Compiling libft files...$(DEFAULT)"
	@$(MAKE) -sC libft/ all
	@echo "$(GREEN)Compiling $(NAME) files...$(DEFAULT)"
	

$(NAME) : $(LIB_MLX) $(OBJS)
	@echo -n '.'
	@$(CC) $^ -o $@ $(FLAGS) $(INC_LIB) $(MINILIB)
	@echo "$(GREEN)\n$(NAME) compilation done.$(DEFAULT)"

clean :
	@$(MAKE) fclean -sC libft
	@echo "$(RED)Cleaning $(NAME) .o files...$(DEFAULT)"
	@rm -f $(OBJS)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

fclean : clean
	@echo "$(RED)Deleting .$(NAME)...$(DEFAULT)" 
	@rm -f $(NAME)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

re : fclean all

# Output colors
DEFAULT	:=\033[0m
GREEN	:=\033[0;32m
RED		:=\033[0;31m
