#include "Compra.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int isValidNombre(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidNombre(pBuffer,limite);
    if(retorno != 1)
    {
        printf("\nEl nombre debe comenzar por mayuscula y el resto minusculas");
    }
    return retorno;
}
static int isValidId(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
static int isValidUnidades(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
static int isValidPrecio(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidFloatPositivo(pBuffer,limite);
    return retorno;
}

Compra* Compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    return this;
}
void Compra_delete(Compra* this)
{
    free(this);
}
Compra* Compra_newConParametros(char* nombreCliente,float precioUnitario,float iva,float montoTotal,int idProducto,int unidades)
{
    Compra* this;
    this=Compra_new();

    if(
    !Compra_setNombreCliente(this,nombreCliente)&&
    !Compra_setPrecioUnitario(this,precioUnitario)&&
    !Compra_setIva(this,iva)&&
    !Compra_setMontoTotal(this,montoTotal)&&
    !Compra_setIdProducto(this,idProducto)&&
    !Compra_setUnidades(this,unidades))
    return this;

    Compra_delete(this);
    return NULL;
}
int Compra_setNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->nombreCliente,nombreCliente);
        retorno=0;
    }
    return retorno;
}
int Compra_getNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(nombreCliente,this->nombreCliente);
        retorno=0;
    }
    return retorno;
}
int Compra_setPrecioUnitario(Compra* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}
int Compra_setIva(Compra* this,float iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->iva=iva;
        retorno=0;
    }
    return retorno;
}

int Compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva=this->iva;
        retorno=0;
    }
    return retorno;
}

int Compra_setMontoTotal(Compra* this,float montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoTotal=montoTotal;
        retorno=0;
    }
    return retorno;
}

int Compra_getMontoTotal(Compra* this,float* montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoTotal=this->montoTotal;
        retorno=0;
    }
    return retorno;
}

int Compra_setIdProducto(Compra* this,int idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idProducto=idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_getIdProducto(Compra* this,int* idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProducto=this->idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_setUnidades(Compra* this,int unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->unidades=unidades;
        retorno=0;
    }
    return retorno;
}

int Compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades=this->unidades;
        retorno=0;
    }
    return retorno;
}

