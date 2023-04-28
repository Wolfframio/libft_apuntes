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
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&((char *)s)[i]);
	return (0);
}
