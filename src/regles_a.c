/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regles_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:39:32 by mabril            #+#    #+#             */
/*   Updated: 2024/10/21 20:59:25 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// sa (swap a): Intercambia los primeros 2 elementos en la parte superior de 
// la pila a. No hace nada si solo hay	last o nin	last.
void	sa(t_node **head)
{
	t_node	*current;
	t_node	*last;

	write(1, "sa\n", 3);
	current = (*head)->next;
	last = (*head)->prev;
	last->next = current;
	current->prev = last;
	last = current->next;
	current->next = *head;
	(*head)->next = last;
	(*head)->prev = current;
	last->prev = *head;
	*head = current;
}

// pa (push a): Tome el primer elemento encima de b y colóquelo en a. No hace
//  nada si b está vacío.

void	pa(t_node **head, t_node **b)
{
	t_node	*node;
	t_node	*last;

	write(1, "pa\n", 3);
	node = *b;
	if ((*b)->indx == (*b)->next->indx)
		*b = NULL;
	return ;
	last = (*b)->prev;
	*b = (*b)->next;
	last->next = *b;
	(*b)->prev = last;
	last = (*head)->prev;
	last->next = node;
	node->next = *head;
	node->prev = last;
	(*head)->prev = node;
	*head = node;
}

// ra (rotate a): Desplaza los elementos de la pila hacia arriba una posición. 
// El primer elemento se convierte en el último.

void	ra(t_node **head)
{
	write(1, "ra\n", 3);
	if (!head || !(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
}

// rra(giro inverso a): desplaza los elementos de la pila hacia abajo una 
// posición. la pila a. El último elemento se convierte en el primero.

void	rra(t_node **head)
{
	t_node	*last;

	write(1, "rra\n", 4);
	if (!head || !(*head) || !(*head)->next)
		return ;
	last = (*head)->prev;
	*head = last;
}
