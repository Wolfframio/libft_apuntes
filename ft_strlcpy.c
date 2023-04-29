/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:25:07 by imontero          #+#    #+#             */
/*   Updated: 2023/04/21 13:24:25 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	copia una cadena de origen en una cadena de destino, 
	y se utiliza para evitar problemas de desbordamiento de búfer al copiar cadenas. 
	
	La función toma tres argumentos:
	- dest: un puntero a una cadena de caracteres de destino.
	- src: un puntero a una cadena de caracteres de origen.
	- dstsize: un número entero que indica la cantidad de caracteres que pueden ser escritos
		en la cadena de destino, incluyendo el carácter nulo.
	La función devuelve el tamaño de la cadena de origen que se pretendía 
	copiar (la longitud de la cadena de origen).
*/

size_t	ft_strlcpy(char	*dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (src[i2])
		i2++;
	if (dstsize < 1) //Si el tamaño de la cadena de destino es menor que 1 (si no se puede escribir nada en la cadena de destino), devuelve la longitud de la cadena de origen.
		return (i2);
	while (src[i] && i < dstsize - 1) //Si la longitud de la cadena de origen es mayor o igual que dstsize, sólo se copian los primeros dstsize - 1 caracteres de la cadena de origen en la cadena de destino, y se agrega un carácter nulo al final de la cadena de destino.
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i2);
}

/*
int	main(void)
{
	char	dest[50];
	//char	dest2[50];
	char	*src;
	int		size;

	src = NULL;
	size = 10;
	ft_strlcpy(dest, src, size);
	printf("%s\n", dest);
	strlcpy(dest2, src, size);
	printf("%s\n", dest2);
}
*/
