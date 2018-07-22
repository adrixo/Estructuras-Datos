#include "dispersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
#define C 5	                // capacidad del cubo
#define CUBOS 20           // N�mero de cubos en el area prima
#define CUBOSDESBORDE  4   // N�mero de cubos area de desborde
*/
void creaHvacio(char *fichHash);
int leeHash(char *fichHash);
int creaHash(char *fichEntrada, char *fichHash);
int buscaReg(FILE *fHash, tipoAlumno *reg, char *dni);
int eliminarReg(char *fichero, char *dni);
int funHash (char *cad);


int funHash (char *cad)
{
  return atoi(cad)%CUBOS;
}

// Crea un fichero hash inicialmente vacio seg�n los criterios especificados en la pr�ctica
// Primera tarea a realizar para  crear un fichero organizado mediante DISPERSI�N
void creaHvacio(char *fichHash)
{ FILE *fHash;
  tipoCubo cubo;
  int j;
  int numCubos =CUBOS+CUBOSDESBORDE;

  memset(&cubo,0,sizeof(cubo));

  fHash = fopen(fichHash,"wb");
  for (j=0;j<numCubos;j++) fwrite(&cubo,sizeof(cubo),1,fHash);
  fclose(fHash);
}
// Lee el contenido del fichero hash organizado mediante el m�todo de DISPERSI�N seg�n los criterios
// especificados en la pr�ctica. Se leen todos los cubos completos tengan registros asignados o no. La
// salida que produce esta funci�n permite visualizar el m�todo de DISPERSI�N

int leeHash(char *fichHash)
{ FILE *f;
  tipoCubo cubo;
  int j,i=0;
  size_t numLee;

   f = fopen(fichHash,"rb");
   rewind(f);
   fread(&cubo,sizeof(cubo),1,f);
   while (!feof(f)){
	for (j=0;j<C;j++) {
        if (j==0)    	printf("Cubo %2d (%2d reg. ASIGNADOS)",i,cubo.numRegAsignados);
        else  	printf("\t\t\t");
	if (j < cubo.numRegAsignados)
		    printf("\t%s %s %s %s %s\n",
	    		cubo.reg[j].dni,
			cubo.reg[j].nombre,
			cubo.reg[j].ape1,
		  	cubo.reg[j].ape2,
  	                cubo.reg[j].provincia);
	else printf ("\n");
        }
       i++;
       fread(&cubo,sizeof(cubo),1,f);
   }
   fclose(f);
   return i;
}


int creaHash(char *fichEntrada,char *fichHash)
{
  FILE *fIn, *fOut;

  tipoAlumno alumno;
  tipoCubo cubo, aux;

  int numCubo;
  int i, j;
  int desbordados=0;

  creaHvacio("alumnos.hash");

  fOut = fopen(fichHash,"r+b");
  fIn = fopen(fichEntrada,"rb");
  if(fIn == NULL)
  {
    printf("error fIn");
    return -1;
  }
  if(fOut == NULL)
  {
    printf("error fOut");
    return -1;
  }

  while(!feof(fIn))
  {
    fread(&alumno, sizeof(alumno),1,fIn);

    numCubo=funHash(alumno.dni);
    fseek(fOut, sizeof(tipoCubo)*numCubo,SEEK_SET);
    fread(&cubo, sizeof(tipoCubo),1,fOut);

    if(cubo.numRegAsignados < C)
    {
      cubo.reg[cubo.numRegAsignados] = alumno;
      cubo.numRegAsignados++;
    } else {
      desbordados ++;
      /*Cubos de desborde*/
      for(j=0; j < CUBOSDESBORDE; j++)
      {
        fseek(fOut, sizeof(tipoCubo)*(CUBOS + j), SEEK_SET);
        fread( &aux, sizeof(tipoCubo), 1,fOut);

        if( aux.numRegAsignados < C)
        {
          aux.reg[aux.numRegAsignados] = alumno;
          aux.numRegAsignados++;
          cubo.numRegAsignados++;
          fseek( fOut, sizeof(tipoCubo)*(CUBOS +j), SEEK_SET);
          fwrite(&aux, sizeof(tipoCubo), 1, fOut);
          j=CUBOSDESBORDE;
        }
      }
    }

    fseek( fOut, sizeof(tipoCubo)*numCubo, SEEK_SET );
    fwrite( &cubo, sizeof(tipoCubo), 1, fOut);
  }

  fclose(fIn);
  fclose(fOut);
  return desbordados;
}

int buscaReg(FILE *fHash, tipoAlumno *reg, char *dni)
{
  int i,j;

  tipoCubo cubo;
  int nCubo = funHash(dni);

  fseek(fHash, sizeof(tipoCubo)*nCubo, SEEK_SET);
  fread(&cubo, sizeof(tipoCubo), 1, fHash);

/* cubos */
  for(i=0; i<C; i++)
  {
    if( i < cubo.numRegAsignados && !strcmp( cubo.reg[i].dni, dni ))
    {
      *reg = cubo.reg[i];
      return nCubo;
    }

		if(i > cubo.numRegAsignados)
      break;
  }

/* desborde */
  if(cubo.numRegAsignados >= C)
  {
    for(i=0; i < CUBOSDESBORDE; i++)
    {
      nCubo = CUBOS+i;
      fseek(fHash, sizeof(tipoCubo)*nCubo, SEEK_SET);
      fread(&cubo, sizeof(tipoCubo), 1, fHash);
      for(j=0; j<C; j++)
      {
        if( j < cubo.numRegAsignados && !strcmp( cubo.reg[j].dni, dni ))
        {
          *reg = cubo.reg[j];
          return nCubo;
        }
        if(j > cubo.numRegAsignados)
          break;
      }
    }
  }
  return -1;
}

int eliminarReg(char *fichero, char *dni)
{
  int nCuboHash, nCubo;
  int i;
  tipoAlumno alumno;
  FILE * f;
  tipoCubo cubo, aux, aux2;

  f = fopen(fichero, "r+b");
  if(f == NULL)
  {
    printf("No se pudo abrir el fichero\n");
    return -1;
  }

  nCubo = buscaReg(f, &alumno, dni);
  nCuboHash = funHash(dni);

  if(nCubo == -1)
  {
    fclose(f);
    return -1;
  }

////////////////////// En un cubo normal
  if(nCubo == nCuboHash) //sin desborde
  {
    fseek( f, sizeof(tipoCubo)*nCuboHash, SEEK_SET );
		fread( &cubo, sizeof(tipoCubo), 1, f );
    if(cubo.numRegAsignados<=C)//cubo sin desborde
    {
      for( i = 0; i < C; i++ )
    	{
    		if( i < cubo.numRegAsignados && !strcmp( cubo.reg[i].dni, dni ))
          break;
        if(i>cubo.numRegAsignados)
          return -1;
    	}
      memset(&cubo.reg[i],0,sizeof(tipoAlumno));
      memcpy(&cubo.reg[i], &cubo.reg[cubo.numRegAsignados-1], sizeof(tipoAlumno));
      memset(&cubo.reg[cubo.numRegAsignados-1], 0, sizeof(tipoAlumno));
      cubo.numRegAsignados--;

      fseek(f, sizeof(tipoCubo)*nCuboHash, SEEK_SET);
      fwrite(&cubo, sizeof(tipoCubo),1,f);
      fclose(f);
      return 0;
    }

//////////////////////
    if(cubo.numRegAsignados>C)//cubo con desborde
    {
      int posAux = -1, posAux2;
      int k, j;
      tipoAlumno *alumnoAux = NULL;
      for( i = 0; i < C; i++ )
      {
        if( i < cubo.numRegAsignados && !strcmp( cubo.reg[i].dni, dni ))
          break;
        if(i>cubo.numRegAsignados)
          return -1;
      }
      int posCubo = i, cuboSustituido;
      int flagSustituido = 0;

      memset(&cubo.reg[posCubo],0,sizeof(tipoAlumno));
      cubo.numRegAsignados--;
      fseek(f, sizeof(tipoCubo)*nCuboHash, SEEK_SET);
      fwrite(&cubo, sizeof(tipoCubo), 1, f);

      for(i = 0; i < CUBOSDESBORDE; i++)
      {
        fseek(f, sizeof(tipoCubo)*(CUBOS+i),SEEK_SET);
        fread(&aux, sizeof(tipoCubo),1,f);
        if(aux.numRegAsignados==0){
          fseek(f, sizeof(tipoCubo)*(CUBOS+i-1),SEEK_SET);
          fread(&aux, sizeof(tipoCubo),1,f);
          i--;
          break;
        }

        for(j=0; j<C; j++)
        {
          if( funHash(aux.reg[j].dni) == nCuboHash && !flagSustituido)
          {
            posAux = j;
            cuboSustituido = i;
            fseek(f,sizeof(tipoCubo)*(CUBOS +i), SEEK_SET);
            fread(&aux, sizeof(tipoCubo), 1, f);

            memcpy(&cubo.reg[posCubo], &aux.reg[j], sizeof(tipoAlumno));
            memset(&aux.reg[j], 0, sizeof(tipoAlumno));

            fseek( f, sizeof(tipoCubo)*nCuboHash, SEEK_SET );
            fwrite( &cubo, sizeof(tipoCubo), 1, f );

            fseek( f, sizeof(tipoCubo)*(CUBOS+i), SEEK_SET );
            fwrite( &aux, sizeof(tipoCubo), 1, f );

            flagSustituido = 1;
            j=C;
            break;
          }
        }
      }

      //Cubo ha sido reutilizado como aux, aux como aux de aux (ultimo cubo de desborde)
      fseek(f,sizeof(tipoCubo)*(CUBOS +i), SEEK_SET);
      fread(&aux, sizeof(tipoCubo), 1, f);

      fseek(f,sizeof(tipoCubo)*(CUBOS +cuboSustituido), SEEK_SET);
      fread(&cubo, sizeof(tipoCubo), 1, f);

      memcpy(&cubo.reg[posAux], &aux.reg[aux.numRegAsignados -1], sizeof(tipoAlumno));
      memset(&aux.reg[aux.numRegAsignados -1], 0, sizeof(tipoAlumno));

      fseek( f, sizeof(tipoCubo)*(CUBOS +cuboSustituido), SEEK_SET );
      fwrite( &cubo, sizeof(tipoCubo), 1, f );

      fseek( f, sizeof(tipoCubo)*(CUBOS+i), SEEK_SET );
      fwrite( &aux, sizeof(tipoCubo), 1, f );
      fclose(f);
      return 0;
    }
  }

//////////////////////
  if(nCubo != nCuboHash) //en cubo de desborde
  {
    int j;
    //fseek( f, sizeof(tipoCubo)*nCubo, SEEK_SET );
    //fread( &cubo, sizeof(tipoCubo), 1, f );

    if(nCubo >= CUBOS && nCubo <(CUBOS + CUBOSDESBORDE))
    {
      fseek( f, sizeof(tipoCubo)*nCubo, SEEK_SET );
      fread( &cubo, sizeof(tipoCubo), 1, f );
      for( i = 0; i < C; i++ )
      {
        if( i < cubo.numRegAsignados && !strcmp( cubo.reg[i].dni, dni ))
          break;
        if(i>cubo.numRegAsignados)
          return -1;
      }
      /*PARA CADA CUBO DE DESBORDE*/
      int posCubo = i;
      int posAux = -1;

      int alumnoAux;
      for(j=0; j<CUBOSDESBORDE; j++)
      {
        fseek(f, sizeof(tipoCubo)*(CUBOS + j), SEEK_SET);
        fread(&aux, sizeof(tipoCubo),1,f);

        for(i=0;i <= C-1; i++)
        {
          if(funHash(aux.reg[i].dni) > 0)
          {
            alumnoAux = i;
            posAux = buscaReg(f,&alumno, aux.reg[i].dni);
          }
        }
      }
      if(posAux == -1 ){
        return -1;
      }

	  /*
      //nCuboHash
      aux = last
      aux.num --
      last = aux
      //nCubo


	   */
		fseek( f, sizeof(tipoCubo)*posAux, SEEK_SET );
		fread( &aux, sizeof(tipoCubo), 1, f );
		aux.numRegAsignados--;
		fseek( f, posAux * sizeof(tipoCubo), SEEK_SET );
		fwrite( &aux, sizeof(tipoCubo), 1, f );

		fseek( f, nCubo * sizeof(tipoCubo), SEEK_SET );
		//fread( &cubo, sizeof(tipoCubo), 1, f );
		fread( &cubo, sizeof(tipoCubo), 1, f );

		memcpy(&cubo.reg[posCubo], &aux.reg[alumnoAux], sizeof(tipoAlumno));
		memset(&aux.reg[alumnoAux], 0, sizeof(tipoAlumno));

		fseek( f, nCubo * sizeof(tipoCubo), SEEK_SET );
		fwrite( &cubo, sizeof(tipoCubo), 1, f );
      fclose(f);
      return 0;
    }
    return -1;
  }
}
