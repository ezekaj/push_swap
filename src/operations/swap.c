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

void	sb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b == NULL || stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_b->top->next;
	stack_b->top->next = temp;
	ft_printf("sb\n");
}
