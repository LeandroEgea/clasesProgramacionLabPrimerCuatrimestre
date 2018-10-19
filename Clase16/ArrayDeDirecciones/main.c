#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"
#include "utn.h"
#define CANTIDAD_CLIENTES 100

int main()
{
    Cliente* clientes[CANTIDAD_CLIENTES];
    Cliente* aux;
    int indiceLibre;
    char auxNombre[64];

    aux = cliente_newCliente();
    indiceLibre = cliente_buscarLugarVacio(clientes, CANTIDAD_CLIENTES);

    if(aux != NULL && indiceLibre!=-1)
    {
        cliente_setNombre(aux, "Leandro");
        clientes[indiceLibre] = aux;
        if(!cliente_getNombre(clientes[indiceLibre], auxNombre))
        {
            printf("%s", auxNombre);
        }
    }
    return 0;
}
