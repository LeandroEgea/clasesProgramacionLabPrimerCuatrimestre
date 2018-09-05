#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.h"
#define CANTIDAD 4

int retornarTotal(int listado[], int tamanio);
float retornarPromedio(int listado[], int tamanio);
int main()
{
    int numeroIngresado;
    int listadoDeNotas[CANTIDAD];
    int i;
    int notaMayor;
    int notaMenor;
    int acumuladorNotas;
    float promedioNotas = 0;
/*
    printf("tamaño: %lu\n", sizeof(numeroIngresado));
    printf("tamaño: %lu\n", sizeof(listadoDeNotas));
    printf("direccion: %p\n", &numeroIngresado);
    printf("direccion: %p\n", listadoDeNotas);*/
    for(i=0;i<CANTIDAD;i++)
    {
        //printf("\n direccion [%d]: %p", i,&listadoDeNotas[i]);
        printf("\nIngrese Nota %d: ", i+1);
        scanf("%d", &numeroIngresado);
        listadoDeNotas[i]=numeroIngresado;
    }
    for(i=0;i<CANTIDAD;i++)
    {
        printf("\nLa nota %d es :%d ", i+1, listadoDeNotas[i]);
    }

    for(i=0;i<CANTIDAD;i++)
    {
        if(i==0 || listadoDeNotas[i]>notaMayor)
        {
            notaMayor = listadoDeNotas[i];
        }
    }
    for(i=0;i<CANTIDAD;i++)
    {
        if(i==0 || listadoDeNotas[i]<notaMenor)
        {
            notaMenor = listadoDeNotas[i];
        }
    }
    acumuladorNotas = retornarTotal(listadoDeNotas, CANTIDAD);
    promedioNotas = retornarPromedio(listadoDeNotas, CANTIDAD);
    printf("\nLa nota total es: %d", acumuladorNotas);
    printf("\nLa nota promedio es: %.2f", promedioNotas);
    printf("\nLa nota mayor es: %d", notaMayor);
    printf("\nLa nota menor es: %d", notaMenor);
    return 0;
}

int retornarTotal(int listado[], int tamanio)
{
    int i;
    int sumaTotal = 0;
    for(i=0;i<tamanio;i++)
    {
        sumaTotal = sumaTotal + listado[i];
    }
    return sumaTotal;
}
float retornarPromedio(int listado[], int tamanio)
{
    int sumaTotal;
    float promedio;
    sumaTotal = retornarTotal(listado, tamanio);
    promedio = (float)sumaTotal/tamanio;
    return promedio;
}
