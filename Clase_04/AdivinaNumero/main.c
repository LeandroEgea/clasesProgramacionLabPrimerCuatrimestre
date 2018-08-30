#include <stdio_ext.h>
#include <stdlib.h>

int getNumero(  int *pResultado,
                char mensaje[],
                char mensajeError[],
                int  minimo,
                int  maximo,
                int  reintentos);

int main()
{
    int numero;
    if (getNumero(&numero, "Ingrese numero\n", "Fuera de Rango\n", 1, 100, 3) == 0)
    {
        printf("El Numero es: %d\n", numero);
    }
    return 0;
}

int getNumero(  int *pResultado,
                char mensaje[],
                char mensajeError[],
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    int numeroIngresado;
    do
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        if(scanf("%d", &numeroIngresado) == 1)
        {
            if(numeroIngresado >= minimo && numeroIngresado <= maximo)
            {
                *pResultado = numeroIngresado;
                retorno = 0;
                break;
            }
            else if(numeroIngresado < minimo || numeroIngresado > maximo)
            {
                printf("%s", mensajeError);
                retorno = 1;
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
