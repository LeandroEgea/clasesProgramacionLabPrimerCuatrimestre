#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.h"
#define CANTIDAD 4

void cargarListado(int listado[], int tamanio);
void MostrarListado(int listado[], int tamanio);
void MostrarInformacionDelArray(int listado[], int tamanio);

int main()
{
    int listadoDeNotas[CANTIDAD];
    cargarListado(listadoDeNotas, CANTIDAD);
    MostrarListado(listadoDeNotas, CANTIDAD);
    MostrarInformacionDelArray(listadoDeNotas, CANTIDAD);
    return 0;
}
void cargarListado(int listado[], int tamanio)
{
    int i;
    int numeroIngresado;
    for(i=0;i<tamanio;i++)
    {
        printf("\nIngrese numero %d: ", i+1);
        scanf("%d", &numeroIngresado);
        listado[i]=numeroIngresado;
    }
}
void MostrarListado(int listado[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("\nLa nota %d es :%d ", i+1, listado[i]);
    }
}
void MostrarInformacionDelArray(int listado[], int tamanio)
{
    int notaMayor;
    int notaMenor;
    int cantidadDePares;
    int acumuladorNotas;
    float promedioNotas;
    int cantidadAprobadosSinFinal;
    int cantidadAprobadosConFinal;
    int cantidadDesaprobados;
    notaMayor = utn_retornarMayor(listado, tamanio);
    notaMenor = utn_retornarMenor(listado, tamanio);
    cantidadDePares = utn_retornarCantidadDePares(listado, tamanio);
    acumuladorNotas = utn_retornarTotal(listado, tamanio);
    promedioNotas = utn_retornarPromedio(listado, tamanio);
    cantidadAprobadosSinFinal = utn_cantidadEnterosEnIntervalo(listado, tamanio, 6, 10);
    cantidadAprobadosConFinal = utn_cantidadEnterosEnIntervalo(listado, tamanio, 4, 5);
    cantidadDesaprobados = utn_cantidadEnterosEnIntervalo(listado, tamanio, 1, 3);
    printf("\nLa nota mayor es: %d", notaMayor);
    printf("\nLa nota menor es: %d", notaMenor);
    printf("\nLa cantidad de pares es: %d", cantidadDePares);
    printf("\nLa nota total es: %d", acumuladorNotas);
    printf("\nLa nota promedio es: %.2f", promedioNotas);
    printf("\nLa cantidad de aprobados sin final es: %d", cantidadAprobadosSinFinal);
    printf("\nLa cantidad de aprobados con final es: %d", cantidadAprobadosConFinal);
    printf("\nLa cantidad de desaprobados es: %d", cantidadDesaprobados);
}
