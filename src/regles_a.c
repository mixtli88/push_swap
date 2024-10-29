/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:39:32 by mabril            #+#    #+#             */
/*   Updated: 2024/10/28 19:46:12 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// sa (swap a): Intercambia los primeros 2 elementos en la parte superior de 
// la pila a. No hace nada si solo hay	last o nin	last.
void	sa(t_node **head)
{
	t_node	*current;

	current = (*head)->next;
	(*head)->prev->next = current;
	current->prev = (*head)->prev;
	(*head)->next = current->next;
	current->next->prev = (*head);
	current->next = *head;
	(*head)->prev = current;
	*head = current;
	write(1, "sa\n", 3);
}

// pa (push a): Tome el primer elemento encima de b y colóquelo en a. No hace
//  nada si b está vacío.

void	pa(t_node **head, t_node **b)
{
	t_node	*node;

	node = *b;
	if ((*b)->next->indx == (*b)->indx)
		*b = NULL;
	else
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		(*b) = (*b)->next;
	}
	if (*head == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *head;
		node->prev = (*head)->prev;
		(*head)->prev->next = node;
		(*head)->prev = node;
	}
	*head = node;
	write(1, "pa\n", 3);
}

// ra (rotate a): Desplaza los elementos de la pila hacia arriba una posición. 
// El primer elemento se convierte en el último.

void	ra(t_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	write(1, "ra\n", 3);
}

// rra(giro inverso a): desplaza los elementos de la pila hacia abajo una 
// posición. la pila a. El último elemento se convierte en el primero.

void	rra(t_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	*head = (*head)->prev;
	write(1, "rra\n", 4);
}
