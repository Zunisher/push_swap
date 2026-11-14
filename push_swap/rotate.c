/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:17:59 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 21:11:04 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ftt_lstlast(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	ra(t_stack **a, c_operations *operation)
{
	rotate(a);
	if (operation->print)
		write(1, "ra\n", 3);
	else
		operation->ra++;
}

void	rb(t_stack **b, c_operations *operation)
{
	rotate(b);
	if (operation->print)
		write(1, "rb\n", 3);
	else
		operation->rb++;
}

void	rr(t_stack **a, t_stack **b, c_operations *operation)
{
	rotate(a);
	rotate(b);
	if (operation->print)
		write(1, "rr\n", 3);
	else
		operation->rr++;
}
