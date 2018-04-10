
#Arboles
ejercicioRecorridosArbol: arbol/ejercicioRecorridos.c arbol.o cola.o
	gcc -g arbol/ejercicioRecorridos.c arbol.o cola.o -o ejercicioRecorridos.TAD

testFuncionamientoArbol: arbol/testFuncionamientoArbol.c arbol.o genArbol.o cola.o
	gcc -g arbol/testFuncionamientoArbol.c arbol.o genArbol.o cola.o -o testFuncionamientoArbol.TAD

#Monticulos
testMonticulo:	monticulo/testMonticulo.c monticulo.o
	gcc -g monticulo/testMonticulo.c monticulo.o -o testMonticulo.TAD

testAlgoritmoHeapsortMonticulos:	monticulo/testAlgoritmoHeapsort.c monticulo.o
	gcc -g monticulo/testAlgoritmoHeapsort.c monticulo.o -o testAlgoritmoHeapsort.TAD

#Conjuntos Disjuntos
cMatrices: conjuntos/prueba.c conjuntos/conjuntosMatrices/conjuntos.o
	gcc -g conjuntos/prueba.c -DMATRICES conjuntos/conjuntosMatrices/conjuntos.o -o cMatrices
cListas: conjuntos/prueba.c conjuntos/conjuntosListas/conjuntos.o
	gcc -g conjuntos/prueba.c -DLISTAS conjuntos/conjuntosListas/conjuntos.o -o cListas
cArboles: conjuntos/prueba.c conjuntos/conjuntosArboles/conjuntos.o
	gcc -g conjuntos/prueba.c -DARBOLES conjuntos/conjuntosArboles/conjuntos.o -o cArboles

#grafos
#

#####Datos
arbol.o: arbol/arbol.h arbol/arbol.c
	gcc -c -g arbol/arbol.c

genArbol.o: arbol/genArbol.h arbol/genArbol.c arbol/arbol.h Pila/pila.c
	gcc -c -g arbol/genArbol.c

#cola/pila
cola.o: Cola/cola.h Cola/cola.c arbol/arbol.h
	gcc -g -c Cola/cola.c

pila.o: Pila/pila.c Pila/pila.h arbol/arbol.h
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
Grafos/cola.o: Grafos/cola.c Grafos/cola.h
	gcc -g -c Grafos/cola.c

limpiar:
	rm *.o *.TAD
