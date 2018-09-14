#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 3

typedef struct sEmpleado
{
    char nombre[50];
    char apellido[50];
    float salario;
}Empleado;

int sortEmpleadosPorNombre(Empleado *pEmpleado, int limite)
{
    int swap;
    int i;
    Empleado bufferEmpleado;
    do
    {
        swap = 0;
        for(i=0;i<limite;i++)
        {
            if(strcmp(pEmpleado[i].nombre, pEmpleado[i+1].nombre)>0)
            {
                swap = 1;
                bufferEmpleado = pEmpleado[i];
            }
        }

    }while...

}

int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    char apellidos[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    char dni[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};

    int i;

    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i], 50, "\nNombre?", "\nError", 3);
    }*/

    //

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s %s %s\n", nombres[i], apellidos[i], dni[i]);
    }

    return 0;
}
