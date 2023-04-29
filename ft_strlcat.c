/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:40:12 by imontero          #+#    #+#             */
/*   Updated: 2023/04/21 09:52:46 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
	concatena dos cadenas de caracteres, y se utiliza para evitar problemas de desbordamiento
	de búfer al concatenar cadenas. 
	
	La función toma tres argumentos:
	- dest: un puntero a una cadena de caracteres de destino.
	- src: un puntero a una cadena de caracteres de origen.
	- size: un número entero que indica la cantidad de caracteres que pueden ser escritos en la cadena de destino, incluyendo el carácter nulo.

	La función devuelve la longitud total de la cadena que se pretendía 
	crear (la longitud de la cadena de origen más la longitud de la cadena de destino original).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	total_len;

	if ((!dst || !src) && size == 0) // comprueba si dst o src son nulas y si size es 0
		return (0);
	dest_len = ft_strlen(dst);
	if (dest_len < size) //Si dest_len es menor que size, se suma la longitud de la cadena de origen src a dest_len para obtener total_len.
		total_len = dest_len + ft_strlen(src);
	else //Si dest_len es mayor o igual que size devuelve la suma de size y la longitud de la cadena de origen src, porque que no se puede escribir más de size caracteres en dst.
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (dest_len + i + 1) < size) //copiar los caracteres de src en dst hasta que se llegue al final de la cadena src, o hasta que se llegue al tamaño máximo permitido de dst. 
	{
		dst[dest_len + i] = src[i];
		i++;// Los caracteres de src se copian en dst a partir de la posición dest_len + i y se incrementa i en cada iteración.
	}
	dst[i + dest_len] = '\0';
	return (total_len);
}

int main(void)
{
	char			dest[50] = "sef";
	char			src[50] = "sedr";
	unsigned int	size;

	size = 8;
    printf("%ld\n", ft_strlcat(dest, src, size));
	printf("dest: %s\n src: %s\n", dest, src);
}
