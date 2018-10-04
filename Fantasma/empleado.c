#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
/**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}
/**
* \brief    Se utiliza esta funcion para obtener el primer lugar libre de un array de tipo empleado,
*           recorriendo el array hasta encontrar un isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return devuelve el indice de la posicion libre, sino el return es -1.
*/
static int getLugarLibre(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief compara a los empleados, primero por apellido y en caso de coincidir, por sector
* \param arrayUno es el primer empleado que se va a comparar
* \param arrayDos es el segundo empleado que se va a comparar
* \return si el primero es mayor devuelve 0(para que se realice el swap), si no -1
*/
static int comparacionApellidoSector(Empleado* arrayUno, Empleado* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL)
    {
        if( strcmp(arrayUno->apellido, arrayDos->apellido) > 0 ||
            (strcmp(arrayUno->apellido, arrayDos->apellido) == 0 && arrayUno->sector > arrayDos->sector))
        {
            retorno = 0;
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para inicializar un array de tipo empleado,
*           recorriendo el array y poniendo cada isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int empleado_init(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un empleado a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del empleado donde se encontro el id,
*           si no el retorno es NULL.
*/
Empleado* empleado_getById(Empleado* array, int len, int id)
{
    Empleado* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idEmpleado == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un empleado a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del empleado donde se encontro el id,
*           si no el retorno es NULL.
*/
Empleado* empleado_getByNombre(Empleado* array, int len, char* nombreEmpleado)
{

    Empleado* retorno = NULL;
    Empleado* auxiliarEmpleado = NULL;
    int i;
    int id;
    int indicePrimerEncontrado;
    int cantidadEncontrados = 0;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if( cantidadEncontrados == 0 && !array[i].isEmpty &&
                strcmp(array[i].nombre,nombreEmpleado) == 0)
            {
                cantidadEncontrados++;
                indicePrimerEncontrado = i;
            }
            else if(cantidadEncontrados == 1 && !array[i].isEmpty &&
                    strcmp(array[i].nombre,nombreEmpleado) == 0)
            {
                cantidadEncontrados++;
                printf("Seleccione por Id\n");
                empleado_mostrar(&array[indicePrimerEncontrado],1);
                empleado_mostrar(&array[i],1);
            }
            else if(!array[i].isEmpty && strcmp(array[i].nombre,nombreEmpleado) == 0)
            {
                empleado_mostrar(&array[i],1);
            }
        }
        if(cantidadEncontrados==1)
        {
            retorno = &array[indicePrimerEncontrado];
        }
        else if(cantidadEncontrados > 1 && !utn_getEnteroSoloNumeros(&id,5,"","",0))
        {
            auxiliarEmpleado = empleado_getById(array, len, id);
            if(strcmp(auxiliarEmpleado->nombre, nombreEmpleado) == 0)
            {
                retorno = auxiliarEmpleado;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de alta un empleado generando un id
*           de manera automatica y el usuario introduce el resto de datos,
*           si se realiza todo correctamente se guardan los datos y se coloca el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int empleado_alta(Empleado* array, int len)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getNombre( nombre, 51,"Nombre empleado?\n",
                        "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                        "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
        !utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
    {
        strncpy(array[indice].nombre, nombre,51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].isEmpty = 0;
        array[indice].idEmpleado = getNextId();
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para modificar todos los datos de un empleado
*           el usuario elige a traves de un id e introduce todos los datos por teclado
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int empleado_modificar(Empleado* array, int len, int reintentos)
{
    int retorno = -1;
    Empleado *empleadoModificado = NULL;
    int id;
    int i;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        empleado_mostrar(array, len);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                empleado_getById(array, len, id) != NULL)
            {
                empleadoModificado = empleado_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    if( empleadoModificado != NULL &&
        !utn_getNombre( nombre, 51,"Nombre empleado?\n",
        "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getNombre( apellido, 51,"Apellido empleado?\n",
        "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
        !utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
    {
        strncpy(empleadoModificado->nombre, nombre, 51);
        strncpy(empleadoModificado->apellido, apellido, 51);
        empleadoModificado->salario = salario;
        empleadoModificado->sector = sector;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para modificar un empleado,
*           el usuario elige a traves de un menu
*           que dato modificar o modificarlos todos
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int empleado_modificarConMenu(Empleado* array, int len, int reintentos)
{
    int retorno = -1;
    Empleado *empleadoModificado = NULL;
    int elegirOpcion = 0;
    int id;
    int i;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        empleado_mostrar(array, len);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                empleado_getById(array, len, id) != NULL)
            {
                empleadoModificado = empleado_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id erroneo\n");
            }
        }
    }
    if(empleadoModificado != NULL)
    {
        printf("1. Modificar nombre\n"
               "2. Modificar apellido\n"
               "3. Modificar salario\n"
               "4. Modificar sueldo\n"
               "5. Modificar todos los datos\n");
        utn_getEnteroSoloNumeros(&elegirOpcion, 5, "Seleccione...\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if( !utn_getNombre(nombre, 51,"Nombre empleado?\n",
                    "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    retorno = 0;
                }
                break;
            case 2:
                if( !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                    "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2))
                {
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    retorno = 0;
                }
                break;
            case 3:
                if(!utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2))
                {
                    empleadoModificado->salario = salario;
                    retorno = 0;
                }
                break;
            case 4:
                if(!utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
                {
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            case 5:
                if( !utn_getNombre( nombre, 51,"Nombre empleado?\n",
                    "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
                    !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                    "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
                    !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
                    !utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    empleadoModificado->salario = salario;
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de baja (baja logica) un empleado,
*           el usuario introduce el id, se le muestra el empleado y
*           confirma la baja(se coloca el isEmpty en 1)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int empleado_baja(Empleado* array, int len, int reintentos)
{
    int retorno = -1;
    Empleado *empleadoModificado;
    char confirmarBaja[10];
    int id;
    int i;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        empleado_mostrar(array, len);
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea dar de baja\n", "", 0) &&
                empleado_getById(array, len, id) != NULL)
            {
                empleadoModificado = empleado_getById(array, len, id);
                printf("Se eliminara el siguiente empleado\n");
                empleado_mostrar(empleadoModificado, 1);
                if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                    strcmp(confirmarBaja, "1") == 0)
                {
                    empleadoModificado->isEmpty = 1;
                    retorno = 0;
                }
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para mostrar todos los datos de los
*           empleados del array (nombre, apellidos, salario, sector, id)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int empleado_mostrar(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\nID: %d\n\n",
                array[i].nombre, array[i].apellido, array[i].salario, array[i].sector, array[i].idEmpleado);
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para cargar los datos de un
*           empleado del array (nombre, apellidos, salario, sector)
*           el id se genera de manera automatica y se pone el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int empleado_ingresoForzado(Empleado* array, int len, char *nombre, char *apellido, float salario, int sector)
{
    int retorno = -1;
    int indice;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && nombre != NULL &&
        apellido != NULL && salario > 0 && sector > 0)
    {
        strncpy(array[indice].nombre, nombre, 51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].idEmpleado = getNextId();
        array[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    ordena un array de empleados por insercion, por 2 criterios,
*           primero por apellido y en caso de coincidir, por sector
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param orden El orden debe ser 0 (Ascendente) o 1 (Descendente)
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int empleado_sortEmpleadosPorApellidoSector(Empleado *array, int len, int orden)
{
    Empleado auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0 && (orden == 0 || orden == 1))
    {
        for(i=1; i < len; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && !comparacionApellidoSector(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
            if(orden == 1)
            {
                while ((j >= 0) && !comparacionApellidoSector(&auxiliar, &array[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Calcula el total de los salarios, el promedio
*           y la cantidad de empleados que superan el promedio.
*           Solo evalua los empleados que tienen el isEmpty en 0.
*           Finalmente muestra toda esa informacion
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostro la informacion, si no el retorno es -1.
*/
int empleado_informacionEmpleados(Empleado *array, int len)
{
    int retorno=-1;
    int i;
    float totalSalarios = 0;
    int totalEmpleados = 0;
    float promedioSalarios;
    int cantidadSalariosSobrePromedio = 0;
    if(array != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(array[i].isEmpty == 0)
            {
                totalSalarios += array[i].salario;
                totalEmpleados++;
            }
        }
        promedioSalarios = totalSalarios/totalEmpleados;
        for(i=0; i < len; i++)
        {
            if(array[i].isEmpty == 0 && array[i].salario > promedioSalarios)
            {
                //empleado_mostrar(&(array[i]), 1);
                cantidadSalariosSobrePromedio++;
            }
        }
        printf("El total de los salarios es: %.2f\n", totalSalarios);
        printf("El promedio de los salarios es: %.2f\n", promedioSalarios);
        printf("Cantidad de salarios que superan el promedio: %d\n", cantidadSalariosSobrePromedio);
        retorno = 0;
    }
    return retorno;
}

/**
* \brief Calcula el promedio de los salarios de los empleados
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostro la informacion, si no el retorno es -1.
*/
int empleado_promedioSalarios(Empleado *array, int len, float *promedioSalarios)
{
    int retorno=-1;
    int i;
    float totalSalarios = 0;
    int totalEmpleados = 0;
    if(array != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(array[i].isEmpty == 0)
            {
                totalSalarios += array[i].salario;
                totalEmpleados++;
            }
        }
        *promedioSalarios = totalSalarios/totalEmpleados;
        retorno = 0;
    }
    return retorno;
}









//Falta DoxyGen

/*
int informar_pantallaMayorMenorDiez(Pantalla *array, int len, int mayorMenor)
{
    int retorno=-1;
    int i;
    int cantidadPantallas = 0;
    if(array != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(mayorMenor == 0 && array[i].isEmpty == 0 && array[i].precio > 10)
            {
                pantalla_mostrar(&(array[i]), 1);
                cantidadPantallas++;
            }
            else if(mayorMenor == 1 && array[i].isEmpty == 0 && array[i].precio <= 10)
            {
                pantalla_mostrar(&(array[i]), 1);
                cantidadPantallas++;
            }
        }
        printf("El total de pantallas es: %d\n", cantidadPantallas);
        retorno = 0;
    }
    return retorno;
}
int informar_pantallaSuperaPromedio(Pantalla *array, int len, int MayorMenor)
{
    int retorno=-1;
    int i;
    float promedioPrecios;
    int cantidadPantallasSobrePromedio = 0;
    if(array != NULL && len > 0 && !pantalla_promedioPrecio(&promedioPrecios, array, len))
    {
        if(MayorMenor == 0)
        {
            for(i=0; i < len; i++)
            {
                if(array[i].isEmpty == 0 && array[i].precio > promedioPrecios)
                {
                    pantalla_mostrar(&(array[i]), 1);
                    cantidadPantallasSobrePromedio++;
                }
            }
            printf("El total de las pantallas que superan el promedio(%.2f) es: %d\n", promedioPrecios, cantidadPantallasSobrePromedio);
        }
        else if(MayorMenor == 1)
        {
            for(i=0; i < len; i++)
            {
                if(array[i].isEmpty == 0 && array[i].precio < promedioPrecios)
                {
                    pantalla_mostrar(&(array[i]), 1);
                    cantidadPantallasSobrePromedio++;
                }
            }
            printf("El total de las pantallas que no superan el promedio(%.2f) es: %d\n", promedioPrecios, cantidadPantallasSobrePromedio);
        }
        retorno = 0;
    }
    return retorno;
}/*
/*
int informar_contratacionesMenorDiezDias(   Contratacion *arrayContratacion, int lenContratacion,
                                            Pantalla *arrayPantalla, int lenPantalla)
{
    int retorno=-1;
    int i;
    int idPantallaAuxiliar;
    float precioTotal;
    Pantalla* pantallaAuxiliar;
    if(arrayContratacion != NULL && lenContratacion > 0 && arrayPantalla != NULL && lenPantalla > 0)
    {
        for(i=0; i < lenContratacion; i++)
        {
            if(arrayContratacion[i].isEmpty == 0 && arrayContratacion[i].dias <= 10)
            {
                idPantallaAuxiliar = arrayContratacion[i].idPantalla;
                pantallaAuxiliar = pantalla_getById(arrayPantalla, lenPantalla, idPantallaAuxiliar);
                precioTotal = pantallaAuxiliar->precio * arrayContratacion[i].dias;
                printf("%s   %.2f   %d   %.2f\n",pantallaAuxiliar->nombre,pantallaAuxiliar->precio,arrayContratacion[i].dias, precioTotal);
            }
        }
        retorno = 0;
    }
    return retorno;
}
*/
/*
int contratacion_crearArrayCuit(Contratacion* arrayContratacion, int lenContratacion, char arrayCuits[][20], int lenArrayCuits)
{
    int retorno = -1;
    int i;
    int indiceLibre = 0;
    if(arrayContratacion!= NULL && lenContratacion>0 && arrayCuits != NULL && lenArrayCuits > 0)
    {
        for(i=0;i<lenArrayCuits;i++)
        {
            strncpy(arrayCuits[i], "isEmpty", 20);
        }
        for(i=0;i<lenContratacion;i++)
        {
            if( arrayContratacion[i].isEmpty == 0 &&
                !contratacion_isCuitCargado(arrayCuits, lenArrayCuits, arrayContratacion[i].cuit))
            {
                strncpy(arrayCuits[indiceLibre], arrayContratacion[i].cuit,20);
                indiceLibre++;
            }
        }
        retorno = 0;
    }
    return retorno;
}*/
/*
int contratacion_isCuitCargado(char arrayCuits[][20],int lenArrayCuits,char* cuit)
{
    int retorno = 0;
    int i;
    if(arrayCuits != NULL && lenArrayCuits > 0)
    {
        for(i=0;i<lenArrayCuits;i++)
        {
            if(strcmp(arrayCuits[i], cuit) == 0)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
*/
/*
int contratacion_mostrarCuits(char arrayCuits[][20], int lenArrayCuits)
{
    int retorno = -1;
    int i;
    int indiceSiguiente = 0;
    for(i=0;i<lenArrayCuits;i++)
    {
        if(strcmp(arrayCuits[i], "isEmpty") != 0)
        {
            printf("%s\n", arrayCuits[indiceSiguiente]);
            indiceSiguiente++;
        }
        retorno = 0;
    }
    return retorno;
}
*/
