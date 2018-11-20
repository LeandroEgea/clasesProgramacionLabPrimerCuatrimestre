#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[51];
    char apellido[51];
    int idPersona;
    int isEmpty;
}Persona;

int persona_setNombre(Persona* this,char* nombre,int lenNombre);
int persona_getNombre(Persona* this,char* nombrei,int lenNombre);

int persona_setApellido(Persona* this,char* apellido,int lenApellido);
int persona_getApellido(Persona* this,char* apellido,int lenApellido);

int persona_setIdPersona(Persona* this,int idPersona);
int persona_getIdPersona(Persona* this,int* idPersona);

Persona* persona_new();
Persona* persona_newConParametros(  char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,int idPersona);
int persona_init (Persona** arrayPersonas, int lenPersonas);
int persona_delete(Persona* this);
int persona_buscarLugarVacio(Persona** arrayPersonas, int lenPersonas);
int persona_buscarPorId(Persona** arrayPersonas,int lenPersonas, int id);

#endif // CLIENTE_H_INCLUDED
