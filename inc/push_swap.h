#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
char	**parse_input(int ac, char **av);
void	error_exit(void);

# endif
