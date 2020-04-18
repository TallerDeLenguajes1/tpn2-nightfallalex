#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int velocidadProcesamientoGHZ;
    int anioFabricacion;
    int cantidadNucleos;
    char *tipoProcesador;
}microprocesador;

void carga(microprocesador *PC);
void miPC(microprocesador PC);
void listaDeProcesadores(microprocesador *PC,int num);
void computadoraAntigua(microprocesador *PC ,int num);
void mayorVelocidad(microprocesador *PC,int num);


int main()
{
    srand (time(NULL));

    int cantidadMicroprocesadores;
    int CPU;
    int cpuNumero;

    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};

    microprocesador *PC; // defino la variable tipo arreglo de estructuras


	printf("\nCuantos Microprocesadores desea adquirir: ");
	scanf("\n%d",&cantidadMicroprocesadores);
 
    PC = (microprocesador *)malloc(cantidadMicroprocesadores*sizeof(PC));  //asigno de manera dinamica la memoria para la variable PC

    printf("\nUsted selecciono la cantidad de %d microprocesadores" , cantidadMicroprocesadores);
    printf("\nSeleccione un Microprocesador en existencia: \n");
//--------------------------------------------------------------------------//	
    for(int j = 0 ; j < 6 ; j++)  // seccion: muestreo de procesadores disponibles
    {
			printf("%d- ",j+1);
			puts(tipos[j]);
	}

    for(int i = 0 ; i < cantidadMicroprocesadores ; i++) // seccion: Seleccion de procesadores
    {
        printf("\nSeleccione el tipo de procesador que desea adquirir (con numeros, mayores a 1 inclusive y menores a 6 inclusive): ");
		scanf("%d",&CPU);

		carga(PC+i); //--Escribe una función a la que se le pase el puntero al arreglo de estructuras y cargue el mismo con los valores asignados a las características de cada PC.
		PC[i].tipoProcesador = *(tipos+CPU);
	}
//---------------------------------------------------------------------------//
    printf("\nCaracteristicas del microprocesador numero: "); //seccion: muestreo de las caracteristicas de la CPU seleccionada
	scanf("%d",&cpuNumero);
	while(cpuNumero > cantidadMicroprocesadores)
    {
        if (cpuNumero <= 0)
        {
            printf("\nEl valor ingresado es igual o menor a 0, por favor ingrese un valor numerico valido: ");
		    scanf("%d",&cpuNumero);
        }else
            {
                printf("\nLa PC ingresada no existe o es un numero invalido, por favor, intente nuevamente: ");
		        scanf("%d",&cpuNumero);
            }
	}
 
    cpuNumero = cpuNumero - 1;
	miPC(PC[cpuNumero]); //Escribe una función que devuelva una PC pasando la estructura como argumento a la función
//----------------------------------------------------------------------------//
    printf("\n\nLista con todas los microProcesadores Adquiridos y sus caracteristicas:\n");
	listaDeProcesadores(PC,cantidadMicroprocesadores);  //Escribe una función que presente la lista de las PC, cada una con sus características.
//------------------------------------------------------------------------------//
    printf("\n\nPC antigua:\n");
    computadoraAntigua(PC,cantidadMicroprocesadores);  //Escribe una función que presente la PC más vieja.
//----------------------------------------------------------------------------//
    printf("\n\nMicroprocesador de mayor velocidad:\n");
    mayorVelocidad(PC,cantidadMicroprocesadores);  //Escribe una función que presente la PC que tiene mayor velocidad.
//---------------------------------------------------------------------------------//

    

    getchar();
    free(PC); // libero memoria del puntero PC
    return 0;
}


void carga(microprocesador *PC)
{
    int aleatorioVelocidad = rand() % 3 + 1;
    int aleatorioAnio = rand() % 18 +2000;
    int aleatorioNucleos = rand () % 4 + 1;
    
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};

    PC->velocidadProcesamientoGHZ = aleatorioVelocidad;
    PC->anioFabricacion = aleatorioAnio;
    PC->cantidadNucleos = aleatorioNucleos;
}

void miPC(microprocesador PC)
{
	printf("\nVelocidad: %d GHz",PC.velocidadProcesamientoGHZ);
	printf("\nAño de fabricacion: %d",PC.anioFabricacion);
	printf("\nCantidad de nucleos: %d",PC.cantidadNucleos);
	printf("\nTipo de procesador: "); puts(PC.tipoProcesador);
	printf("\n");
}

void listaDeProcesadores(microprocesador *PC,int num)
{
	for(int i = 0 ; i < num ; i++)
    {
		printf("\nMicroprocesador numero %d: ",i+1);
		printf("\nVelocidad: %d GHz" , PC[i].velocidadProcesamientoGHZ);
		printf("\nAño de Fabricacion: %d" , PC[i].anioFabricacion);
		printf("\nCantidad de nucleos: %d" , PC[i].cantidadNucleos);
		printf("\nTipo de procesador: ");
        puts(PC[i].tipoProcesador);
        printf("\n");
	}
}

void computadoraAntigua(microprocesador *PC ,int num)
{
	int aux=2018;
    int antigua;
    int i;

	for(i = 0 ; i < num ; i++)
    {
		if(PC[i].anioFabricacion < aux){
			antigua = i;
			aux = PC[i].anioFabricacion;
		}
	}
	printf("\nEl procesador mas antiguo es: %d",antigua+1);
    printf("\n");
}

void mayorVelocidad(microprocesador *PC,int num)
{
	int aux=0;
    int mayor;

	for(int i = 0 ; i < num ; i++)
    {
		if(PC[i].velocidadProcesamientoGHZ > aux){
			mayor = i;
			aux = PC[i].velocidadProcesamientoGHZ;
		}
	}
	printf("\nEl procesador mas veloz es el: %d",mayor+1);
    printf("\n");
}