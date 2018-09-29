#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int idAsociado;
    char motivo[20];
    char estado[20];
    int tiempo;
    int idAmbulancia;
    //********************
    int idLlamada;
    int isEmpty;
}Llamada;

int llamada_init(Llamada* array, int len);
Llamada* llamada_getById(Llamada* array, int len,int id);
int llamada_alta(Llamada* array, int len);


#endif
