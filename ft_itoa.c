/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:33:52 by imontero          #+#    #+#             */
/*   Updated: 2023/04/25 13:12:58 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Reserva memoria (con malloc(3)) y devuelve la cadena de caracteres
	que representa el número pasado como argumento. Se debe manejar
	la conversión de números negativos.
*/

static	int	ft_nlen(int n) //buscamos de cuantos digitos se compone el int ("tamaño del int")
{
	int	nlen;

	nlen = 1;
	if (n < 0)
		nlen++; //si n es negativo añadimos un espacio extra para el '-'
	while (n / 10 != 0)
	{
		n /= 10; //cada division x 10 suma 1 al contador
		nlen++;
	}
	return (nlen);
}

static	char	*ft_newstr(char *str, long num, int nlen) //recibe el str reservado. ya tiene caracter nulo al final
{
	int	i;

	i = 1;
	while (num / 10 != 0)
	{
		str[nlen - i] = (num % 10) + '0'; //va guardando el ultimo digito de n en el final del string
		num /= 10; //elimina ultimo digito y continua el bucle
		i++;
	}
	str[nlen - i] = (num % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	int		i;
	long	num;

	i = 0;
	nlen = ft_nlen(n); //nlen ya viene con el tamaño adecuado para si n es positivo o negativo
	str = malloc((nlen + 1) * sizeof(char)); //reservamos para el string + 1 para null
	if (!str)
		return (NULL);
	num = n; 
	if (num < 0) //si n es negativo guardamos el signo en el primer indice del str
	{
		str[i] = '-';
		num = num * -1;
		i++;
	}
	str[(nlen)] = '\0';
	ft_newstr(str, num, nlen);
	return (str);
}

/*
int	main(void)
{
	int	num = -3450;
	char	*output;

	output = ft_itoa(num);
	printf("%s\n", output);
	free(output);
	return (0);
}
*/