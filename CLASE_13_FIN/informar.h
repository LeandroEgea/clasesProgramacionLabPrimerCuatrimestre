#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

int informar_sortPantallaPorPrecioNombre(Pantalla *array, int len);
int informar_pantallaMayorMenorDiez(Pantalla *array, int len, int mayorMenor);
int informar_pantallaSuperaPromedio(Pantalla *array, int len, int MayorMenor);
int informar_contratacionesMenorDiezDias(   Contratacion *arrayContratacion, int lenContratacion,
                                            Pantalla *arrayPantalla, int lenPantalla);

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

#endif
