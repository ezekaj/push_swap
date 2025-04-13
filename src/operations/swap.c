#include "../../inc/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_a->top->next;
	stack_a->top->next = temp;
	ft_printf("sa\n");
}
