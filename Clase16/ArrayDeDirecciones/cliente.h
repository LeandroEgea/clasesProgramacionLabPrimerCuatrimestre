#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[51];
    char apellido[51];
    int idCliente;
}Cliente;

int cliente_init (Cliente** arrayClientes, int lenClientes);
Cliente* cliente_newCliente(void);
int cliente_setNombre(Cliente* cliente, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_buscarLugarVacio(Cliente** arrayClientes, int lenClientes);
int cliente_buscarPorId(Cliente** arrayClientes,int lenClientes, int id);
#endif
