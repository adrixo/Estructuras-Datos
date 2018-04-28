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

//Operaciones
void crearMonticulo(Monticulo *m);

void iniciaMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
int insertar(tipoElemento x, Monticulo *m);
int eliminarMinimo(Monticulo *m, tipoElemento *minimo);

//control
int esMonticulo(Monticulo m);
void decrementarClave(int pos, int cantidad, Monticulo *m);
void incrementarClave(int pos, int cantidad, Monticulo *m);
//Auxiliares
void filtradoDescendente(Monticulo *m, int i);
void filtradoAscendente(Monticulo *m, int i);

//Algoritmos
void heapsort(Monticulo *m);
