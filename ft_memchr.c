/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:52:34 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 13:33:03 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	busca un byte específico en un bloque de memoria dado
	La función toma tres argumentos: 
	- un puntero al bloque de memoria a ser buscado (s),
	- el valor de byte que se busca (c),
	- y el número de bytes a buscar (n). 
	Devuelve un puntero a la primera aparición del byte buscado 
	en la memoria, o un puntero nulo (NULL) si no lo encuentra.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c) //al utilizar unsigned char en lugar de char, se evita cualquier problema que pueda surgir debido a las diferentes implementaciones de los compiladores.
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
