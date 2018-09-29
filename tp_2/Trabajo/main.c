#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define CANTIDAD_EMPLEADOS 1000

int main()
{
    Empleado empleados[CANTIDAD_EMPLEADOS];

    empleado_init(empleados, CANTIDAD_EMPLEADOS);


    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Daniel", "Perez", 43521.22, 4);
    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Martina", "Gomez", 10000, 22);
    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Rolando", "Mota", 123.2, 2);
    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Marcos", "Lopez", 500, 7);
    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "David", "Lopez", 6000.2, 4);
    empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Rafael", "Lopez", 123.2, 1);

    //empleado_alta(empleados, CANTIDAD_EMPLEADOS);
    //empleado_modificar(empleados, CANTIDAD_EMPLEADOS, 2);
    //falta modificar
    //empleado_baja(empleados, CANTIDAD_EMPLEADOS, 2);

    empleado_sortEmpleadosPorApellidoSector(empleados, CANTIDAD_EMPLEADOS);
    empleado_mostrar(empleados, CANTIDAD_EMPLEADOS);
}
