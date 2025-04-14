#include "../../inc/push_swap.h"

void	rev_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*sec_last;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	tmp = stack->top;
	sec_last = NULL;
	while (tmp->next)
	{
		sec_last = tmp;
		tmp = tmp->next;
	}
	sec_last->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	rra(t_stack *stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
