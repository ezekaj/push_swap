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

// Stacks
t_stack	*init_stack(void);

// Input
char	**parse_input(int ac, char **av);

// Error handling
void	error_exit(void);
void	free_stack(t_stack *stack);
void	free_stacks_and_exit(t_stack *stack_a, t_stack *stack_b);

// Operations
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_b);
void	sb(t_stack *stack_b);

# endif
