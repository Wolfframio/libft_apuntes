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

#include "libft.h"

/*
	ischar comprueba si un carácter está en el conjunto de caracteres set. 
	Recibe
	un carácter c
	una cadena set 
	
	devuelve
	1 si c se encuentra en set
	0 si no se encuentra.
*/
static	size_t	ft_ischar(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		start;
	size_t		end;

	if (!s1 || !set) //Si alguno de los dos parámetros es NULL, la función devuelve NULL.
		return (NULL);
	start = 0;
	while (s1[start] && ft_ischar(s1[start], set)) //comprueba si el primer carácter de s1 está en el set. Si es así, se incrementa start y se continúa hasta que se encuentre un carácter que no esté en el set o se llegue al final de la cadena s1.
		start++; //start se queda en el indice que necesitamos para el string resultado
	end = ft_strlen(s1); //	se establece el índice final end como la longitud de la cadena s1
	while (end > start && ft_ischar(s1[end - 1], set)) //bucle para avanzar desde el final si el indice de s1 está en el set.
		end--; //el indice end queda como la ultima posicion del string que necesitamos
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++]; //copiamos s1 a str con los indices despues de recortar
	str[i] = 0;
	return (str);
}

int  main(void)
{
   char    s1[] = "   lorem lorem ipsum amet dolor sit amet   ";
   char    *set;
   char    *strtrim;


   set = " ";
 
   strtrim = ft_strtrim(s1, set);
   printf("%s\n", strtrim);
}
