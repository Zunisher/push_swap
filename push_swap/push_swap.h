/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:47:23 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 21:11:28 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_swap
{
	int	val;
	int	index;
	struct s_swap	*next;
	struct s_swap	*previous;
}	t_stack;

typedef struct s_operation
{
	int	medium;
	int	simple;
	int	comple;
	int	print;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	rr;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rrr;
}	c_operations;

void	sa(t_stack**stack, c_operations *p);
void	sb(t_stack **stack, c_operations *p);
void	ss(t_stack **b, t_stack **a, c_operations *p);
void	pa(t_stack **a, t_stack **b, c_operations *p);
void	pb(t_stack **a, t_stack **b, c_operations *p);
void	ra(t_stack **a, c_operations *p);
void	rb(t_stack **b, c_operations *p);
void	rr(t_stack **a, t_stack **b, c_operations *p);
void	rra(t_stack **a, c_operations *p);
void	rrb(t_stack **b, c_operations *p);
void	rrr(t_stack **a, t_stack **b, c_operations *p);
int	is_sorted(t_stack *lst);
t_stack	**create_fill_struct (int argc, char **argv);
int     parser(char **argv, c_operations *p);
int non_flag(char **argv);
void    sorting_chunk(t_stack **stack_a, t_stack **stack_b, c_operations *p);
int     ft_sqrt(int nbr);
int     find_next_position(t_stack *stack);
void    pushing_back_to_a(t_stack **stack_a, t_stack **stack_b, c_operations *p);
void	disorder(t_stack **stack, t_stack **b, c_operations *p);
int     is_sorted(t_stack *lst);
void    simple_sort(t_stack **a, t_stack **b, c_operations *p);
void	difficult_sort(t_stack **stack, t_stack **b, c_operations *p);
void	medium_sort(t_stack **stack, t_stack **b, c_operations *p);
int stack_size(t_stack *stack);
t_stack *ftt_lstlast(t_stack *lst);

#endif
