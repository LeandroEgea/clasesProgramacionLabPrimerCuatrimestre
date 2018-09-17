#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char Texto[20];
    if(utn_getWeb(Texto, 20, "\nnn", "\nnoooo", 1)==0)
        printf("\n%s", Texto);
}
