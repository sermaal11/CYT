/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:18 by smarin-a          #+#    #+#             */
/*   Updated: 2023/09/27 12:34:15 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Un array es una forma de organizar en memoria datos, declarando un numero
// de datos en posiciones contiguas de memoria.
// 
// Cuando construimos un array, lo que ocurre en memoria es que en vez de 
// reservar espacio para guardar una variable, se declara en memoria espacio
// para guardar n variables y todas ellas se utilizan con el mismo
// identificador.
//
// Para refirirnos a una posicion en concreto, utilizaremos un indice.
// Por medio de ese indice, podemos conseguir que se establezca un valor en
// esa variable o que se obtenga el valor de esa variable siempre en terminos
// de indices, es decir, nos situaremos en la celda concreta del array
// que nos interesa y ahi escribimos o leemos la informacion deseada.
//

int main(void)
{
// Para declarara un array lo haremos como si declarasemos cualquier tipo
// de variable, con la diferencia, que entre corchetes cuadrados [], indicamos
// el tamaño que va a tener ese array, es decir, cuantas "celdas" de memoria 
// vamos a necesitar.
	
	int edades[8];	//Array de enteros de 8 posiciones consecutivas
	int i;

// Para guardar valores en posicones especificas lo haremos de la siguiente 
// manera: Pondremos el nombre del identificador, y entre corchetes cuadrados
// [], la posicion del array que quiero escribir, en este caso, en el array
// edades, vamos a guardar el numero 5 en la posicion 2 del array.
// Hemos de tener en cuenta que los arrays SIEMPRE empiezan a contar desde la
// posicion 0, por lo que en este momento, el array se encuntra distribuido de
// la siguiente forma:
//
// edades = [5]
//
//    0     1     2     3     4     5     6     7
// |     |     |  5  |     |     |     |     |     |
//
// Esta inicializacion del array no es lo mas correcto, pues hemos
// inicializado la posicion numero 2, pero el resto ha quedado sin
// inicializar.
//
// Cuando se declara una array, al igual que cuando se declara cualquier
// otro tipo de variable, lo que ocurre es que C va a reservar un espacio 
// de memoria, pero NUNCA se va a preocupar de limpiar lo que antes 
// hubiese ahi. Es decir, que si algun otro programa del ordenador
// ha utilizado ese espacio de memoria en algun momento, se van a quedar los 
// valores que haya utilizado ese programa, xq la memoria RAM normalmente
// no se limpia, salvo que lo hagamos nosotros mismos.
// 
// Por lo tanto, es importante que las variables tengan valores iniciales 
// para evitarnos ese problema, lo que devemos hacer es inicializar todo el 
// array desde un principio. Esto lo haremos de la siguinte forma debido a la
// norma V3 de 42.
//

	edades[0] = 3;
	edades[1] = 7;
	edades[2] = 23;
	edades[3] = 14;
	edades[4] = 33;
	edades[5] = 12;
	edades[6] = 90;
	edades[7] = 2;
	i = 0;

// Veamos como queda la informacion estructurada en el array:

	while (i < 8)
	{
		printf("Edades[%d] = %d\n", i, edades[i]);
		i++;
	}
	
	return (0);
}
