#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[51];
    char apellido[51];
    int idCliente;
}Cliente;

int cliente_setNombre(Cliente* this,char* nombre,int lenNombre);
int cliente_getNombre(Cliente* this,char* nombrei,int lenNombre);

int cliente_setApellido(Cliente* this,char* apellido,int lenApellido);
int cliente_getApellido(Cliente* this,char* apellido,int lenApellido);

int cliente_setIdCliente(Cliente* this,int idCliente);
int cliente_getIdCliente(Cliente* this,int* idCliente);

Cliente* cliente_new();
Cliente* cliente_newConParametros(  char* nombre,int lenNombre,
                                    char* apellido,int lenApellido,int idCliente);
int cliente_init (Cliente** arrayClientes, int lenClientes);
int cliente_delete(Cliente* this);
int cliente_buscarLugarVacio(Cliente** arrayClientes, int lenClientes);
int cliente_buscarPorId(Cliente** arrayClientes,int lenClientes, int id);

#endif // CLIENTE_H_INCLUDED
