/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bibliotecas_estaticas.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:20:36 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/21 17:47:52 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Una biblioteca sirve para aportar funciones a otros proyectos que necesiten
// utilizarlas. Otra de las ventajas de las bibliotecas es que nos permiten
// distribuir facilmente el codigo que hay dentro de ellas. Las bibliotecas
// son un pilar fundamental a la hora de realizar software ya que nos van a
// facilitar el trabajo.

// A la hora de realizar bibliotecas, existen 2 tipos bibliotecas estaticas y
// bibliotecas dinamicas. En este caso, nos centraremos en la bibliotecas
// estaticas.

// Una biblioteca estatica, es la forma mas simple de crear una biblioteca.
// Se trata de un archivo empaquetado, como si de un .zip se tratase y dentro
// de ese archivo va a estar todo el codigo objeto de nuestra biblioteca.
//
// Como ejemplo, trabajaremos con un archivo .h, que sera nuestra biblioteca
// en si, la cual contendra 4 funciones, llamadas dividir.c, multiplicar.c,
// restar.c, sumar.c.

// Este archivo, "bibliotecas_estaticas.c" sera nuestro main en el cual
// realizaremos nuestras pruebas y comprobaremos que nuestra biblioteca
// funciona.

// Para ello, debemos incluir todas las bibliotecas que vamos a utilizar. En
// estre caso, añadiremos ENTRE COMILLAS DOBLES "",la siguiente declaracion.

#include "calculadora.h"

// Una vez incluida la biblioteca, crearemos nuestro main.

int	main(void)
{
	int res;

	printf("3 + 2 = %d \n", sumar(3, 2));
	printf("3 - 2 = %d \n", restar(3, 2));
	printf("3 * 2 = %d \n", multiplicar(3, 2));
	dividir(6, 2, &res);
	printf("3 / 2 = %d \n", res);
	return (0);
}
