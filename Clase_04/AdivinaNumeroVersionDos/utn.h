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

