/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:15:35 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/19 03:20:00 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->previous = tmp;
	tmp->previous = NULL;
	*dst = tmp;
	return (1);
}

void	pa(t_stack **a, t_stack **b, t_operations *p)
{
	if (!push(b, a))
		return ;
	write(1, "pa\n", 3);
	p->pa++;
}

void	pb(t_stack **a, t_stack **b, t_operations *p)
{
	if (!push(a, b))
		return ;
	write(1, "pb\n", 3);
	p->pb++;
}
