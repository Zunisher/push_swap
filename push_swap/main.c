/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:01:46 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 21:17:43 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <threads.h>

int	main(int argc, char **argv)
{
	t_stack		**p;
	c_operations	*banch;

	if (argc < 2)
	    return (1);
	p = create_fill_struct(argc, argv);
	banch = ft_calloc(sizeof(banch), 1);
	if(parser(argv, banch) || !p)
	{
		ft_putstr_fd("Error", 1);
		return 1;
	}
	t_stack *b = ft_calloc(sizeof(t_stack), 4);
	disorder(p, &b, banch);
	return 0;
}
