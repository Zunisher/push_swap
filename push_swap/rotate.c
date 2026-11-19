/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:17:59 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/19 03:20:00 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = ftt_lstlast(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	return (1);
}

void	ra(t_stack **a, t_operations *operation)
{
	if (!rotate(a))
		return ;
	write(1, "ra\n", 3);
	operation->ra++;
}

void	rb(t_stack **b, t_operations *operation)
{
	if (!rotate(b))
		return ;
	write(1, "rb\n", 3);
	operation->rb++;
}

void	rr(t_stack **a, t_stack **b, t_operations *operation)
{
	int	moved;

	moved = rotate(a);
	moved |= rotate(b);
	if (!moved)
		return ;
	write(1, "rr\n", 3);
	operation->rr++;
}
