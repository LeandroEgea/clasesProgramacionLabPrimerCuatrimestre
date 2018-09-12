#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD 10

int main()
{
    char nombre[CANTIDAD];
    if(utn_getStringAlfabetico(nombre, CANTIDAD) == 0)
    {
        printf("nombre: %s\n", nombre);
    }
    else
    {
        printf("error");
    }






 /*   char usuario[CANTIDAD];
    char clave[CANTIDAD];
    char auxUsuario[]="admin\n";
    char auxClave[]="admin\n";
    int tamanio;

    printf("Usuario:\n");
    fgets(usuario, CANTIDAD, stdin);
    __fpurge(stdin);
    printf("Clave\n");
    fgets(clave, CANTIDAD, stdin);
    __fpurge(stdin);

    tamanio = strlen(usuario);
    printf("Tamanio usuario: %d\n", tamanio);
    printf("usuario: %s\n", usuario);

    if(strcmp(usuario,auxUsuario)==0 && strcmp(clave,auxClave)==0)
    {
        printf("Ingreso!!!");
    }
    else
    {
        printf("Nope!");
    }
    return 0;
    */
/*
    char nombre[CANTIDAD];
    char apellido[CANTIDAD];
    char localidad[CANTIDAD];
    int tamanio;

    tamanio = sizeof(nombre);
    printf("El tamanio es: %d\n", tamanio);

    fgets(nombre, CANTIDAD, stdin);
    __fpurge(stdin);
    fgets(apellido, CANTIDAD, stdin);
    __fpurge(stdin);
    fgets(localidad, CANTIDAD, stdin);
    __fpurge(stdin);
    printf("nombre: %s apellido: %s localidad:%s\n",nombre, apellido, localidad);
    return 0;*/
}
