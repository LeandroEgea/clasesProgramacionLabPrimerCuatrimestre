#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.h"
#define CANTIDAD 4

void cargarListado(int listado[], int tamanio);
void MostrarListado(int listado[], int tamanio);
void MostrarInformacionDelArray(int listado[], int tamanio);
int retornarMayor(int listado[], int tamanio);
int retornarMenor(int listado[], int tamanio);
int retornarCantidadDePares(int listado[], int tamanio);
int retornarTotal(int listado[], int tamanio);
float retornarPromedio(int listado[], int tamanio);

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
    notaMayor = retornarMayor(listado, tamanio);
    notaMenor = retornarMenor(listado, tamanio);
    cantidadDePares = retornarCantidadDePares(listado, tamanio);
    acumuladorNotas = retornarTotal(listado, tamanio);
    promedioNotas = retornarPromedio(listado, tamanio);
    printf("\nLa nota mayor es: %d", notaMayor);
    printf("\nLa nota menor es: %d", notaMenor);
    printf("\nLa cantidad de pares es: %d", cantidadDePares);
    printf("\nLa nota total es: %d", acumuladorNotas);
    printf("\nLa nota promedio es: %.2f", promedioNotas);
}
int retornarMayor(int listado[], int tamanio)
{
    int mayor;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]>mayor)
        {
            mayor = listado[i];
        }
    }
    return mayor;
}
int retornarMenor(int listado[], int tamanio)
{
    int menor;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]<menor)
        {
            menor = listado[i];
        }
    }
    return menor;
}
int retornarCantidadDePares(int listado[], int tamanio)
{
    int i;
    int cantidadDePares = 0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i] % 2 == 0)
        {
            cantidadDePares++;
        }
    }
    return cantidadDePares;
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
