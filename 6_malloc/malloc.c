/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:47:30 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/04 12:10:45 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// La memoria dinamica la tenemos que gestionar manualmente, y eso incluye 
// liberarla cuando no la necesitemos para no estropear la memoria de nuestro
// programa y que se quede sin memoria por alguna causa accidental.
//
// Para trabajar con memoria dinamica, vamos a trabajar con la funcion
// malloc.
// La sintaxis de malloc es la siguiente: void *malloc(size_t size)
// Malloc tiene un parametro que indica cuantos bytes queremos reservar para
// nuestro espacio de memoria y con ello nos devolvera un buffer que podemos
// guardar en una variable para acceder a el y guardar lo que queramos.
//
// Para utilizarla de manera segura, siempre debemos multiplicar por el
// tamano del tipo de dato que queremos utilizar.
//
// Los datos tienen los siguientes tamanos:
//
// Para plataformas de 32 bits:
//
// char: 1 byte.
// short: 2 bytes.
// int: 4 bytes
// long: 4 bytes.
// float: 4 bytes.
// double: 4 bytes.
// long double: 12 bytes.
// puntero: 4 bytes.
//
// Para plataformas de 64 bytes:
//
// char: 1 byte.
// short: 2 bytes.
// int: 4 bytes.
// long: 8 bytes.
// float: 4 bytes.
// double: 8 bytes.
// long double: 16 bytes.
// puntero: 8 bytes.
//
// Para no tener que memorizar estos tamanos, tenemos a nuestra disposicion
// la funcion sizeof(), en la que si por ejemplo queremos utiizar el
// tamano de un char, la funcion tendra el siguiente aspecto: sizeof(char)
//
// Por otro lado, malloc es una funcion que devuelve un puntero de
// tipo void, es decir, void *, es decir, que tenemos que convertirlo a un
// puntero que queramos manejar.
// Esto siginifca que si queremos guardar char, por ejemplo, deberemos
// convertirlo  a un puntero del tipo char. Por ejemplo, si quisiesemos 
// reservar memoria para guardar 1200 char, la sintaxis de malloc seria la
// siguiente: char* malloc(1200 * sizeof(char))
// 
// Este malloc podriamos guardarlo en una variable la cual tendremos que
// castearla para que se convierta de void* a char puntero*, por lo que 
// la sintaxis quedaria de la siguiente manera:
//
// char* nombres;
// nombres = (char*) malloc(1200 * sizeof(char));
//
// De esta forma, nuestra memoria ya estara reservada y lista para utilizar.
//
// Cuando malloc falla, devuelve un NULL, por lo que siempre es recomedable
// verificar que lo que nos ha devuelto no es un NULL.
//
// Esto lo podemos verificar realizando un if con la siguiente sintaxis:
//
// if (nombres == NULL)
// {
//		printf("No hay tanta memoria disponible.\n");
//		rerturn (1);
// }
//
// Por ultimo, es importante que cuando ya vayamos a dejar de utilizar una
// zona de memoria que hemos reservado con malloc la liberemos.
//
// Para liberar la memoria utilizaremos la funcion free.
// El parametro que tiene free es un puntero al buffer que queramos eliminar
// y una vez que lo hayamos llamado, automaticamente, esa zona de memoria 
// habra quedado liberada.
//
// En este caso, para liberar la memoria que hemos reservado para nombres
// con malloc, escribiramos free(nombres).
//
// Una consecuencia muy importante de llamar a free, es que no podemos esperar
// que ese array contenga valores utiles, es decir, despues del free, no 
// podemos utilizar la variable nombres a no ser que hagamos un malloc de
// nuevo.

int main(void)
{
	char* nombres;
	int i;
	
	nombres = (char*) malloc(10 * sizeof(char));
	i = 0;

	if (nombres == NULL)
	{
		printf("No tienes tanta memoria disponible.\n");
		return (1);
	}
	while (i < 10)
	{
		i++;
	}
	printf("Todo ok");
	free(nombres);
	return (0);
}
