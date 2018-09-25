#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

static int getLugarLibre(Pantalla* array, int len)
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

int pantalla_init(Pantalla* array, int len)
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

Pantalla* pantalla_getById(Pantalla* array, int len,int id)
{
    Pantalla* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array, int len)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char direccion[200];
    float precio;
    char tipo[20];

    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getTexto(nombre,50,"Nombre pantalla?\n","nombre no valido\n",2) &&
        !utn_getTexto(direccion,200,"Direccion pantalla?\n","direccion no valida\n",2) &&
        !utn_getFloat(&precio, 20, "Precio pantalla?\n", "precio no valido\n", 2) &&
        !utn_getOpcionEntreDos(tipo, 20, "LCD", "LED", "1", "2", 2))
    {
        strncpy(array[indice].nombre, nombre,50);
        strncpy(array[indice].direccion, direccion,200);
        array[indice].precio = precio;
        strncpy(array[indice].tipo, tipo, 20);
        if(strcmp("LCD", tipo) == 0)
        {
            array[indice].numeroDeTipo = 1;
        }
        else if(strcmp("LED", tipo) == 0)
        {
            array[indice].numeroDeTipo = 2;
        }
        array[indice].isEmpty = 0;
        array[indice].id = getNextId();
        retorno = 0;
    }
    return retorno;
}

int pantalla_modificar(Pantalla* array, int len, int reintentos)
{
    int retorno = -1;
    Pantalla *pantallaModificada;
    int id;
    int i;
    char nombre[50];
    char direccion[200];
    float precio;
    char tipo[20];

    if(array != NULL && len > 0 && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                pantalla_getById(array, len, id) != NULL)
            {
                pantallaModificada = pantalla_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    if( !utn_getTexto(nombre,50,"Nombre pantalla?\n","nombre no valido\n",2) &&
        !utn_getTexto(direccion,200,"Direccion pantalla?\n","direccion no valida\n",2) &&
        !utn_getFloat(&precio, 20, "Precio pantalla?\n", "precio no valido\n", 2) &&
        !utn_getOpcionEntreDos(tipo, 20, "LCD", "LED", "1", "2", 2))
    {
        strncpy(pantallaModificada->nombre, nombre,50);
        strncpy(pantallaModificada->direccion, direccion,200);
        pantallaModificada->precio = precio;
        strncpy(pantallaModificada->tipo, tipo, 20);
        if(strcmp("LCD", tipo) == 0)
        {
            pantallaModificada->numeroDeTipo = 1;
        }
        else if(strcmp("LED", tipo) == 0)
        {
            pantallaModificada->numeroDeTipo = 2;
        }
        pantallaModificada->id = getNextId();//PREGUNTAR
        retorno = 0;
    }
    return retorno;
}

int pantalla_baja(Pantalla* array, int len, int reintentos)
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
}

int pantalla_mostrar(Pantalla* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %s\nID: %d\n\n",
                array[i].nombre, array[i].direccion, array[i].precio, array[i].tipo, array[i].id);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int pantalla_ordenar(Pantalla* array, int len);
