#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char caracter;
    if (utn_getCaracter(&numero, "Ingrese caracter\n", "Fuera de Rango\n", 'a', 'z', 3) == 0)
    {
        printf("El Caracter es: %d\n", caracter);
    }
    return 0;
}
