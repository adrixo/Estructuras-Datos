# Ejercicio 1
cMatrices:prueba.c conjuntosMatrices/conjuntos.o  
	gcc -g prueba.c -DMATRICES conjuntosMatrices/conjuntos.o -o cMatrices
conjuntosMatrices/conjuntos.o: conjuntosMatrices/conjuntos.c conjuntosMatrices/conjuntos.h
	gcc -c -g conjuntosMatrices/conjuntos.c -o conjuntosMatrices/conjuntos.o
# Ejercicio 2
cListas:prueba.c conjuntosListas/conjuntos.o 
	gcc -g prueba.c -DLISTAS conjuntosListas/conjuntos.o -o cListas
conjuntosListas/conjuntos.o: conjuntosListas/conjuntos.c conjuntosListas/conjuntos.h
	gcc -c -g conjuntosListas/conjuntos.c -o conjuntosListas/conjuntos.o
# Ejercicio 3 
cArboles:prueba.c conjuntosArboles/conjuntos.o 
	gcc -g prueba.c -DARBOLES conjuntosArboles/conjuntos.o -o cArboles
conjuntosA/conjuntos.o: conjuntosArboles/conjuntos.c conjuntosArboles/conjuntos.h
	gcc -c -g conjuntosArboles/conjuntos.c -o conjuntosArboles/conjuntos.o

