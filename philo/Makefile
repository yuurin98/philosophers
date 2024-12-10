CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = main.c
OBJS = $(SRCS:.c=.o)

NAME = philo

INCLUDE = philo.h

all : $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :		
			rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)
			
re : fclean all

.PHONY : all clean fclean re