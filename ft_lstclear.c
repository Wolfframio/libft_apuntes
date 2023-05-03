/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:31:17 by imontero          #+#    #+#             */
/*   Updated: 2023/05/03 15:05:57 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Elimina y libera el nodo ’lst’ dado y todos los
	consecutivos de ese nodo, utilizando la función
	’del’ y free(3).
	Al final, el puntero a la lista debe ser NULL.
	
	Parámetros 
	lst: la dirección de un puntero a un nodo.
	del: un puntero a función utilizado para eliminar
	el contenido de un nodo.

	Valor devuelto Nada
 
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	while(*lst->next) //mientras el nodo exista
	{
		temp = (*lst)->next; //almacenamos el puntero al siguiente nodo en una variable temporal
		ft_lstdelone((*lst), del); //ft_lstdelone aplica del al contenido del nodo
		*lst = temp; //ahora lst tiene la direccion del siguiente nodo
	}
}
