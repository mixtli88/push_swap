/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:30 by mabril            #+#    #+#             */
/*   Updated: 2024/10/18 19:28:00 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct stack_node
{
	int					num;
	int					indx;
	struct stack_node	*next;
	struct stack_node	*prev;
}	t_node;

// type data
// 	-> int nbr_of_node;

void 	init(t_node **head, char **av, bool flag_split);
void	msg_error(void);
long	ft_atolong(char *str);
void	new_node(t_node **head, int num);
void	print_list(t_node *head);
void	free_list(t_node *head);
void 	tidex(t_node **head, int nd);
int 	ft_listlen(t_node *head);
void 	free_av(char **av);
int 	error_syntax(char *str_nb);
void 	error_free( t_node **head, char **av, bool flag_split);
bool 	check_ord(t_node *head);
void 	sa(t_node **head);
void 	trie_2(t_node **head);
void 	trie_3(t_node **head);
void 	rra(t_node **head);
void 	ra(t_node **head);
bool 	reppet(t_node *head, long nbr);
void 	pb(t_node **head,t_node **b);
void 	pa(t_node **head,t_node **b);
void 	two_n_b(t_node **b);
void 	push_swap(t_node **head, t_node **b);
void 	minimoa(t_node **head,t_node **b, int nn);
void 	trie_5(t_node **head, t_node **b, int nn);
void 	is_min_a(t_node **head, t_node **b, int nn);
int error_reppet(t_node **head , char **av, bool flag_split);


// if deja trier exit

#endif