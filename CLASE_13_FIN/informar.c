#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"

static int comparacionPrecioNombre(Pantalla* arrayUno, Pantalla* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL)
    {
        if(arrayUno->precio < arrayDos->precio ||
            (arrayUno->precio == arrayDos->precio  && strcmp(arrayUno->nombre, arrayDos->nombre) > 0))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int informar_sortPantallaPorPrecioNombre(Pantalla *array, int len)
{
    Pantalla auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0 )
    {
        for(i=1; i < len; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            while ((j >= 0) && !comparacionPrecioNombre(&array[j], &auxiliar))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = auxiliar;
        }
        retorno = 0;
    }
    return retorno;
}

int informar_pantallaMayorMenorDiez(Pantalla *array, int len, int mayorMenor)
{
    int retorno=-1;
    int i;
    int cantidadPantallas = 0;
    if(array != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(mayorMenor == 0 && array[i].isEmpty == 0 && array[i].precio > 10)
            {
                pantalla_mostrar(&(array[i]), 1);
                cantidadPantallas++;
            }
            else if(mayorMenor == 1 && array[i].isEmpty == 0 && array[i].precio <= 10)
            {
                pantalla_mostrar(&(array[i]), 1);
                cantidadPantallas++;
            }
        }
        printf("El total de pantallas es: %d\n", cantidadPantallas);
        retorno = 0;
    }
    return retorno;
}
int informar_pantallaSuperaPromedio(Pantalla *array, int len, int MayorMenor)
{
    int retorno=-1;
    int i;
    float promedioPrecios;
    int cantidadPantallasSobrePromedio = 0;
    if(array != NULL && len > 0 && !pantalla_promedioPrecio(&promedioPrecios, array, len))
    {
        if(MayorMenor == 0)
        {
            for(i=0; i < len; i++)
            {
                if(array[i].isEmpty == 0 && array[i].precio > promedioPrecios)
                {
                    pantalla_mostrar(&(array[i]), 1);
                    cantidadPantallasSobrePromedio++;
                }
            }
            printf("El total de las pantallas que superan el promedio(%.2f) es: %d\n", promedioPrecios, cantidadPantallasSobrePromedio);
        }
        else if(MayorMenor == 1)
        {
            for(i=0; i < len; i++)
            {
                if(array[i].isEmpty == 0 && array[i].precio < promedioPrecios)
                {
                    pantalla_mostrar(&(array[i]), 1);
                    cantidadPantallasSobrePromedio++;
                }
            }
            printf("El total de las pantallas que no superan el promedio(%.2f) es: %d\n", promedioPrecios, cantidadPantallasSobrePromedio);
        }
        retorno = 0;
    }
    return retorno;
}

int informar_contratacionesMenorDiezDias(   Contratacion *arrayContratacion, int lenContratacion,
                                            Pantalla *arrayPantalla, int lenPantalla)
{
    int retorno=-1;
    int i;
    int idPantallaAuxiliar;
    Pantalla* pantallaAuxiliar;
    if(arrayContratacion != NULL && lenContratacion > 0 && arrayPantalla != NULL && lenPantalla > 0)
    {
        for(i=0; i < lenContratacion; i++)
        {
            if(arrayContratacion[i].isEmpty == 0 && arrayContratacion[i].dias <= 10)
            {
                idPantallaAuxiliar = arrayContratacion[i].idPantalla;
                pantallaAuxiliar = pantalla_getById(arrayPantalla, lenPantalla, idPantallaAuxiliar);
                printf("",pantallaAuxiliar.nombre,pantallaAuxiliar.precio,arrayContratacion[i].dias,arrayContratacion[i].)
            }
        }
        retorno = 0;
    }
    return retorno;
}




int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}
