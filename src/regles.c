/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:34:06 by mabril            #+#    #+#             */
/*   Updated: 2024/10/28 02:30:51 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// ss: sa y sb al mismo tiempo.

void	ss(t_node **head, t_node **b)
{
	printf("ss\n");
	// write(1, "rr\n", 3);
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
	printf("rr\n");
	// write(1, "rr\n", 3);
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
	printf("rrr\n");
	// write(1, "rrr\n", 4);
}
