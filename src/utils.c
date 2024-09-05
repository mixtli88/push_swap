/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/09/05 12:18:03 by mabril           ###   ########.fr       */
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

void	init(t_node **head, char **av)
{
	long nbr;
	int i;

	i = 0;
	while (av[i])
	{
		nbr = ft_atolong(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit(EXIT_FAILURE);

		new_node(head,(int)nbr);
		i++;	
	}
}

void	new_node(t_node **head, int num)
{
	t_node	*node;
	t_node	*tem;

	node = ft_calloc(1, sizeof(t_node));
	tem = ft_calloc(1, sizeof(t_node));
	tem = *head;
	
	node->num = num;
	node->next = NULL;
	
	if(*head == NULL)
	{
		*head = node;
	}
	else
	{
		while(tem->next)
		{
			tem = tem->next;
		// printf("num tem-next= %d\n ", tem->num);
		}
		
		tem->next = node;
	}
		// printf("num = %d\n ", node->num);
	// free(tem);
}
void print_list(t_node *head)
{
	int count = 1;
	while (head)
	{
		printf("\nTotal nodos: %d\n", count);
		printf("%d ", head->num);
		head = head->next;
		count++;
	}
}

void free_list(t_node *head)
{
	while (head)
	{
		t_node *next = head->next;
		free(head);
		head = next;
	}
}