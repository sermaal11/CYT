# Instrucciones basicas para hacer un Makefile

# Definimos una variable llamada "NAME" que contiene el nombre del archivo
# de salida, el cual en este caso se va a llamar "Calculadora.a"

NAME = Calculadora.a

# Definimos una variable llamada "CC" que especifica que compilador se va
# a usar.

CC = gcc

# Definimos una variable llamada CFLAGS que especifica las opciones de 
# compilación. Estas opciones habilitan la generación de advertencias
# detalladas con -Wall y -Wextra, así como convierten las advertencias en 
# errores con -Werror.

CFLAGS = -Wall -Wextra -Werror

# Definimos una variable llamada CALCULADORA que contiene el nombre del archivo
# de encabezado llamado  "calculadora.h". 

CALCULADORA = calculadora.h

# Definimos una variable llamada SRCS que contiene una lista de archivos
# fuente que forman parte del proyecto. En este caso, hay cuatro
# archivos fuente: 

SRCS = sumar.c\
			 restar.c\
			 multiplicar.c\
			 dividir.c

# Definimos una variable llamada OBJS que contiene una lista de archivos
# objeto generados a partir de los archivos fuente en SRCS. Utilizamos una 
# regla de sustitución de sufijo para reemplazar la extensión ".c" por ".o" 
# en los nombres de los archivos fuente.

OBJS = $(SRCS:.c=.o)

# Definimos  una variable llamada all que especifica que el objetivo
# predeterminado para la compilación es el archivo definido en NAME, es
# decir, "Calculadora.a".

all: $(NAME)

# La siguiente regla especifíca cómo se debe crear el archivo "Calculadora.a".
# Indica que para crear "Calculadora.a", se necesitan los archivos objeto
# especificados en OBJS. Debajo de la regla, escribimos la "receta" que se
# ejecuta para construir el archivo "Calculadora.a".
# La explicacion de los comandos seria la siguiente:
#
# 	ar:	Es el comando para crear archivos de biblioteca.
#		-c:	Indica que se deben crear nuevos archivos o actualizar los existentes.
# 	-r:	Indica que se deben agregar o reemplazar archivos en la biblioteca.
# 	-s:	Indica que se debe actualizar el índice de la biblioteca.
# 	$@:	Es una variable especial que se expande al objetivo de la regla,
# 			en este caso, "Calculadora.a".
# 	$^: Es una variable especial que se expande en la lista de dependencias,
# 			en este caso, los archivos objeto en OBJS.

$(NAME) : $(OBJS)
	ar -crs $@ $^

# Esta es una regla implícita que le dice a Make cómo compilar archivos objeto
# (".o") a partir de archivos fuente (".c"). El signo de porcentaje (%) es una
# coincidencia de patrones que representa cualquier nombre de archivo. En este
# caso, establece que cualquier archivo ".c" se compilará en un archivo objeto
# ".o" utilizando la "receta" escrita justo por debajo. Dicha "receta" se
# compone de las siguientes partes:
#
# 	$(CC):			Utiliza el compilador definido en la variable CC, que es "gcc"
# 							en este caso.
# 	-c:					Indica al compilador que solo realice la compilación y no la
# 							vinculación.
# 	$(CFLAGS):	Incluye las opciones de compilación definidas en la variable
# 							CFLAGS.
# 	$<:					Es una variable especial que se expande al primer requisito en
# 							la regla, en este caso, el archivo fuente ".c".
# 	-o $@:			Especifica el nombre del archivo objeto resultante, que es el
# 							objetivo de la regla (el archivo ".o" correspondiente).

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Define un objetivo llamado "clean". Este objetivo se utiliza para eliminar
# los archivos objeto (".o") mediante la "receta" escrita justo debajo. Dicha
# "receta" se compone de las siguientes partes:
# 
# 	rm:		Abreviatura de "remove", sirve para eliminar archivos.
# 	-f:		Abreviatura de "force", en este caso, sirve para forzar las
# 				eliminaciones sin preguntar.
# 	*.o:	El * es el simbolo que se utiliza para "todos" y .o siginifica
# 				archivos que terminan con la extension .o.
#
# En este caso, esta "receta" dice: Eliminar de manera forzada todos los
# archivos con la extension .o.

clean:
	rm -f *.o

# Define un objetivo llamado "fclean". Este objeto tiene como objetivo eliminar
# el archivo biblioteca llamado "Calculadora.a". Esta accion se realiza
# mediante la "receta" escrita justo debajo. Dicha receta se compone de las
# siguientes partes:
#
#		rm:   		Abreviatura de "remove", sirve para eliminar archivos.
#		-f:   		Abreviatura de "force", en este caso, sirve para forzar las
#        			eliminaciones sin preguntar.
#		$(NAME):	Archivo definido en la variable NAME, que es "Calculadora.a".

fclean: clean
	rm -f $(NAME)

#	Define un objetivo llamado "re". Este objetivo se utiliza para reconstruir
#	todo el proyecto desde cero, eliminando primero los archivos existentes y
#	luego compilando nuevamente. La "receta" asociada se compone de las
#	siguientes partes:
#
#	fclean:	Elimina los archivos.
#	all:		Compila nuevamente el proyecto:

re: fclean all

# Esta línea declara que los objetivos "clean", "fclean" y "re" son objetivos
# ficticios (phony targets). Los objetivos ficticios no representan archivos
# reales y siempre se ejecutan, independientemente de si los archivos con esos
# nombres existen o no. Esto se usa comúnmente para evitar conflictos con
# archivos o directorios que pueden tener los mismos nombres que los objetivos.

.PHONY: clean fclean re
