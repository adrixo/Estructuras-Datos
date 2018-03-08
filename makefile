
#Arboles
ejercicioRecorridos: arbol/ejercicioRecorridos.c arbol.o cola.o
	gcc -g arbol/ejercicioRecorridos.c arbol.o cola.o -o ejercicioRecorridos.TAD

testFuncionamientoArbol: arbol/testFuncionamientoArbol.c arbol.o genArbol.o cola.o
	gcc -g arbol/testFuncionamientoArbol.c arbol.o genArbol.o cola.o -o testFuncionamientoArbol.TAD

#Monticulos


arbol.o: arbol/arbol.h arbol/arbol.c 
	gcc -c -g arbol/arbol.c 

genArbol.o: arbol/genArbol.h arbol/genArbol.c arbol/arbol.h Pila/pila.c
	gcc -c -g arbol/genArbol.c 

cola.o: Cola/cola.h Cola/cola.c arbol/arbol.h
	gcc -g -c Cola/cola.c

pila.o: Pila/pila.c Pila/pila.h arbol/arbol.h
	gcc -c Pila/pila.c
limpiar:
	rm *.o *.TAD



