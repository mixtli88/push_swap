/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/09/03 17:41:12 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	msg_error(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	exit(EXIT_FAILURE);
}

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
	while (str[i] == '+' || str[i] == '-')
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

void	init(t_node **head, char *av)
{
	long nbr;
	int i;

	i = 0;
	while (av[i])
	{
		nbr = ft_atolong(&av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			// free()
			exit(EXIT_FAILURE);
		}
		new_node(head,(int)nbr);
		i++;		
	}
}

void	new_node(t_node **head, int num)
{
	t_node	*node;
	// t_node	*ult_node;

	node = ft_calloc(1, sizeof(t_node));
	if (!head)
	{
		// free()
		exit(EXIT_FAILURE);
	}
	node->num = num;
	node->sig = NULL;
	if(*head == NULL)
	{
		*head = node;
		node->prev = NULL;
	}
}
void print_list(t_node *head)
{
	while (head)
	{
		printf("%d ", head->num);
		head = head->sig;
	}
	printf("\n");
}

void free_list(t_node *head)
{
	while (head)
	{
		t_node *next = head->sig;
		free(head);
		head = next;
	}
}