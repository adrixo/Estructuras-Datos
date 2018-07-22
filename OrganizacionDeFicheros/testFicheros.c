
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "70959657B.c"
//#include "70921486C.c"


int main()
{int i,numRegDes;
 FILE *f;
 tipoAlumno reg;
 char dni[10];

	printf("hehe\n");
  numRegDes=creaHash("alumnos.dat","alumnos.hash");
  printf("%d Registros DESBORDADOS\n\n",numRegDes);
	printf("hehe\n");
  i = leeHash("alumnos.hash");
	printf("hehe\n");
  // B�squeda de registros
  f=fopen("alumnos.hash","rb");

  strcpy(dni,"7389298"); // Existe en el area PRIMA
  i=buscaReg(f,&reg,dni);
  if (i<0) printf("No existe alumno con dni %s\n",dni);
  else { printf("Registro encontrado en el CUBO %d",i);
  	     printf("\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
        }
  strcpy(dni,"7219752"); // Existe en el area De DESBORDE
  i=buscaReg(f,&reg,dni);
  if (i<0) printf("No existe alumno con dni %s\n",dni);
  else { printf("Registro encontrado en el CUBO %d",i);
  	     printf("\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
        }
  strcpy(dni,"123456789"); // No existe
  i=buscaReg(f,&reg,dni);
  if (i<0) printf("\nNo existe alumno con dni %s\n",dni);
  else { printf("Registro encontrado en el CUBO %d",i);
  	     printf("\t %s %s %s %s %s\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
        }

	eliminarReg("alumnos.hash","11000258");
	leeHash("alumnos.hash");
  fclose(f);

  //Fin de B�squeda

}




