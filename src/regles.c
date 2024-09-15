#include "../inc/push_swap.h"

// sa (swap a): Intercambia los primeros 2 elementos en la parte superior de la pila a. No hace nada si solo hay uno o ninguno.
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
}
void min(t_node **head)
{
    t_node *uno;
    t_node *dos;

    if (!head || !(*head) || !(*head)->next) 
        return;
    uno = *head;
    dos = uno->next;
    *head = dos;
}
void rra(t_node **head)
{
    t_node *last;
    t_node *dos;

    if (!head || !(*head) || !(*head)->next) 
        return;
    last = (*head)->prev;
	*head = last;
    // dos = uno->next;
    // *head = dos;
}
void tresnudos(t_node **head)
{
    t_node *uno;
    t_node *dos;
	t_node *tres;

    if (!head || !(*head) || !(*head)->next) 
        return;
    uno = *head;
    dos = (*head)->next;

    if(uno->indx < dos->indx)
		if(dos->indx > dos->next->indx)
			rra(head);
    if(uno->indx > dos->indx && uno->indx > dos->next->indx )
    	if(dos->indx < dos->next->indx)
			min(head);
}

// sb (swap b): Intercambia los primeros 2 elementos en la parte superior de la pila b. No hace nada si solo hay uno o ninguno.
// // void sb(t_node **a)

// ss: sa y sb al mismo tiempo.
// void ss(t_note **f)

// pa (push a): Tome el primer elemento encima de b y colóquelo en a. No hace nada si b está vacío.


// pb (push b): Toma el primer elemento encima de a y colócalo en b. No hace nada si a está vacío.


// ra (rotate a): Desplaza todos los elementos de la pila hacia arriba una posición. El primer elemento se convierte en el último.


// rb (rotate b): Desplaza todos los elementos de la pila b una posición hacia arriba. El primer elemento se convierte en el último.


// rr : ra y rb al mismo tiempo.


// rra(giro inverso a): desplaza todos los elementos de la pila hacia abajo una posición. la pila a. El último elemento se convierte en el primero.


// rrb(rotación inversa b): desplaza todos los elementos de la pila b una posición hacia abajo. la pila b. El último elemento se convierte en el primero.


// rrr: rra y rrb al mismo tiempo.