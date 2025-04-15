#include "../../inc/push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	min = current->data;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

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
	else if (stack_a->top->next->data > stack_a->top->data && stack_a->top->next->data > stack_a->top->next->next->data)
		ra(stack_a);
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL || stack_a->top->next->next->next == NULL)
		return ;
	if (find_min_pos(stack_a) == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 3)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 0)
		pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL || stack_a->top->next->next->next == NULL || stack_a->top->next->next->next->next == NULL)
		return ;
	if (find_min_pos(stack_a) == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (find_min_pos(stack_a) == 0)
		pb(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
