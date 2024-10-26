/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:54:21 by mabril            #+#    #+#             */
/*   Updated: 2024/10/25 20:07:45 by mabril           ###   ########.fr       */
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
	t_node	*tem;

	tem = (*head)->next;
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
	int		i;
	int		j;
	int		max_bits;
	int		len_b;
	// int		bit;
	// t_node	*tem;

	max_bits = 0;
	// tem= (*head);
	while ((nn >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits && !check_ord(*head))
	{
		j = 0;
		// while (*head)
		// {
		// 	printf("%d\n", tem->indx);
		// 	tem = tem->next;
		// 	if (tem == *head)
		// 		break;
		// }
		while (j < nn)
		{
			// bit = (((*head)->indx >> 3) & 1);
			// printf("%d ", bit);
			// bit = (((*head)->indx >> 2) & 1);
			// printf("%d ", bit);
			// bit = (((*head)->indx >> 1) & 1);
			// printf("%d ", bit);
			// bit = (((*head)->indx >> 0) & 1);
			// printf("%d\n ", bit);
			if ((((*head)->indx >> i) & 1))
				ra(head);
			else
				pb(head, b);
			j++;
		}
		j = 0;
		len_b = ft_listlen(*b);
		while (j < len_b)
		{
			// tem = (*b);
			// while (*b)
			// {
			// 	printf("%d\n  ", tem->indx);
			// 	tem = tem->next;
			// 	if (tem == *b)
			// 		break;
			// }
			// bit = (((*b)->indx >> 3) & 1);
			// printf("%d ", bit);
			// bit = (((*b)->indx >> 2) & 1);
			// printf("%d ", bit);
			// bit = (((*b)->indx >> 1) & 1);
			// printf("%d ", bit);
			// bit = (((*b)->indx >> 0) & 1);
			// printf("%d\n", bit);
			if (!(((*b)->indx >> (i + 1)) & 1) && ((i + 1) < max_bits ))
				rb(b);
			else
				pa(head, b);
			j++;
		}
		while (*b)
			pa(head, b);
		i++;
	}
}
