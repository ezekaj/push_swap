/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:13:26 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/19 12:25:01 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

char	**parse_input(int ac, char **av)
{
	char	**input;

	if (ac == 1)
		return (NULL);
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		if (!input)
			return (NULL);
	}
	else
		input = av + 1;
	return (input);
}

void	push_node(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit();
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
