# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:49:49 by kfaustin          #+#    #+#              #
#    Updated: 2023/01/09 15:58:48 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= includes/libft
PRINTF	= includes/ft_printf
LIBA	= libft.a
PRIA	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	=	./src/server.c
SRCC	=	./src/client.c
SRCSB	=	./src/bonusserver.c
SRCCB	=	./src/bonusclient.c

all: sc clean

sc: printf libft
		$(CC) $(CFLAGS) $(SRCS) $(PRIA) -o server
		$(CC) $(CFLAGS) $(SRCC) $(LIBA) $(PRIA) -o client

bonus: printf libft
		$(CC) $(CFLAGS) $(SRCSB) $(PRIA) -o server
		$(CC) $(CFLAGS) $(SRCCB) $(LIBA) $(PRIA) -o client
		$(RM) libft.a libftprintf.a
libft:
		@make -C $(LIBFT)
		@cp $(LIBFT)/$(LIBA) .
printf:
		@make -C $(PRINTF)
		@cp $(PRINTF)/$(PRIA) .

clean:
		$(RM) libft.a libftprintf.a
		make -C $(LIBFT) clean
		make -C $(PRINTF) clean
fclean: clean
		make -C $(LIBFT) fclean
		make -C $(PRINTF) fclean
finish: fclean
		$(RM) server client

re: fclean all
reall: finish all
