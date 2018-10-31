#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
//TP3
//NEXT ID, y ver examen y tp anterior a ver q falta
// empezar con add, modificar y borrar
// guardar modo texto
//FALTA DOCUMENTAR
//usar punteros a funciones



//TP 4
//hacer el swap bien, hacer solo 1 get de cada una
//contador de seguridad... el numero de swap consecutivos es el len cuadrado(peor caso posible).
//usar punteros a funciones
//usar el map, que recorre todo el ll y le pasas una funcion q haga algo con eso
//sublista, le pasas el ll y un criterio para q cree un criterio
//reduce
//ll_next         se llama iterator       te ahorras el for, por un while
//ll_setNext
//mirar como seria la doblemente enlazada
/*int flagSwap;
long contadorSeguridad = ll_len(this);

if(this!=NULL)*/





int main()
{
//controller_init
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("clear");
        printf( "1. Carga de empleados (modo texto)\n"
                "2. Carga de empleados (modo binario)\n"
                "3. Alta empleado\n"
                "4. Modificar empleado\n"
                "5. Baja empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados\n"
                "8. Guardar empleados (modo texto)\n"
                "9. Guardar empleados (modo binario)\n"
                "10. Salir\n");
        option = 0;
        utn_getEntero(&option, 5, "Seleccione...\n", "", 0);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("\nPulse Enter para continuar");
        __fpurge(stdin);
        getchar();
    }while(option != 10);
    return 0;
}
