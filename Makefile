NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libs/libft
PRINTF_PATH = libs/printf

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRC = src/main.c src/utils.c src/operations/push.c \
		src/operations/swap.c src/operations/rotate.c \
		src/sort/small_sort.c src/sort/big_sort.c src/error.c

OBJS = ${SRC:.c=.o}

all: ${LIBFT} ${PRINTF} ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH}

${PRINTF}:
	make -C ${PRINTF_PATH}

${NAME}: ${OBJS}
	ar rcs $(NAME) ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} ${LIBFT} ${PRINTF} -o push_swap

clean:
	make -C ${LIBFT_PATH} clean
	make -C ${PRINTF_PATH} clean
	rm -f ${OBJS}

fclean: clean
	make -C ${LIBFT_PATH} fclean
	make -C ${PRINTF_PATH} fclean
	rm -f ${NAME}
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re
