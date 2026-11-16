/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:21:40 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 21:12:53 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ftt_lstlast(*stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *stack;
	(*stack)->previous = last;
	*stack = last;
}

void	rra(t_stack **a, c_operations *operation)
{
	reverse_rotate(a);
	if (operation->print)
		write(1, "rra\n", 4);
	else
		operation->rra++;
}

void	rrb(t_stack **b, c_operations *operation)
{
	reverse_rotate(b);
	if (operation->print)
		write(1, "rrb\n", 4);
	else
		operation->rrb++;
}

void	rrr(t_stack **a, t_stack **b, c_operations *operation)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (operation->print)
		write(1, "rrr\n", 4);
	else
		operation->rrr++;
}
