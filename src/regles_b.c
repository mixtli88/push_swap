/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:42:27 by mabril            #+#    #+#             */
/*   Updated: 2024/10/22 18:18:27 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// sb (swap b): Intercambia los primeros 2 elementos en la parte 
// superior de la pila b. No hace nada si solo hay	last o nin	last.
void	sb(t_node **b)
{
	t_node	*current;
	t_node	*last;

	write(1, "sa\n", 3);
	current = (*b)->next;
	last = (*b)->prev;
	last->next = current;
	current->prev = last;
	last = current->next;
	current->next = *b;
	(*b)->next = last;
	(*b)->prev = current;
	last->prev = *b;
	*b = current;
}

// pb (push b): Toma el primer elemento encima de a y colócalo en b.
//  No hace nada si a está vacío.

void	pb(t_node **head, t_node **b)
{
	t_node	*node;
	t_node	*last;

	write(1, "pb\n", 3);
	node = *head;
	last = (*head)->prev;
	*head = (*head)->next;
	last->next = *head;
	(*head)->prev = last;
	if (*b == NULL)
	{
		*b = node;
		node->next = *b;
		node->prev = *b;
	}
	else
	{
		last = (*b)->prev;
		last->next = node;
		node->prev = last;
		node->next = *b;
		(*b)->prev = node;
		*b = node;
	}
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
	write(1, "rra\n", 4);
}
