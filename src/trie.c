/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:54:21 by mabril            #+#    #+#             */
/*   Updated: 2024/10/28 19:49:41 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	trie_3(t_node **head)
{
	t_node	*last;
	t_node	*second;

	if (!head || !(*head) || !(*head)->next)
		return ;
	while (!check_ord(*head))
	{
		last = (*head)->prev;
		second = (*head)->next;
		if ((*head)->indx > last->indx && (*head)->indx > second->indx)
			ra(head);
		else if (last->indx < (*head)->indx && last->indx < second->indx)
			rra(head);
		else
			sa(head);
	}
}

void	trie_5(t_node **head, t_node **b, int nn)
{
	if ((*head)->indx < (*head)->next->indx
		&& (*head)->indx < (*head)->prev->indx)
	{
		if (top_is_min_a(*head) == 1)
			head_is_min_a(head, b, nn);
		else
			head_not_min_a(head, nn);
	}
	else if ((*head)->prev->indx < (*head)->indx
		&& (*head)->prev->indx < (*head)->next->indx)
		last_node_is_min_a(head, nn);
	else if (((*head)->next->indx < (*head)->indx
			&& (*head)->next->indx < (*head)->prev->indx))
		next_node_is_min_a(head, nn);
	else if ((*head)->indx > (*head)->next->indx
		&& (*head)->indx > (*head)->prev->indx)
		ra(head);
}

void	trie_radix(t_node **head, t_node **b, int nn)
{
	int	i;
	int	j;
	int	max_bits;

	max_bits = 0;
	while ((nn >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits && !check_ord(*head))
	{
		j = 0;
		while (j < nn)
		{
			if ((((*head)->indx >> i) & 1))
				ra(head);
			else
				pb(head, b);
			j++;
		}
		while (*b)
			pa(head, b);
		i++;
	}
}

void	trie_bloque(t_node **head, t_node **b, int nn)
{
	int	max_node;

	push_block_to_b(head, b, nn);
	while (*b)
	{
		max_node = find_max_node(*b);
		move_to_top(b, max_node);
		pa(head, b);
	}
}
