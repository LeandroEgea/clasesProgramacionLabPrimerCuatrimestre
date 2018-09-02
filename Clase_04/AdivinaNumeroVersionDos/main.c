#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char cadena[55];
    if (utn_getCadena(cadena, "Ingrese frase\n", "Fuera del Rango de Longitud\n", 2, 50, 5) == 0)
    {
        if(utn_validarMail(cadena)== 0)
        {
        printf("El mail es %s\n", cadena);
        }
    }
    return 0;
}
/*
int main()
{
    char caracter;
    if (utn_getCaracter(&caracter, "Ingrese caracter\n", "Fuera de Rango\n", 'a', 'z', 3) == 0)
    {
        printf("El Caracter es: %c\n", caracter);
    }
    return 0;
}

int main()
{
    float flotante;
    if (utn_getFlotante(&flotante, "Ingrese numero\n", "Fuera de Rango\n", 0, 100, 3) == 0)
    {
        printf("El Numero es: %.2f\n", flotante);
    }
    return 0;
}

*/
