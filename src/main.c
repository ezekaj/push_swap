/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:13:19 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/19 12:13:20 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort2(stack_a);
	else if (stack_a->size == 3)
		sort3(stack_a);
	else if (stack_a->size == 4)
		sort4(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort5(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char		**input;
	t_stack		*stack_a;
	t_stack		*stack_b;

	input = parse_input(ac, av);
	if (!input)
		return (0);
	if (!validate_input(input))
		error_exit();
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		error_exit();
	populate_stack(stack_a, input);
	if (has_duplicates(stack_a))
		error_exit();
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	choose_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
