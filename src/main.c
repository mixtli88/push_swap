/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/09/11 12:23:25 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	main(int ac, char **av)
{
	t_node	*a;
	// t_node	*b;
	int i;
	i = 0;
	a = NULL;
	// b = NULL;
	if (ac != 2 && !av[1])
		return (1);
	else
		init(&a, av = ft_split(av[1], ' '));
	
	tidex(&a, ft_listlen(a));
	print_list(a);
	free_list(a);
	
	return 0;
}
