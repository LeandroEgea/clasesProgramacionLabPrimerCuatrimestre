#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_mostrar(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}

int array_calcularMaximo(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int array_init(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}

int array_ordenar(int *pArray, int limite, int orden)
{
    int retorno=-1;
    int i;
    int j;
    if(pArray != NULL && limite > 0)
    {
        if(orden == 0)
        {
            for(j=0;j<limite;j++)
            {
                array_minimoDesde(pArray, limite, j, &i);
                array_swap(&pArray[j], &pArray[i]);
            }
        }
        else if(orden == 1)
        {
            for(j=(limite-1);j>0;j--)
            {
                array_minimoDesde(pArray, j+1, 0, &i);
                array_swap(&pArray[j], &pArray[i]);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int array_ordenar2(int *pArray, int limite, int orden)
{
    int retorno=-1;
    int j;
    int flagSwap;
    if(pArray != NULL && limite > 0)
    {
        do
        {
            flagSwap = 0;
            for(j=0;j<(limite-1);j++)
            {
                if( (orden == 0 && pArray[j] < pArray[j+1]) ||
                    (orden == 1 && pArray[j] > pArray[j+1]))
                {
                    flagSwap = 1;
                    array_swap(&pArray[j], &pArray[j+1]);
                }
            }
        }while(flagSwap==1);
        retorno = 0;
    }
    return retorno;
}

int array_minimoDesde(int *pArray, int limite, int desde, int *pMinimo)
{
    int retorno=-1;
    int i;
    int menor;
    int auxiliarIndiceMinimo;
    if(pArray != NULL && limite > 0 && limite >= desde)
    {
        for(i=desde;i<limite;i++)
        {
            if(i==desde || pArray[i] < menor)
            {
                menor = pArray[i];
                auxiliarIndiceMinimo = i;
            }
        }
        *pMinimo = auxiliarIndiceMinimo;
        retorno = 0;
    }
    return retorno;
}

void array_swap(int *elementoA, int *elementoB)
{
    int auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}
