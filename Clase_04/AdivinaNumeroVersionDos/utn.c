#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin);
}
static int getInt(int* numeroIngresado)
{
    myFpurge();
    return scanf("%d", &numeroIngresado);
}
static int getInt(float* numeroIngresado)
{
    myFpurge();
    return scanf("%f", &numeroIngresado);
}
static int getInt(char* caracterIngresado)
{
    myFpurge();
    return scanf("%c", &caracterIngresado);
}
static int getInt(char caracterIngresado[])
{
    myFpurge();
    return scanf("%s", &textoIngresado);
}





/**
* \brief Solicita un entero al usuario y lo devuelve a traves de pResultado si es validado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError ES el mensaje que se muestra en caso de error
* \param minimo Es el entero minimo aceptado
* \param maximo Es el entero maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un entero
* \return En caso de exito retorna 0, si no es un entero validado 1 y si no es un entero -1
*
*/

int utn_getEntero(  int *pResultado,
                char mensaje[],
                char mensajeError[],
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    int numeroIngresado;
    do
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        if(scanf("%d", &numeroIngresado) == 1)
        {
            retorno = utn_validarEnteroEnIntervalo(numeroIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pResultado = numeroIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}

/**
* \brief Valida si un entero esta entre un maximo y un minimo
* \param numeroIngresado Es el numero se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/

int utn_validarEnteroEnIntervalo(int numeroIngresado, int minimo, int maximo)
{
    int retorno;
    if(numeroIngresado >= minimo && numeroIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(numeroIngresado < minimo || numeroIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}


/**
* \brief Solicita un caracter al usuario y le muestra el resultado
* \param pCaracterResultante Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError ES el mensaje que se muestra en caso de error
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un caracter
* \return En caso de exito retorna 0, si no es un carcter validado 1 y si no es un carcter -1
*
*/


int utn_getCaracter(  char *pCaracterResultante,
                char mensaje[],
                char mensajeError[],
                char minimo,
                char maximo,
                int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    char caracterIngresado;
    do
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        if(scanf("%d", &caracterIngresado) == 1)
        {
            retorno = utn_validarCaracterEnIntervalo(numeroIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pCaracterResultante = caracterIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}

/**
* \brief Valida si un caracter esta entre un maximo y un minimo
* \param caracterIngresado Es el caracter se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/

int utn_validarEnteroEnIntervalo(int caracterIngresado, int minimo, int maximo)
{
    int retorno;
    if(caracterIngresado >= minimo && caracterIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(caracterIngresado < minimo || caracterIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}



