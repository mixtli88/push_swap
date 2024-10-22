/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:04:30 by mabril            #+#    #+#             */
/*   Updated: 2024/10/21 21:22:01 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void head_is_min_a(t_node **head, t_node **b, int nn)
{
    t_node *cur = *head;
    while (cur && cur->next)
    {
        if (cur->next == *head || cur->indx < cur->next->indx)
        {
            if (cur->next->indx > (nn / 2) && cur->indx > (nn / 2))
                sa(head);
            else if (cur->prev->indx == cur->indx + 1 && cur->next->indx == cur->prev->indx + 1)
                rra(head);
            else
                pb(head, b);
            break;
        }
        cur = cur->next;
    }
}
void	head_is_min_a(t_node **head, t_node **b, int nn)
{
	t_node	*tem;

	tem = (*head)->next;
	while ((*head)->next)
	{
		if (tem == (*head))
		{
			if ((*head)->next->indx > (*head)->prev->indx
				&& ((*head)->next->indx > (nn / 2)) && (*head)->indx > (nn / 2))
				sa(head);
			else if ((*head)->prev->indx - 1 == (*head)->indx
				&& (*head)->next->indx - 1 == (*head)->prev->indx)
				rra(head);
			else
				pb(head, b);
			break ;
		}
		else if ((*head)->indx > tem->indx)
		{
			if ((*head)->prev->indx - 1 == (*head)->indx)
				rra(head);
			else
				ra(head);
			break ;
		}
		tem = tem->next;
	}
}

void	last_node_is_min_a(t_node **head, t_node **b, int nn)
{
	if ((*head)->prev->indx + 1 == (*head)->indx && (*head)->prev->indx < (nn
			/ 2))
		rra(head);
	else if ((*head)->next->indx - 1 == (*head)->prev->indx)
		sa(head);
	else if ((*head)->indx - 1 == (*head)->prev->indx && (*head)->indx > (nn
			/ 2))
		ra(head);
	else
		rra(head);
}

void	next_node_is_min_a(t_node **head, t_node **b, int nn)
{
	t_node	*tem;

	tem = (*head)->next;
	if (((*head)->indx == ((*head)->prev->indx + 1) && (*head)->next->indx
			+ 1 != (*head)->prev->indx) || ((tem->next->indx)
			+ 1 == (*head)->next->indx && (*head)->next->indx < (nn / 2)))
		ra(head);
	else
		sa(head);
}
