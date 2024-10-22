/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/10/22 18:14:06 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	new_node(t_node **head, int num)
{
	t_node	*node;
	t_node	*last;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return ;
	node->num = num;
	node->indx = 0;
	if (*head == NULL)
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

bool	reppet(t_node *head, long nbr)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->num == nbr)
			return (true);
		current = current->next;
		if (current == head)
			break ;
	}
	return (false);
}

int	ft_listlen(t_node *head)
{
	int		lst_len;
	t_node	*current;

	lst_len = 0;
	current = head;
	while (current)
	{
		current = current->next;
		lst_len++;
		if (current == head)
			break ;
	}
	return (lst_len);
}

bool	check_ord(t_node *head)
{
	t_node	*current;

	current = head;
	if (!head)
		return (1);
	while (current->next && current->next != head)
	{
		if (current->indx > current->next->indx)
			return (false);
		current = current->next;
	}
	return (true);
}

int	top_is_min_a(t_node *head)
{
	t_node	*tem;

	tem = head->next;
	while (tem != head)
	{
		if (head->indx > tem->indx)
			return (0);
		tem = tem->next;
	}
	return (1);
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
// 			break ;
// 	}
// 	current = head;
// 		printf("\n");
// 	while (head)
// 	{
// 		printf("      %d       ",current->indx) ;
// 		current = current->next;
// 		if (current == head)
// 			break ;
// 	}
// 	printf("\n");
// }
