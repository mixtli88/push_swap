#include "../inc/push_swap.h"

// sa (swap a): Intercambia los primeros 2 elementos en la parte superior de la pila a. No hace nada si solo hay	last o nin	last.
void sa(t_node **head)
{
    t_node *current;
    t_node *last;

	// printf("sa\n");
	ft_putstr_fd("sa\n", 1);
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
	// print_list(*head);
}
void trie_2(t_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return;
	sa(head);
}

void 	trie_3(t_node **head)
{
    t_node 	*last;
    t_node *two;

    if (!head || !(*head) || !(*head)->next)
		return;
	while(!check_ord(*head))
	{
		last = (*head)->prev;
		two = (*head)->next;
		if((*head)->indx > last->indx && (*head)->indx > two->indx)
			ra(head);
		else if (last->indx < (*head)->indx)
			rra(head);
		else
			sa(head);
	}
}

// sb (swap b): Intercambia los primeros 2 elementos en la parte superior de la pila b. No hace nada si solo hay	last o nin	last.
// // void sb(t_node **a)

// ss: sa y sb al mismo tiempo.
// void ss(t_note **f)

// pa (push a): Tome el primer elemento encima de b y colóquelo en a. No hace nada si b está vacío.

void pa(t_node **head,t_node **b)
{
	t_node *node;
	t_node *last;

	ft_putstr_fd("pa\n", 1);
	node = *b;
	if((*b)->indx == (*b)->next->indx )
		*b = NULL;
	else
	{
		last = (*b) ->prev;
		*b = (*b)->next;
		last->next = *b;
		(*b)->prev = last;
	}
	if(*head == NULL)
	{
		*head = node;
		node->next = *head;
		node->prev = *head;
	}
	else
	{
		last = (*head) ->prev;
		last->next = node;
		node->next = *head;
		node->prev = last;
		(*head)->prev = node;
		*head =  node;
	}
	// print_list(*head);
}

// pb (push b): Toma el primer elemento encima de a y colócalo en b. No hace nada si a está vacío.

void pb(t_node **head,t_node **b)
{
	t_node *node;
	t_node *last;

	ft_putstr_fd("pb\n", 1);
	node = *head;
	last = (*head) ->prev;
	*head = (*head)->next;
	last->next = *head;
	(*head) ->prev = last;
	
	if(*b == NULL)
	{
		*b = node;
		node->next = *b;
		node->prev = *b;
	}
	else
	{ 
		last = (*b)->prev;
		last->next = node;
		node->prev = last;
		node->next = *b;
		(*b)->prev = node;
		*b = node;
	}
}
// ra (rotate a): Desplaza totwo los elementos de la pila hacia arriba una posición. El primer elemento se convierte en el último.

void ra(t_node **head)
{
    // t_node *curt;
	ft_putstr_fd("ra\n", 1);
    if (!head || !(*head) || !(*head)->next)
	   	return;
    *head= (*head)->next;
	// print_list(*head);
}

// rb (rotate b): Desplaza totwo los elementos de la pila b una posición hacia arriba. El primer elemento se convierte en el último.


// rr : ra y rb al mismo tiempo.


// rra(giro inverso a): desplaza los elementos de la pila hacia abajo una posición. la pila a. El último elemento se convierte en el primero.

void rra(t_node **head)
{
    t_node *last;

	// printf("\nrra\n");
	ft_putstr_fd("rra\n", 1);
    if (!head || !(*head) || !(*head)->next)
	   	return;
    last = (*head)->prev;
	*head = last;
	// print_list(*head);
}
// rrb(rotación inversa b): desplaza totwo los elementos de la pila b una posición hacia abajo. la pila b. El último elemento se convierte en el primero.


// rrr: rra y rrb al mismo tiempo.