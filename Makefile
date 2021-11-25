# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedison <tedison@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 10:26:43 by tedison           #+#    #+#              #
#    Updated: 2021/06/11 14:08:54 by tedison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
SERVER_S = server.c ft_putnbr_base.c ft_bzero.c
CLIENT_S = client.c ft_atoi.c ft_convert_base.c
SERVER_O = $(SERVER_S:.c=.o)
CLIENT_O = $(CLIENT_S:.c=.o)
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra 

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_O)
	@$(CC) $(SERVER_O) -o $(SERVER)

$(CLIENT) : $(CLIENT_O)
	@$(CC) $(CLIENT_O) -o $(CLIENT)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(CLIENT_O) $(SERVER_O)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
