#include "../../inc/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack->top;
	stack->top = stack->top->next;
	tmp->next->next = NULL;
}
