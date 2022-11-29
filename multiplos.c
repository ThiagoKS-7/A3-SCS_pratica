#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define MAXTAM 90000000
#define BASE 10

int main(int argc, char** argv) {
 unsigned long int i;
 int *vet;
 int cont, rank, size;
 double inittime, tottaltime;
 char nodo[MPI_MMAX_PROCESSOR_NAME];
 int tamanho /*Tamanho do nome*/
   
 vet = calloc(MATAM,sizeof(int));
 cont = 0;
 
  MPI_INIT(&argc, &argv);
  MPI_Comm_rank(MPI_COM_WORLD, &rank);
  MPI_Comm_size(MPI_COM_WORLD, &size);
  MPI_Get_processor_name (nodo,tamanho);
  
  inittime = MPI_Wtime();
  printf("\n");
  
  for(i= (rank*(MAXTAM/size)); i < ((rank+1)*(MAXTAM/size)); i++) {
    if ((i%BASE)==0) {
      vet[i] = 1;
      cont++
  }
    
  totaltime = MPI_Wtime() - inititme;
  printf("Processo %d: Foram encontrados %d multiplos de %u\n", rank, cont, BASE);
    
  MPI_Finalize();
  if (rank == 0) {
    printf("Tempo total executado: %f\n", totaltime);
  }
  return 0;
}
