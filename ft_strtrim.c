/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:09:38 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 16:23:21 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Elimina todos los caracteres de la string set desde el principio
	y desde el final de s1, 
	hasta encontrar un carácter no perteneciente a set. 
	La string resultante se devuelve con una reserva de malloc(3).
	Valor a configurar

	Parametros
	s1 		Es la cadena que se va a recortar
	set		Son los caracteres que, si aparecen en s1, 
			van a cortarla por delante y por detrás

	Retorno
	Si falla reserva memoria	Devuelve NULL
	Si s1 y s2 no están vacíos	Devuelve la cadena juntando s1 y s2
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
