#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "contrataciones.h"

static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice);
int con_inicializarArray(Contratacion* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int con_borrarPorID(Contratacion* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].ID==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int con_contratarPublicidad(Contratacion* pBuffer,int id,int limite){
    int indice;
    if(con_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].ID=con_obtenerID();
        pBuffer[indice].isEmpty=0;
        pBuffer[indice].idPantalla=id;
        utn_getLetrasYNumeros(pBuffer[indice].video,15,"\nIngrese el nombre del video: ");
        utn_getLetrasYNumeros(pBuffer[indice].cuit,10,"\nIngrese el CUIT: ");
        utn_getEntero(&pBuffer[indice].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
    }
    return 0;
}
int con_obtenerID(){
    static int ID=0;
    return ID++;
}
static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int con_imprimirPorCuit(Contratacion* pBuffer,int limite,char* cuit){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0&&cuit!=NULL){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&&strcmp(pBuffer[i].cuit,cuit)==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].ID);
                printf("\tID Pantalla: %d",pBuffer[i].idPantalla);
                printf("\tDias: %d",pBuffer[i].dias);
                printf("\tVideo: %s",pBuffer[i].video);
            }
        }
    }
    return retorno;
}
int con_modificarPorIdPantalla(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                retorno=0;
                utn_getEntero(&pBuffer[i].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
            }
        }
    }
    return retorno;
}
int con_cancelarById(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
        if(pBuffer!=NULL&&limite>0){
            for(i=0;i<limite;i++){
                if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                    retorno=0;
                    pBuffer[i].isEmpty=1;
                }
            }
        }
    return retorno;
}

int con_listarImportePorContratacion(Contratacion* pBufferCon,Pantalla* pBufferPan,int limiteCon,char* cuit,int limitePan){
    int retorno=-1;

    return retorno;
}

int con_imprimirContrataciones(Contratacion* array,int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nID: %d\nvideo: %s\ncuit: %s\ndias: %d\n\n",
                array[i].ID, array[i].video, array[i].cuit, array[i].dias);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int con_ordenarByCuit(Contratacion* pArray,int limite,int orden)
{
    int retorno=-1;
    int i;
    int j;
    Contratacion auxiliar;
    if(pArray != NULL && limite > 0 && (orden == 0 || orden == 1))
    {
        for(i=1;i < limite; i++)
        {
            if(pArray[i].isEmpty == 0)
            {
                auxiliar = pArray[i];
                j = i - 1;
                if(orden == 0)
                {
                    while ((j >= 0) && pArray[j].isEmpty == 0 && (strcmp(auxiliar.cuit, pArray[j].cuit) < 0))
                    {
                        pArray[j + 1] = pArray[j];
                        j--;
                    }
                    pArray[j + 1] = auxiliar;
                }
                else if(orden == 1)
                {
                    while ((j >= 0) && pArray[j].isEmpty == 0 && (strcmp(auxiliar.cuit, pArray[j].cuit) < 0))
                    {
                        pArray[j + 1] = pArray[j];
                        j--;
                    }
                    pArray[j + 1] = auxiliar;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int con_intercambiarPocionEstructura(Contratacion* pBuffer,int indiceDestino,int indiceOrigen){
    return 0;
}

int con_list(Contratacion* pArray, int limite)
{
    int retorno = -1;
    Contratacion auxiliar;
    int flagDistinto;
    if(pArray != NULL && limite > 0)
    {
        con_ordenarByCuit(pArray, limite, 0);
        do
        {
            flagDistinto = 0;

        }while(flagDistinto == 1);
    }
    return retorno;
}

int con_agruparPosiciones(Contratacion* pBuffer,int limite){

    return 1;
}

int con_ingresoForzado(Contratacion* pBuffer,int limite,char* video,char* cuit,int dias,int idPantalla){
    int aux;
    con_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].video,video);
    strcpy(pBuffer[aux].cuit,cuit);
    pBuffer[aux].dias=dias;
    pBuffer[aux].idPantalla=idPantalla;
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].ID=con_obtenerID();
    return 0;
}
int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan){

    return 1;
}
