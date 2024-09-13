/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:03 by mabril            #+#    #+#             */
/*   Updated: 2024/09/13 18:57:53 by mabril           ###   ########.fr       */
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
		return (1);
	else if(2 == ac)
	{
		av = ft_split(av[1], ' ');
		init(&a, av, ac == 2);
	}	
	else
		init(&a, av + 1, ac == 2);
	if(!check_ord(a))
	{
		if (ft_listlen == 2)
			sa(&a,)
	}
	tidex(&a, ft_listlen(a));
	print_list(a);
	free_list(a);
	
	return 0;
}
