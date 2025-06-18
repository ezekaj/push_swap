/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:12:21 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/19 12:15:07 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	if (stack == NULL || stack->top == NULL)
		return (0);
	current = stack->top;
	max = current->data;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

void	mm_values(t_stack *stack_a)
{
	int	min;
	int	max;

	min = find_min_pos(stack_a);
	max = find_max_pos(stack_a);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	pushed;
	int	total_size;

	if (!stack_a || !stack_b || stack_a->size <= 5)
		return ;
	total_size = stack_a->size;
	chunk_size = total_size / 5;
	if (chunk_size < 15)
		chunk_size = 15;
	pushed = 0;
	while (stack_a->size > 3 && pushed < total_size - 3)
	{
		if (stack_a->top->data <= (total_size / 2))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	sort3(stack_a);
	while (stack_b->size > 0)
	{
		pushed = find_max_pos(stack_b);
		while (pushed-- > 0)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
}
