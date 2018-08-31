#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numero;
    if (utn_getEntero(&numero, "Ingrese numero\n", "Fuera de Rango\n", 1, 100, 3) == 0)
    {
        printf("El Numero es: %d\n", numero);
    }
    return 0;
}
