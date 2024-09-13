/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/09/13 18:56:49 by mabril           ###   ########.fr       */
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

void	init( t_node **head, char **av, bool flag_split)
{
	long nbr;
	int i;

	i = 0;
	nbr = 0;
	while (av[i])
	{
		if(error_syntax(av[i]) == 1)
			error_free(head, av, flag_split);
		nbr = ft_atolong(av[i]);
		
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(head, av, flag_split);
		new_node(head,nbr);
		i++;	
	}
	if(flag_split)
		free_av(av);
}

void	new_node(t_node **head, int num)
{
	t_node	*node;
	t_node	*last;
	
	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return;
	node->num = num;
	node->indx = 0;
	//si head  no existe head apunta a nodo
	if(*head == NULL)
	{
		*head = node;
		node->next = *head;
		node->prev = *head;
	}
	else
	{ 
		last = (*head)->prev;
		last->next = node;
		node->prev = last;
		node->next = *head;
		(*head)->prev = node;
	}
}
void print_list(t_node *head)
{
	t_node *current;

	current = head;
	while (head)
	{		
		printf("   | %d|   %d   |%d    ", current->prev->num,current->num, 
		current->next->num);
		current = current->next;
		if (current == head)
			break;
	}
	current = head;
		printf("\n");
	while (head)
	{		
		printf("           %d          ",current->indx) ;
		current = current->next;
		if (current == head)
			break;
	}
	printf("\n");
}

void free_list(t_node *head)
{
	t_node *current = head->prev;
	head->prev = NULL;
	current->next = NULL;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

void tidex(t_node **head, int nd)
{
	int i;
	t_node *current;
	t_node *tem;
	
	i = 1;
	while(0 < nd)
	{	
		current = *head;
		while (current->indx != 0 )
			current = current->next;
		tem = current->next;
		while(tem && tem != *head)
		{
			if(tem->indx == 0 && tem->num < current->num)
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

void free_av(char **av)
{
	int i;
	
	i=0;
	while(av[i])
		free(av[i++]);
	free(av);
}
bool check_ord(t_node *head)
{
	if
}