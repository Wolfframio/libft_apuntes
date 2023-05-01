#include "libft.h"

/*
	Añade el nodo ’new’ al final de la lista ’lst’.
	
	Parámetros 
	lst: el puntero al primer nodo de una lista.
	new: el puntero a un nodo que añadir a la lista.

	Valor devuelto Nada
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if(!new)
		return ;
	if(!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

