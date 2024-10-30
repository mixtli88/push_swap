/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:05:26 by mabril            #+#    #+#             */
/*   Updated: 2024/10/30 14:03:52 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_max_node(t_node *stack)
{
	t_node	*tem;
	int		max_node;

	tem = stack->next;
	max_node = stack->indx;
	while (tem != stack)
	{
		if (tem->indx > max_node)
			max_node = tem->indx;
		tem = tem->next;
	}
	return (max_node);
}

void	move_to_top(t_node **b, int node)
{
	int		pos;
	t_node	*current;

	pos = 0;
	if ((*b)->next->indx > (*b)->indx)
		sb(b);
	current = *b;
	while (current && current->indx != node)
	{
		current = current->next;
		pos++;
	}
	if (pos <= (ft_listlen(*b) / 2))
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = (ft_listlen(*b) - pos);
		while (pos-- > 0)
			rrb(b);
	}
}

void	push_block_to_b(t_node **head, t_node **b, int nn)
{
	int	block_size;
	int	min;
	int	max;

	block_size = nn / 6;
	min = 0;
	max = block_size;
	if (*head == NULL)
		return ;
	while (min <= nn)
	{
		while (*head)
		{
			if ((*head)->indx >= min && (*head)->indx <= max)
				pb(head, b);
			else
				ra(head);
			if (ft_listlen(*b) == max)
				break ;
		}
		min += block_size;
		max += block_size;
		if (max > nn)
			max = nn;
	}
}
