#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "llamada.h"

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

static int getLugarLibre(Llamada* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int llamada_init(Llamada* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

Llamada* llamada_getById(Llamada* array, int len,int id)
{
    Llamada* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idLlamada == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
/*
int llamada_alta(Llamada* array, int len)
{
    int retorno = -1;
    int indice;
    int idAsociado;
    char motivo[20];
    char estado[20];
    int tiempo;
    int idAmbulancia;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getEnteroPositivo(dni, 20,"idAsociado?\n","id no valido\n",2) &&

        !utn_getAlfabetico(nombre,50,"Nombre asociado?\n","nombre no valido\n",2) &&
        !utn_getAlfabetico(apellido,200,"apellido asociado?\n","apellido no valido\n",2) &&


        !utn_getEnteroPositivo(&tiempo, 3, "tiempo resolucion(minutos)?\n", "tiempo no valido\n", 2) &&
        !utn_getEnteroPositivo(dni, 20,"idAmbulancia?\n","id no valido\n",2))
    {
        strncpy(array[indice].dni, dni,20);
        strncpy(array[indice].nombre, nombre, 50);
        strncpy(array[indice].apellido, apellido, 50);
        array[indice].edad = edad;
        array[indice].isEmpty = 0;
        array[indice].isActive = 1;
        array[indice].idAsociado = getNextId();
        retorno = 0;
    }
    return retorno;
}*/
