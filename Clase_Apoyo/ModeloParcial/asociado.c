#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "asociado.h"

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

static int getLugarLibre(Asociado* array, int len)
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

int asociado_init(Asociado* array, int len)
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

Asociado* asociado_getById(Asociado* array, int len,int id)
{
    Asociado* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idAsociado == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}

int asociado_alta(Asociado* array, int len)
{
    int retorno = -1;
    int indice;
    char dni[20];
    char nombre[50];
    char apellido[50];
    int edad;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getDni(dni, 20,"Dni asociado?\n","dni no valido\n",2) &&
        !utn_getAlfabetico(nombre,50,"Nombre asociado?\n","nombre no valido\n",2) &&
        !utn_getAlfabetico(apellido,50,"apellido asociado?\n","apellido no valido\n",2) &&
        !utn_getEnteroPositivo(&edad, 100, "edad asociado?\n", "edad no valida\n", 2))
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
}

int asociado_modificar(Asociado* array, int len, int reintentos)
{
    int retorno = -1;
    Asociado *asociadoModificado = NULL;
    int id;
    int i;
    char dni[20];
    char nombre[50];
    char apellido[50];
    int edad;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "Id erroneo\n", 0) &&
                asociado_getById(array, len, id) != NULL)
            {
                asociadoModificado = asociado_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
                if(i != reintentos)
                {
                    asociado_mostrar(array, len);
                }
            }
        }
    }
    if( asociadoModificado != NULL &&
        !utn_getDni(dni, 20,"Dni asociado?\n","dni no valido\n",2) &&
        !utn_getAlfabetico(nombre,50,"Nombre asociado?\n","nombre no valido\n",2) &&
        !utn_getAlfabetico(apellido,50,"apellido asociado?\n","apellido no valido\n",2) &&
        !utn_getEnteroPositivo(&edad, 3, "edad asociado?\n", "edad no valida\n", 2))
    {
        strncpy(asociadoModificado->dni, dni, 20);
        strncpy(asociadoModificado->nombre, nombre, 50);
        strncpy(asociadoModificado->apellido, apellido, 50);
        asociadoModificado->edad = edad;
        retorno = 0;
    }
    return retorno;
}
int asociado_baja(Asociado* array, int len, int reintentos);
/*
{
    int retorno = -1;
    Pantalla *pantallaModificada;
    char confirmarBaja[10];
    int id;
    int i;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea dar de baja\n", "", 0) &&
                pantalla_getById(array, len, id) != NULL)
            {
                pantallaModificada = pantalla_getById(array, len, id);
                printf("Se eliminara la siguiente pantalla\n");
                pantalla_mostrar(pantallaModificada,1);
                if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                    strcmp(confirmarBaja, "1") == 0)
                {
                    pantallaModificada->isEmpty = 1;
                }
                else
                {
                    printf("La baja no fue efectuada\n");
                }
                retorno = 0;
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    return retorno;
}*/
int asociado_mostrar(Asociado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nDni: %s\nNombre: %s\nApellido: %s\nEdad: %d\nID: %d\n\n",
                array[i].dni, array[i].nombre, array[i].apellido, array[i].edad, array[i].idAsociado);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/*
int pantalla_ordenar(Pantalla* array, int len);
{
    int retorno=-1;
    int i;
    int j;
    int auxiliarNumero;
    if(array != NULL && len > 0 && (orden == 0 || orden == 1))
    {
        for(i=1;i < len; i++)
        {
            auxiliarNumero = pArray[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && (auxiliarNumero < pArray[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliarNumero;
            }
            else if(orden == 1)
            {
                while ((j >= 0) && (auxiliarNumero > pArray[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliarNumero;
            }
        }
        retorno = 0;
    }
    return retorno;
}*/


int asociado_ingresoForzado(Asociado* array, int len, char *dni, char *nombre, char *apellido, int edad)
{
    int indice;
    indice = getLugarLibre(array,len);
    strncpy(array[indice].dni, dni, 20);
    strncpy(array[indice].nombre, nombre, 50);
    strncpy(array[indice].apellido, apellido, 50);
    array[indice].edad = edad;
    array[indice].idAsociado = getNextId();
    array[indice].isEmpty = 0;
    array[indice].isActive = 1;
    return 0;
}
