/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:11:29 by imontero          #+#    #+#             */
/*   Updated: 2023/04/19 19:33:07 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	 copia n bytes desde la dirección de memoria src a la dirección de memoria dest. 
	 La función maneja correctamente los casos en que los bloques de memoria se superponen, 
	 es decir, cuando src y dest se refieren a regiones de memoria que se solapan.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src) //verifica si ambas direcciones de memoria son nulas, en cuyo caso la función devuelve un puntero nulo.
		return (NULL);
	if (dest == src) //verifica si las direcciones de memoria son iguales, en cuyo caso no es necesario hacer nada y la función devuelve el puntero dest.
		return (dest);
	i = 0;
	if (dest > src) 
	// verifica si las direcciones de memoria se solapan y si el bloque 
	//de memoria de destino (dest) se encuentra después del bloque de memoria de origen (src)
	{
		while (i < n)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;// En este caso, la función realiza la copia desde el final del bloque, hacia el inicio para no destruir valores
		}
	}
	else //Las direcciones de memoria no se solapan y el bloque de destino se encuentra antes del bloque de origen en la memoria
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++; //la función copia los bytes desde el inicio del bloque hacia el final,
		}
	}
	return (dest);
}
