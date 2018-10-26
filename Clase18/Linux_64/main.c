#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
//View.c View.h
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 1;//0
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                printf("size de la lista %d", ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\nSize de la lista %d", ll_len(listaEmpleados));
                option = 6;//NOOOOO
                break;
            case 6:
                //ll_sort(listaEmpleados,Employee_criterioSortNombre,0);//NOOOO
                controller_ListEmployee(listaEmpleados);
                option = 10;//NNOOOO
                break;



        }
    }while(option != 10);
    return 0;
}
