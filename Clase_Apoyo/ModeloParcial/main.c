#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "asociado.h"
#include "llamada.h"
#define CANTIDAD_ASOCIADOS 10
#define CANTIDAD_LLAMADAS 10

int main()
{
    Asociado asociados[CANTIDAD_ASOCIADOS];
    Llamada llamadas[CANTIDAD_LLAMADAS];
    asociado_init(asociados, CANTIDAD_ASOCIADOS);


    asociado_ingresoForzado(asociados, CANTIDAD_ASOCIADOS, "99.333.333", "Daniela", "Perez", 39);
    asociado_ingresoForzado(asociados, CANTIDAD_ASOCIADOS, "96.223.555", "Daniel", "Ramirez", 28);
    asociado_ingresoForzado(asociados, CANTIDAD_ASOCIADOS, "99.333.333", "Aldo", "Perez", 56);
    asociado_ingresoForzado(asociados, CANTIDAD_ASOCIADOS, "99.333.333", "Mauricio", "Davila", 77);
    asociado_alta(asociados, CANTIDAD_ASOCIADOS);
    asociado_modificar(asociados, CANTIDAD_ASOCIADOS, 2);
    //asociado_baja(asociados, CANTIDAD_ASOCIADOS);

    asociado_mostrar(asociados, CANTIDAD_ASOCIADOS);
}
