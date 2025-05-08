#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int i;
    int *puntero, tamano;
    printf("ingrese tamaño:");
    scanf("%d",&tamano);
    printf("\n");
    puntero = (int *) malloc(tamano*sizeof(int));
    //tamaño*sizeof(int) -->tamaño en bytes a reservar
    //(int *) --> casting a puntero a entero
    for(i=0;i<tamano;i++){
          puntero[i]=i+1;
          printf("%d\n",puntero[i]);
    }
    free(puntero); //Liberar la memoria del heap
    return 0;
}