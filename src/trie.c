/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:54:21 by mabril            #+#    #+#             */
/*   Updated: 2024/10/22 18:26:00 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	trie_3(t_node **head)
{
	t_node	*last;
	t_node	*two;

	if (!head || !(*head) || !(*head)->next)
		return ;
	while (!check_ord(*head))
	{
		last = (*head)->prev;
		two = (*head)->next;
		if ((*head)->indx > last->indx && (*head)->indx > two->indx)
			ra(head);
		else if (last->indx < (*head)->indx)
			rra(head);
		else
			sa(head);
	}
}

void	trie_5(t_node **head, t_node **b, int nn)
{
	t_node	*tem;

	tem = (*head)->next;
	if ((*head)->indx < (*head)->next->indx
		&& (*head)->indx < (*head)->prev->indx)
	{
		if (top_is_min_a(*head) == 1)
			head_is_min_a(head, b, nn);
		else
			head_not_min_a(head);
	}
	else if ((*head)->prev->indx < (*head)->indx
		&& (*head)->prev->indx < (*head)->next->indx)
		last_node_is_min_a(head, nn);
	else if ((*head)->indx > (*head)->next->indx
		&& (*head)->indx > (*head)->prev->indx)
		ra(head);
	else if (((*head)->next->indx < (*head)->indx
			&& (*head)->next->indx < (*head)->prev->indx))
		next_node_is_min_a(head, nn);
}