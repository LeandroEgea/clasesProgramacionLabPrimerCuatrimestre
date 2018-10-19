#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"
#include "utn.h"
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
Cliente* cliente_newCliente(void)
{
    //return (Cliente*)malloc(sizeof(Cliente));
    Cliente* p;
    p = (Cliente*)malloc(sizeof(Cliente));
    return p;
}
int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre, sizeof(this->nombre)))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
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
    //validar todo
    for(i=0; i<lenClientes; i++)
    {
        if((arrayClientes+i) != NULL && (*(arrayClientes+i))->idCliente == id)//preguntar
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int cliente_deleteCliente(Cliente* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}
Cliente* cliente_newClienteParametros(char* nombre, char* apellido, char* id)
{
//validar
    Cliente* p;
    p = cliente_newCliente();
    if(p!=NULL)
    {
        if(cliente_setNombre(p, nombre)-1)// || el set de apellido y el set de id)
        {
            cliente_deleteCliente(p);
            p = NULL;
        }
    }
    return p;
}
//hacer todos los getters y setters
//hacer publicos todos los isValid
//hacer isValid propios de la entidad
//delete
//mirar todo y corregirlo un poco validar todo
