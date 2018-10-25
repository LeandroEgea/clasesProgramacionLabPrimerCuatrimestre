#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
* \brief Evalua si se trata de un entero sin signo
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidEnteroSoloNumeros(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if (pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
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
* \brief    Evalua si es un nombre, solo puede tener un espacio y cada nombre
*           debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        pBuffer[0]>='A' && pBuffer[0]<='Z')

    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int isValidTrueOrFalse(char* pBuffer, int limite)
{
    int retorno = 0;
    //char pBufferAux[1024];
    //strncpy(pBufferAux,pBuffer,1024);
    //char verdadero[5];
    char verdadero[5] = {'t','r','u','e','\0'};
    //char falso[6];
    char falso[6] = {'f','a','l','s','e','\0'};
    //strcpy(verdadero, "true\0");
    //strcpy(falso, "false\0");
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        (!strcmp(pBuffer, verdadero) || !strcmp(pBuffer, falso)))
        //(!strcmp(pBufferAux, verdadero) || !strcmp(pBufferAux, falso)))
        //(!strcmp(pBuffer, "true") || !strcmp(pBuffer, "false")))
    {
        retorno = 1;
    }
    printf("%s\n",pBuffer);
    printf("%d\n", retorno);
    return retorno;
}

int persona_setIdPersona(Persona* this,char* idPersona)
{
    int retorno=-1;
    int idPersonaInt;
    if(this!=NULL && isValidEnteroSoloNumeros(idPersona,20))
    {
        idPersonaInt = atoi(idPersona);
        this->idPersona=idPersonaInt;
        retorno=0;
    }
    return retorno;
}

int persona_getIdPersona(Persona* this,int* idPersona)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idPersona=this->idPersona;
        retorno=0;
    }
    return retorno;
}

int persona_setNombre(Persona* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidNombre(nombre,lenNombre))
    {
        strncpy(this->nombre,nombre,lenNombre);
        retorno=0;
    }
    return retorno;
}

int persona_getNombre(Persona* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(nombre,this->nombre,lenNombre);
        retorno=0;
    }
    return retorno;
}

int persona_setApellido(Persona* this,char* apellido,int lenApellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidNombre(apellido,lenApellido))
    {
        strncpy(this->apellido,apellido,lenApellido);
        retorno=0;
    }
    return retorno;
}

int persona_getApellido(Persona* this,char* apellido,int lenApellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strncpy(apellido,this->apellido,lenApellido);
        retorno=0;
    }
    return retorno;
}

int persona_setIsEmpty(Persona* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isValidTrueOrFalse(isEmpty, 20))
    {
        if(!strcmp(isEmpty,"true"))
        {
            this->isEmpty=1;
            retorno=0;
        }
        else if(!strcmp(isEmpty,"false"))
        {
            this->isEmpty=0;
            retorno=0;
        }
    }
    //retorno = 0;
    return retorno;
}

int persona_getIsEmpty(Persona* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *isEmpty=this->isEmpty;
        retorno=0;
    }
    return retorno;
}

Persona* persona_new()
{
    Persona* this = NULL;
    this = malloc(sizeof(Persona));
    return this;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}

Persona* persona_newConParametros(  char* idPersona,char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,char* isEmpty)
{
    Persona* this;
    this = persona_new();
    Persona* retorno = NULL;
    if( this!=NULL &&
        !persona_setIdPersona(this,idPersona)&&
        !persona_setNombre(this,nombre,lenNombre)&&
        !persona_setApellido(this,apellido,lenApellido)&&
        !persona_setIsEmpty(this,isEmpty))
    {
        retorno = this;
    }
    else
    {
        persona_delete(this);
    }
    return retorno;
}
int persona_buscarLugarVacio(Persona** arrayPersonas, int lenPersonas)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && lenPersonas > 0)
    {
        for(i=0;i<lenPersonas;i++)
        {
            if(*(arrayPersonas+i) == NULL)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_buscarPorId(Persona** arrayPersonas,int lenPersonas, int id)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && lenPersonas > 0)
    {
        for(i=0; i<lenPersonas; i++)
        {
            if((arrayPersonas+i) != NULL && (*(arrayPersonas+i))->idPersona == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
