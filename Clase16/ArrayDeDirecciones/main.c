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
    char auxApellido[64];

    aux = cliente_newConParametros("Pepe",51,"Gomez",51,3);
    indiceLibre = cliente_buscarLugarVacio(clientes, CANTIDAD_CLIENTES);

    if(aux != NULL && indiceLibre!=-1)
    {
        cliente_setNombre(aux, "Leandro",51);
        clientes[indiceLibre] = aux;
        if(!cliente_getNombre(clientes[indiceLibre], auxNombre,64))
        {
            printf("%s", auxNombre);
        }
        if(!cliente_getApellido(clientes[indiceLibre], auxApellido,64))
        {
            printf("%s", auxApellido);
        }
    }
    return 0;
}
