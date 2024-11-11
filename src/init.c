/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:42:07 by mabril            #+#    #+#             */
/*   Updated: 2024/10/30 20:52:06 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atolong(char *str)
{
	int		i;
	int		sig;
	long	n;

	n = 0;
	sig = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sig);
}

void	n_idex(t_node **head, int nd)
{
	int		i;
	t_node	*current;
	t_node	*tem;

	i = 1;
	while (0 < nd)
	{
		current = *head;
		while (current->indx != 0)
			current = current->next;
		tem = current->next;
		while (tem && tem != *head)
		{
			if (tem->indx == 0 && tem->num < current->num)
				current = tem;
			tem = tem->next;
		}
		current->indx = i++;
		nd--;
	}
}

void	init(t_node **head, char **av, bool flag_split)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (av[i])
	{
		if (error_syntax(av[i]) == 1)
			error_free(head, av, flag_split);
		nbr = ft_atolong(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || reppet(*head, nbr))
			error_free(head, av, flag_split);
		new_node(head, nbr);
		i++;
	}
	if (flag_split)
		free_av(av);
}

void	push_swap(t_node **head, t_node **b)
{
	float	nn;

	nn = ft_listlen(*head);
	while (!check_ord(*head) || *b != NULL)
	{
		while (!check_ord(*head))
		{
			if (ft_listlen(*head) == 2)
				sa(head);
			else if (ft_listlen(*head) == 3)
				trie_3(head);
			else if (ft_listlen(*head) <= 5)
				trie_5(head, b, nn);
			else
			{
				if (nn > 100)
					trie_radix(head, b, nn);
				else
					trie_bloque(head, b, nn);
			}
		}
		if (*b != NULL)
			pa(head, b);
	}
}
