/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/09/05 12:18:11 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	// char **split_result = ft_split("223 54 675 676 5", ' ');
	// int i = 0;
	
	a = NULL;
	b = NULL;
	if (ac != 2 && !av[1])
		return (1);
	else
	{
		init(&a, (av =ft_split(av[1], ' ')));
	
		//  para depurar si split funciona 
		// while (av[i])
		// {
		// 	printf("Token %d: %s\n", i, av[i]);
		// 	i++;
		// }
	}
	print_list(a);
	// free_list(a);
	return 0;
}
