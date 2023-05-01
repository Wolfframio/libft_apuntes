#include "libft.h"
#include <stdio.h>

/*
	Crea un nuevo nodo utilizando malloc(3). 
	La variable miembro ’content’ se inicializa con el contenido del parámetro ’content’. 
	La variable ’next’, con NULL
	
	Parámetros 
	content: el contenido con el que crear el nodo.
	
	Devuelve
	El nuevo nodo
*/

/*
DECLARACION DE NODO T_LIST

typedef struct s_list 			//declaramos el nodo que hay que meterlo en libft.h
{								//es una estructura de nombre s_list
	void			*content; 	//es un puntero a void llamado content que se utiliza para almacenar cualquier tipo de dato en el nodo.
	struct s_list	*next; 		//es un puntero a la misma estructura s_list llamado next, que se utiliza para señalar al siguiente nodo en la lista.  
}					t_list; 	//alias de la estructura s_list. Esto permite que la estructura sea referenciada en el código simplemente como t_list.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list; //decaramos puntero a un nodo de la lista enlazada que se utiliza para almacenar la dirección de memoria del nuevo nodo.

	list = malloc(sizeof(*list)); //reservamos memoria para el nodo
	if (!list)
		return (NULL);
	list->content = content; //se guarda el valor del puntero content pasado como argumento en el puntero content del nuevo nodo
	list->next = NULL; //se inicializa el puntero next del nuevo nodo con NULL para indicar que este es el último nodo de la lista.
	return (list);
}
/*
int	main(void)
{
	char	str[] = "eugenio";
	t_list	*elem;

	elem = ft_lstnew((void *)str);
	printf("Contenido (content) del nodo creado: %s\n", ((char *)elem->content)); //casteamos a char * el void * para usar %s en el printf
	printf("Siguiente nodo (next) del nodo creado: %p\n", elem->next);
	free(elem);
}
*/