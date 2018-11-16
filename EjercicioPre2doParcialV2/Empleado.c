#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
/**
 * \brief Evalua si se trata de un id valido
 *
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
 * \brief    Evalua si es un nombre valido
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el tamano maximo del string
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidNombre(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidNombre(pBuffer,limite);
    if(retorno != 1)
    {
        printf("\nEl nombre debe comenzar por mayuscula y el resto minusculas");
    }
    return retorno;
}
/**
 * \brief Evalua si se trata de una cantidad de horas trabajada valida
 *
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
 *
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
/**
 * \brief Incrementa el nuevo Id del empleado en 1, empezando desde 0 con el metodo static.
 *
 * \return Int Devuelve el nuevo Id.
 */
int empleado_getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
/**
 * \brief Toma el indice de un empleado por el Id.
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde se buscan los empleados.
 * \param index int* Se retorna por parametros el index donde se encuentra el empleado.
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getById(LinkedList* pArrayListEmpleado, int* index)
{
    int retorno = -1;
    int id;
    if(pArrayListEmpleado != NULL)
    {
        empleado_list(pArrayListEmpleado);
        if( !utn_getEntero(&id, 10, "\nIntroduzca el Id: ", "", 0) &&
            !empleado_getIndexById(pArrayListEmpleado, id, index))
        {
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Toma el indice de un empleado por el Id recorriendo todo el LinkedList
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde se buscan los empleados.
 * \param index int* Se retorna por parametros el index donde se encuentra el empleado.
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getIndexById(LinkedList* pArrayListEmpleado,int id, int* index)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int bufferId;
    int i;
    if(pArrayListEmpleado != NULL)
    {
        for(i=0;i < ll_len(pArrayListEmpleado);i++)
        {
            pEmpleado = ll_get(pArrayListEmpleado,i);
            empleado_getId(pEmpleado,&bufferId);
            if(bufferId == id)
            {
                *index = ll_indexOf(pArrayListEmpleado, pEmpleado);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Setter del Id
 *
 * \param this Empleado* Es el empleado donde se guarda el id
 * \param id int Es el id que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter del Id
 *
 * \param this Empleado* Es el empleado que contiene el id
 * \param id int* Se retorna por parametros el dato del id
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter del Nombre
 *
 * \param this Empleado* Es el empleado donde se guarda el nombre
 * \param nombre char* Es el nombre que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter del Nombre
 *
 * \param this Empleado* Es el empleado que contiene el nombre
 * \param nombre char* Se retorna por parametros el dato del nombre
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter de las horas
 *
 * \param this Empleado* Es el empleado donde se guardan las horas trabajadas
 * \param horasTrabajadas int Es la cantidad de horas que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Getter de las horasTrabajadas
 *
 * \param this Empleado* Es el empleado que contiene las horasTrabajadas
 * \param id int* Se retorna por parametros el dato de las horasTrabajadas
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Setter del Sueldo
 *
 * \param this Empleado* Es el empleado donde se guarda el sueldo
 * \param sueldo int Es el sueldo que se guarda en el empleado
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Getter del Sueldo
 *
 * \param this Empleado* Es el empleado que contiene el sueldo
 * \param sueldo int* Se retorna por parametros el dato del sueldo
 * \return En caso de exito retorna 1, si no 0
 *
 */
int empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Setter de todos las propiedades del empleado
 *
 * \param this Empleado* Es el empleado donde se guardan estos datos
 * \param id int Es el id que se guarda en el empleado
 * \param nombre char* Es el nombre que se guarda en el empleado
 * \param horasTrabajadas int Son las horas trabajadas a guardar en el empleado
 * \param sueldo int Es el sueldo que se guarda en el empleado
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_setAll(Empleado* this, int id,char* nombre, int horasTrabajadas, int sueldo)
{
    int retorno = -1;
    if( !empleado_setId(this, id) &&
        !empleado_setNombre(this, nombre) &&
        !empleado_setHorasTrabajadas(this, horasTrabajadas)&&
        !empleado_setSueldo(this, sueldo))
    {
        retorno = 0;
    }
    return retorno;

}
/**
 * \brief Muestra toda la informacion de un solo empleado
 *
 * \param this Empleado* Es el empleado que contiene la informacion
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_showInfo(Empleado* this)
{
    int retorno = -1;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(this!=NULL)
    {
        empleado_getId(this, &bufferId);
        empleado_getNombre(this, bufferNombre);
        empleado_getHorasTrabajadas(this, &bufferHorasTrabajadas);
        empleado_getSueldo(this, &bufferSueldo);
        printf( "\nId: %d - Nombre: %s - Horas: %d - Sueldo: %d",
                bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Asigna el espacio de memoria para la creacion de un empleado
 * \return Empleado* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Empleado* empleado_new()
{
    Empleado* this;
    this = malloc(sizeof(Empleado));
    return this;
}
/**
 * \brief Libera el espacio de memoria donde se encontraba el empleado utilizando free()
 *
 * \param this Empleado* Es el empleado que se desea eliminar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_delete(Empleado* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Asigna el espacio de memoria para la creacion de un empleado con todos sus atributos cargados
 * \return Empleado* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Empleado* empleado_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString)
{
    Empleado* this;
    this = empleado_new();
    Empleado* retorno = NULL;
    int idInt = atoi(idString);
    int horasTrabajadasInt = atoi(horasTrabajadasString);
    int sueldoInt = atoi(sueldoString);
    if( isValidId(idString,20) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,20) &&
        isValidSueldo(sueldoString,20) &&
        !empleado_setAll(this, idInt, nombre, horasTrabajadasInt, sueldoInt))
    {
        retorno = this;
    }
    else
    {
        empleado_delete(this);
    }
    return retorno;
}
Empleado* empleado_newConParametrosSinSueldo(   char* idString,char* nombre,int lenNombre,
                                                char* horasTrabajadasString)
{
    Empleado* this;
    this = empleado_new();
    Empleado* retorno = NULL;
    int idInt = atoi(idString);
    int horasTrabajadasInt = atoi(horasTrabajadasString);
    if( isValidId(idString,20) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,20) &&
        !empleado_setAll(this, idInt, nombre, horasTrabajadasInt, -1))
    {
        retorno = this;
    }
    else
    {
        empleado_delete(this);
    }
    return retorno;
}
/**
 * \brief Aniade un empleado al final de la LinkedList
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_add(LinkedList* pArrayListEmpleado)
{
    int retorno = -1;
    Empleado* pEmpleado;
    char bufferIdString[20];
    int bufferIdInt;
    char bufferNombre[128];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    if( pArrayListEmpleado != NULL &&
        !utn_getTexto(  bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0) &&
        !utn_getTexto(  bufferHorasTrabajadas,20,"\nIntroduzca horas trabajadas del empleado: ", "",0) &&
        !utn_getTexto(  bufferSueldo,20,"\nIntroduzca sueldo del empleado: ","",0))
    {
        bufferIdInt = empleado_getNextId();
        snprintf(bufferIdString, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleado = empleado_newConParametros(  bufferIdString,bufferNombre, 128,
                                                bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleado != NULL)
        {
            ll_add(pArrayListEmpleado, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Edita un empleado seleccionado de la LinkedList a traves de un id
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_edit(LinkedList* pArrayListEmpleado)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int indexEmpleado;
    if( pArrayListEmpleado != NULL &&
        !empleado_getById(pArrayListEmpleado,&indexEmpleado))
    {
        pEmpleado = ll_get(pArrayListEmpleado, indexEmpleado);
        if( !empleado_confirmEditOrRemove(pEmpleado))
        {
            retorno = empleado_menuEdicion(pEmpleado);
        }
    }
    return retorno;
}
/**
 * \brief Se selecciona que atributos se desean editar del empleado
 *
 * \param this Empleado* Es el empleado que se desea editar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_menuEdicion(Empleado* this)
{
    int retorno = -1;
    Empleado* pEmpleadoAux;
    char previousNombre[128];
    int previousHorasTrabajadas;
    int previousSueldo;
    char bufferNombre[128];
    char bufferId[20];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    int bufferIdInt;
    int bufferHorasTrabajadasInt;
    int bufferSueldoInt;
    if(this != NULL)
    {
        empleado_getNombre(this, previousNombre);
        printf("\nEditar Nombre: %s", previousNombre);
        if(!utn_confirm())
        {
            utn_getTexto(bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0);
        }
        else
        {
            empleado_getNombre(this, bufferNombre);
        }

        empleado_getHorasTrabajadas(this, &previousHorasTrabajadas);
        printf("\nEditar Horas: %d", previousHorasTrabajadas);
        if(!utn_confirm())
        {
            utn_getTexto(bufferHorasTrabajadas,128,"\nIntroduzca horas del empleado: ","",0);
        }
        else
        {
            empleado_getHorasTrabajadas(this, &bufferHorasTrabajadasInt);
            snprintf(bufferHorasTrabajadas, 20*sizeof(char), "%d", bufferHorasTrabajadasInt);
        }

        empleado_getSueldo(this, &previousSueldo);
        printf("\nEditar Sueldo: %d",previousSueldo);
        if(!utn_confirm())
        {
            utn_getTexto(bufferSueldo,128,"\nIntroduzca sueldo del empleado: ","",0);
        }
        else
        {
            empleado_getSueldo(this, &bufferSueldoInt);
            snprintf(bufferSueldo, 20*sizeof(char), "%d", bufferSueldoInt);
        }
        empleado_getId(this, &bufferIdInt);
        snprintf(bufferId, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleadoAux = empleado_newConParametros(   bufferId, bufferNombre, 128,
                                                    bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleadoAux != NULL)
        {
            printf("\nEmpleado sin editar");
            empleado_showInfo(this);
            printf("\nEmpleado editado");
            empleado_showInfo(pEmpleadoAux);
            if(!utn_confirm())
            {
                empleado_setAll(this, bufferIdInt, bufferNombre,
                                atoi(bufferHorasTrabajadas), atoi(bufferSueldo));
                retorno = 0;
            }
        }
    }
    return retorno;
}
/**
 * \brief Elimina un empleado seleccionado de la LinkedList a traves de un id
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde estan los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_remove(LinkedList* pArrayListEmpleado)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int indexRemove;
    if( pArrayListEmpleado != NULL &&
        !empleado_getById(pArrayListEmpleado,&indexRemove))
    {
        pEmpleado = ll_get(pArrayListEmpleado, indexRemove);
        if( !empleado_confirmEditOrRemove(pEmpleado))
        {
            free(ll_pop(pArrayListEmpleado, indexRemove));
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Muestra el empleado seleccionado y confirma si se desea editar o eliminar
 *
 * \param this Empleado* Es el empleado que se desea editar o eliminar
* \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_confirmEditOrRemove(Empleado* this)
{
    int retorno = -1;
    system("clear");
    printf("\nHa seleccionado el siguiente empleado");
    empleado_showInfo(this);
    if( !utn_confirm())
    {
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Muestra toda la informacion de los empleados
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_list(LinkedList* pArrayListEmpleado)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int i;
    int numeroEmpleados = 0;
    if(pArrayListEmpleado != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmpleado);i++)
        {
            pEmpleado = ll_get(pArrayListEmpleado,i);
            empleado_showInfo(pEmpleado);
            numeroEmpleados++;
        }
        printf("\nHay %d empleados\n",numeroEmpleados);
    }
    return retorno;
}
/**
 * \brief Ordena todos los empleados por el criterio seleccionado a traves de un menu
 *
 * \param pArrayListEmpleado LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
int empleado_sort(LinkedList* pArrayListEmpleado)
{
    int retorno = -1;
    int option = 0;
    if(pArrayListEmpleado != NULL)
    {
        printf( "\n1. Id(Menor a Mayor)"
                "\n2. Id(Mayor a Menor)"
                "\n3. Nombre(A-Z)"
                "\n4. Nombre(Z-A)"
                "\n5. Horas(Menor a Mayor)"
                "\n6. Horas(Mayor a Menor)"
                "\n7. Sueldo(Menor a Mayor)"
                "\n8. Sueldo(Mayor a Menor)"
                "\n9. Cancelar");
        utn_getEntero(&option, 5, "Seleccione...\n", "", 0);
        if(option > 0 && option < 9)
        {
            printf("Esto puede llevar unos minutos...\n");
        }
        switch(option)
        {
            case 1:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortId,1))
                {
                    retorno = 0;
                }
                break;
            case 2:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortId,0))
                {
                    retorno = 0;
                }
                break;
            case 3:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortNombre,1))
                {
                    retorno = 0;
                }
                break;
            case 4:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortNombre,0))
                {
                    retorno = 0;
                }
                break;
            case 5:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortHorasTrabajadas,1))
                {
                    retorno = 0;
                }
                break;
            case 6:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortHorasTrabajadas,0))
                {
                    retorno = 0;
                }
                break;
            case 7:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortSueldo,1))
                {
                    retorno = 0;
                }
                break;
            case 8:
                if(!ll_sort(pArrayListEmpleado,empleado_criterioSortSueldo,0))
                {
                    retorno = 0;
                }
                break;
            default:
                break;
        }
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus id
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int empleado_criterioSortId(void* thisA, void* thisB)
{
    int idA;
    int idB;
    int retorno = 0;
    empleado_getId(thisA,&idA);
    empleado_getId(thisB,&idB);
    if(idA > idB)
    {
        retorno = 1;
    }
    else if(idB > idA)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus nombres
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int empleado_criterioSortNombre(void* thisA, void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int retorno = 0;
    empleado_getNombre(thisA,nombreA);
    empleado_getNombre(thisB,nombreB);
    if(strcmp(nombreA,nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus horas
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int empleado_criterioSortHorasTrabajadas(void* thisA, void* thisB)
{
    int horasTrabajadasA;
    int horasTrabajadasB;
    int retorno = 0;
    empleado_getHorasTrabajadas(thisA,&horasTrabajadasA);
    empleado_getHorasTrabajadas(thisB,&horasTrabajadasB);
    if(horasTrabajadasA > horasTrabajadasB)
    {
        retorno = 1;
    }
    else if(horasTrabajadasB > horasTrabajadasA)
    {
        retorno = -1;
    }
    return retorno;
}
/**
 * \brief Toma dos empleados y compara sus sueldos
 *
 * \return Int En caso de que thisA sea mayor retorna 1, si thisB es mayor -1 y si son iguales 0
 *
 */
int empleado_criterioSortSueldo(void* thisA, void* thisB)
{
    int sueldoA;
    int sueldoB;
    int retorno = 0;
    empleado_getSueldo(thisA,&sueldoA);
    empleado_getSueldo(thisB,&sueldoB);
    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoB > sueldoA)
    {
        retorno = -1;
    }
    return retorno;
}
//me quede aca
int em_calcularSueldo(void* pElement)
{
    int returnAux = -1;
    Empleado* empleado = pElement;
    int horas = empleado->horasTrabajadas;
    int sueldo = 0;
    if(pElement != NULL)
    {
        returnAux = 1;
        if(horas >= 80 && horas <= 240)
        {
            returnAux = 0;
            if(horas<=120)
            {
                sueldo
            }
        }
        empleado->sueldo = sueldo;
    }
    return returnAux;
}    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350
