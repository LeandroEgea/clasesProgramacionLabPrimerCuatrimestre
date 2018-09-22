#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char Sexo[20];
    if(utn_getOpcionEntreDos(Sexo, 20, "Masculino", "Femenino", "M", "F", 5)==0)
        printf("\n%s", Sexo);



    /*int array[6] = {5, 28 , -3, 0, 12 ,15};
    if(!utn_sortArrayEnterosPorInsercion(array, 6, 0))
    {
        utn_mostrarArrayEnteros(array, 6);
    }*/
}
