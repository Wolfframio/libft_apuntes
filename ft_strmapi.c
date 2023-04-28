#include "libft.h"

/*
	A cada carácter de la string s, aplica la función f dando como parámetros
	el índice de cada carácter dentro de s y el propio carácter.
	Genera una nueva string con el resultado del uso sucesivo de f
	
	- Parámetros 
	s: La string que iterar.
	f: La función a aplicar sobre cada carácter.
	
	- Valor devuelto
	La string creada tras el correcto uso de ’f’ sobre cada carácter.
	NULL si falla la reserva de memoria.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	unsigned int	len;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
char	ft_mierder(unsigned int i, char c)
{
	i = 32;
	return (c - i);
}

int	main(void)
{
	char	*src;
	char	*dest;

	src = "La mierda la sole";
	dest = ft_strmapi(src, ft_mierder);
	printf("%s\n", src);
	printf("%s\n", dest);
	write(1, dest, 20);
	return (0);
	free(dest);
}
*/
