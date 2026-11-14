/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:39:28 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 20:01:25 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float compute_disorder(t_stack *stack)
{
    int     mistakes;
    int     total_pairs;
    t_stack  *comper;
    t_stack  *corent;

    mistakes = 0;
    total_pairs = 0;
    corent = stack;
    while (corent)
    {
        comper = corent->next;
        while (comper)
        {
            total_pairs++;
            if (corent->val > comper->val)
                mistakes++;
            comper = comper->next;
        }
        corent = corent->next;
    }
    if (total_pairs == 0)
        return (0);
    return ((float)mistakes / total_pairs);
}

void	disorder(t_stack **stack, t_stack **b, c_operations *p)
{
    double disorder;

    if (p->simple)
        simple_sort(stack, b, p);
    else if (p->medium)
        medium_sort(stack, b, p);
    else if (p->comple)
        difficult_sort(stack, b, p);
    else
    {
        disorder = compute_disorder(*stack);
        if (disorder < 0.2)
            simple_sort(stack, b, p);
        else if (disorder < 0.5)
            medium_sort(stack, b, p);
        else
            difficult_sort(stack, b, p);
    }
}
