NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/utils.c srcs/operations/push.c \
       srcs/operations/swap.c srcs/operations/rotate.c \
       srcs/sort/small_sort.c

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