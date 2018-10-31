#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    pArchivo = fopen(path,"rb");
    if(!parser_EmployeeFromBinary(pArchivo,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 //funcion privada del controller para el editar y añadir(parte comun) usando utn.h
 //separar los get de los valid en el utn.h
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 //intentar hacerlo un poco mas copado
 //le mostras lo q tiene cada campo y si lo quiere cambiar
 //le muestra el nuevo y el viejo, y que confirme si desea cambiar
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 //ll_remove hace la baja fisica, pero  no es obligatorio usarla???
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    Employee* auxPunteroEmpleado;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(auxPunteroEmpleado,nombre);
            printf("\nNombre: %s", nombre);
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
  //pasar lo importante al parser
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 //pasar lo importante al parser
 //hacer bien lo del retorno
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo = fopen(path, "wb");
    Employee* pEmpleado;
    int i;
    //char nombre[128];

    if(pArchivo != NULL)//comprobar siempre por el modo administrador
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            //employee_getNombre(pEmpleado,nombre);
            //printf("\n%s",nombre);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    fclose(pArchivo);
    return 1;
}

