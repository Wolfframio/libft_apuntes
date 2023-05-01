# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imontero <imontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 19:35:16 by imontero          #+#    #+#              #
#    Updated: 2023/04/19 19:35:16 by imontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_split.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

				
OBJS		= $(SRCS:%.c=%.o)
#El resultado es una lista de archivos objeto que tienen los mismos nombres que los archivos fuente pero con la extensión .o. (cambia .c por .o)

FLAGS		= -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
# -c crear archivos objeto .o
	ar rc $(NAME) $(OBJS) 
#crear un archivo de biblioteca a partir de una lista de archivos objeto. 
# r indica que se debe agregar archivos al archivo de biblioteca (en lugar de reemplazarlo)
# c indica que se debe crear un nuevo archivo de biblioteca si aún no existe.
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
#indica que los objetivos que contiene no son archivos y no tiene que buscarlos