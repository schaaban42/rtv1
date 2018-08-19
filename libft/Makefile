# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 12:08:41 by schaaban          #+#    #+#              #
#    Updated: 2018/03/26 20:36:26 by schaaban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME	=	ft
NAME		=	lib$(LIB_NAME).a

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

SRCS_DIR	=	./srcs
INC_DIR		=	./includes
OBJS_DIR	=	./objs

CC_INC		=	-I $(INC_DIR)

SRCS		=	$(addprefix $(SRCS_DIR)/, 	\
				ft_a2ddel.c					\
				ft_a2dlen.c					\
				ft_atoi.c					\
				ft_bounds.c					\
				ft_bzero.c					\
				ft_colorgradient.c			\
				ft_del.c					\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isdigit.c				\
				ft_isdigit_base.c			\
				ft_isprint.c				\
				ft_itoa.c					\
				ft_itoa_base.c				\
				ft_join.c					\
				ft_lstadd.c					\
				ft_lstdel.c					\
				ft_lstdelone.c				\
				ft_lstiter.c				\
				ft_lstmap.c					\
				ft_lstnew.c					\
				ft_memalloc.c				\
				ft_memccpy.c				\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memdel.c					\
				ft_memmove.c				\
				ft_memset.c					\
				ft_printf.c					\
				ft_putchar_fd.c				\
				ft_putchar.c				\
				ft_putendl_fd.c				\
				ft_putendl.c				\
				ft_putlong.c				\
				ft_putnbr_fd.c				\
				ft_putnbr.c					\
				ft_putstr_fd.c				\
				ft_putstr.c					\
				ft_s2dnew.c					\
				ft_strcat.c					\
				ft_strchr.c					\
				ft_strclr.c					\
				ft_strcmp.c					\
				ft_strcpy.c					\
				ft_strdel.c					\
				ft_strdup.c					\
				ft_strequ.c					\
				ft_str_isdigit.c			\
				ft_striter.c				\
				ft_striteri.c				\
				ft_strjoin.c				\
				ft_strjoin_free.c			\
				ft_strlcat.c				\
				ft_strlen.c					\
				ft_strmap.c					\
				ft_strmapi.c				\
				ft_strncat.c				\
				ft_strncmp.c				\
				ft_strncpy.c				\
				ft_strnequ.c				\
				ft_strnew.c					\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_strsplit.c				\
				ft_strstr.c					\
				ft_strsub.c					\
				ft_strtrim.c				\
				ft_tolower.c				\
				ft_toupper.c				\
				get_next_line.c				)
OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[1;34m
COLOR_GREEN	=	\033[1;32m
COLOR_WHITE	=	\033[0m

all: $(NAME)

$(NAME): dir_creation $(OBJS)
	@echo "$(COLOR_BLUE)LIBFT - $(COLOR_GREEN)Compiling libft...$(COLOR_WHITE)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(COLOR_BLUE)LIBFT - $(COLOR_GREEN)Done !$(COLOR_WHITE)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC_DIR)/libft.h
	@$(CC) $(FLAGS) $(CC_INC) -o $@ -c $<

dir_creation:
	@echo "$(COLOR_BLUE)LIBFT - $(COLOR_GREEN)Objs creation...$(COLOR_WHITE)"
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "$(COLOR_BLUE)LIBFT - $(COLOR_RED)Cleaning objs...$(COLOR_WHITE)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(COLOR_BLUE)LIBFT - $(COLOR_RED)Cleaning libft...$(COLOR_WHITE)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean dir_creation
