/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/09/25 10:13:53 by mike             ###   ########.fr       */
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
		if(!reppet(*head, nbr))
			new_node(head,nbr);
		i++;	
	}
	if(flag_split)
		free_av(av);
}

bool reppet(t_node *head, long nbr)
{
	t_node *current;

	current = head;
	while(current != NULL)
	{
		if(current->num == nbr)
			return (true);
		current = current->next;
		if(current ==  head)
			break;
	}
	return (false);
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
		printf("   |  %d   |   ", current->num);
		current = current->next;
		if (current == head)
			break;
	}
	current = head;
		printf("\n");
	while (head)
	{		
		printf("      %d       ",current->indx) ;
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
	t_node *current;

	current = head;
	if(!head)
		return (1);
	while(current->next && current->next != head)
	{
		if(current->indx > current->next->indx)
			return (false);
		current = current->next;
	}
	return(true);
}
void push_swap(t_node **head, t_node **b)
{
	// t_node *current;
	// int i;
	int nn;

	// i = 0; 
	nn = ft_listlen(*head);
	while(!check_ord(*head) || *b != NULL)
	{
	
		while(!check_ord(*head))
		{
			if(minimoa(*head, nn) == 5)
				ra(head);
			else if(minimoa(*head, nn) == 3)
				rra(head);
			else if(minimoa(*head, nn) == 2 || minimoa(*head, nn) == 4)
				sa(head);
			else if(minimoa(*head, nn) == 1)
				pb(head, b);
			if(ft_listlen(*head) == 3)
				tresnudos(head);
			print_list(*head);
		}
		if(*b != NULL)
			pa(head, b);
	}
}

		


int minimoa(t_node *head, int nn)
{	
	t_node *cola;
	int pri;
	int prox;
	int ult;
	int penul;

	cola = head->prev;
	
	pri =head->indx;
	prox =head->next->indx;
	ult =head->prev->indx;
	penul = cola->prev->indx;
	
	if(penul < (nn / 2) && penul < pri && penul < ult )
		return(3);
	if(pri > prox && pri > ult)
	{
		if(ult < (nn / 2))
			return (3);	
		if(pri > (nn / 2))
			return(5);
	}
	if(pri < prox && pri < ult)
	{
		if((pri +1) == ult)
			return(3);
		if(prox > ult)
			if(prox > (nn / 2))
				return(4);
		if( ult < prox)
			return(3);
		return(1);
	}
	if(prox < pri && pri < ult)
		return(2);
	if(ult < pri && ult < prox)
		return(3);
	// if(head->prev->indx head->indx > head->next->indx && head->next->indx > )
	// 	return(3);
		
	return(0);
}

void two_n_b(t_node **b)
{
    t_node *last;

    if (!b || !(*b) || !(*b)->next)
	   	return;
	last = (*b)->next;
    *b = last;
}