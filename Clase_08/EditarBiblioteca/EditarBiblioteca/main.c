#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char Texto[250];
    //hacer una generica de archivos
    //terminar el archivoportipo comparando la extension con el resto de la cadena strcmp[i]
    //y ponerle el \0 a la extension en la funcion
    if(utn_getArchivoPorTipo(Texto, 250, "exe", "\nnn", "\nnoooo", 6)==0)
        printf("\n%s", Texto);
}
