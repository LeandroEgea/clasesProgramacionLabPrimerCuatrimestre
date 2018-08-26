#include <stdio_ext.h>
#include <stdlib.h>

#define LIMITE_ARRAY 3
#define limpiar() __fpurge(stdin)
int main()
{
    int numeroMaximo;
    int numeroMinimo;
    int numero[LIMITE_ARRAY];
    int i;

    for(i=0;i<LIMITE_ARRAY;i++)
    {
        printf("\nNumero %d:", i+1);
        while(scanf("%d", &numero[i]) != 1)
        {
            printf("\nError - Numero %d:", i+1);
            limpiar();
        }
        if(i==0)
        {
            numeroMaximo = numero[i];
            numeroMinimo = numero[i];
        }
        else
        {
                if(numero[i] > numeroMaximo)
                {
                    numeroMaximo = numero[i];
                }
                else if (numero[i] < numeroMinimo)
                {
                    numeroMinimo = numero[i];
                }
        }
    }
    for(i=0;i<LIMITE_ARRAY;i++)
    {
        if(numero[i] < numeroMaximo && numero[i] > numeroMinimo)
        {
            printf("\nEl numero del medio es: %d", numero[i]);
            break;//rompe for, while, do while
        }
    }
    return 0;
}
