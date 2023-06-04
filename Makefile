# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 18:06:34 by mohtakra          #+#    #+#              #
#    Updated: 2023/06/03 15:08:15 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
LIB= LIB.a
CFLAGS= -Wall -Wextra -Werror -pthread
RM=rm -f
PARSINGPATH=./parsing/parsing_utils/

SRC = philo.c ./list/ft_lstadd_back.c ./list/ft_lstadd_front.c\
	./list/ft_lstlast.c \
	./list/ft_lstclear.c ./list/ft_lstdelone.c \
	./list/ft_lstnew.c ./list/ft_lstsize.c


OBJ = $(SRC:.c=.o)
OBJPARSING = $(SRCPARSING:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -o $@ $(SRC:.c=.o)
		@echo "the files has ben archived successfully"

%.o: %.c ./libphilo.h
		@$(CC) $(CFLAGS) -o $@ -c $<
		@echo "the file $@ has been created from $<"
		
clean:
		@$(RM) $(OBJ) $(LIB)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the library has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re