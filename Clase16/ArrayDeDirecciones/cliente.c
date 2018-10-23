#include "cliente.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        pBuffer[0]>='A' && pBuffer[0]<='Z')

    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidNombre(nombre, lenNombre))
    {
        strncpy(this->nombre,nombre,lenNombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(nombre,this->nombre,lenNombre);
        retorno=0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this,char* apellido,int lenApellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidNombre(apellido, lenApellido))
    {
        strncpy(this->apellido,apellido,lenApellido);
        retorno=0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this,char* apellido,int lenApellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strncpy(apellido,this->apellido,lenApellido);
        retorno=0;
    }
    return retorno;
}

int cliente_setIdCliente(Cliente* this,int idCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idCliente=idCliente;
        retorno=0;
    }
    return retorno;
}

int cliente_getIdCliente(Cliente* this,int* idCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idCliente=this->idCliente;
        retorno=0;
    }
    return retorno;
}

Cliente* cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

Cliente* cliente_newConParametros(  char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,int idCliente)
{
    Cliente* this;
    this=cliente_new();

    if(
    !cliente_setNombre(this,nombre,lenNombre)&&
    !cliente_setApellido(this,apellido,lenApellido)&&
    !cliente_setIdCliente(this,idCliente))
        return this;

    cliente_delete(this);
    return NULL;
}

int cliente_init (Cliente** arrayClientes, int lenClientes)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0;i<lenClientes;i++)
        {
            *(arrayClientes+i) = NULL;
        }
    }
    return retorno;
}

int cliente_delete(Cliente* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}

int cliente_buscarLugarVacio(Cliente** arrayClientes, int lenClientes)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0;i<lenClientes;i++)
        {
            if(*(arrayClientes+i) == NULL)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_buscarPorId(Cliente** arrayClientes,int lenClientes, int id)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i<lenClientes; i++)
        {
            if((arrayClientes+i) != NULL && (*(arrayClientes+i))->idCliente == id)//preguntar
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
//hacer Abm del parcial con todo esto
