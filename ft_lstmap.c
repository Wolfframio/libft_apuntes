/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:56:52 by imontero          #+#    #+#             */
/*   Updated: 2023/05/03 16:00:08 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Itera la lista ’lst’ y aplica la función ’f’ al
	contenido de cada nodo. 
	Crea una lista resultante de la aplicación correcta
	y sucesiva de la función ’f’ sobre cada nodo. 
	La función ’del’ se utiliza para eliminar el contenido
	de un nodo, si hace falta.

	Parámetros lst: un puntero a un nodo.
	- f: la dirección de un puntero a una función usada
	en la iteración de cada elemento de la lista.
	- del: un puntero a función utilizado para eliminar
	el contenido de un nodo, si es necesario.

	Valor devuelto 
	- La nueva lista.
	- NULL si falla la reserva de memoria.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:56:52 by imontero          #+#    #+#             */
/*   Updated: 2023/05/03 15:53:31 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lstnew;
	void	*a;

	lstnew = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		a = f(lst->content);
		new = ft_lstnew(a);
		if (!new)
		{
			free(a);
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, new);
		lst = lst->next;
	}
	return (lstnew);
}
