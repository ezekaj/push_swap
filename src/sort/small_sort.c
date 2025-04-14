#include "../../inc/push_swap.h"

void	sort2(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}
