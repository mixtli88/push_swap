/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:30 by mabril            #+#    #+#             */
/*   Updated: 2024/09/12 09:23:00 by mike             ###   ########.fr       */
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
	int					indx;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_node;

// type data
// 	-> int nbr_of_node;

void 	init(t_node **head, char **av);
void	msg_error(void);
long	ft_atolong(char *str);
void	new_node(t_node **head, int num);
void	print_list(t_node *head);
void	free_list(t_node *head);
void 	tidex(t_node **head, int nd);
int 	ft_listlen(t_node *head);
void 	free_av(char **av);
// if deja trier exit

#endif