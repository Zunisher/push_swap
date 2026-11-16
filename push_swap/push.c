/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:15:35 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 20:35:06 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->previous = tmp;
	tmp->previous = NULL;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b, c_operations *p)
{
	push(b, a);
	if (p->print)
		write(1, "pa\n", 3);
	else
		p->pa++;
}

void	pb(t_stack **a, t_stack **b, c_operations *p)
{
	push(a, b);
	if (p->print)
		write(1, "pb\n", 3);
	else
		p->pb++;
}
