/* 1111111 */
/*
  Módulo de implementación de 'utils'.

  Curso EDA 2022
  UTU -LATU Turno Nocturno
  Profesor Fernando Arrieta
 */

#include "../include/utils.h"

#include "stdio.h"

nat leerNat() {
  nat res;
  scanf("%u", &res);
  return res;
}

char leerChar() {
  char res;
  scanf(" %c", &res);
  return res;
}

double leerDouble() {
  double res;
  scanf("%lf", &res);
  return res;
}

void leerChars(ArregloChars cs) { scanf("%s", cs); }

void leerRestoLinea(ArregloChars cs) { scanf("%[^\n]", cs); }
