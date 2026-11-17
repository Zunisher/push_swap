/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:01:46 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/17 21:33:26 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			**p;
	t_stack			*b;
	t_operations	*bench;

	if (argc < 2)
		return (1);
	p = create_fill_struct(argc, argv);
	bench = ft_calloc(1, sizeof(*bench));
	if (!p || !bench)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (parser(argv, bench))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	b = NULL;
	disorder(p, &b, bench);
	return (0);
}
