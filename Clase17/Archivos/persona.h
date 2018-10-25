#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    int idPersona;
    char nombre[51];
    char apellido[51];
    int isEmpty;
}Persona;

int persona_setIdPersona(Persona* this,char* idPersona);
int persona_getIdPersona(Persona* this,int* idPersona);
int persona_setNombre(Persona* this,char* nombre,int lenNombre);
int persona_getNombre(Persona* this,char* nombre,int lenNombre);
int persona_setApellido(Persona* this,char* apellido,int lenApellido);
int persona_getApellido(Persona* this,char* apellido,int lenApellido);
int persona_setIsEmpty(Persona* this,char* isEmpty);
int persona_getIsEmpty(Persona* this,int* isEmpty);
Persona* persona_new();
int persona_delete(Persona* this);
Persona* persona_newConParametros(  char* idPersona,char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,char* isEmpty);
int persona_buscarLugarVacio(Persona** arrayPersonas, int lenPersonas);
int persona_buscarPorId(Persona** arrayPersonas,int lenPersonas, int id);
#endif
