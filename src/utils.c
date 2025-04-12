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
	input = ft_split(av[1], ' ');
	if (!input)
		return (NULL);
	return (input);
}
