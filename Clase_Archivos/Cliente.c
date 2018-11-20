#include "Cliente.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int persona_setNombre(Persona* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidNombre(nombre, lenNombre))
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
    if(this!=NULL && apellido!=NULL && isValidNombre(apellido, lenApellido))
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

int persona_setIdPersona(Persona* this,int idPersona)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idPersona=idPersona;
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

Persona* persona_new()
{
    Persona* this;
    this=malloc(sizeof(Persona));
    return this;
}

Persona* persona_newConParametros(  char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,int idPersona)
{
    Persona* this;
    this=persona_new();

    if(
    !persona_setNombre(this,nombre,lenNombre)&&
    !persona_setApellido(this,apellido,lenApellido)&&
    !persona_setIdPersona(this,idPersona))
        return this;

    persona_delete(this);
    return NULL;
}

int persona_init (Persona** arrayPersonas, int lenPersonas)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && lenPersonas > 0)
    {
        for(i=0;i<lenPersonas;i++)
        {
            *(arrayPersonas+i) = NULL;
        }
    }
    return retorno;
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
            if((arrayPersonas+i) != NULL && (*(arrayPersonas+i))->idPersona == id)//preguntar
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
