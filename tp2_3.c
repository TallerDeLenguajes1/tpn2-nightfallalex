#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand (time(0));

    int fila = 15;
    int f;
    int c;
    int *pMatriz;
    int i;

    int columna = (5 + (rand() % 11));
    
    int *pNumerosPares = (int *) malloc (fila * sizeof(int));
    int numerosPares = 0;
    
//-----------------------------------------PRUEBAS FALLIDAS CONSULTAR----------------------------------
/*
    for (f = 0; f < fila; f++)
    {
        pMatriz = (int *) malloc (fila*columna * (sizeof (int))); //reserva de memoria para la matriz
    }
*/

/*
    for (f = 0; f < fila; f++)
    {
        
        for (c = 0; c < columna; c++)
        {
            *(pMatriz + c) = rand() % (999-100+1) + 100; //escribiendo numeros aleatorios en la matriz
        }

    }
*/
    pMatriz = (int *) malloc (fila*columna * (sizeof (int))); //reserva de memoria para la matriz
    
    for (i = 0; i < fila*columna ; i++)
    {
        *(pMatriz + i) = (rand() % 900) + 100; //escribiendo numeros aleatorios en la matriz
    }

    for (f = 0 ; f < fila ; f++)
    {
        for (c = 0 ; c < columna ; c++)
        {
            printf("| %d |",*(pMatriz + f*columna+c)); //imprimiendo los valores por pantalla
        }
        printf("\n");
    }

    //cantidad de numeros pares de la matriz.
    
    for(f = 0 ; f < fila ; f++)
    {
        for(c = 0 ; c < columna ; c++)
        {
            if(*(pMatriz + f*columna+c)%2 == 0)
            {
                numerosPares = numerosPares + 1;
            }
        }
        
        printf("\nen la fila %d existen %d numeros pares",f+1,numerosPares);
        
        *(pNumerosPares+f) = numerosPares;
                
        numerosPares = 0;
    }

    //Impresion por pantalla del vector dinamico

    printf("\n\n");

    printf("\t Vector con la cantidad de numeros pares por fila: \n\t");
    
    for(f = 0 ; f < fila ; f++)
    {
        printf("| %d |",*(pNumerosPares+f));
    }
    
    // liberacion de memoria dinamica

    free(pNumerosPares);

    free(pMatriz);
    

    getchar();
    return 0;
}
