# Sesión 2 Implementación de las funciones del ejercicio2

# Ejercicio 1: Recorridos en árboles binarios

ejercicio1: ejercicio1.c arbol.o cola.o
	gcc -g ejercicio1.c arbol.o cola.o -o ejercicio1

# Ejercicio 2: Aplicar las funciones recursivas del ejercicio2 a los arboles de los ejercicios 1 y 3

# Sesión 1 	Aplicación de los TAD's pila y cola en la generación y recorrido de árboles binarios

ejercicio3: ejercicio3.c arbol.o genArbol.o cola.o
	gcc -g ejercicio3.c arbol.o genArbol.o cola.o -o ejercicio3

arbol.o: arbol/arbol.h arbol/arbol.c 
	gcc -c -g arbol/arbol.c 

genArbol.o: arbol/genArbol.h arbol/genArbol.c arbol/arbol.h Pila/pila.c
	gcc -c -g arbol/genArbol.c 

cola.o: Cola/cola.h Cola/cola.c arbol/arbol.h
	gcc -g -c Cola/cola.c

pila.o: Pila/pila.c Pila/pila.h arbol/arbol.h
	gcc -c Pila/pila.c
limpiar:
	rm *.o



