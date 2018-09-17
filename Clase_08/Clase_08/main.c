#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_EMPLEADOS 3

/*typedef struct sEmpleado
{
    char nombre[50];
    char apellido[50];
    char DNI[20];
    //float salario;
}Empleado;*/

int main()
{
    Empleado trabajadores[CANTIDAD_EMPLEADOS];

    //ARRAYS PARALELOS
    //char nombres[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    //char apellidos[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};
    //char dni[CANTIDAD_EMPLEADOS][50] = {"AAA", "CCC", "BBB"};

    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(trabajadores[i].nombre, 50, "\nNombre?", "\nError", 3);
        utn_getNombre(trabajadores[i].apellido, 50, "\nApellido?", "\nError", 3);
        utn_getNombre(trabajadores[i].DNI, 20, "\nDNI?", "\nError", 3);
    }

    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i], 50, "\nNombre?", "\nError", 3);
    }*/

    if(utn_sortEmpleadosPorNombre(trabajadores,CANTIDAD_EMPLEADOS) == 0)
    {
        for(i=0;i < CANTIDAD_EMPLEADOS;i++)
        {
            printf("\n%s %s %s",    trabajadores[i].nombre,
                                    trabajadores[i].apellido,
                                    trabajadores[i].DNI);
        }
    }

        /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
        {
            printf("%s %s %s\n", nombres[i], apellidos[i], dni[i]);
        }*/

    return 0;
}
