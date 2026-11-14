/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fill_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:32:09 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/13 20:45:43 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	ft_isintanse(char *argv, char t)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (argv[i] == t)
			return (1);
		i++;
	}
	return (0);
}

static int fill(t_stack **p, char **argv, int size)
{
    size_t i;

    i = 0;
    while (i < (size_t)size)
    {
        p[i] = ft_calloc(1, sizeof(t_stack));
        if (!p[i])
            return (0);
        p[i]->val = ft_atoi(argv[i]);
        if (i > 0)
        {
            p[i]->previous = p[i - 1];
            p[i - 1]->next = p[i];
        }
        i++;
    }
    return (1);
}

void free_split(char **split)
{
    int i;

    i = 0;
    if (!split)
        return ;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

static t_stack	**fill_split(char *arg)
{
	char	**split;
	t_stack	**p;
	size_t	size;

	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	size = 0;
	while (split[size])
		size++;
	p = ft_calloc(size, sizeof(t_stack *));
	if (!fill(p, split, size))
		return (free_split(split), NULL);
	free_split(split);
	return (p);
}

t_stack	**create_fill_struct(int argc, char **argv)
{
	size_t	i;
	size_t	size;
	t_stack	**p;

	i = non_flag(argv);
	if (i >= (size_t)argc)
		return (NULL);
	if (ft_isintanse(argv[i], ' '))
		return (fill_split(argv[i]));
	size = (argc - 1) - i;
	p = ft_calloc(size, sizeof(t_stack *));
	if (!p)
		return (NULL);
	if(!fill(p, &argv[++i], size))
		return (NULL);
	return (p);
}
