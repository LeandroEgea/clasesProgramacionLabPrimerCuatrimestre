#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/**
* \brief Evalua si se trata de un id valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidId(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
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
    int retorno;
    retorno = utn_isValidNombre(pBuffer,limite);
    return retorno;
}
/**
* \brief Evalua si se trata de una cantidad de horas trabajada valida
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidHorasTrabajadas(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
* \brief Evalua si se trata de un sueldo valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidSueldo(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}




int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && lenNombre > 0)
    {
        strncpy(this->nombre,nombre,lenNombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}


Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString)
{
    Employee* this;
    this = Employee_new();
    Employee* retorno = NULL;
    int idInt = atoi(idString);
    int horasTrabajadasInt = atoi(horasTrabajadasString);
    int sueldoInt = atoi(sueldoString);
    //le paso los len que sea

    if( isValidId(idString,51) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,51) &&
        isValidSueldo(sueldoString,51) &&
        !Employee_setId(this,idInt)&&
        !Employee_setNombre(this,nombre,lenNombre)&&
        !Employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
        !Employee_setSueldo(this,sueldoInt))
            retorno = this;
    else
    {
        Employee_delete(this);
    }
    return retorno;
}

//poner en minuscula los employee
//funcion comparar de la misma entidad devuelve 0 -1 ó 1
//ordenar por todos los campos individuales
int Employee_criterioSortNombre(void* thisA, void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int retorno = 0;
    Employee_getNombre(thisA,nombreA);
    Employee_getNombre(thisA,nombreB);
    if(strcmp(thisA,thisB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(thisA,thisB) > 0)
    {
        retorno = -1;
    }
    return retorno;
}
