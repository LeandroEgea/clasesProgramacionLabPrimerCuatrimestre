#include <stdio_ext.h>
#include <stdlib.h>

int PedirEdad(void);
int ValidarEnteroEntreMinimoYMaximo(int valor, int minimo, int maximo);

int main(void)
{
    int edad;
    edad = PedirEdad();
    printf("La edad es: %d\n", edad);
}

int PedirEdad(void)
{
    int edad;
    int esValidaLaEdad;
    int contadorIntentos = 0;
    do
    {
        printf("Introduzca la edad\n");
        __fpurge(stdin);
        if (scanf("%d", &edad) == 1)
        {
            esValidaLaEdad = ValidarEnteroEntreMinimoYMaximo(edad,1, 100);
        }
        else
        {
            printf("Solo se admiten numeros\n");
        }
        contadorIntentos++;
    }while(esValidaLaEdad!=1 && contadorIntentos < 3);
    if(contadorIntentos==3)
    {
        edad = -1;
    }
    return edad;
}

int ValidarEnteroEntreMinimoYMaximo(int valor, int minimo, int maximo)
{
    if(valor >= minimo && valor <= maximo)
    {
        return 1;
    }
    else if(valor < minimo || valor > maximo)
    {
        printf("Fuera del rango(%d - %d)\n", minimo, maximo);
        return 0;
    }
    else
    {
        printf("Error\n");
        return -1;
    }
}
