/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:01:45 by mabril            #+#    #+#             */
/*   Updated: 2024/08/27 18:06:24 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*new_node(int num)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->num = num;
	node->sig = NULL;
	return (node);
}
t_node	*crear_lista(void *)
{
	t_node	*cabeza;
	

	cabeza = NULL;
	return (cabeza);
}

