#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#include "utnmath.h"

#define CANTIDAD_EMPLEADOS 6

int main()
{
    float numeroUno;
    float numeroDos;
    int i;
    for(i=0;i<10;i++)
    {
        //sacar el static a getFloat y ponerla en el.h
        if(getFloat(&numeroUno)==0 && getFloat(&numeroDos)==0)
        {
            printf("\n----> %.3f\n", (numeroUno + numeroDos));
        }
        else
        {
            printf("\nerror\n");
        }
    }
    return 0;
}
