#include "../../inc/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b == NULL || stack_b->top == NULL)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	stack_b->size--;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
	stack_b->size++;
	stack_a->size--;
	ft_printf("pb\n");
}
