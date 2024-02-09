/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:51:35 by sergio            #+#    #+#             */
/*   Updated: 2024/02/09 23:46:51 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
La función fork() crea un nuevo proceso duplicando el proceso que la llama.
El nuevo proceso, llamado proceso hijo, es una copia exacta del proceso que le 
dio origen, llamado proceso padre. Después de que fork() es llamada, ambos
procesos se ejecutan simultáneamente.
Ambos procesos tendrán el mismo código, los mismos datos, los mismos 
descriptores de archivos, los mismos recursos, los mismos límites de memoria, 
etc.
En lo que difieren es en su PID (identificador de proceso).
*/

/*
Uso: pid_t fork(void);

Parámetros: Ninguno.

Valor de retorno: 0 en el proceso hijo, > 0 en el proceso padre y -1 en caso de
error siendo el hijo NO creado.

Libreria a incluir: #include <unistd.h>

Ejemplo:	pid_t pid = fork();
			Ese pid_t pid es el PID del proceso hijo.
*/

#include <unistd.h>
#include <stdio.h>

// Variable global
int var = 21;

int main(void)
{
	pid_t pid_child;
	printf("Antes del fork\n");
	//getpid() devuelve el PID del proceso que la llama.
	printf("Proceso padre: PID %d\n", getpid());
	// La funcion fork crea un nuevo proceso. Se generará una llamada al sistema.
	pid_child = fork();
	// Este proceso se ejecutará 2 veces, una en el proceso padre y otra en el 
	// proceso hijo.
	printf("Proceso PID: %d, pid_child: %d\n", getpid(), pid_child);
	if (pid_child > 0)
	{
		var = 42;
	}
	else if (pid_child == 0)
	{
		var = 84;
	}
	else
	{
		printf("Error al crear el proceso hijo\n");
	}
	while (1)
	{
		sleep(2);
		printf("Proceso PID: %d, var: %d\n", getpid(), var);
	}
	return 0;
}