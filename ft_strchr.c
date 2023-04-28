/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:56:11 by imontero          #+#    #+#             */
/*   Updated: 2023/04/23 19:41:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Busca cierto carácter dentro de una cadena de texto.
	Recibe dos argumentos:
	- s es un puntero constante a un caracter, 
		que corresponde al inicio de la cadena en la que se buscará el caracter c.
	- c es un entero, que corresponde al caracter que se busca dentro de la cadena s.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i]) // Dentro del bucle, se comprueba si el caracter actual de la cadena (s[i]) es igual al caracter c que se está buscando. 
	{
		if (s[i] == (char) c) //Si se encuentra una coincidencia, se devuelve un puntero a esa posición de la cadena. El puntero se obtiene mediante el uso de un casting de tipos: primero se convierte el puntero s de const char* a char*
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&((char *)s)[i]);
	return (0);
}

int main(void)
{
    char str[] = "cagon tus muelas!";
    char *result;
	
	result = ft_strchr(str, 'm');
    if (result != NULL)
        printf("El caracter 'm' se encuentra en la posición %ld de la cadena \"%s\".\n", result - str, str);
    else
        printf("El caracter 'm' no se encuentra en la cadena \"%s\".\n", str);

    result = ft_strchr(str, 'x');
    if (result != NULL)
        printf("El caracter 'x' se encuentra en la posición %ld de la cadena \"%s\".\n", result - str, str);
    else
        printf("El caracter 'x' no se encuentra en la cadena \"%s\".\n", str);

    return 0;
}






