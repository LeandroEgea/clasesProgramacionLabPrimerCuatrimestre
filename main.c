#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Compra.h"
#include "Parser.h"
#include "utn.h"
#include "string.h"
/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    // Leer compras de archivo data.csv
    if(!parser_parseCompras("data.csv",listaCompras))
    {
        // Filtrar
        int idProducto;
        char idString[20];
        utn_getEnteroSoloNumeros(&idProducto, 15,"Ingrese id de producto:","\nError",0);
        snprintf(idString,20,"%d",idProducto);
        listaFiltrada = ll_filter(listaCompras, Compra_filtradoPorIdProducto,idString);

        // Calcular montos
        printf("Calculando montos totales...\n");
        ll_map(listaCompras, Compra_calculoMonto, 0, ll_len(listaCompras));
        Compra_list(listaFiltrada);
        Compra_list(listaCompras);

        // Generar archivo de salida
        if(!generarArchivoInforme("informe.csv",listaFiltrada))
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo compras\n");

    return 0;
}

int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    int retorno = -1;
    Compra* pCompra;
    int i;
    char bufferNombre[128];
    int bufferId;
    float bufferPrecio;
    int bufferUnidades;
    float bufferIva;
    float bufferMonto;

    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"nombreCliente,idProducto,precioUnitario,unidades,iva,monto");
        for(i=0;i<ll_len(listaCompras);i++)
        {
            pCompra = ll_get(listaCompras,i);
            Compra_getNombreCliente(pCompra, bufferNombre);
            Compra_getIdProducto(pCompra, &bufferId);
            Compra_getPrecioUnitario(pCompra, &bufferPrecio);
            Compra_getUnidades(pCompra, &bufferUnidades);
            Compra_getIva(pCompra, &bufferIva);
            Compra_getMontoTotal(pCompra, &bufferMonto);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferPrecio > 0 && bufferUnidades > 0 &&
                bufferIva >= 0 && bufferMonto > 0)
            {
                fprintf(pFile,"\n%s,%d,%f,%d,%f,%f",bufferNombre, bufferId,
                                                    bufferPrecio,bufferUnidades,
                                                    bufferIva,bufferMonto);
            }
        }
    }
    return retorno;
}
