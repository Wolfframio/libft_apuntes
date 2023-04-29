/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:44:43 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 11:27:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	compara el string 1 y el string 2 n número de caracteres.
	str1 < str2 (ASCII) devuelve str1 - str2 (valor negativo)
	str2 > str1 (ASCII) devuelve str1 - str2 (valor positivo)
	str1 = str2 devuelve 0
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && (i < n)) //El bucle continúa mientras el carácter actual de str1 o str2 no sea el carácter nulo y i sea menor que n.
	{
		if (str1[i] < str2[i])
		{
			return (str1[i] - str2[i]);
		}
		else if (str1[i] > str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
    char str1[] = "Hello, world!";
    char str2[] = "a ";
    int n = 3;

    printf("Comparando '%s' y '%s' hasta %d caracteres: \n", str1, str2, n);
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, n));
    printf("strncmp: %d\n", strncmp(str1, str2, n));
    return (0);
}

