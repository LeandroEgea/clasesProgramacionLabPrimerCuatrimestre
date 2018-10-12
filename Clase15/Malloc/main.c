#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 9
int* newArray(int size);
int* reSizeArray(int* arrayInt, int newSize);
int initArray(int* arrayInt, int limite, int valor);
int showArray(int* arrayInt, int limite);
int deleteArray(int* arrayInt);

int main()
{
    int* arrayEnteros = NULL;
    arrayEnteros = newArray(6);
    arrayEnteros = reSizeArray(arrayEnteros,CANTIDAD_NUMEROS);
    initArray(arrayEnteros,CANTIDAD_NUMEROS,1024);
    showArray(arrayEnteros,CANTIDAD_NUMEROS);
    deleteArray(arrayEnteros);
    return 0;
}

int* newArray(int size)
{
    int* retorno = NULL;
    int* auxiliarInt;
    if(size > 0)
    {
        auxiliarInt = (int*) malloc(sizeof(int)*size);
        if(auxiliarInt != NULL)
        {
            retorno = auxiliarInt;
        }
    }
    return retorno;
}

int* reSizeArray(int* arrayInt, int newSize)
{
    int* retorno = arrayInt;
    int* auxiliarInt;
    if(arrayInt != NULL && newSize > 0)
    {
        auxiliarInt = (int*) realloc(arrayInt, sizeof(int)*newSize);
        if(auxiliarInt != NULL)
        {
            retorno = auxiliarInt;
        }
    }
    return retorno;
}

int initArray(int* arrayInt, int limite, int valor)
{
    int retorno = -1;
    int i;
    if(arrayInt != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            *(arrayInt+i) = valor;
        }
        retorno = 0;
    }
    return retorno;
}

int showArray(int* arrayInt, int limite)
{
    int retorno = -1;
    int i;
    if(arrayInt != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            printf("%p - [%d] - %d\n", arrayInt+i, i, *(arrayInt+i));
        }
        retorno = 0;
    }
    return retorno;
}

int deleteArray(int* arrayInt)
{
    int retorno = -1;
    if(arrayInt != NULL)
    {
        free(arrayInt);
        retorno = 0;
    }
    return retorno;
}
