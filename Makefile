NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 
OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re : fclean all

.PHONY: all clean fclean re