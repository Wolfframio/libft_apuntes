/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:39:47 by imontero          #+#    #+#             */
/*   Updated: 2023/04/19 19:39:47 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	La función reserva un bloque de memoria de n elementos de tamaño size bytes cada uno, 
	y luego inicializa todos los bytes de la memoria reservada a cero.
*/

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n != 0 && (n * size) / n != size) 
/*comprueba si el tamaño total de la memoria que se va a reservar es mayor que el tamaño máximo 
que puede ser representado en el sistema. Si el valor calculado de n * size es demasiado grande 
para ser almacenado en una variable de tamaño size_t, entonces se produce un desbordamiento de memoria 
y la condición devuelve true.*/
		return (NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
