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
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
