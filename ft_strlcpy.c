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
	toma el tamaño de dst como parámetro y 
	no escribirá más de esa cantidad de bytes para evitar 
	el desbordamiento del búfer (suponiendo que el tamaño sea correcto).
	Además, siempre escribe un solo byte ‘\0’ en el destino 
	(si el tamaño no es cero). 
	Se garantiza que la cadena resultante terminará en ‘\0’ 
	incluso si se trunca. Además, no pierde el tiempo 
	escribiendo múltiples bytes ‘\0’ para llenar el resto del búfer.
*/

size_t	ft_strlcpy(char	*dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (src[i2])
		i2++;
	if (dstsize < 1)
		return (i2);
	while (src[i] && i < dstsize - 1)
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
