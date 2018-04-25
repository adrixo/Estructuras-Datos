
#Arboles
ejercicioRecorridosArbol: Arbol/ejercicioRecorridos.c arbol.o colaArbol.o
	gcc -g Arbol/ejercicioRecorridos.c arbol.o colaArbol.o -o ejercicioRecorridos.TAD

testFuncionamientoArbol: Arbol/testFuncionamientoArbol.c arbol.o genArbol.o colaArbol.o
	gcc -g Arbol/testFuncionamientoArbol.c arbol.o genArbol.o colaArbol.o -o testFuncionamientoArbol.TAD

testFuncionesArbol: Arbol/testFuncionesArbol.c arbol.o genArbol.o colaArbol.o pila.o
	gcc -g Arbol/testFuncionesArbol.c arbol.o genArbol.o colaArbol.o -o testFuncionesArbol.TAD

#Monticulos
testMonticulo:	monticulo/testMonticulo.c monticulo.o
	gcc -g monticulo/testMonticulo.c monticulo.o -o testMonticulo.TAD

testAlgoritmoHeapsortMonticulos:	monticulo/testAlgoritmoHeapsort.c monticulo.o
	gcc -g monticulo/testAlgoritmoHeapsort.c monticulo.o -o testAlgoritmoHeapsort.TAD

#Conjuntos Disjuntos
cMatrices: conjuntos/prueba.c conjuntos/conjuntosMatrices/conjuntos.o
	gcc -g conjuntos/prueba.c -DMATRICES conjuntos/conjuntosMatrices/conjuntos.o -o cMatrices.TAD
cListas: conjuntos/prueba.c conjuntos/conjuntosListas/conjuntos.o
	gcc -g conjuntos/prueba.c -DLISTAS conjuntos/conjuntosListas/conjuntos.o -o cListas.TAD
cArboles: conjuntos/prueba.c conjuntos/conjuntosArboles/conjuntos.o
	gcc -g conjuntos/prueba.c -DARBOLES conjuntos/conjuntosArboles/conjuntos.o -o cArboles.TAD

#grafos
ej1: Grafos/ejercicio1.c Grafos/grafos.o cola.o
	gcc -g Grafos/ejercicio1.c Grafos/grafos.c cola.o -o ej2

#####Estructuras de datos
arbol.o: Arbol/arbol.h Arbol/arbol.c
	gcc -c -g Arbol/arbol.c

genArbol.o: Arbol/genArbol.h Arbol/genArbol.c Arbol/arbol.h Pila/pila.c
	gcc -c -g Arbol/genArbol.c

#cola/pila
cola.o: Cola/cola.h Cola/cola.c
	gcc -g -c Cola/cola.c
colaArbol.o: Cola/colaArbol.h Cola/colaArbol.c
	gcc -g -c Cola/colaArbol.c

pila.o: Pila/pila.c Pila/pila.h Arbol/arbol.h
	gcc -c Pila/pila.c

#monticulo
monticulo.o: monticulo/monticulo.h monticulo/monticulo.c
	gcc -c -g monticulo/monticulo.c

#conjuntos
conjuntos/conjuntosMatrices/conjuntos.o: conjuntos/conjuntosMatrices/conjuntos.c conjuntos/conjuntosMatrices/conjuntos.h
	gcc -c -g conjuntos/conjuntosMatrices/conjuntos.c -o conjuntos/conjuntosMatrices/conjuntos.o
conjuntos/conjuntosListas/conjuntos.o: conjuntos/conjuntosListas/conjuntos.c conjuntos/conjuntosListas/conjuntos.h
	gcc -c -g conjuntos/conjuntosListas/conjuntos.c -o conjuntos/conjuntosListas/conjuntos.o
conjuntos/conjuntosA/conjuntos.o: conjuntos/conjuntosArboles/conjuntos.c conjuntos/conjuntosArboles/conjuntos.h
	gcc -c -g conjuntos/conjuntosArboles/conjuntos.c -o conjuntos/conjuntosArboles/conjuntos.o

#Grafos
Grafos/grafos.o: Grafos/grafos.c Grafos/grafos.h
	gcc -g -c Grafos/grafos.c

limpiar:
	rm *.o *.TAD
