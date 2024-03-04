/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:28:08 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 15:43:38 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fork y pipe.

El pipe es un mecanismo de comunicación entre procesos que permite la
comunicación entre un proceso padre y un proceso hijo. El pipe es unidireccional
y se utiliza para la comunicación entre procesos.
Los datos fluyen del extremo de escritura al extremo de lectura. 
El pipe va asociado a dos file descriptors, uno para el extremo de escritura y
otro para el extremo de lectura. Con un file descriptor se escribe en el pipe y
con el otro se lee del pipe.

Las funciones que se utilizan para trabajar con pipes son:

int pipe(int pipefd[2]); fd[0] es el extremo de lectura y fd[1] es el extremo de
escritura. Devuelve 0 si tiene éxito y -1 si hay un error.
EL argumento es un array de dos enteros que se utilizan para almacenar los file
descriptors del pipe.

ssize_t read(int fd, void *buf, size_t count); Lee datos del pipe. Devuelve el
número de bytes leídos o -1 si hay un error. Si el extremo de escritura del pipe
está cerrado, read() devolverá 0.

ssize_t write(int fd, const void *buf, size_t count); Escribe datos en el pipe.
Devuelve el número de bytes escritos o -1 si hay un error. Si el extremo de
lectura del pipe está cerrado, write() devolverá un error.

int close(int fd); Cierra el file descriptor. Devuelve 0 si tiene éxito y -1 si
hay un error. COn esta funcion cerramos el extremo de escritura o de lectura del
pipe.

int wait(int *status); Espera a que un proceso hijo termine. Devuelve el PID del
proceso hijo que ha terminado o -1 si hay un error.

Un proceso padre crea un prceso hijo que se comunica con el padre a través del
pipe.

Lo primero que hace el padre es crear el pipe con la función pipe() con el
argumento fd que es un array de dos enteros. Esta funcion devulve 0 si tiene
éxito y -1 si hay un error. Si tiene exito, el retorno son dos file descriptors
que se utilizan para leer y escribir en el pipe.

Después de crear el pipe, el padre crea un proceso hijo con la función fork().
Este proceso hijo hereda los file descriptors del pipe del padre. Los file
descriptosr de escritura y de lectura. El padre sera el que lea y el hijo el
que escriba.

Lo siguiente que hace el padre es cerrar el file descriptor de escritura con la
función close(). El padre solo va a leer del pipe, no va a escribir.
*/

#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <unistd.h> // fork(), pipe(), read(), write(), close()

int main()
{
	int fd[2];
	pid_t	pid;
	char buffer[9];

	// Creamos el pipe
	pipe(fd);
	if (pipe(fd) == -1)
		perror("Error al crear el pipe.\n");

	// Creamos el proceso hijo con fork() y comprobamos si se ha creado bien.
	pid = fork();
	if (pid == 0) //Proceso del hijo
	{
		//Cerramos el estremo de lectura del pipe del hijo.
		close(fd[0]);

		//Escribimos en el pipe. Primero el file descriptor, luego el mensaje o 
		//el buffer y por último el tamaño del buffer.
		write(fd[1], "Hola papa", 9);

		//Cerramos el estremo de escritura del pipe del hijo.
		close(fd[1]);

		//Salimos del proceso hijo.
		exit(0);
	}
	else if (pid > 0) //Proceso del padre
	{
		//Cerramos el estremo de escritura del pipe del padre.
		close(fd[1]);

		//Leemos del pipe. Primero el file descriptor, luego el mensaje o el
		//buffer y por cantidad de bytes que queremos leer.
		read(fd[0], buffer, sizeof(buffer));

		//Cerramos el estremo de lectura del pipe del padre.
		close(fd[0]);

		//Mediante la funcion wait() esperamos a que el hijo termine antes de
		//terminar el padre.
		wait(NULL);

		//Imprimimos el mensaje que hemos leido del pipe.
		printf("Mensaje leido del pipe: %s\n", buffer);

		//Salimos del proceso padre.
		exit(0);
	}
	else
	{
		perror("Error al realizar el fork. Hijo no creado.\n");
	}
	return (0);
}