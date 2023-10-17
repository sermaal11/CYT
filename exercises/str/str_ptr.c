/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:43 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/03 18:16:43 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char str[] = "supercalifragilisticoespialidoso";
	char *ptr;
	int c;
	int l;
	char target;
	int flag;
	int i;

	// Imprimir cada caracter del string usando un puntero
	
	// El puntero *ptr apunta al inicio del string str
	ptr = str;
	
	// Usamos un bucle while para recorrer el string y en cada iteracion
	// imprimimos el caracter al que apunta el puntero *ptr
	while (*ptr != '\0')
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");

	// Contar la cantidad de caracteres de un string usando un puntero
	
	ptr = str;
	c =  0;
	while (*ptr != '\0')
	{
		ptr++;
		c++;
	}
	printf("La longitud del string es %d.\n", c);

	// Imprimir un string en reversa usando un puntero
	
	ptr = str;
	l = 0;

	while (*ptr != '\0')
	{
		l++;
		ptr++;
	}
	// Retrocedemos un paso para apuntar al ultimo caracter.
	ptr--;
	while (l >= 0)
	{
		printf("%c", *ptr);
		ptr--;
		l--;
	}
	printf("\n");
	
	// Contar las vocales de un string usando un puntero.
	
	ptr = str;
	c = 0;

	while (*ptr != '\0')
	{
		if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
		{
			c++;
		}
		ptr++;
	}
	printf("la cantidad de vocales son: %d\n", c);

	// Encontrar la primera ocurrencia de un char especifico usando un puntero
	
	ptr = str;
	target = 'l';
	i = 0;
	flag = 0;

	while (*ptr != '\0')
	{
		if (*ptr == target)
		{
			flag = 1;
			break;
		}
		ptr++;
		i++;
	}
	if (flag == 1)
	{
		printf("El caracter '%c' esta en la posicion %d", target, i);
	}
	else
	{
		printf("El caracter '%c' no se encontro en el string", target);
	}

	return (0);
}
