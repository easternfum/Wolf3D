# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 11:01:05 by kfum              #+#    #+#              #
#    Updated: 2022/10/05 11:07:45 by kfum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
		ft_memchr ft_memcmp ft_strlen ft_strdup ft_strcpy \
		ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr \
		ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
		ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii \
		ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel \
		ft_strnew ft_strdel	ft_strclr ft_striter ft_striteri \
		ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
		ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar \
		ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd \
		ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel \
		ft_lstadd ft_lstiter ft_lstmap ft_lstcount ft_lstrev \
		ft_isspace ft_abs ft_strrev ft_swap ft_sqrt \
		get_next_line ft_count ft_search ft_map_check

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)	
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo -n '.'

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)\nLibft compilation done.\n$(DEFAULT)"

all: $(NAME)

clean:
	@echo "$(RED)Cleaning libft .o files...$(DEFAULT)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

fclean: clean
	@echo "$(RED)Deleting $(NAME)...$(DEFAULT)" 
	@$(RM) $(NAME)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

re: fclean all

# Output colors
DEFAULT	:=\033[0m
GREEN	:=\033[0;32m
RED		:=\033[0;31m