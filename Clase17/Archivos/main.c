#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
/*id,first_name,last_name,is_empty
1,Eric,Knight,false*/
void mostrar(Persona** arrayPunterosCliente,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%s\n",(*(arrayPunterosCliente+i))->apellido;//NOOOOOOOOOOOOOOOOOOOO
    }
}

int main()
{
    Persona* arrayPunterosPersona[1024];
    int i;
    FILE* pArchivo = fopen("./data.csv","r");
    FILE* pArchivoBkp = fopen("./dataBkp.csv","w");

    char buffer[4096];
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferIsEmpty[1024];

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%s\n",buffer);
        i = 0;
        while(!feof(pArchivo))
        {
            fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);
            fprintf(pArchivoBkp, "%s\n",buffer);
            i++;
        }
        fclose(pArchivo);
        fclose(pArchivoBkp);
    }
    else
    {
        printf("Error no existe!!!");
    }
    return 0;
}
