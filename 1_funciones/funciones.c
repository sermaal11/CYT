/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:31:39 by sergio            #+#    #+#             */
/*   Updated: 2023/07/03 12:35:00 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Tipos de instrucciones que nos vamos a encontrar en C

// ASIGNACION: 	Una asignacion guarda un valor en la memoria temporal.
//
// CONDICIONAL: Partiendo si se cumple una condicion, se ejecutara un bloqe de codigo
// 							u otro bloque de codigo.
//
// BUCLES:			El programa repetira una serie de instrucciones n numero de veces o 
// 							hasta que una condicion se cunmpla.
//
// LLAMADAS:		Es cuanndo una funcion "llama" o "invoca" a otra funcion. El flujo de 
// 							instrucciones pasa a otra zona del codigo. Una funcion tiene valores de
// 							entrada y valores de salida.
//
// En C todo el codigo va a estar siempre dentro de funciones.
//
// La primera funcion que va a ejecutar el programa es la funcion "main" y dentro de 
// el "main" van a estar la llamadas a las otras funciones que queremos ejecutar.
// 
// Los 4 tipos de datos elementales que nos vamos a encontrar en C son los siguientes:
//
// NUMEROS ENTEROS:	En C se representan con la palabra clave int.
// 
// NUMEROS DECIMALES O FLOTANTES: En C se representan con la palabra clave float. En C
// 																los numeros decimales se representan con un ., como por
// 																ejemplo, 12.3 ó 36.87
//
// Caracteres: En C se representan con la palabra clave char. Representan un caracter 
// 						 de la tabla ASCII. Estos son algunos ejemplos de char: 'a', 'E', '~'...
// 						 Para ver la tabla ASCII en vim usar "man ascii". Los caracteres se 
// 						 representan entre comillas simples ' '.
// 						 Dentro de los caracteres, tenemos las cadenas de caracteres. Las 
// 						 representamos por medio de comillas dobles " ". Un ejemplo de una 
// 						 cadena de caracteres seria "Hola mundo" donde tenemos los caracteres 
// 						 siguientes: 'H' 'o' 'l' 'a' ' ' 'm' 'u' 'n' 'd' 'o'.
//
// Tipo de dato nulo: En c se represneta con la palabra clave void. Lo utilizamos
// 										cuando queremos construir funciones que no devuelven nada, que
// 										esto es algo perfectamente posible. Es decir, funciones que 
// 										ejecuten un trozo de codigo y que no devuelvan nada. Estas 
// 										funciones tambien se pueden llamar procedimientos. Estos
// 										procedimientos son trozos de codigo que ejcutan algo y que 
// 										cuando finalizan,  vuelve a la funcion que la llamo.
//
// Lo siguiente es un archivo de cabecera. Un archivo de cabecera es un archivo que va
// a contener definiciones de funciones. El archivo de cabecera en el que se defien
// printf es la biblioteca stdio.h

#include <stdio.h> 

// Esta funcion main, no tiene parametros de entrada (void) y devuelve un entero int.

int main(void)
{
	printf("Hola Mundo");	// Al termino de cada instruccion debemos escribir un ;

	return (0);						// La palabre return significa devolver.
}


