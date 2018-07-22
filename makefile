###########################
#	Adrián Valera Román 
###########################
#
# 1. Árboles
# 2. Montículos
# 3. Conjuntos disjuntos
# 4. Grafos
# 5. arboles binarios de busqueda
#
###########################

clear:
	rm *.o *.TAD

###########################
# 1. Arboles
ejercicioRecorridosArbol: Arbol/ejercicioRecorridos.c arbol.o colaArbol.o
	gcc -g Arbol/ejercicioRecorridos.c arbol.o colaArbol.o -o ejercicioRecorridos.TAD
testFuncionamientoArbol: Arbol/testFuncionamientoArbol.c arbol.o genArbol.o colaArbol.o
	gcc -g Arbol/testFuncionamientoArbol.c arbol.o genArbol.o colaArbol.o -o testFuncionamientoArbol.TAD
testFuncionesArbol: Arbol/testFuncionesArbol.c arbol.o genArbol.o colaArbol.o pila.o
	gcc -g Arbol/testFuncionesArbol.c arbol.o genArbol.o colaArbol.o -o testFuncionesArbol.TAD


###########################
# 2. Monticulos
testMonticulo:	Monticulo/testMonticulo.c monticulo.o
	gcc -g Monticulo/testMonticulo.c monticulo.o -o testMonticulo.TAD
testAlgoritmoHeapsortMonticulos:	Monticulo/testAlgoritmoHeapsort.c monticulo.o
	gcc -g Monticulo/testAlgoritmoHeapsort.c monticulo.o -o testAlgoritmoHeapsort.TAD

###########################
# 3. Conjuntos Disjuntos
conjuntosMatrices: Conjuntos/testConjuntos.c Conjuntos/conjuntosMatrices/conjuntos.o
	gcc -g Conjuntos/testConjuntos.c -DMATRICES Conjuntos/conjuntosMatrices/conjuntos.o -o conjuntosMatrices.TAD
conjuntosListas: Conjuntos/testConjuntos.c Conjuntos/conjuntosListas/conjuntos.o
	gcc -g Conjuntos/testConjuntos.c -DLISTAS Conjuntos/conjuntosListas/conjuntos.o -o conjuntosListas.TAD
conjuntosArboles: Conjuntos/testConjuntos.c Conjuntos/conjuntosArboles/conjuntos.o
	gcc -g Conjuntos/testConjuntos.c -DARBOLES Conjuntos/conjuntosArboles/conjuntos.o -o conjuntosArboles.TAD

###########################
# 4. grafos
testGrafosBasico: Grafos/testGrafosBasico.c Grafos/grafos.o cola.o pilaG.o monticuloG.o ConjuntosArbolesG.o
	gcc -g Grafos/testGrafosBasico.c Grafos/grafos.c cola.o pila.o monticulo.o conjuntos.o -o testGrafosBasico.TAD
testGrafosOrdenTopologico: Grafos/testGrafosOrdenTopologico.c Grafos/grafos.o cola.o pilaG.o monticuloG.o ConjuntosArbolesG.o
	gcc -g Grafos/testGrafosOrdenTopologico.c Grafos/grafos.c cola.o pila.o monticulo.o conjuntos.o -o testGrafosOrdenTopologico.TAD
testGrafosCaminos: Grafos/testGrafosCaminos.c Grafos/grafos.o cola.o pilaG.o monticuloG.o ConjuntosArbolesG.o
	gcc -g Grafos/testGrafosCaminos.c Grafos/grafos.c cola.o pila.o monticulo.o conjuntos.o -o testGrafosCaminos.TAD
testGrafosArbolExpansion: Grafos/testGrafosArbolExpansion.c Grafos/grafos.o cola.o pilaG.o monticuloG.o ConjuntosArbolesG.o
	gcc -g Grafos/testGrafosArbolExpansion.c Grafos/grafos.c cola.o pila.o monticulo.o conjuntos.o -o testGrafosArbolExpansion.TAD

###########################
# 5. arboles binarios de busqueda
testArbolBinarioBusqueda_SinNodosRepetidos: ArbolBusqueda/testSinNodosRepetidos.c arbolBB_Sin.o
	gcc -g -DSINREPETIDOS ArbolBusqueda/testSinNodosRepetidos.c arbolBB_Sin.o -o testArbolBinarioBusqueda_SinNodosRepetidos.TAD
testArbolBinarioBusqueda_ConNodosRepetidos: ArbolBusqueda/testConNodosRepetidos.c arbolBB_Con.o
	gcc -g -DCONREPETIDOS ArbolBusqueda/testConNodosRepetidos.c arbolBB_Con.o -o testArbolBinarioBusqueda_ConNodosRepetidos.TAD

###########################
#Estructuras de datos
###########################

# arbol
arbol.o: Arbol/arbol.h Arbol/arbol.c
	gcc -c -g Arbol/arbol.c
genArbol.o: Arbol/genArbol.h Arbol/genArbol.c Arbol/arbol.h Pila/pila.c
	gcc -c -g Arbol/genArbol.c

# cola
cola.o: Cola/cola.h Cola/cola.c
	gcc -g -c Cola/cola.c
colaArbol.o: Cola/colaArbol.h Cola/colaArbol.c
	gcc -g -c Cola/colaArbol.c

# pila
pila.o: Pila/pila.c Pila/pila.h Arbol/arbol.h
	gcc -c Pila/pila.c

# monticulo
monticulo.o: Monticulo/monticulo.h Monticulo/monticulo.c
	gcc -c -g Monticulo/monticulo.c

# conjuntos
Conjuntos/conjuntosMatrices/conjuntos.o: Conjuntos/conjuntosMatrices/conjuntos.c Conjuntos/conjuntosMatrices/conjuntos.h
	gcc -c -g Conjuntos/conjuntosMatrices/conjuntos.c -o Conjuntos/conjuntosMatrices/conjuntos.o
Conjuntos/conjuntosListas/conjuntos.o: Conjuntos/conjuntosListas/conjuntos.c Conjuntos/conjuntosListas/conjuntos.h
	gcc -c -g Conjuntos/conjuntosListas/conjuntos.c -o Conjuntos/conjuntosListas/conjuntos.o
Conjuntos/conjuntosA/conjuntos.o: Conjuntos/conjuntosArboles/conjuntos.c Conjuntos/conjuntosArboles/conjuntos.h
	gcc -c -g Conjuntos/conjuntosArboles/conjuntos.c -o Conjuntos/conjuntosArboles/conjuntos.o

# Grafos
Grafos/grafos.o: Grafos/grafos.c Grafos/grafos.h
	gcc -g -c Grafos/grafos.c
pilaG.o: Grafos/aux/Pila/pila.c Grafos/aux/Pila/pila.h
	gcc -g -c Grafos/aux/Pila/pila.c
monticuloG.o: Grafos/aux/Monticulo/monticulo.c Grafos/aux/Monticulo/monticulo.h
	gcc -g -c Grafos/aux/Monticulo/monticulo.c
ConjuntosArbolesG.o: Grafos/aux/ConjuntosArboles/conjuntos.c Grafos/aux/ConjuntosArboles/conjuntos.h
	gcc -g -c Grafos/aux/ConjuntosArboles/conjuntos.c

# Arboles Binarios Busqueda
arbolBB_Sin.o: ArbolBusqueda/arbolBB.h ArbolBusqueda/arbolBB.c
	gcc -c -g -DSINREPETIDOS ArbolBusqueda/arbolBB.c -o arbolBB_Sin.o
arbolBB_Con.o: ArbolBusqueda/arbolBB.c ArbolBusqueda/arbolBB.h
	gcc -c -g -DCONREPETIDOS ArbolBusqueda/arbolBB.c -o arbolBB_Con.o



