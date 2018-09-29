#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#define INFARTO 1
#define ACV 2
#define GRIPE 3
#define PENDIENTE 1
#define CUMPLIDO 2

typedef struct
{
    char dni[20];
    char nombre[50];
    char apellido[50];
    int edad;
    //********************
    int idAsociado;
    int isEmpty;
    int isActive;
}Asociado;

int asociado_init(Asociado* array, int len);
Asociado* asociado_getById(Asociado* array, int len,int id);
int asociado_alta(Asociado* array, int len);
int asociado_modificar(Asociado* array, int len, int reintentos);
int asociado_baja(Asociado* array, int len, int reintentos);
int asociado_mostrar(Asociado* array, int len);


int asociado_ingresoForzado(Asociado* array, int len, char *dni, char *nombre, char *apellido, int edad);

#endif
