#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"

#define CANTIDAD_EMPLEADOS 6

int main()
{
    int edades[CANTIDAD_EMPLEADOS] = {50, 10, 30, 50, 1, 22};
    //int i;
/*
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }
    */


    int cantidad;
    int numero;
    char bufferNumero[4097];
    scanf("%s", bufferNumero);
    if(validarIntString(bufferNumero) == 0)
    {
        numero = atoi(bufferNumero);
    }

    strncpy(nombre, bufferNumero, 3);
    printf("\n---> %s", nombre);



    //array_ordenar2(edades,CANTIDAD_EMPLEADOS,0);
    //array_mostrar(edades,CANTIDAD_EMPLEADOS);
    return 0;
}
