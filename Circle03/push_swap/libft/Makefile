# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 16:24:36 by gipark            #+#    #+#              #
#    Updated: 2021/04/14 16:25:03 by gipark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

PATH_SRC = ./libc/

CFLAGS = -Wall -Wextra -Werror

INC = -I./includes

SRC = ft_bzero.c				\
	  ft_memcpy.c				\
	  ft_memccpy.c				\
	  ft_memmove.c				\
	  ft_memchr.c				\
	  ft_memcmp.c				\
	  ft_strlen.c				\
	  ft_strdup.c				\
	  ft_strcpy.c				\
	  ft_strncpy.c				\
	  ft_strcat.c				\
	  ft_strncat.c				\
	  ft_strlcat.c				\
	  ft_strchr.c				\
	  ft_strrchr.c				\
	  ft_strstr.c				\
	  ft_strnstr.c				\
	  ft_strcmp.c				\
	  ft_strncmp.c				\
	  ft_atoi.c					\
	  ft_isalpha.c				\
	  ft_isdigit.c				\
	  ft_isalnum.c				\
	  ft_isascii.c				\
	  ft_isprint.c				\
	  ft_toupper.c				\
	  ft_tolower.c				\
	  ft_memalloc.c				\
	  ft_memdel.c				\
	  ft_strnew.c				\
	  ft_strdel.c				\
	  ft_strclr.c				\
	  ft_striter.c				\
	  ft_striteri.c				\
	  ft_strmap.c				\
	  ft_strmapi.c				\
	  ft_strequ.c				\
	  ft_strnequ.c				\
	  ft_strsub.c				\
	  ft_strjoin.c				\
	  ft_strtrim.c				\
	  ft_strsplit.c				\
	  ft_itoa.c					\
	  ft_putchar.c				\
	  ft_putstr.c				\
	  ft_putendl.c				\
	  ft_putnbr.c				\
	  ft_putchar_fd.c			\
	  ft_putstr_fd.c			\
	  ft_putendl_fd.c			\
	  ft_putnbr_fd.c 			\
	  ft_abs.c					\
	  ft_strncmp.c				\
	  ft_swap.c					\
	  ft_is_space.c				\
	  ft_print_words_tables.c	\
	  ft_sqrt.c					\
	  get_next_line.c			\
	  ft_lentoc.c				\

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
