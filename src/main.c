/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/09/17 11:53:05 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	main(int ac, char **av)
{
	t_node	*a;
	// t_node	*b;
	
	a = NULL;
	// b = NULL;
	if (ac == 1 || (2 == ac && !av[1][0]))
		return (1);
	else if(2 == ac)
	{
		av = ft_split(av[1], ' ');
		init(&a, av, ac == 2);
	}	
	else
		init(&a, av + 1, ac == 2);
	tidex(&a, ft_listlen(a));
	if(!check_ord(a))
	{
			printf("s");
		if (ft_listlen(a) == 2)
		{
			
			// sa(&a);
			min(&a);
		}
		if(ft_listlen(a) == 3)
			tresnudos(&a);
			
	}
	print_list(a);
	free_list(a);
	
	return 0;
}
