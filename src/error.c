#include "../inc/push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}
