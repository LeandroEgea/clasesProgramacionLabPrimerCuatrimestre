#include <stdio.h>
#include <stdlib.h>

/*
   id, first_name, last_name, isEmpty
   1, Eric, knight, false
*/



int main()
{
   FILE*pArchivo = fopen("data.csv","r");
// FILE*pArchivoBkp = fopen("dataBkp.csv","w");
   char bufferId[1024];
   char bufferNombre[1024];
   char bufferApellido[1024];
   char bufferIsEmpty[1024];
   if (pArchivo != NULL)
   {
        fscanf(pArchivo, "%s\n", bufferId);
        while (!feof(pArchivo))
        {
        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido, bufferIsEmpty);
//        fprintf(pArchivoBkp, "%s\n", buffer);
        printf("\n%s-%s-%s-%s", bufferId, bufferNombre, bufferApellido, bufferIsEmpty);
        }
        fclose(pArchivo);

   }
   else
   {
        printf("\nERROR NO EXISTE!!!");
   }

   return 0;
}
