/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:54:21 by mabril            #+#    #+#             */
/*   Updated: 2024/10/28 04:22:09 by mike             ###   ########.fr       */
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
	// t_node	*tem;

	// tem = (*head)->next;
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

// void	trie_radix(t_node **head, t_node **b, int nn)
// {
// 	int		i;
// 	int		j;
// 	int		max_bits;

// 	max_bits = 0;
// 	while ((nn >> max_bits) != 0)
// 		max_bits++;
// 	i = 0;
// 	while (i < max_bits && !check_ord(*head))
// 	{
// 		j = 0;
// 		while (j < nn)
// 		{
// 			if ((((*head)->indx >> i) & 1))
// 				ra(head);
// 			else
// 				pb(head, b);
// 			j++;
// 		}
// 		while (*b)
// 			pa(head, b);
// 		i++;
// 	}
// }
void	push_chunk_to_b(t_node **head, t_node **b, int min, int max, int nn)
{
	int i = 0;
	if(*head == NULL)
		return;
	// Mueve cada elemento en `head` a `b` si su índice está en el rango [min, max]
	while (i < nn)
	{
		if ((*head)->indx >= min && (*head)->indx <= max)
			pb(head, b);  // Envía el nodo a `b` si está en el rango
		else
			ra(head);
		if (ft_listlen(*b) == max )
			break;    // Rota en `head` si no está en el rango
		i++;
	}
}
void	move_to_top(t_node **b, int target)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = *b;
	while (current && current->indx != target)
	{
		current = current->next;
		pos++;
	}
	// Mueve el nodo a la cima usando rotaciones (`rb`) o rotaciones inversas (`rrb`)
		// Si el nodo está en la mitad superior, usa `rb` hasta que esté en la cima
	if (pos <= ft_listlen(*b) / 2)
		while (pos-- > 0)
			rb(b);
	else
	{
		// Si el nodo está en la mitad inferior, usa `rrb` hasta que esté en la cima
		pos = ft_listlen(*b) - pos;
		while (pos-- > 0)
			rrb(b);
	}
}
int	find_max_node(t_node *stack, int bloq)
{
	t_node	*tem = stack->next;
	int		max_node; 
	max_node = stack->indx;
	// Recorre la pila para encontrar el nodo con el índice más alto
	while (bloq >=0)
	{
		if (tem->indx > max_node)
			max_node = tem->indx;  // Actualiza `max_node` si se encuentra un índice mayor
		tem = tem->next;
		bloq--;
	}
	return max_node;
}

void	trie_bloque(t_node **head, t_node **b, int nn)
{
	int chunk_size = nn /7.5 ;   // Tamaño de bloque, ajustable según la eficiencia deseada
	int min = 0;
	int max = chunk_size;
	// t_node *tem;
	// 1. Mover bloques a `b` basados en el rango de índices
	while (min <= nn)
	{
		push_chunk_to_b(head, b, min, max, nn);
		min += chunk_size;   // Incrementa el mínimo para el siguiente bloque
		max += chunk_size;   // Incrementa el máximo para el siguiente bloque
		if (max > nn) max = nn;  // Asegura que `max` no exceda `nn`
	}
	// 2. Reinsertar los elementos de `b` a `head` en el orden correcto
	while (*b)
	{
		// Encontrar el índice más grande en `b`
		int max_node = find_max_node(*b, ft_listlen(*b));
		// Lleva el nodo con el índice mayor a la cima de `b`
		move_to_top(b, max_node);
		pa(head, b);  // Inserta el nodo en `head`
	}
}
