/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:04:48 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 11:12:54 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Busca cierta letra dentro de una cadena de texto 
	empezando desde detrás de la cadena.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
		i++; // = strlen(str), tamaño de str
	while (i >= 0) //recorre de atrás hacia delante
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
