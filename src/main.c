/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/09/12 07:13:56 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	main(int ac, char **av)
{
	t_node	*a;
	// t_node	*b;
	
	a = NULL;
	// b = NULL;
	if (ac != 2 && !av[1])
		return (1);
	else
	{
		init(&a, av = ft_split(av[1], ' '));
		
	}
	
	tidex(&a, ft_listlen(a));
	print_list(a);
	free_list(a);
	
	return 0;
}
