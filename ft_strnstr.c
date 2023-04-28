/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:35:30 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 13:43:43 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Busca una subcadena (needle) en una cadena de texto (haystack)
	en los primeros len caracteres.
	- haystack const void*	Este parámetro recoge el valor de la cadena
		en la que tenemos que buscar la subcadena (pajar)
	- needle const void*	Este parámetro recoge el valor de la subcadena
		 que tenemos que buscar en la cadena (aguja)
	- len 	size_t	Número de caracteres a buscar
	 needle = NULL ->  devuelve la cadena haystack
	 needle no se encuentra en haystack -> devuelve NULL
	 needle se encuentra en haystack -> devuelve un puntero al primer 
		carácter encontrado
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
