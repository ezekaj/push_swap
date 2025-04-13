#include "../../inc/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*temp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = stack->top->next;
	stack->top->next = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
