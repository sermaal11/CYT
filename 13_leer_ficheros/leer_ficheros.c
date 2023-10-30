/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_ficheros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:51:19 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/30 14:58:38 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// En este ejercicio vamos a ver como leer un fichero. Para ello utilizaremos 
// las funciones opem, read y close.
//
// Estas funciones tienen la siguientes sintaxis:
//
// 	Open: 	int	open(const char *pathname, int flags);
// 	Read:	ssize_t	read(int fd, void *buf, size_t count);
// 	Close:	int	close(int fd);
//

#include <fcntl.h>
#include <unistd.h>

// Los dos archivos de cabecera anteriores son para poder utilizar las
// funciones open, read y close.

#include <stdio.h>

int	main(void)
{
	// Lo primero, definimos una variable de tipo int llamada fd.
	
	int	fd;
	
	// fd va a ser nuestro file descriptor, un entero que va a devolver la
	// funcion open y que es algo asi como un indicador del fichero.
	// Mediante la funcion open vamos a abrir el fichero.
	// El primer argumento, va a ser el pathname, es decir la ruta del
	// fichero.
	// El segundo argumento va a saer una flag, y va a ser el modo de acceso
	// a ese ficher cuando lo abramos.
	// Las diferentes flags que podemos incluir son las siguientes:
	//
	// 	O_RDONLY: Abrir el archivo solo para lectura.
	// 	O_WRONLY: Abrir el archivo solo para escritura.
	// 	O_RDWR: Abrir el archivo para lectura y escritura.
	// 	O_APPEND: Añadir al final del archivo al escribir.
	// 	O_CREAT: Crear el archivo si no existe.
	// 	O_EXCL: Usado con O_CREAT, el llamado fallará si el archivo ya existe.
	// 	O_TRUNC: Truncar el archivo a longitud cero si ya existe.
	// 	O_SYNC: Escribe los cambios de manera sincrónica (espera a que los 
	// 	datos se escriban físicamente).
	// 	O_NONBLOCK: Abrir en modo no bloqueante.
	// 	O_NOCTTY: Si el archivo que se está abriendo es un TTY (terminal), 
	// 	no lo haga el TTY del proceso.
	// 	O_DSYNC: Escribe los cambios de manera sincrónica, pero solo la
	// 	información de datos (no la metadata).
	// 	O_NOFOLLOW: No seguir enlaces simbólicos (en sistemas que los soportan).
	// 	O_DIRECTORY: Falla si el archivo no es un directorio (en sistemas que
	// 	lo soportan).
	// 	O_LARGEFILE: Permite abrir archivos que son más grandes que lo que el
	// 	sistema operativo normalmente permitiría (en sistemas que lo soportan).
	//
	// Estas flags se pueden combinar usando el operador |.
	
	char	buf[10];
	ssize_t	num_bytes;

	fd = open("/Users/smarin-a/documents/cyt/13_leer_ficheros/textos/chito_ipsum.txt", O_RDONLY );
	
	// Si la funcion open produce algun error, como por ejemplo si el archivo no
	// existiese o no se pudiese abrir devolveria un valor de "-1".
	// para ello, realizariamo un control de errores con un if
	
	if (fd == -1)
	{
		printf("Error al abrir el archivo.\n");
	}
	else
	{
		// El primer argumento va a ser nuestro fd, el segundo va a ser un
		// buffer que va a almacenar los bytes leidos, y el tercer argumento
		// va a ser el numero de bytes que como maximo vamos a leer del
		// fichero.
		// Esta funcion va a devolver un numero de tipo ssize_t que va a ser el
		// numero de caracteres que se han leido.

		num_bytes = read(fd, buf, 5);

		// Despues de operar con un fichero, es importante cerrarlo, si no 
		// podriamos tener problemas. Para ello utilizamos la funcion close.
		// El argumento que toma close es nuestro fd.

		close(fd);

		if (num_bytes == 0)
		{
			printf("El archivo esta vacio.\n");
		}
		else
		{
			printf("El numero de caracteres leidos es %zd, y el contenido es: %s.\n", num_bytes, buf);
		}
	}
	return (0);	
}
