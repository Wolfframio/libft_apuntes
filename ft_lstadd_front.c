#include "libft.h"

/*
	Añade el nodo ’new’ al principio de la lista ’lst’.
	
	Parámetros 
	lst: la dirección de un puntero al primer nodo de una lista.
	new: un puntero al nodo que añadir al principio de la lista.
	
	Valor devuelto Nada
*/

/*
DECLARACION DE NODO T_LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/


/*
FT_LSTNEW para crear un nuevo nodo

	t_list	*ft_lstnew(void *content)
{
	t_list	*list; //decaramos puntero a un nodo de la lista enlazada que se utiliza para almacenar la dirección de memoria del nuevo nodo.

	list = malloc(sizeof(*list)); //reservamos memoria para el nodo
	if (!list)
		return (NULL);
	list->content = content; //se guarda el valor del puntero content pasado como argumento en el puntero content del nuevo nodo
	list->next = NULL; //se inicializa el puntero next del nuevo nodo con NULL para indicar que este es el último nodo de la lista.
	return (list);
}
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (!lst || !new) //si lst (recibe &list) y new (recibe node1, 2, 3) son NULL, no hace nada y sale.
		return;
	new->next = *lst; 	//aqui guardamos la direccion que estaba en el puntero de la lista y que apuntaba al
						//primer nodo de la lista. Ahora va a apuntar al siguiente si hay mas nodos (sera NULL si no hay mas nodos)
						//Recordemos que next es un puntero a una estructura de tipo t_list (nodo)
						
	*lst = new; //aqui vamos a guardar la direccion del nuevo nodo en el puntero de la lista
				//para decirle que apunte al nuevo nodo, que es el primero de la lista
}

int main(void)
{
    t_list  *list; 
    t_list  *node1, *node2, *node3;

    //list = NULL; //hemos declarado e iniciado una lista vacia

    node1 = ft_lstnew("Montoya");//creamos tambien 3 nodos con estos contenidos con la funcion ft_lstnew
    node2 = ft_lstnew("Yoyas"); 
    node3 = ft_lstnew("Aberroncho"); 

    ft_lstadd_front(&list, node1); 	/* enviamos la direccion de list (NULL) y la direccion del nuevo nodo/node1
									la funcion va a:
									1ero. Pasar el contenido del puntero list (NULL) al campo/miembro next del node1
									2o.  Cambiar el contenido del puntero list por la direccón del nuevo nodo.

									Es decir, el nuevo nodo siempre va a apuntar al siguiente nodo y va a ser apuntado
									por list. Así se convierte en el primer nodo.
									*/

	ft_lstadd_front(&list, node2); 
    ft_lstadd_front(&list, node3);

    t_list *current;
	
	current = list;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

	t_list *next;

	current = list;
	while (current != NULL)
	{
    	next = current->next;
    	free(current);
    	current = next;
	}
    return (0);
}
