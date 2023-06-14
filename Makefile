# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 18:06:34 by mohtakra          #+#    #+#              #
#    Updated: 2023/06/14 22:54:36 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
CFLAGS=-Wall -Wextra -Werror -pthread -fsanitize=thread -g -O1
RM=rm -f
PARSINGPATH=./parsing/utils/
PHILOUTILS=./philo_utils/

SRC = philo.c ./list/ft_lstadd_back.c ./list/ft_lstadd_front.c\
	./list/ft_lstlast.c \
	./list/ft_lstclear.c ./list/ft_lstdelone.c \
	./list/ft_lstnew.c ./list/ft_lstsize.c\
	$(PARSINGPATH)../is_valid_parsing.c $(PARSINGPATH)is_only_digits.c \
	$(PARSINGPATH)is_valid_nbr_args.c $(PARSINGPATH)is_accepted_int.c \
	$(PHILOUTILS)eat_sleep_think.c $(PHILOUTILS)del.c\
	$(PHILOUTILS)ft_atoi.c $(PHILOUTILS)ft_usleep.c\
	$(PHILOUTILS)print_state.c $(PHILOUTILS)right_now.c\
	$(PHILOUTILS)set_mutual_data.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) -fsanitize=thread -o $@ $(SRC:.c=.o)
		@echo "the files has ben archived successfully"

%.o: %.c ./libstructs.h ./libphilo.h ./parsing/libparsing.h
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