#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

typedef struct sEmpleado
{
    char nombre[50];
    char apellido[50];
    char DNI[20];
    //float salario;
}Empleado;

int utn_getStringAlfabetico(char *textoIngresado, int tamanio, int espacios);

void utn_myStrncpy (char *destino, char *origen, int tamanio);

int utn_validarIntString(char *stringEntero);

int utn_validarFloatString(char *stringFlotante);

int utn_validarStringAlfabetico(char *stringAlfabetico, int tamanio);

int utn_validarStringAlfabeticoConEspacios(char *stringAlfabetico, int tamanio);

int utn_getEntero(  int *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int  minimo,
                    int  maximo,
                    int  reintentos);

int utn_validarEnteroEnIntervalo(int numero, int minimo, int maximo);

int utn_getFlotante(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int reintentos);

int utn_getFlotanteEnIntervalo(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    float minimo,
                    float maximo,
                    int reintentos);

int utn_validarFlotanteEnIntervalo(float numeroIngresado, float minimo, float maximo);

int utn_getCaracter(char *pCaracterResultante,
                    char mensaje[],
                    char mensajeError[],
                    char minimo,
                    char maximo,
                    int reintentos);

int utn_validarCaracterEnIntervalo(char caracterIngresado, char minimo, char maximo);

int utn_getCadena(  char *pCadenaResultante,
                    char mensaje[],
                    char mensajeError[],
                    int longitudMinima,
                    int longitudMaxima,
                    int reintentos);

int utn_validarLongitudDeLaCadena(int longitudCadenaIngresada, int longitudMinima, int longitudMaxima);

int utn_copiarCadenaEnOtraCadena(char *pCadenaInicial, char *pCadenaCopiada);

int utn_obtenerLongitudCadena(char *cadenaIngresada);

int utn_validarMail(char *pPosibleMail);

int utn_validarTelefono(char *pPosibleTelefono);

void utn_imprimirResultadoFloatOErrorEnPantalla(int opcionAMostrar,
                                                char mensajeResultado[],
                                                float resultado,
                                                char mensajeNoExiteResultado[],
                                                char mensajeError[]);

void utn_imprimirResultadoLongLongOErrorEnPantalla( int opcionAMostrar,
                                                    char mensajeResultado[],
                                                    unsigned long long int resultado,
                                                    char mensajeNoExiteResultado[],
                                                    char mensajeError[]);

int utn_retornarMayor(int listado[], int tamanio);

int utn_retornarMenor(int listado[], int tamanio);

int utn_retornarCantidadDePares(int listado[], int tamanio);

int utn_retornarTotal(int listado[], int tamanio);

float utn_retornarPromedio(int listado[], int tamanio);

int utn_cantidadEnterosEnIntervalo(int listado[], int tamanio, int minimo, int maximo);

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char msgErr[], int reintentos);


void utn_swapEmpleado(Empleado *pEmpleadoUno, Empleado *pEmpleadoDos);

int utn_sortEmpleadosPorNombre(Empleado *pEmpleado, int cantidadEmpleados);

#endif // UTN_H_INCLUDED
