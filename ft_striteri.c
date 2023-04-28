#include "libft.h"

/*
	A cada carácter de la string ’s’, aplica la función
	’f’ dando como parámetros el índice de cada
	carácter dentro de ’s’ y la dirección del propio
	carácter, que podrá modificarse si es necesario.

	-Parámetros 
	s: La string que iterar.
	f: La función a aplicar sobre cada carácter.

	-Valor devuelto
	Nada
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]); //f espera un puntero a un char y le pasamos la direccion de memoria de esa posición del str
		i++;
	}
}

void print_char_index(unsigned int index, char* ch) {
    printf("El caracter en la posicion %d es %c\n", index, *ch);
}

int main() {
    char str[] = "vaaaaalgame primo";
    
    ft_striteri(str, &print_char_index);
    
    return 0;
}
