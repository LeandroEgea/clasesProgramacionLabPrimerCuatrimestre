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
    return scanf("%d", numeroIngresado);
}
static int getFloat(float* numeroIngresado)
{
    myFpurge();
    return scanf("%f", numeroIngresado);
}
static int getChar(char* caracterIngresado)
{
    myFpurge();
    return scanf("%c", caracterIngresado);
}
static int getString(char textoIngresado[])
{
    myFpurge();
    return scanf("%s", textoIngresado);
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
        if(getInt(&numeroIngresado) == 1)
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
* \brief Solicita un flotante al usuario y lo devuelve a traves de pResultado si es validado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError ES el mensaje que se muestra en caso de error
* \param minimo Es el flotante minimo aceptado
* \param maximo Es el flotante maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un flotante
* \return En caso de exito retorna 0, si no es un flotante validado 1 y si no es un flotante -1
*
*/
int utn_getFlotante(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    float minimo,
                    float maximo,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    float numeroIngresado;
    do
    {
        printf("%s", mensaje);
        if(getFloat(&numeroIngresado) == 1)
        {
            retorno = utn_validarFlotanteEnIntervalo(numeroIngresado, minimo, maximo);
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
* \brief Valida si un flotante esta entre un maximo y un minimo
* \param numeroIngresado Es el numero se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/
int utn_validarFlotanteEnIntervalo(float numeroIngresado, float minimo, float maximo)
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
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un caracter
* \return En caso de exito retorna 0, si no es un caracter validado 1 y si no es un caracter -1
*
*/
int utn_getCaracter(char *pCaracterResultante,
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
        if(getChar(&caracterIngresado) == 1)
        {
            retorno = utn_validarCaracterEnIntervalo(caracterIngresado, minimo, maximo);
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
int utn_validarCaracterEnIntervalo(char caracterIngresado, char minimo, char maximo)
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
/**
* \brief Solicita una cadena al usuario y le muestra el resultado
* \param pCadenaResultante Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param longitudMinima Es la longitud de la cadena minima aceptada
* \param longitudMaxima Es la longitud de la cadena maxima aceptada
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar una cadena
* \return En caso de exito retorna 0, si no es una cadena validada 1 y si no se recibio el string -1
*
*/
int utn_getCadena(  char *pCadenaResultante,
                    char mensaje[],
                    char mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    char caracterIngresado;
    do
    {
        printf("%s", mensaje);
        if(getChar(&caracterIngresado) == 1)
        {
            retorno = utn_validarCaracterEnIntervalo(caracterIngresado, minimo, maximo);
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
* \brief Valida si una cadena tiene una longitud entre un maximo y un minimo
* \param caracterIngresado Es el caracter se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/
int utn_validarCaracterEnIntervalo(char caracterIngresado, char minimo, char maximo)
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



