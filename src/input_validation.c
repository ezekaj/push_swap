/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 12:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_safe(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		error_exit();
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		error_exit();
	return ((int)result);
}

int	validate_input(char **input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		if (!is_valid_number(input[i]))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

void	populate_stack(t_stack *stack, char **input)
{
	int	i;
	int	value;

	i = 0;
	while (input[i])
		i++;
	i--;
	while (i >= 0)
	{
		value = ft_atoi_safe(input[i]);
		push_node(stack, value);
		i--;
	}
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->data == check->data)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
