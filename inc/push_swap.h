/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:30 by mabril            #+#    #+#             */
/*   Updated: 2024/10/28 04:00:27 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stack_node
{
	int					num;
	int					indx;
	struct stack_node	*next;
	struct stack_node	*prev;
}						t_node;

// init.c
long	ft_atolong(char *str);
void	n_idex(t_node **head, int nd);
void	init(t_node **head, char **av, bool flag_split);
void	push_swap(t_node **head, t_node **b);
// utils.c
void	new_node(t_node **head, int num);
int		ft_listlen(t_node *stack);
bool	check_ord(t_node *head);
bool	reppet(t_node *head, long nbr);
int		top_is_min_a(t_node *head);
// error.c
void	free_list(t_node *head);
void	free_av(char **av);
int		error_syntax(char *str_nb);
void	error_free(t_node **head, char **av, bool flag_split);
// trie.c
void	trie_3(t_node **head);
void	trie_5(t_node **head, t_node **b, int nn);
void	trie_radix(t_node **head, t_node **b, int nn);

// regles.c
void	sa(t_node **head);
void	ra(t_node **head);
void	rra(t_node **head);
void	pa(t_node **head, t_node **b);
void	sb(t_node **b);
void	rb(t_node **b);
void	rrb(t_node **b);
void	pb(t_node **head, t_node **b);

// conditions.c
void	head_is_min_a(t_node **head, t_node **b, int nn);
void	head_not_min_a(t_node **head, int nn);
void	last_node_is_min_a(t_node **head, int nn);
void	next_node_is_min_a(t_node **head, int nn);
void	last_node_is_max_a(t_node **head, int nn);
// void print_list(t_node *head);
void	trie_bloque(t_node **head, t_node **b, int nn);

#endif