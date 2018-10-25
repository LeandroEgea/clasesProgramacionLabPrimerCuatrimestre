#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"
/*id,first_name,last_name,is_empty
1,Eric,Knight,false*/
void mostrar(Persona** arrayPunterosCliente,int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%s\n",(*(arrayPunterosCliente+i))->apellido);
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
            //printf("%s\n",bufferIsEmpty);
            arrayPunterosPersona[i] = persona_newConParametros( bufferId,bufferNombre,51,
                                                                bufferApellido,51,bufferIsEmpty);
            //printf("%s\n",arrayPunterosPersona[i]->apellido);
            //printf("%s\n",arrayPunterosPersona[i]->isEmpty);
            if(arrayPunterosPersona[i]!=NULL)
            {
                fprintf(pArchivoBkp, "%s,%s,%s,%s\n",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);
            }
            i++;
        }
        fclose(pArchivo);
        fclose(pArchivoBkp);
    }
    else
    {
        printf("Error no existe!!!");
    }
    //mostrar(arrayPunterosPersona,i);
    return 0;
}
