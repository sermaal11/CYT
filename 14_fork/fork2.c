/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:40:49 by sergio            #+#    #+#             */
/*   Updated: 2024/02/19 20:26:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // fork()
#include <stdio.h>	// printf()
#include <sys/wait.h> // wait() y waitpid()
#include <stdlib.h> // exit()

/*
pid_t fork(void);
	Esta función crea un nuevo proceso duplicando el proceso que la llama. El
	nuevo proceso, llamado proceso hijo, es una copia exacta del proceso que le
	dio origen, llamado proceso padre. Después de que fork() es llamada, ambos
	procesos se ejecutan simultáneamente. Ambos procesos tendrán el mismo
	código, los mismos datos, los mismos descriptores de archivos, los mismos
	recursos, los mismos límites de memoria, etc. En lo que difieren es en su
	PID (identificador de proceso).

pid_t wait(int *wstatus);
	Esta función suspende la ejecución del proceso que la llama hasta que un
	proceso hijo termine. Si el proceso hijo ya ha terminado, la función
	retorna inmediatamente. La función wait() almacena el estado de salida del
	proceso hijo en la variable wstatus si no es NULL. El valor de retorno es
	el PID del proceso hijo que terminó. Si se produce un error, la función
	retorna -1. 

WEXITSTATUS(wstatus)
	Este macro devuelve el estado de salida de un proceso hijo. El argumento
	wstatus debe ser el valor devuelto por wait() o waitpid(). Si el proceso
	hijo terminó normalmente, el valor devuelto es el valor devuelto por el
	proceso hijo. Si el proceso hijo terminó debido a una señal, el valor
	devuelto es 255.
*/

int main()
{
	int num_child;
	int ret_child;
	pid_t pid_child;
	int status;

	num_child = 5;
	while (num_child > 0)
	{
		// Crea un nuevo proceso. Se generará una llamada al sistema.
		// Este porceso es un proceso hijo.
		pid_child = fork();
		// Este if es para el proceso padre.
		if (pid_child > 0)
		{

		}
		// Este else if es para el proceso hijo.
		else if (pid_child == 0)
		{
			// srand() inicializa la semilla del generador de números aleatorios.
			// srand() debe ser llamada antes de llamar a rand().
			// srand usa como semilla el PID del proceso hijo.
			srand(getpid());
			// rand() devuelve un número entero aleatorio entre 0 y 255.
			ret_child = rand() % 256;
			// El proceso hijo termina con el valor ret_child.
			(printf("Proceso hijo: PID = %d, random value calculado: %d\n", getpid(), ret_child));
			exit(ret_child);
		}
		else
		{
			printf("Error al crear el proceso hijo\n");
		}
		num_child--;
	}
	while (num_child < 5)
	{
		// La función wait() suspende la ejecución del proceso que la llama
		// hasta que un proceso hijo termine.
		pid_child = wait(&status);
		printf("Prooceso padre: PID = %d, hijo con PID = %d terminado, status del hiijo = %d\n", getpid(), pid_child, WEXITSTATUS(status));
		num_child++;
	}
}

