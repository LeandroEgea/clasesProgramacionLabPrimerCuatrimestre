#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin);
}

/*
static int getInt(int* numeroIngresado)
{
    int retorno = 1;
    char bufferNumero[1000];
    myFpurge();
    if(scanf("%s", bufferNumero)==1)
    {
        if(utn_validarIntString(bufferNumero) == 0)
        {
            *numeroIngresado = atoi(bufferNumero);
            retorno = 0;
        }
    }
    return retorno;
}
static int getFloat(float* numeroIngresado)
{
    int retorno = 1;
    char bufferNumero[1000];
    myFpurge();
    if(scanf("%s", bufferNumero)==1)
    {
        if(utn_validarFloatString(bufferNumero) == 0)
        {
            *numeroIngresado = atof(bufferNumero);
            retorno = 0;
        }
    }
    return retorno;
}
static int getChar(char* caracterIngresado)
{
    myFpurge();
    return scanf("%c", caracterIngresado);
}*/

//TOMA DE DATOS STATIC

/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*
*/
static int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0)
    {
        myFpurge();
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

//VALIDACIONES

/**
* \brief Evalua si se trata de una cadena solo de letras
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidAlfabetico(char *pBuffer, int limite)
{
    int retorno = 0;
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
* \brief Evalua si se trata de una cadena alfanumerica
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidAlfanumerico(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(!(   (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z') ||
                    (pBuffer[i] >= '0' && pBuffer[i] <= '9')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Evalua si se trata de un texto valido(Letras numeros simbolos)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidTexto(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(!(   (pBuffer[i] >= ' ' && pBuffer[i] <= '"') ||
                    pBuffer[i] == '(' || pBuffer[i] == ')' ||
                    (pBuffer[i] >= ',' && pBuffer[i] <= '.') ||
                    (pBuffer[i] >= '0' && pBuffer[i] <= ';') ||
                    (pBuffer[i] >= '?' && pBuffer[i] <= 'Z') ||
                    (pBuffer[i] >= 'a' && pBuffer[i] <= 'z')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Valida si un entero esta entre un maximo y un minimo
* \param numeroIngresado Es el numero se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero maximo aceptado
* \return En caso de exito retorna 1, si esta fuera del rango 0
*
*/
static int isValidEnteroEnIntervalo(int numeroIngresado, int minimo, int maximo)
{
    int retorno = 0;
    if(numeroIngresado >= minimo && numeroIngresado <= maximo)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Evalua si se trata de un mail(acepta letras numeros '.' '_' antes del @ y letras '.' despues)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidMail(char *pBuffer, int limite)
{
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        tolower(pBuffer[0]) >= 'a' &&
        tolower(pBuffer[0]) <= 'z')
    {
        retorno = 1;
        flagLetraIntroducida = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDeArrobas == 0))
            {
                flagLetraIntroducida = 1;
            }
            else if(pBuffer[i] == '@' && contadorDeArrobas == 0 && flagLetraIntroducida == 1)
            {
                contadorDeArrobas++;
                flagLetraIntroducida = 0;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
                if(contadorDeArrobas == 1)
                {
                    contadorDePuntosTrasArroba++;
                }
            }
            else if(pBuffer[i] == '_' && flagLetraIntroducida == 1 && contadorDeArrobas == 0)
            {
                flagLetraIntroducida = 0;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    if(retorno == 1 && contadorDeArrobas == 1 && contadorDePuntosTrasArroba > 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nejemplo_123@mail.com.ar");
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Evalua si es un telefono fijo (4XXX-XXXX)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidTelefonoFijo(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        strlen(pBuffer) == 9 && pBuffer[4] == '-' && pBuffer[0] == '4')
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=4)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Evalua si es una fecha valida (dd/mm/aaaa)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
            (dia > 0 && dia <= 31)) ||
           ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
            (dia > 0 && dia <= 30)) ||
           ((mes == 2 && (anio % 4) == 0) &&
            (dia > 0 && dia <= 29)) ||
           ((mes == 2 && (anio % 4) != 0) &&
            (dia > 0 && dia <= 28)))
        {
            retorno = 1;
        }
    }
    return retorno;
}
/**
* \brief Evalua si se trata de una web valida
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidWeb(char *pBuffer, int limite)
{
    int retorno = 0;
    int contadorDePuntos = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 7 &&
        tolower(pBuffer[0]) == 'w' && tolower(pBuffer[1]) == 'w' &&
        tolower(pBuffer[2]) == 'w' && pBuffer[3] == '.')
    {
        retorno = 1;
        for(i=4;i < limite && pBuffer[i] != '\0';i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDePuntos == 0))
            {
                flagLetraIntroducida = 1;
            }
            else if(pBuffer[i] == '-' && contadorDePuntos == 0 && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
                contadorDePuntos++;
            }
            else
            {
                retorno = 0;
                break;
            }

        }
    }
    if(retorno == 1 && contadorDePuntos > 0 && contadorDePuntos <= 2)
    {
        retorno = 1;
    }
    else
    {
        printf("\nwww.ejemplo.com");
        retorno = 0;
    }
    return retorno;
}

//TOMA DE DATOS PARA EL MAIN

/**
* \brief Toma una cadena y evalua si tiene solo letras
* \param pAlfabetico Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getAlfabetico(  char *pAlfabetico, int limite, char *mensaje,
                        char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferAlfabetico[4096];
    if( pAlfabetico != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferAlfabetico, limite) == 0 &&
                isValidAlfabetico(bufferAlfabetico, limite))
            {
                strncpy(pAlfabetico, bufferAlfabetico, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es alfanumerica
* \param pAlfanumerico Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getAlfanumerico(char *pAlfanumerico, int limite, char *mensaje,
                        char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pAlfanumerico != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidAlfanumerico(buffer, limite))
            {
                strncpy(pAlfanumerico, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es un texto valido
* \param pTexto Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getTexto(   char *pTexto, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pTexto != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidTexto(buffer, limite))
            {
                strncpy(pTexto, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es un entero
* \param pEntero Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEntero(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es un float
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si puede ser un mail
* \param pMail Recibe el mail ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getMail(char *pMail, int limite, char *mensaje,
                char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pMail != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidMail(buffer, limite))
            {
                strncpy(pMail, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es un telefono fijo (4XXX-XXXX)
* \param pTelefono Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getTelefonoFijo(char *pTelefono, int limite, char *mensaje,
                        char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pTelefono != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidTelefonoFijo(buffer, limite))
            {
                strncpy(pTelefono, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es una fecha valida (dd/mm/aaaa)
* \param pFecha Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getFecha(   char *pFecha, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferDia[512];
    char bufferMes[512];
    char bufferAnio[512];
    int dia;
    int mes;
    int anio;
    if( pFecha != NULL && limite >= 11 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            printf("\nIntroduzca Dia(dd): ");
            if( getString(bufferDia, limite) == 0 &&
                strlen(bufferDia) == 2 &&
                isValidEntero(bufferDia, limite))
            {
                dia = atoi(bufferDia);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Mes(mm): ");
            if( getString(bufferMes, limite) == 0 &&
                strlen(bufferMes) == 2 &&
                isValidEntero(bufferMes, limite))
            {
                mes = atoi(bufferMes);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Anio(aaaa): ");
            if( getString(bufferAnio, limite) == 0 &&
                strlen(bufferAnio) == 4 &&
                isValidEntero(bufferAnio, limite))
            {
                anio = atoi(bufferAnio);
            }
            else
            {
                continue;
            }
            if (isValidFecha(dia, mes, anio))
            {
                strncpy(pFecha, bufferDia,4);
                pFecha[2] = '/';
                strcat(pFecha, bufferMes);
                pFecha[5] = '/';
                strcat(pFecha, bufferAnio);
                pFecha[10] = '\0';
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es una web valida
* \param pWeb Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getWeb( char *pWeb, int limite, char *mensaje,
                char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pWeb != NULL && limite > 7 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidWeb(buffer, limite))
            {
                strncpy(pWeb, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
//SWAP

/**
* \brief Realiza un swap de dos enteros
* \param pElementoUno -
* \param pElementoDos -
*
*/
void utn_swapEnteros(int *pElementoUno, int *pElementoDos)
{
    int auxiliar;
    auxiliar = *pElementoUno;
    *pElementoUno = *pElementoDos;
    *pElementoDos = auxiliar;
}

/**
* \brief Realiza un swap de dos empleados
* \param pEmpleadoUno -
* \param pEmpleadoDos -
*
*/
void utn_swapEmpleado(Empleado *pEmpleadoUno, Empleado *pEmpleadoDos)
{
    Empleado bufferEmpleado;
    bufferEmpleado = *pEmpleadoUno;
    *pEmpleadoUno = *pEmpleadoDos;
    *pEmpleadoDos = bufferEmpleado;
}

//ARRAYS

/**
* \brief Inicializa con un valor un array de enteros
* \param pArray Es el array de enteros que vamos a inicializar
* \param limite Es la cantidad de numeros q tiene el array
* \param valor Es el valor con el que se inicializa cada elemento
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_inicializarArrayEnteros(int* pArray, int limite, int valor)
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
/**
* \brief Hace un printf con cada valor del array
* \param pArray Es el array de enteros que vamos a mostrar
* \param limite Es la cantidad de numeros q tiene el array
*
*/
void utn_mostrarArrayEnteros(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);
    }
}
/**
* \brief Calcula el maximo
* \param pArray Es el array de enteros que vamos a evaluar
* \param limite Es la cantidad de numeros q tiene el array
* \param pMaximo Por ahi se devuelve el valor del maximo
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_calcularMaximoArrayEnteros(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = 0;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != -1)
            {
                if(flagPrimerMaximo == 0)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = 1;
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
/**
* \brief Calcula el minimo desde un indice indicado
* \param pArray Es el array de enteros que vamos a evaluar
* \param limite Es la cantidad de numeros q tiene el array
* \param desde Desde que indice(empezando desde 1) comenzamos a evaluar
* \param pMinimo Por ahi se devuelve el valor del minimo
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_minimoDesdeEnArrayEnteros(int *pArray, int limite, int desde, int *pMinimo)
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
/**
* \brief Ordena todos los numeros del array
* \param pArray Es el array de enteros que vamos a ordenar
* \param limite Es la cantidad de numeros q tiene el array
* \param orden Establece de mayor a menor(0) o de menor a mayor (1)
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_sortArrayEnterosPorBurbujeo(int *pArray, int limite, int orden)
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
                    utn_swapEnteros(&pArray[j], &pArray[j+1]);
                }
            }
        }while(flagSwap==1);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief devuelve el mayor numero dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \return devuelve el mayor numero
*
*/
int utn_retornarMayor(int listado[], int tamanio)
{
    int mayor;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]>mayor)
        {
            mayor = listado[i];
        }
    }
    return mayor;
}
/**
* \brief devuelve el menor numero dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \return devuelve el menor numero
*
*/
int utn_retornarMenor(int listado[], int tamanio)
{
    int menor;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(i==0 || listado[i]<menor)
        {
            menor = listado[i];
        }
    }
    return menor;
}
/**
* \brief devuelve la cantidad de valores pares dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \return devuelve la cantidad de valores pares
*
*/
int utn_retornarCantidadDePares(int listado[], int tamanio)
{
    int i;
    int cantidadDePares = 0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i] % 2 == 0)
        {
            cantidadDePares++;
        }
    }
    return cantidadDePares;
}
/**
* \brief devuelve la suma de todos los valores dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \return devuelve la suma de todos los valores
*
*/
int utn_retornarTotal(int listado[], int tamanio)
{
    int i;
    int sumaTotal = 0;
    for(i=0;i<tamanio;i++)
    {
        sumaTotal = sumaTotal + listado[i];
    }
    return sumaTotal;
}
/**
* \brief devuelve el promedio de la suma de todos los valores dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \return devuelve el promedio de la suma de todos los valores
*
*/
float utn_retornarPromedio(int listado[], int tamanio)
{
    int sumaTotal;
    float promedio;
    sumaTotal = utn_retornarTotal(listado, tamanio);
    promedio = (float)sumaTotal/tamanio;
    return promedio;
}
/**
* \brief devuelve los enteros que estan en un intervalo dentro de un array de enteros
* \param listado Es el array que vamos a evaluar
* \param tamanio Es la cantidad de numeros que tiene el array
* \param minimo Es el minimo del intervalo
* \param maximo Es el maximo del intervalo
* \return devuelve los enteros que estan en un intervalo
*
*/
int utn_cantidadEnterosEnIntervalo(int listado[], int tamanio, int minimo, int maximo)
{
    int i;
    int cantidadEnteros = 0;
    for(i=0; i<tamanio; i++)
    {
        if(isValidEnteroEnIntervalo(listado[i], minimo, maximo))
        {
            cantidadEnteros++;
        }
    }
    return cantidadEnteros;
}

//ESTRUCTURAS

/**
* \brief Realiza un ordenamiento de una serie de empleados
* \param pEmpleado Es el array de estructuras de empleados
* \param cantidadEmpleados Es el numero de empleados que se van a ordenar
*
*/
int utn_sortEmpleadosPorNombre(Empleado *pEmpleado, int cantidadEmpleados)
{
    int retorno = -1;
    int swap;
    int i;
    if(pEmpleado != NULL && cantidadEmpleados > 0)
    {
        do
        {
            swap = 0;
            for(i=0;i<cantidadEmpleados-1;i++)
            {
                if(strcmp(pEmpleado[i].nombre, pEmpleado[i+1].nombre)>0)
                {
                    swap = 1;
                    utn_swapEmpleado(&(pEmpleado[i]), &(pEmpleado[i+1]));
                }
            }
        }while(swap != 0);
        retorno = 0;
    }
    return retorno;
}

//MATH

/**
* \brief Suma numeros con decimales
* \param numeroUno Primer sumando
* \param numeroDos Segundo sumando
* \return Devuelve el resultado de la suma
*
*/
float utn_sumarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoSuma;
    resultadoSuma = numeroUno + numeroDos;
    return resultadoSuma;
}
/**
* \brief Resta numeros con decimales
* \param numeroUno Minuendo de la resta
* \param numeroDos Sustraendo de la resta
* \return Devuelve el resultado de la resta
*
*/
float utn_restarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoResta;
    resultadoResta = numeroUno - numeroDos;
    return resultadoResta;
}
/**
* \brief Multiplica numeros con decimales
* \param numeroUno Primer factor
* \param numeroDos Segundo factor
* \return Devuelve el resultado de la multiplicacion
*
*/
float utn_multiplicarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion = numeroUno * numeroDos;
    return resultadoMultiplicacion;
}
/**
* \brief Dividir numeros con decimales
* \param numeroUno Dividendo
* \param numeroDos Divisior
* \param resultadoDivision Es el resultado que se obtiene si es posible dividir
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede dividir
*/
int utn_dividirDosFlotantes(float numeroUno, float numeroDos, float *resultadoDivision)
{
    int retorno;
    if(numeroDos == 0)
    {
        retorno = 1;
    }
    else
    {
        *resultadoDivision = numeroUno / numeroDos;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Obtiene el resultado de
* \param numero Es el numero en el que se realiza el factorial
* \param resultadoFactorial Es el resultado que se obtiene si es posible realizar el factorial
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede realizar el factorial
*/
unsigned long long int utn_obternerResultadoFactorial(int numero)
{
    unsigned long long int resultado;
    if(numero == 1)
    {
        return 1;
    }
    resultado =  numero * utn_obternerResultadoFactorial(numero-1);
    return resultado;
}
/**
* \brief Realiza el factorial de un flotante
* \param numero Es el numero en el que se evalua si se puede realizar el factorial
* \param resultadoFactorial Es el resultado que se obtiene si es posible realizar el factorial
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede realizar el factorial
*/
int utn_realizarFactorialConFlotante(float numero, unsigned long long int *resultadoFactorial)
{
    unsigned long long int resultadoParcial;
    int numeroEntero;
    int retorno;
    if((numero - (int)numero) == 0)
    {
        numeroEntero = (int)numero;
        if(numeroEntero < 0)
        {
            printf("No se puede realizar el factorial de un numero negativo\n");
            retorno = 1;
        }
        else if(numeroEntero == 0)
        {
            *resultadoFactorial = 1;
            retorno = 0;
        }
        else if(numeroEntero > 0 && numeroEntero <=20)
        {
            resultadoParcial = utn_obternerResultadoFactorial(numeroEntero);
            *resultadoFactorial = resultadoParcial;
            retorno = 0;
        }
        else if(numero > 20)
        {
            printf("El numero es demasiado grande, solo es posible hasta el factorial de 20\n");
            retorno = 1;
        }
        else
        {
            printf("No se pudo realizar el factorial\n");
            retorno = 1;
        }
    }
    else
    {
        printf("No se puede realizar el factorial de un numero decimal\n");
        retorno = 1;
    }
    return retorno;
}

//OTHER

/**
* \brief imprime un resultado, el error producido en la operacion o un error en caso de que se pase otro valor
* \param opcionAMostrar Debe valer 0 o 1 para que el usuario la vea
* \param mensajeResultado mensaje que se muestra cuando opcionAMostrar es 0
* \param resultado Es el flotante que muestra el resultado obtenido
* \param mensajeNoExisteResultado mensaje que se muestra cuando opcionAMostrar es 1
* \param mensajeError mensaje que se muestra cuando opcionAMostrar es distinta de 0 y 1
*
*/
void utn_imprimirResultadoFloatOErrorEnPantalla(int opcionAMostrar,
                                                char mensajeResultado[],
                                                float resultado,
                                                char mensajeNoExiteResultado[],
                                                char mensajeError[])
{
    if(opcionAMostrar == 0)
    {
        printf("%s %.5f\n", mensajeResultado, resultado);
    }
    else if(opcionAMostrar == 1)
    {
        printf("%s\n", mensajeNoExiteResultado);
    }
    else
    {
        printf("%s\n", mensajeError);
    }
}
/**
* \brief imprime un resultado, el error producido en la operacion o un error en caso de que se pase otro valor
* \param opcionAMostrar Debe valer 0 o 1 para que el usuario la vea
* \param mensajeResultado mensaje que se muestra cuando opcionAMostrar es 0
* \param resultado Muestra el resultado obtenido si la operacion es correcta
* \param mensajeNoExisteResultado mensaje que se muestra cuando opcionAMostrar es 1
* \param mensajeError mensaje que se muestra cuando opcionAMostrar es distinta de 0 y 1
*
*/
void utn_imprimirResultadoLongLongOErrorEnPantalla( int opcionAMostrar,
                                                    char mensajeResultado[],
                                                    unsigned long long int resultado,
                                                    char mensajeNoExiteResultado[],
                                                    char mensajeError[])
{
    if(opcionAMostrar == 0)
    {
        printf("%s %llu\n", mensajeResultado, resultado);
    }
    else if(opcionAMostrar == 1)
    {
        printf("%s\n", mensajeNoExiteResultado);
    }
    else
    {
        printf("%s\n", mensajeError);
    }
}
