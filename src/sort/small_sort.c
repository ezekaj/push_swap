/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:12:03 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/19 12:27:22 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	a;
	int	b;
	int	c;

	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL
		|| stack_a->top->next->next == NULL)
		return ;
	a = stack_a->top->data;
	b = stack_a->top->next->data;
	c = stack_a->top->next->next->data;
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_a->top || !stack_a->top->next
		|| !stack_a->top->next->next || !stack_a->top->next->next->next)
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
	if (!stack_a || !stack_b || !stack_a->top || !stack_a->top->next
		|| !stack_a->top->next->next || !stack_a->top->next->next->next
		|| !stack_a->top->next->next->next->next)
		return ;
	if (find_min_pos(stack_a) == 1)
		sa(stack_a);
	else if (find_min_pos(stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (find_min_pos(stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min_pos(stack_a) == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
