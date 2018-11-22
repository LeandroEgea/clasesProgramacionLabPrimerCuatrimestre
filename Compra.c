#include "Compra.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
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
static int isValidIva(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidFloatPositivo(pBuffer,limite);
    return retorno;
}
static int isValidMontoTotal(char *pBuffer, int limite)
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
Compra* Compra_newConParametros(char* nombreCliente,char* idProducto,char* unidades,
                                char* precioUnitario,char* iva, char* montoTotal)
{
    Compra* this;
    this=Compra_new();
    Compra* retorno = NULL;
    int idInt = atoi(idProducto);
    int unidadesInt = atoi(unidades);
    float precioFloat = atof(precioUnitario);
    float ivaFloat = atof(iva);
    float montoFloat = atof(montoTotal);
    if( isValidNombre(nombreCliente, 128) &&
        isValidId(idProducto,15) &&
        isValidUnidades(unidades,15) &&
        isValidPrecio(precioUnitario,15) &&
        isValidIva(iva,15) &&
        isValidMontoTotal(montoTotal,15) &&
        !Compra_setAll(this, nombreCliente, idInt, unidadesInt, precioFloat, ivaFloat, montoFloat))
    {
        retorno = this;
    }
    else
    {
        Compra_delete(this);
    }
    return retorno;
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
int Compra_setAll(  Compra* this,char* nombreCliente, int idProducto, int unidades,
                    float precioUnitario, float iva, float montoTotal)
{
    int retorno = -1;
    if( !Compra_setNombreCliente(this, nombreCliente) &&
        !Compra_setIdProducto(this, idProducto) &&
        !Compra_setUnidades(this, unidades) &&
        !Compra_setPrecioUnitario(this, precioUnitario) &&
        !Compra_setIva(this, iva) &&
        !Compra_setMontoTotal(this, montoTotal))
    {
        retorno = 0;
    }
    return retorno;
}
int Compra_showInfo(void* thisVoid)
{
    Compra* this = (Compra*) thisVoid;
    int retorno = -1;
    char bufferNombre[128];
    int bufferId;
    int bufferUnidades;
    float bufferPrecio;
    float bufferIva;
    float bufferMonto;
    if( this!=NULL &&
        !Compra_getNombreCliente(this, bufferNombre) &&
        !Compra_getIdProducto(this, &bufferId) &&
        !Compra_getUnidades(this, &bufferUnidades) &&
        !Compra_getPrecioUnitario(this, &bufferPrecio) &&
        !Compra_getIva(this, &bufferIva) &&
        !Compra_getMontoTotal(this, &bufferMonto))
    {
        printf( "\nNombre: %s - Id: %d - Ud: %d - Precio: %.2f - Iva: %.2f - Monto: %.2f\n",
                bufferNombre,bufferId,bufferUnidades,bufferPrecio,bufferIva,bufferMonto);
        retorno = 0;
    }
    return retorno;
}
int Compra_list(LinkedList* this)
{
    int retorno = -1;
    //Compra* pCompra = NULL;
    //int i;
    if(this != NULL)
    {
        ll_map(this, Compra_showInfo,0,ll_len(this));
        /*ll_startIterator(this);
        for(i=0;i < ll_len(this);i++)
        {
            pCompra = ll_getNext(this);
            Compra_showInfo(pCompra);
        }*/
        printf("\nHay %d compras\n",ll_len(this));
        retorno = 0;
    }
    return retorno;
}

int Compra_filtradoPorIdProducto(void* thisVoid, char* idString)
{
    Compra* this = (Compra*) thisVoid;
    int retorno = 0;
    int idProductoFilter = atoi(idString);
    int idProductoThis;
    if( this != NULL && !Compra_getIdProducto(this,&idProductoThis) &&
        idProductoFilter == idProductoThis)
    {
        retorno = 1;
    }
    return retorno;
}

int Compra_calculoMonto(void* thisVoid)
{
    Compra* this = (Compra*)thisVoid;
    int retorno = -1;
    float precio;
    int unidades;
    float iva;
    float monto;
    if( this!=NULL && !Compra_getPrecioUnitario(this, &precio) &&
        !Compra_getUnidades(this,&unidades) && !Compra_getIva(this, &iva))
    {
        monto = (precio * unidades) + (precio*unidades*iva) / 100;
        if(!Compra_setMontoTotal(this, monto))
        {
            retorno = 0;
        }
    }
    return retorno;
}
