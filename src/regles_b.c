/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:42:27 by mabril            #+#    #+#             */
/*   Updated: 2024/10/29 15:04:15 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// sb (swap b): Intercambia los primeros 2 elementos en la parte
// superior de la pila b. No hace nada si solo hay	last o nin	last.
void	sb(t_node **b)
{
	t_node	*current;

	current = (*b)->next;
	(*b)->next = current->next;
	current->next->prev = *b;
	current->next = (*b);
	current->prev = (*b)->prev;
	(*b)->prev->next = current;
	(*b)->prev = current;
	*b = current;
	write(1, "sb\n", 3);
}

// pb (push b): Toma el primer elemento encima de a y colócalo en b.
//  No hace nada si a está vacío.

void	pb(t_node **head, t_node **b)
{
	t_node	*node;

	node = *head;
	if ((*head)->next->indx == (*head)->indx)
		*head = NULL;
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		*head = (*head)->next;
	}
	if (*b == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		(*b)->prev->next = node;
		node->prev = (*b)->prev;
		node->next = *b;
		(*b)->prev = node;
	}
	*b = node;
	write(1, "pb\n", 3);
}
// rb (rotate b): Desplaza los elementos de la pila
// b una posición hacia arriba. El primer elemento se convierte en el último.

void	rb(t_node **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	*b = (*b)->next;
	write(1, "rb\n", 3);
}
// rrb(rotación inversa b): desplaza los elementos de la pila b una posición
// hacia abajo. la pila b. El último elemento se convierte en el primero.

void	rrb(t_node **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}
