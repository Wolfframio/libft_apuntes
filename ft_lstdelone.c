#include "libft.h"

/*
	Toma como parámetro un nodo ’lst’ y libera la
	memoria del contenido utilizando la función ’del’
	dada como parámetro, además de liberar el nodo. La
	memoria de ’next’ no debe liberarse.
	
	Parámetros
	lst: el nodo a liberar.
	del: un puntero a la función utilizada para liberar el contenido del nodo.

	Valor devuelto
	Nada
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free (lst);
}
