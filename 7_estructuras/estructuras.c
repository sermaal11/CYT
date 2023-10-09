/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estructuras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:48:00 by smarin-a          #+#    #+#             */
/*   Updated: 2023/09/28 13:13:14 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Con estructuras lo que hacemos basicamente es agrupar variables en un
// bloque y a ese bloque darle un identificador.
// Luego, podemos construir esos bloques mediante simples instrucciones
// sencillas y asignar los datos a cada una de las variables de ese bloque.
//
// El primer paso, pasa por declarar la estructura como tal.
// Para ello usamos la palabra struct, luego el identificador y despues
// pondriamos los corchetes {} como si se tratase de una funcion.
// Dentro de los corchetes ira el codigo que define las distintas variables
// que tiene esa estructura.
// Es importante que despues del corchete de cierre } de una estructura,
// escribamos un ;.
//
// Aqui tenemos construido una estructura de 4 campos. Cada variable se
// convertira en un campo y con una sintaxis especial podremos acceder y
// manipular cada uno de los campos de la estructura.
struct s_cuenta
{
	char nombre[30];
	char apellido[40];
	int identificador;
	int saldo;
};

// Una vez tengo declarado el identificador, lo puedo usar de forma normal, es
// decir, puedo usarlo para pasarlo como parametro de una funcion.
// Para ello vamos a crear una funcion llamada imprimir datos

void imprimir_datos(struct s_cuenta *c)
{
	printf("El cliente %s %s con el identificado %d tiene %d en su cuenta. \n",
			(*c).nombre, (*c).apellido, (*c).identificador, (*c).saldo);
}

int main(void)
{

// Con esto, lo que tenemos es una variable llamada c1 del tipo struct cuenta.

	struct s_cuenta c1;

// Tambien puedo manipular los campos de c1, para ello, utilizaremos la 
// siguiente sintaxis para manipular estructuras y acceder a sus campos.
//
// Simplemente, para acceder al campo de una estructura, debemos escribir
// el identificador de la estructura¡, seguido de un . y el nombre del 
// campo.
	strcpy(c1.nombre, "Sergio");
	strcpy(c1.apellido, "Marin");
	c1.identificador = 72891738;
	c1.saldo = 400;

	imprimir_datos(&c1);

	return (0);
}
