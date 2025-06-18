/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:14:13 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/19 12:25:09 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Stacks
t_stack		*init_stack(void);
void		push_node(t_stack *stack, int value);

// Input
char		**parse_input(int ac, char **av);

// Error handling
void		error_exit(void);
void		free_stack(t_stack *stack);
void		free_stacks_and_exit(t_stack *stack_a, t_stack *stack_b);

// Operations
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		swap(t_stack *stack);
void		sa(t_stack *stack_b);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rev_rotate(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

// Small Sort
int			find_min_pos(t_stack *stack);
int			find_max_pos(t_stack *stack);
void		sort2(t_stack *stack_a);
void		sort3(t_stack *stack_a);
void		sort4(t_stack *stack_a, t_stack *stack_b);
void		sort5(t_stack *stack_a, t_stack *stack_b);
void		sort_big(t_stack *stack_a, t_stack *stack_b);

#endif
