/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:36:54 by imontero          #+#    #+#             */
/*   Updated: 2023/04/27 09:31:45 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Reserva (utilizando malloc(3)) un array de strings
	resultante de separar la string ’s’ en substrings
	utilizando el caracter ’c’ como delimitador. El
	array debe terminar con un puntero NULL.
	
	- Parámetros 
	s: La string a separar.
	c: El carácter delimitador.

	- Valor devuelto 
	El array de nuevas strings resulatente de la separación.
	NULL si falla la reserva de memoria.
	"Hola que tal"
*/

static	int	ft_strcount(const char *str, char sep)
{
	int	i;
	int	strcount;

	i = 0;
	strcount = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			strcount++;
			while (str[i] != sep && str[i])
				i++;
		}
	}
	return (strcount);
}

static	char	**ft_splitstrings(char **tab, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			tab[k++] = ft_substr(s, i, j - i);
			i = j;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		strcount;
	char	**result;

	strcount = ft_strcount(s, c);
	result = malloc(sizeof(char *) * (strcount + 1));
	if (!result)
		return (NULL);
	return (ft_splitstrings(result, s, c));
}
