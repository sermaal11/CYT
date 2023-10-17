/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:31:08 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/04 13:01:00 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

//Reservar memoria para un entero

	int *my_int;

	my_int = (int*)malloc(sizeof(int));
	if (my_int == NULL)
	{
		printf("Error al asignar la memoria\n");
		return (1);
	}

	*my_int = 42;

	printf("El valor de mi entero es %d.\n", *my_int);

	free(my_int);

// Reservar memoria para un array de enteros
	
	int *my_array;
	int len;
	int i;

	len = 5;
	i = 0;

	my_array = (int*)malloc(len * sizeof(int));
	if (my_array == NULL)
	{
		printf("Error al asiganr la memoria\n");
	}
	while (i < len)
	{
		my_array[i] = i * 2;
		printf("Elemento %d del array: %d\n", i, my_array[i]);
		i++;
	}
	free(my_array);

// Reservar memoria para una cadena de caracteres (String)

	char *my_str;
	char txt[] = "Hola mundo";

	my_str = (char *)malloc((strlen(txt) + 1) * sizeof(char));
	if (my_str == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}

	strcpy(my_str, txt);
	printf("String: %s\n", my_str);
	free(my_str);

	return (0);
}
