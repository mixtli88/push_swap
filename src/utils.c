/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/09/10 22:30:17 by mabril           ###   ########.fr       */
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
	t_node	*last;
	node = ft_calloc(1, sizeof(t_node));
	
	node->num = num;
	node->next = *head;
	
	
	if(*head == NULL)
	{
		*head = node;
		node->prev = *head;
	}
	else
	{
		last = (*head)->prev;
		last->next = node;
		node->prev = last;
		(*head)->prev = node;
	}
}
void print_list(t_node *head)
{
	int count = 1;
	t_node *current;
	current = head;
	while (1)
	{		
		printf("***<- %d| %d - %d |%d -> *** ", current->prev->num,current->num,current->indx, current->next->num);
		current = current->next;
		count++;
		if (current == head)
			break;
	}
}

void free_list(t_node *head)
{
	t_node *next = head->next;
	
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void tidex(t_node **head, int nd)
{
	int i;
	t_node *current;
	t_node *tem;
	
	i = 1;
	current = *head;
	while(0 < nd)
	{
		current = *head;
		while (current->indx)
			current = current->next;
		tem = current->next;
		while(tem != *head)
		{
			while (tem->indx)
				tem = tem->next;
			if(tem->num < current->num )
				current = tem;
			tem = tem->next;
		}		
		current->indx = i++;
		nd--;
	}

}

int ft_listlen(t_node *head)
{
	int lst_len = 0;
	t_node *current; 
	
	current = head;
	while (current)
	{
		current = current->next;
		lst_len++;
		if (current == head)
			break;
	}
	return (lst_len);
}