# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 15:12:45 by jkiragu           #+#    #+#              #
#    Updated: 2022/11/03 15:13:50 by jkiragu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client 

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

HEADER = ./minitalk.h 

SRC = utils.c
SRC_S = server.c
SRC_C = client.c 

OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_S = $(patsubst %.c,%.o,$(SRC_S))
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))

all:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):		$(OBJ) $(OBJ_S)
		  $(CC)	  $(FLAGS) $(OBJ) $(OBJ_S) -o $(SERVER_NAME)

$(CLIENT_NAME):		$(OBJ) $(OBJ_C)
		  $(CC)   $(FLAGS) $(OBJ) $(OBJ_C) -o $(CLIENT_NAME)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_S) $(OBJ_C)

fclean: clean
	$(RM) server client

re: fclean all

.PHONY:	all clean fclean re