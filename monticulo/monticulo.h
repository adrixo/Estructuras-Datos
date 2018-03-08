#define MAXIMO 100

typedef int tipoClave ;
typedef int tipoInfo ;

typedef struct
{ tipoClave clave;
   tipoInfo  informacion;
} tipoElemento;

typedef struct
{ tipoElemento elemento[MAXIMO];
    int tamanno;
} Monticulo;


/* Ejercicio 1 */

void iniciaMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
int insertar(tipoElemento x, Monticulo *m);
int eliminarMinimo(Monticulo *m, tipoElemento *minimo);
void decrementarClave(int pos, int cantidad, Monticulo *m);
void incrementarClave(int pos, int cantidad, Monticulo *m);
int esMonticulo(Monticulo m);

/* Funciones auxiliares que conviene implementar: las dos estrategias de filtrado en las 
   que se basan todos los algoritmos que manejan montículos */

  void filtradoDescendente(Monticulo *m, int i);
  void filtradoAscendente(Monticulo *m, int i);

/* Operación crearMonticulo la utilizaremos en ejercicio 2 y en tema de grafos */ 

  void crearMonticulo(Monticulo *m);


