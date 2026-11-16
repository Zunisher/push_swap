/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:12:23 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 20:31:54 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	first->previous = second;
	*stack = second;
}

void	sa(t_stack **a, c_operations *operation)
{
	swap(a);
	if (operation->print)
		write(1, "sa\n", 3);
	else
		operation->sa++;
}

void	sb(t_stack **b, c_operations *operation)
{
	swap(b);
	if (operation->print)
		write(1, "sb\n", 3);
	else
		operation->sb++;
}

void	ss(t_stack **a, t_stack **b, c_operations *operation)
{
	swap(a);
	swap(b);
	if (operation->print)
		write(1, "ss\n", 3);
	else
		operation->ss++;
}
