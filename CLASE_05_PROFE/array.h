#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define DATO_INVALIDO -1
#define false 0
#define true 1

int array_mostrar(int* pArray, int limite);

int array_calcularMaximo(int* pArray, int limite, int* pMaximo);

int array_init(int* pArray, int limite, int valor);

#endif // ARRAY_H_INCLUDED
