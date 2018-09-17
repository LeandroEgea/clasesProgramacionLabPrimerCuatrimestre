#ifndef UTNMATH_H_INCLUDED
#define UTNMATH_H_INCLUDED

float utn_sumarDosFlotantes(float numeroUno, float numeroDos);

float utn_restarDosFlotantes(float numeroUno, float numeroDos);

float utn_multiplicarDosFlotantes(float numeroUno, float numeroDos);

int utn_dividirDosFlotantes(float numeroUno, float numeroDos, float *resultadoDivision);

unsigned long long int utn_obternerResultadoFactorial(int numero);

int utn_realizarFactorialConFlotante(float numero, unsigned long long int *resultadoFactorial);

#endif // UTNMATH_H_INCLUDED
