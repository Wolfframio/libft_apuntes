/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:56:52 by imontero          #+#    #+#             */
/*   Updated: 2023/05/02 12:02:10 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Itera la lista ’lst’ y aplica la función ’f’ al
	contenido de cada nodo. 
	Crea una lista resultante de la aplicación correcta
	y sucesiva de la función ’f’ sobre cada nodo. 
	La función ’del’ se utiliza para eliminar el contenido
	de un nodo, si hace falta.

	Parámetros lst: un puntero a un nodo.
	- f: la dirección de un puntero a una función usada
	en la iteración de cada elemento de la lista.
	- del: un puntero a función utilizado para eliminar
	el contenido de un nodo, si es necesario.

	Valor devuelto 
	- La nueva lista.
	- NULL si falla la reserva de memoria.
*/