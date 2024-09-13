#include "../inc/push_swap.h"

int error_syntax(char *str_nb)
{
	if(!(str_nb == '+' || str_nb == '-' || (str_nb >= '0' && str_nb<= '9')))
		return(1);
	if((str_nb == '+' || str_nb == '-' || !(str_nb[1] >= '0' && str_nb[1] <= '9')))
	while(++str_nb)
	{
		if(!(str_nb >= '0' && str_nb <= '9'))
			return(1);		
	}
	return (0);
}