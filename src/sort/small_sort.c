#include "../../inc/push_swap.h"

void	sort2(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}

void	sort3(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL)
		return ;
	if (stack_a->top->data < stack_a->top->next->data && stack_a->top->next->data < stack_a->top->next->next->data)
		return ;
	else if (stack_a->top->data > stack_a->top->next->data && stack_a->top->next->data < stack_a->top->next->next->data)
		sa(stack_a);
	else if (stack_a->top->data < stack_a->top->next->data && stack_a->top->next->data > stack_a->top->next->next->data)
		rra(stack_a);
	else if (stack_a->top->data > stack_a->top->next->data && stack_a->top->next->data > stack_a->top->next->next->data)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->top->next->data > stack_a->top->data && stack_a->top->next->data > stack_a->top->next->next->data))
		ra(stack_a);
}
