#include "LinkedList.h"
#include "string.h"
#include "Empleado.h"
#include <stdio.h>
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    char bufferLine[1024];
    char* delimitador = ",";
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    int retorno = -1;
    int flagOnce = 1;
    int i;
    Empleado* pEmpleado;
    char *token;
    FILE* pFile;
    pFile = fopen("data.csv","w");

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                fscanf(pFile,"%[^\n]\n",bufferLine);
                flagOnce = 0;
            }
            fscanf(pFile,"%[^\n]\n",bufferLine);
            token = strtok(bufferLine, ",");
            //settear e
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                    bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);

            pEmpleado = employee_newConParametros(  bufferId,
                                                    bufferNombre,
                                                    128,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);
            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEmployee, pEmpleado);
                lastId = atoi(bufferId);
            }
        }
        for(i=0;i<=lastId;i++)
        {
            employee_getNextId();
        }
    }
    return retorno;
}

