/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/10/29 19:23:11 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (2 == ac && !av[1][0]))
	{
		write(2, "Error\n", 6);
		return (2);
	}
	else if (2 == ac)
		init(&a, av = ft_split(av[1], ' '), ac == 2);
	else
		init(&a, av + 1, ac == 2);
	n_idex(&a, ft_listlen(a));
	push_swap(&a, &b);
	free_list(a);
	return (0);
}
