/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_while.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:58:55 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/03 17:11:26 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char str[] = "supercalifragilisticoespialidoso";
	int i;
	int c;
	int l;
	char target;
	int flag;

	// Recorrer un string e imprimir cada caracter

	i = 0;
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}

	printf("\n");

	// Recorrer un string y contar la cantidad de caracters
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("La longitud del string es: %d\n", i);

	// Recorrer un string en reversa e imprimir cada caracter
	
	i = 0;
	l = 0;
	
	while (str[l] != '\0')
	{
		l++;
	}
	while (l >= 0)
	{
		printf("%c", str[l]);
		l--;
	}

	printf("\n");

	// Recorrer un string y contar la cantidad de vocales
	
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a' || str[i] == 'e' || str [i] == 'i' || str[i] == 'o'
			|| str [i] == 'u')
		{
			c++;
		}
		i++;	
	}
	printf("Cantidad de vocales: %d\n",c);

	// Recorrer un string y encontrar la primera ocurrencia de un caracter especifico
	
	target = 'l';
	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == target)
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1)
	{
		printf("El caracter '%c' se encontro en la posicion %d.\n", target, i);
	}
	else
	{
		printf("El caracter '%c' no se encontro en el string.\n", target);
	}
	return (0);
}
