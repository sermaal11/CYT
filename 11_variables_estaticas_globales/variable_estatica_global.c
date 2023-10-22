 ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:41:21 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/22 22:00:32 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Una variable  global es una variable a la que podremos accder desde
// cualquier funcion, a diferencia de una variable local, que solo tiene
// validez dentro de los corchetes {} en la que la variable este contenido.

// Una variable estatica la declaramos en el nivel mas alto, es decir, fuera
// de una funcion.

// El principal problema de las variable estaticas es que han de estar bien
// identificadas, porque si no es muy facil perder el origen de la misma.
// Para ello, cada vez que definamos una variable globlal, la nombraremos con
// el prefijo g_, --> g_name_variable.

int	g_total = 0;
int	g_acumulado = 0;

void	asignar(void)
{
	acumulado = 25;
	total = 4;
}

void	media(void)
{
	float	media;

	media = ((float) acumulado) / total;
	printf("La media es %f.\n", media);
}

int	main(void)
{
	asignar();
	media();
	return (0);
}
