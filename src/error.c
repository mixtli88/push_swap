#include "../inc/push_swap.h"

int error_syntax(char *str_nb)
{
	if(!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0' && *str_nb<= '9')))
		return(1);
	if((*str_nb == '+' || *str_nb == '-' || !(str_nb[1] >= '0' && str_nb[1] <= '9')))
	while(*++str_nb)
	{
		if(!(*str_nb >= '0' && *str_nb <= '9'))
			return(1);		
	}
	return (0);
}
void error_free( t_node **head, char **av, bool flag_split)
{
	free_list(*head);
	if(flag_split)
		free_av(av);
	write(2, "Error\n", 6);
	exit(1);
}