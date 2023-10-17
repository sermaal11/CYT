/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_variadicas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:28:52 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/17 20:23:18 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// Printf es una funcion variadica, es decir, acepta de 1 a n parametros.

// Para que funcione una funcion variadica, vamos a necesitar incluir una 
// libreria llamada #include <stdarg.h>.

// Para indicar que una funcion tiene un numero variable de argumentos,
// tenemos que poner un parametro especial que es el triple punto (...) y
// ademas es muy importante que haya un parametro previo porque el estandar
// de C asi lo requiere.
//
// Para poder utilizar los parametros variadicos (...), lo primero que tendre
// que hacer es declarar una variable local de tipo va_list que es uno de 
// los tipos que esta incluido en <stdarg.h>

// Ejemplo de funcion variadica:

int sumatorio(int n, ...)
{
	va_list argumento;
	int acumulado = 0;
	int i = 0;
	printf("Iniciamos argumentos\n");
	
	// Para inicializar la variable va_list, tenemos que llamar a la macro
	// va_start que tambien esta presente en <stdarg.h> pasandole como primer
	// paramtro el va_list que acabamos de crear y como segundo parametro, el 
	// parametro que valla justo antes del paramtro variadico de la funcion, es
	// decir, el parametro anterior al triple punto (...)
	
	va_start(argumento, n);

	// Para recorrer los argumentos variadicos de nuestra funcion, parra ello
	// utilizaremos una macro mas, tambien incluida en <stdarg.h> que se 
	// denomina va_arg y nos va a perimitir el siguiente parametro de la lista.
	// Para ello le pasaremos como primer  parametro nuestro va_list y como
	// segundo parametro el tipo de datos que hay, pues con el triple
	// punto (...), no especificamos el tipo de dato que toma la funcion.

	while (i < n)
	{
		int sig_param = va_arg(argumento, int);
		printf("El siguiente parametro es un %d\n", sig_param);
		acumulado = acumulado + sig_param;
		i++;
	}

	printf("Termnamos argumentos\n");

	// Es importate que antes de cerrar la funcion, llamemos a la macro va_end
	// especificandole como parametro la variable local va_list que queremos 
	// cerrar.
	
	va_end(argumento);
	return (acumulado);
}

int	main (void)
{
	int total = sumatorio(3, 1, 2, 3);

	// Es IMPORTANTE que no llamemos a va_arg mas veces de la cantidad de
	// argumentos variadicos que hayamos proporcionado a la funcion, porque
	// si no, accederemos a posiciones de memoria que no corresponden.

	printf("Total: %d\n", total);
	return (0);
}
