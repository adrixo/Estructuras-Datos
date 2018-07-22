#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Crea un fichero hash inicialmente vacio
void creaHvacio(char *fichHash)
{
  FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++)
    fwrite(&cubo,sizeof(cubo),1,fHash);

  fclose(fHash);
}

// Lee el contenido del fichero hash organizado mediante el método de DISPERSIÓN
// Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta función permite visualizar el método de DISPERSIÓN
int leeHash(char *fichHash)
{
  FILE *f;
  tipoCubo cubo;
  int j,i=0;
  size_t numLee;

  f = fopen(fichHash,"rb");
  rewind(f);
  fread(&cubo,sizeof(cubo),1,f);
  while (!feof(f)
  {
  	for (j=0;j<C;j++)
    {
      if (j==0)
        printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
      else
        printf("\t\t\t");
    	if (j < cubo.numRegAsignados)
      {
        printf("\t%s %s %s %s %s\n",
          cubo.reg[j].dni,
          cubo.reg[j].nombre,
          cubo.reg[j].ape1,
          cubo.reg[j].ape2,
          cubo.reg[j].provincia);
       }
        else printf ("\n");
    }
    i++;
    fread(&cubo,sizeof(cubo),1,f);
  }
  fclose(f);
  return i;
}


int fHash (char *cad)
{
  return atoi(cad)%CUBOS;
}

int creaHash(char *fichEntrada,char *fichHash)
{
  FILE *fIn, *fOut;

  tipoCubo cubo;
  int numCubo;

  Alumno (tipoAlumno*)malloc sizeof(tipoAlumno));
  fIn = fopen(fichEntrada,"rb");
  fOut = fopen(fichHash,"wb");
  if(fIN == NULL)
  {
    printf("error");
    return -1;
  }

  if(fOut == NULL)
  {
    printf("error");
    return -1;
  }
  while(!feof(fIn))
  {
    fread(Alumno, sizeof(Alumno),1,fIn);
    numCubo=fHash(Alumno->dni);
    fseek(fOut, sizeof(tipoCubo)*numCubo,SEEK_SET);
  }
  fclose
  fclose
  free
}

int densidad(char *nombreFichero)
{
  File *f;

  f=fopen();
}
