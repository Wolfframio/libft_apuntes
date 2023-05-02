/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:33:20 by imontero          #+#    #+#             */
/*   Updated: 2023/05/02 11:56:04 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Itera la lista ’lst’ y aplica la función ’f’ en el
	contenido de cada nodo.

	Parámetros
	lst: un puntero al primer nodo.
	f: un puntero a la función que utilizará cada nodo.

	Valor devuelto Nada
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if(!lst)
		return ;
	while(lst)
	{
		f(lst->content); // aplica la funcion f al contenido iterando en cada nodo
		lst = lst->next;
	}
}
