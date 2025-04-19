NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c ft_strlen.c ft_strrchr.c ft_strchr.c ft_memchr.c \
    ft_itoa.c ft_strdup.c ft_split.c ft_memcpy.c ft_memset.c \
    ft_calloc.c ft_isdigit.c ft_substr.c ft_tolower.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
    ft_atoi.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
