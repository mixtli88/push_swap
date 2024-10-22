/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:34:06 by mabril            #+#    #+#             */
/*   Updated: 2024/10/22 18:15:08 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// ss: sa y sb al mismo tiempo.

void	ss(t_node **head, t_node **b)
{
	write(1, "rr\n", 3);
	if (!b || !(*b) || !(*b)->next)
		return ;
	if (!head || !(*head) || !(*head)->next)
		return ;
	sa(head);
	sb(b);
}
// rr : ra y rb al mismo tiempo.

void	rr(t_node **head, t_node **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	if (!head || !(*head) || !(*head)->next)
		return ;
	ra(head);
	rb(b);
	write(1, "rr\n", 3);
}

// rrr: rra y rrb al mismo tiempo.

void	rrr(t_node **head, t_node **b)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	if (!b || !(*b) || !(*b)->next)
		return ;
	rra(head);
	rrb(b);
	write(1, "rrr\n", 4);
}
