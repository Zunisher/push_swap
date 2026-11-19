/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:12:23 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/19 03:20:00 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	first->previous = second;
	*stack = second;
	return (1);
}

void	sa(t_stack **a, t_operations *operation)
{
	if (!swap(a))
		return ;
	write(1, "sa\n", 3);
	operation->sa++;
}

void	sb(t_stack **b, t_operations *operation)
{
	if (!swap(b))
		return ;
	write(1, "sb\n", 3);
	operation->sb++;
}

void	ss(t_stack **a, t_stack **b, t_operations *operation)
{
	int	moved;

	moved = swap(a);
	moved |= swap(b);
	if (!moved)
		return ;
	write(1, "ss\n", 3);
	operation->ss++;
}
