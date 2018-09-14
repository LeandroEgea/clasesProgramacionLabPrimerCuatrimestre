#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer, int limite)
{
    int retorno = 0;//solo para las (is)
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(!(tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferString, limite, stdin);
        len = strlen(bufferString);
        if(len != limite-1 || bufferString[limite-2] == '\n')
        {
            bufferString[len-1] = '\0';
        }
        strncpy(pBuffer, bufferString, limite);
        retorno = 0;
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char msgErr[], int reintentos)
{
    int retorno=-1;
    char bufferNombre[4096];
    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s", msg);
            if( getString(bufferNombre, limite) == 0 &&
                isValidNombre(bufferNombre, limite))
            {
                    strncpy(pNombre, bufferNombre, limite);
                    retorno = 0;
                    break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos>0);
    }
    return retorno;
}
