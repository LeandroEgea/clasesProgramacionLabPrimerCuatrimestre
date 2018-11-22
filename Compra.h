#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
  char nombreCliente[128];
  int idProducto;
  int unidades;
  float precioUnitario;
  float iva;
  float montoTotal;
}Compra;

Compra* Compra_new();
void Compra_delete();
Compra* Compra_newConParametros(char* nombreCliente,char* idProducto,char* unidades,
                                char* precioUnitario,char* iva, char* montoTotal);

int Compra_setNombreCliente(Compra* this,char* nombreCliente);
int Compra_getNombreCliente(Compra* this,char* nombreCliente);

int Compra_setPrecioUnitario(Compra* this,float precioUnitario);
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario);

int Compra_setIva(Compra* this,float iva);
int Compra_getIva(Compra* this,float* iva);

int Compra_setMontoTotal(Compra* this,float montoTotal);
int Compra_getMontoTotal(Compra* this,float* montoTotal);

int Compra_setIdProducto(Compra* this,int idProducto);
int Compra_getIdProducto(Compra* this,int* idProducto);

int Compra_setUnidades(Compra* this,int unidades);
int Compra_getUnidades(Compra* this,int* unidades);
int Compra_setAll(  Compra* this,char* nombreCliente, int idProducto, int unidades,
                    float precioUnitario, float iva, float montoTotal);
int Compra_showInfo(void* thisVoid);
int Compra_list(LinkedList* this);
int Compra_filtradoPorIdProducto(void* thisVoid, char* idString);
int Compra_calculoMonto(void* thisVoid);

#endif // COMPRA_H_INCLUDED
