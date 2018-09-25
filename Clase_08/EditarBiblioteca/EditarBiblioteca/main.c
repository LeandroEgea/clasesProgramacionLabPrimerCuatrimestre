#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char dni[20];
    if(utn_getDni(dni, 20, "\nnnn", "\nnooooo", 7)==0)
        printf("\n%s", dni);

    /*int array[6] = {5, 28 , -3, 0, 12 ,15};
    if(!utn_sortArrayEnterosPorBurbujeo(array, 6, 1))
    {
        utn_mostrarArrayEnteros(array, 6);
    }*/
}
