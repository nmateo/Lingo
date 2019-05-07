##
## EPITECH PROJECT, 2019
## idk
## File description:
## idk
##

NAME	= lingo

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/utils.c \
	  ./src/utils2.c \
	  ./src/game.c \
	  ./src/parsing.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
