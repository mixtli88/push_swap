/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:04:30 by mabril            #+#    #+#             */
/*   Updated: 2024/10/23 14:34:13 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	head_is_min_a(t_node **head, t_node **b, int nn)
{
	if ((*head)->next->indx > (*head)->prev->indx && ((*head)->next->indx > (nn
				/ 2)) && (*head)->indx > (nn / 2))
		sa(head);
	else if ((*head)->prev->indx - 1 == (*head)->indx && (*head)->next->indx
		- 1 == (*head)->prev->indx)
		rra(head);
	else
		pb(head, b);
}

void	head_not_min_a(t_node **head, int nn)
{
	t_node	*tem;
	float	med;

	med = (float)nn / 2;
	tem = (*head)->next;
	if (((*head)->prev->indx - 1 == (*head)->indx && (*head)->prev->indx < med)
		|| ((*head)->prev->indx - 1 == (*head)->next->indx) || ((*head)->prev->indx + 1 == (*head)->next->indx))
		rra(head);
	else if ((*head)->indx + 1 == (*head)->next->indx && (*head)->next->indx
		+ 1 == tem->next->indx)
		rra(head);
	else if ((*head)->next->indx > med)
		sa(head);
	else
		ra(head);
}

void	last_node_is_min_a(t_node **head, int nn)
{
	t_node	*tem;
	float	med;

	med = (float)nn / 2;
	tem = (*head)->next;
	if (((*head)->next->indx - 1 == (*head)->prev->indx) && (*head)->next->indx + 1 != tem->next->indx)
		sa(head);
	else if (((*head)->prev->indx + 1 == (*head)->indx && (*head)->prev->indx < med)
		|| ((*head)->prev->indx + 1 == (*head)->next->indx
			&& (*head)->prev->indx < med))
		rra(head);
	else if ((*head)->indx - 1 == (*head)->prev->indx && (*head)->indx > med)
		ra(head);
	else
		rra(head);
}

void	next_node_is_min_a(t_node **head, int nn)
{
	t_node	*tem;
	float	med;

	med = (float)nn / 2;
	tem = (*head)->next;
	if ((*head)->indx - 1 == tem->next->indx)
		sa(head);
	else if (((*head)->indx == ((*head)->prev->indx + 1) && (*head)->next->indx
			+ 1 != (*head)->prev->indx) || ((tem->next->indx)
			+ 1 == (*head)->next->indx && (*head)->next->indx < med)
		|| ((*head)->indx > med && (*head)->indx + 1 != (tem->next->indx)))
		ra(head);
	else
		sa(head);
}

void	last_node_is_max_a(t_node **head, int nn)
{
	t_node	*tem;
	float	med;

	med = (float)nn / 2;
	tem = (*head)->next;
	if ((*head)->indx + 1 == ((*head)->prev->indx) && (*head)->next->indx
		+ 1 == (*head)->indx && (*head)->next->indx > med)
		sa(head);
	else
		ra(head);
}
