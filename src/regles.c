#include "../inc/push_swap.h"

// sa (swap a): Intercambia los primeros 2 elementos en la parte superior de la pila a. No hace nada si solo hay	last o nin	last.
void sa(t_node **head)
{
    t_node *current;
    t_node *last;

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
void min(t_node **head)
{
    t_node *last;

    if (!head || !(*head) || !(*head)->next)
	   	return;
	last = (*head)->next;
    *head = last;
}

void 	tresnudos(t_node **head)
{
    t_node 	*last;
    t_node *two;
		int i = 0;

    if (!head || !(*head) || !(*head)->next)
		return;
	while(!check_ord(*head))
	{
		last = (*head)->prev;
		two = (*head)->next;
		if((*head)->indx > last->indx)
		{	
			if((*head)->indx > two->indx)
			{	
				printf("ra\n");
				ra(head);
			}
			else if (last->indx < (*head)->indx)
			{

				printf("rra\n");
				rra(head);
			}
		}
		else
		{
			printf("sa\n");
			sa(head);
		}
		print_list(*head);
		// if((*head)->indx < two->indx && two->indx > last->indx)
		// {
		// 	if(last->indx < (*head)->indx)
		// 		rra(head);
		// 	else
		// 	{
		// 		rra(head);
		// 		sa(head);
		// 	}
		// }
		// if((*head)->indx > two->indx && two->indx > last->indx)
		// {
		// 	if(last->indx < (*head)->indx)
		// 		rra(head);
		// 	else
		// 	{
		// 		rra(head);
		// 		sa(head);
		// 	}
		// }
		i++;
		if(i == 3)
			break;
	}
}

// sb (swap b): Intercambia los primeros 2 elementos en la parte superior de la pila b. No hace nada si solo hay	last o nin	last.
// // void sb(t_node **a)

// ss: sa y sb al mismo tiempo.
// void ss(t_note **f)

// pa (push a): Tome el primer elemento encima de b y colóquelo en a. No hace nada si b está vacío.


// pb (push b): Toma el primer elemento encima de a y colócalo en b. No hace nada si a está vacío.


// ra (rotate a): Desplaza totwo los elementos de la pila hacia arriba una posición. El primer elemento se convierte en el último.

void ra(t_node **head)
{
    // t_node *curt;

    if (!head || !(*head) || !(*head)->next)
	   	return;
    *head= (*head)->next;
	
}

// rb (rotate b): Desplaza totwo los elementos de la pila b una posición hacia arriba. El primer elemento se convierte en el último.


// rr : ra y rb al mismo tiempo.


// rra(giro inverso a): desplaza los elementos de la pila hacia abajo una posición. la pila a. El último elemento se convierte en el primero.

void rra(t_node **head)
{
    t_node *last;

    if (!head || !(*head) || !(*head)->next)
	   	return;
    last = (*head)->prev;
	*head = last;
}
// rrb(rotación inversa b): desplaza totwo los elementos de la pila b una posición hacia abajo. la pila b. El último elemento se convierte en el primero.


// rrr: rra y rrb al mismo tiempo.