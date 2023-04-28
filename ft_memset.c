/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:33:54 by imontero          #+#    #+#             */
/*   Updated: 2023/04/19 19:33:54 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	copia el carácter c (un carácter sin signo) 
	en los primeros n caracteres de la cadena 
	a la que apunta el argumento str
*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = ptr;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/* int main() 
{
    int a = 5;
	
	char *str = (char*)malloc(10 * sizeof(char));
    ft_memset(str, -3, a);
	
	for (int i = 0; i < a; i++)
        printf("%c", str[i]);
    
	printf("\n");

	printf("%s", str);
	printf("\n");

	for (int i = 0; i < a; i++)
        printf("%d ", str[i]);
    
    printf("\n");
	free(str);

	printf("\n");



	char *str2 = (char*)malloc(10 * sizeof(char));
    memset(str2, -3, a);
	
	for (int i = 0; i < a; i++)
        printf("%c", str2[i]);
    
	printf("\n");
	
	printf("%s", str2);
	printf("\n");

	for (int i = 0; i < a; i++)
        printf("%d ", str2[i]);
    
    printf("\n");
	free(str2);

    return 0;
}
*/