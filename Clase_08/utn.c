#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"




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

//sèparar






static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin);
}
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
}
/*
static int getString(char textoIngresado[])
{
    myFpurge();
    return scanf("%s", textoIngresado);
}*/
/**
* \brief El usuario ingresa una cadena con gets y se evalua si es alfabetica
* \param textoIngresado Recibe el texto ingresado en caso de exito
* \param tamanio es el tamanio de la cadena
* \param espacios si recibe un 0 no valida los espacios, pero si con un 1
* \return En caso de exito retorna 0, si no es un string solo de letras un 1
*
*/
int utn_getStringAlfabetico(char *textoIngresado, int tamanio, int espacios)
{
    int retorno = 1;
    int tamanioStringBuffer;
    char bufferString[1000];
    myFpurge();
    fgets(bufferString, 1000, stdin);
    tamanioStringBuffer = strlen(bufferString) - 1;
    if(tamanioStringBuffer<tamanio)
    {
        if( (espacios==0 && utn_validarStringAlfabetico(bufferString, tamanioStringBuffer) == 0) ||
            (espacios==1 && utn_validarStringAlfabeticoConEspacios(bufferString, tamanioStringBuffer) == 0))
        {
            utn_myStrncpy(textoIngresado, bufferString, tamanio);
            retorno = 0;
        }
    }
    return retorno;
}
void utn_myStrncpy (char *destino, char *origen, int tamanio)
{
    strncpy(destino, origen, tamanio);
    destino[tamanio - 1] = '\0';
}
/**
* \brief Toma una cadena y evalua si se trata de un numero entero
* \param stringEntero Es la cadena que vamos a evaluar si se trata de un entero
* \return En caso de exito retorna 0, si no es un entero 1
*
*/
int utn_validarIntString(char *stringEntero)
{
    int i;
    int retorno = 1;
    int tamanioStringEntero;
    tamanioStringEntero = strlen(stringEntero);
    if( stringEntero[0] == '-' ||
        stringEntero[0] == '+' ||
        (stringEntero[0]>='0' && stringEntero[0]<='9'))
    {
        retorno = 0;
        for(i=1; i<tamanioStringEntero; i++)
        {
            if(!(stringEntero[i]>='0' && stringEntero[i]<='9'))
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si se trata de un flotante
* \param stringFlotante Es la cadena que vamos a evaluar si se trata de un flotante
* \return En caso de exito retorna 0, si no es un flotante 1
*
*/
int utn_validarFloatString(char *stringFlotante)
{
    int i;
    int retorno = 1;
    int contadorDePuntos = 0;
    int tamanioStringFlotante;
    tamanioStringFlotante = strlen(stringFlotante);
    if((stringFlotante[0]== '+' ||
        stringFlotante[0]== '-') &&
        stringFlotante[1]== '.')
    {
        retorno = 1;
    }
    else if(stringFlotante[0] == '-' ||
            stringFlotante[0] == '+' ||
            (stringFlotante[0]>='0' && stringFlotante[0]<='9'))
    {
        retorno = 0;
        for(i=1; i<tamanioStringFlotante; i++)
        {
            if(stringFlotante[i]=='.' && contadorDePuntos == 0)
            {
                contadorDePuntos = 1;
            }
            else if(!(stringFlotante[i]>='0' && stringFlotante[i]<='9'))
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si se trata de un string solo de letras
* \param stringAlfabetico Es la cadena que vamos a evaluar si se trata de un string alfabetico
* \param tamanio es el tamanio de la cadena sin el (\ n) y el (\ 0)
* \return En caso de exito retorna 0, si no es un string solo de letras un 1
*
*/
int utn_validarStringAlfabetico(char *stringAlfabetico, int tamanio)
{
    int i;
    int retorno = 0;
    char stringAuxiliar[tamanio];
    strncpy(stringAuxiliar, stringAlfabetico, tamanio);
    for(i=0; i<tamanio; i++)
    {
        stringAuxiliar[i] = tolower(stringAuxiliar[i]);
        if(!(stringAuxiliar[i]>='a' && stringAuxiliar[i]<='z'))
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si se trata de un string de letras y espacios
* \param stringAlfabetico Es la cadena que vamos a evaluar
* \param tamanio es el tamanio de la cadena sin el (\ n) y el (\ 0)
* \return En caso de exito retorna 0, si no es un string de letras y espacios un 1
*
*/
int utn_validarStringAlfabeticoConEspacios(char *stringAlfabetico, int tamanio)
{
    int i;
    int retorno = 0;
    char stringAuxiliar[tamanio];
    strncpy(stringAuxiliar, stringAlfabetico, tamanio);
    for(i=0; i<tamanio; i++)
    {
        stringAuxiliar[i] = tolower(stringAuxiliar[i]);
        if(!((stringAuxiliar[i]>='a' && stringAuxiliar[i]<='z') || stringAuxiliar[i] ==' ')
            || (stringAuxiliar[i] == ' ' && stringAuxiliar[i-1] == ' '))
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
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
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un flotante
* \return En caso de exito retorna 0, si no es un flotante retorna 1
*
*/
int utn_getFlotante(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
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
            *pResultado = numeroIngresado;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", mensajeError);
            retorno = 1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
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
int utn_getFlotanteEnIntervalo(float *pResultado,
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
                    int longitudMinima,
                    int longitudMaxima,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    char cadenaIngresada[longitudMaxima*3];
    int longitudCadenaIngresada;
    do
    {
        printf("%s", mensaje);
        if(getString(cadenaIngresada, longitudMaxima) == 1)
        {
            longitudCadenaIngresada = utn_obtenerLongitudCadena(cadenaIngresada);
            retorno = utn_validarLongitudDeLaCadena(longitudCadenaIngresada, longitudMinima, longitudMaxima);
            if(retorno == 0)
            {
                retorno = utn_copiarCadenaEnOtraCadena(cadenaIngresada, pCadenaResultante);
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
* \param longitudCadenaIngresada Es la longitud que se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param longitudMinima Es la longitud de la cadena minima aceptada
* \param longitudMaxima Es la longitud de la cadena maxima aceptada
* \return En caso de exito retorna 0, si esta fuera del rango de longitud 1
*
*/
int utn_validarLongitudDeLaCadena(int longitudCadenaIngresada, int longitudMinima, int longitudMaxima)
{
    int retorno;
    if(longitudCadenaIngresada >= longitudMinima && longitudCadenaIngresada <= longitudMaxima)
    {
        retorno = 0;
    }
    else if(longitudCadenaIngresada < longitudMinima || longitudCadenaIngresada > longitudMaxima)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Copia el contenido de una cadena otra
* \param pCadenaInicial Es la cadena que se recibe
* \param pCadenaCopiada Es la cadena donde se va a copiar el contenido
* \return En caso de exito retorna 0, si se produce un error devuelve 1
*
*/
int utn_copiarCadenaEnOtraCadena(char *pCadenaInicial, char *pCadenaCopiada)
{
    while(*pCadenaInicial!='\0')
    {
        *pCadenaCopiada = *pCadenaInicial;
        pCadenaInicial++;
        pCadenaCopiada++;
    }
    *pCadenaCopiada = '\0';
    return 0;
}
/**
* \brief Obtiene la longitud de la cadena
* \param pCadenaIngresada Es la cadena que se recibe
* \return Retorna el valor de la longitud
*
*/
int utn_obtenerLongitudCadena(char *pCadenaIngresada)
{
    int longitudCadena = 0;
    while(*pCadenaIngresada!='\0')
    {
        longitudCadena++;
        pCadenaIngresada++;
    }
    return longitudCadena;
}
/**
* \brief Verifica si la cadena ingresada puede ser un mail valido o no
* \param pPosibleMail Es la cadena que vamos a evaluar
* \return Retorna un 0 si puede ser un mail y un 1 si no
*
*/
int utn_validarMail(char *pPosibleMail)
{
    int contadorPosicionesTrasCaracterImportante=0;
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    while(*pPosibleMail!='\0')
    {
        if(*pPosibleMail == '@')
        {
            if(contadorDeArrobas>0)
            {
                printf("El Mail puede contener un unico @\n");
                retorno = 1;
                break;
            }
            if(contadorPosicionesTrasCaracterImportante == 0)
            {
                printf("Debe ingresar algun caracter antes del @\n");
                retorno = 1;
                break;
            }
            contadorDeArrobas++;
            contadorPosicionesTrasCaracterImportante = -1;
        }
        else if(*pPosibleMail==' ')
        {
            printf("El Mail no puede contener espacios\n");
            retorno = 1;
            break;
        }
        else if(contadorDeArrobas==1 && *pPosibleMail == '.')
        {
            if(contadorPosicionesTrasCaracterImportante == 0)
            {
                printf("Debe ingresar algun caracter antes del '.'\n");
                retorno = 1;
                break;
            }
            contadorDePuntosTrasArroba++;
            contadorPosicionesTrasCaracterImportante = -1;
        }
        contadorPosicionesTrasCaracterImportante++;
        pPosibleMail++;
    }
    if(retorno == 0)
    {
        if(contadorDeArrobas == 1 && contadorDePuntosTrasArroba>0 && contadorPosicionesTrasCaracterImportante>0)
        {
            retorno = 0;
        }
        else
        {
            printf("El mail debe contener un @ y luego un .(dominio)");
            retorno = 1;
        }
    }
    return retorno;
}
/**
* \brief Verifica si la cadena ingresada es un telefono valido o no
* \param pPosibleTelefono Es la cadena que vamos a evaluar
* \return Retorna un 0 si puede ser un telefono y un 1 si no
*
*/
int utn_validarTelefono(char *pPosibleTelefono)
{
    int i;
    int retorno;
    int tamanioCadena;
    tamanioCadena = strlen(pPosibleTelefono);
    if( tamanioCadena == 9 &&
        pPosibleTelefono[0] == '4'&&
        pPosibleTelefono[4] == '-')
    {
        retorno = 0;
        for(i=1; i<=8; i++)
        {
            if(!(pPosibleTelefono[i] >= '0' && pPosibleTelefono[i] <= '9') && i!=4)
            {
                retorno = 1;
                printf("\n4XXX-XXXX\n");
                break;
            }
        }
    }
    else
    {
        printf("\n4XXX-XXXX\n");
        retorno = 1;
    }
    return retorno;
}
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
        if(utn_validarEnteroEnIntervalo(listado[i], minimo, maximo)==0)
        {
            cantidadEnteros++;
        }
    }
    return cantidadEnteros;
}

//separar



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
