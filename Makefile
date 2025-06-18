NAME = push_swap.a
EXEC = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libs/libft
PRINTF_PATH = libs/printf

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRC = src/main.c src/utils.c src/input_validation.c \
		src/operations/push.c src/operations/swap.c src/operations/rotate.c \
		src/operations/rev_rotate.c \
		src/sort/small_sort.c src/sort/big_sort.c src/error.c

OBJS = ${SRC:.c=.o}

all: ${LIBFT} ${PRINTF} ${NAME} ${EXEC}

${LIBFT}:
	make -C ${LIBFT_PATH}

${PRINTF}:
	make -C ${PRINTF_PATH}

${NAME}: ${OBJS}
	ar rcs $(NAME) ${OBJS}

${EXEC}: ${NAME}
	$(CC) $(CFLAGS) -o ${EXEC} ${OBJS} ${LIBFT} ${PRINTF}

clean:
	make -C ${LIBFT_PATH} clean
	make -C ${PRINTF_PATH} clean
	rm -f ${OBJS}

fclean: clean
	make -C ${LIBFT_PATH} fclean
	make -C ${PRINTF_PATH} fclean
	rm -f ${NAME}
	rm -f ${EXEC}

re: fclean all

.PHONY: all clean fclean re
