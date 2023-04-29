/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:55:06 by imontero          #+#    #+#             */
/*   Updated: 2023/04/20 10:55:06 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	convierte una letra mayúscula en la letra minúscula correspondiente. 
	El argumento debe poder representarse como un 
	unsigned char o el valor de EOF (End Of File)
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int main(void)
{
    char c;
	
	c = 'A';
    printf("Carácter original: %c\n", c);
    printf("Carácter convertido a minúscula: %c\n", ft_tolower(c));
    return (0);
}