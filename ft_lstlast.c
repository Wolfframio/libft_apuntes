#include "libft.h"

/*
	Devuelve el último nodo de la lista.
	
	Parámetros
	lst: el principio de la lista.

	Valor devuelto
	Último nodo de la lista.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL) 	//recorre la lista por miembro next cuyo valor en el ultimo nodo es NULL
		lst = lst->next;		//de esta forma NO nos salimos de la lista y nos quedamos en el ultimo nodo
	return (lst);				//que es el que hay que devolver
}

int main(void)
{
    t_list  *lista;
    t_list  *lista1;
    t_list  *lista2;
    t_list  *last;
    char    str[] = "final";


    lista = malloc(sizeof(*lista));
    lista1 = malloc(sizeof(*lista1));
    lista2= malloc(sizeof(*lista2));
    last= malloc(sizeof(*last));

    lista->next = lista1;
    lista1->next = lista2;
    lista2->content = (void *)str;
    lista2->next = NULL;

    last = ft_lstlast(lista);
    printf("El ultimo nodo de la lista contiene: %s\n", ((char *)last->content));

    free(lista);
    free(lista1);
    free(lista2);
    free(last);
    return (0);
}
