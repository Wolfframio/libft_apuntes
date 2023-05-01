#include "libft.h"

/*
	Cuenta el número de nodos de una lista.

	Parámetros 
	lst: el principio de la lista.

	Valor devuelto
	La longitud de la lista. 
*/

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL) //mientras el nodo este dentro de la lista
	{
		lst = lst->next;//lst = siguiente nodo (el miembro next de lst apunta al siguiente nodo)
		i++; //suma al contador
	}
	return (i);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(*node1));
	node2 = malloc(sizeof(*node2));
	node3 = malloc(sizeof(*node3));
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("El tamaño de la lista es %i", ft_lstsize(node1));
	free(node1);
	free(node2);
	free(node3);
}
