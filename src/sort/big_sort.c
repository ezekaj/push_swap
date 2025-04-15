#include "../../inc/push_swap.h"

int	find_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	max = current->data;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	
}
