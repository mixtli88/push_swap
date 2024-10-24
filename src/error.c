/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:56:36 by mabril            #+#    #+#             */
/*   Updated: 2024/10/21 20:57:55 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	error_syntax(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0'
				&& *str_nb <= '9')) || !*str_nb)
		return (1);
	if ((*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0'
				&& *str_nb <= '9')))
	{
		while (*++str_nb)
			if (!(*str_nb >= '0' && *str_nb <= '9'))
				return (1);
	}
	return (0);
}

void	error_free(t_node **head, char **av, bool flag_split)
{
	if (*head)
		free_list(*head);
	if (flag_split)
		free_av(av);
	write(2, "Error de syntax perro\n", 21);
	exit(1);
}

int	error_reppet(t_node **head, char **av, bool flag_split)
{
	if (*head)
		free_list(*head);
	if (flag_split)
		free_av(av);
	write(2, "Error number repet\n", 18);
	exit(1);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_list(t_node *head)
{
	t_node	*current;

	current = head->prev;
	head->prev = NULL;
	current->next = NULL;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
