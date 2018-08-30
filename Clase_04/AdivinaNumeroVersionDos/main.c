#include <stdio_ext.h>
#include <stdlib.h>

int getNumero(  int *pResultado,
                char mensaje[],
                char mensajeError[],
                int  minimo,
                int  maximo,
                int  reintentos);

int validarEntero(int numero, int minimo, int maximo);

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
            retorno = validarEntero(numeroIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pResultado = numeroIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
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

int validarEntero(int numeroIngresado, int minimo, int maximo)
{
    int retorno;
    if(numeroIngresado >= minimo && numeroIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(numeroIngresado < minimo || numeroIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}

