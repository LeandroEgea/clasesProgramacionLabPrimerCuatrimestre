#include "LinkedList.h"
#include "Compra.h"
#include "stdio.h"
#include "string.h"


int parser_parseCompras(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    char bufferLine[1024];
    char* delimitador = ",";
    char* token;

    char bufferNombre[1024];
    char bufferId[1024];
    char bufferPrecio[1024];
    char bufferUnidades[1024];
    char bufferIva[1024];

    int flagOnce = 1;
    Compra* pCompra = NULL;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce && fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                flagOnce = 0;
            }
            if(fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                token = strtok(bufferLine, delimitador);
                strncpy(bufferNombre, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferId, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferPrecio, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferUnidades, token, 1024);
                token = strtok(NULL, "\n");
                strncpy(bufferIva, token, 1024);
                pCompra = Compra_newConParametros(  bufferNombre,bufferId,bufferUnidades,
                                                    bufferPrecio,bufferIva,"0");
            }
            if(pCompra != NULL)
            {
                retorno = 0;
                ll_add(lista, pCompra);
            }
        }
    }
    return retorno;
}

