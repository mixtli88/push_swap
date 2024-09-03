/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:30 by mabril            #+#    #+#             */
/*   Updated: 2024/09/03 17:44:45 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct stack_node
{
	int					num;
	struct stack_node	*sig;
	struct stack_node	*prev;
	
}	t_node;

void 	init(t_node **a, char *av);
void	msg_error(void);
long	ft_atolong(char *str);
void	new_node(t_node **head, int num);
void	print_list(t_node *head);
void	free_list(t_node *head);
#endif