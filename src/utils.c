/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/10/18 19:35:55 by mabril           ###   ########.fr       */
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
		if(reppet(*head, nbr))
			error_reppet(head, av, flag_split);
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
	int nn;
	nn = ft_listlen(*head);
	while(!check_ord(*head) || *b != NULL)
	{
		while(!check_ord(*head))
		{
			if (ft_listlen(*head) == 5 || ft_listlen(*head) == 4)
				trie_5(head, b, nn);
			else if
				(ft_listlen(*head) == 3)
					trie_3(head);
			else if
				(ft_listlen(*head) == 2)
					trie_2(head);
		}
		if(*b != NULL)
			pa(head, b);
	}
}

void trie_5(t_node **head, t_node **b, int nn)
{
	t_node *tem;
	
	int pri;
	int prox;
	int ult;

	pri = (*head)->indx;
	prox =(*head)->next->indx;
	ult = (*head)->prev->indx;
	tem = (*head)->next;

	if(pri < prox && pri < ult)
		is_min_a( head, b, nn);
	else if(ult < pri && ult < prox)
	{
		if(ult + 1  == pri && ult < (nn/2))
			rra(head);
		else if(prox - 1 == ult)
			sa(head);
		else if (pri - 1 == ult && pri > (nn/2))
			ra(head);
		// else if(pri < prox)
		// 	sa(head);
		else 
			rra(head);
	}
	else if (pri > prox && pri > ult)
		ra(head);
	else if((prox < pri && prox < ult) )
	{
		if((pri == (ult +1) && prox+1 != ult ) || ((tem->next->indx)+1 == prox && prox < (nn/2)))
			ra(head);
		else
			sa(	head);
	}
	// print_list(*head);
}

void minimoa(t_node **head, t_node **b, int nn)
{	
	t_node *cola;
	int pri;
	int prox;
	int ult;
	int penul;

	cola = (*head)->prev;
	
	pri = (*head)->indx;
	prox =(*head)->next->indx;
	ult = (*head)->prev->indx;
	penul = cola->prev->indx;
	
	if(pri > ult && prox > ult && ult <= (nn / 2))
		rra(head);
	else if(penul < (nn / 2) && penul < pri && penul < ult )
		rra(head);
	else if(pri > prox && pri > ult)
	{
		if(ult < (nn / 2))
			rra(head);	
		if(pri > (nn / 2))
			ra(head);
	}
	else if(pri < prox && pri < ult)
	{
		if((pri +1) == ult)
			rra(head);
		else if(prox > ult)
		{
			if(prox > (nn / 2))
				sa(head);
		else if( ult < prox)
			rra(head);
		else if(pri < prox && pri < ult)
			pb(head, b);
		}
	else if(pri > prox  && prox < ult)
		sa(head);
	// if(ult < pri && ult < prox)
	// 	rra(head);
	}
}

void is_min_a(t_node **head, t_node **b, int nn)
{
	t_node *tem;

	tem = (*head)->next;
	while((*head)->next)
		{
			if(tem == (*head))
			{
				if((*head)->next->indx > (*head)->prev->indx && ((*head)->next->indx > (nn / 2)) && (*head)->indx >(nn / 2))
					sa(head);
				else if((*head)->prev->indx - 1 == (*head)->indx && (*head)->next->indx - 1 == (*head)->prev->indx)
					rra(head);
				else	
					pb(head, b);
				break;
			}
			else if((*head)->indx > tem->indx)
			{
				if((*head)->prev->indx - 1 == (*head)->indx)
					rra(head);
				else
					ra(head);
				break;
			}
			tem = tem->next;
		}
}

// void print_list(t_node *head)
// {
// 	t_node *current;

// 	current = head;
// 	while (head)
// 	{		
// 		printf("   |  %d   |   ", current->num);
// 		current = current->next;
// 		if (current == head)
// 			break;
// 	}
// 	current = head;
// 		printf("\n");
// 	while (head)
// 	{		
// 		printf("      %d       ",current->indx) ;
// 		current = current->next;
// 		if (current == head)
// 			break;
// 	}
// 	printf("\n");
// }

// void two_n_b(t_node **b)
// {
//     t_node *last;

//     if (!b || !(*b) || !(*b)->next)
// 	   	return;
// 	last = (*b)->next;
//     *b = last;
// }

// while((*head)->next)
		// {
		// 	if((*head)->indx < tem->indx)
		// 		tem = tem->next;
		// 	else
		// 	{
		// 		ra(head);
		// 		break;
		// 	}
		// 	if(tem == (*head))
		// 	{
		// 		if(prox == (ult + 1))
		// 			sa(head);
		// 		else if(ult - 1 == pri)
		// 			rra(head);
		// 		else	
		// 			pb(head, b);
		// 		break;
		// 	}
		// }