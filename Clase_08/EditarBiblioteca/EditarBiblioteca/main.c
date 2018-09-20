#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char Texto[20];
    if(utn_getCelularArgentino(Texto, 20, "\nnn", "\nnoooo", 6)==0)
        printf("\n%s", Texto);
}
