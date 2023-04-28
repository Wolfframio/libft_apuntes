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

/*
	agrega una cadena al final de la otra. 
	Ofrece un argumento adicional, dstsize.
	Este argumento establece la longitud de la 
	cadena de destino, de hecho igual a su tamaño de búfer.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	total_len;

	if ((!dst || !src) && size == 0)
		return (0);
	dest_len = ft_strlen(dst);
	if (dest_len < size)
		total_len = dest_len + ft_strlen(src);
	else
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[i + dest_len] = '\0';
	return (total_len);
}

/*
int main(void)
{
	char			dest[50] = "sef";
	char			src[50] = "sed";
	unsigned int	size;

	size = 6;
	printf("%lu\n", strlcat(dest, src, size));
    printf("%d\n", ft_strlcat(dest, src, size));
	printf("dest: %s\nsrc: %s\n", dest, src);
}
*/