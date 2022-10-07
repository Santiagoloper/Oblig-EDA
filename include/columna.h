/*
  Módulo de definición de 'TColumna'.

  Un elemento de tipo 'TColumna' es una colección de 'TColumna's.

  Cada columna tiene un nombre, tipo-Columna y un calificador-Columna.

  Laboratorio de Tecnologo informatico turno nocturno.
  UTU-LATU
 */

#ifndef _COLUMNA_H
#define _COLUMNA_H

#include "tupla.h"
#include <cstddef>


// Representación de 'TColumna'.
// Se debe definir en 'columna.cpp'.
// struct _rep_columna;
// Declaración del tipo 'TColumna'

typedef struct _rep_columnas *TColumna;
enum TCol {INT, STRING};
enum TCalif {NOT_EMPTY, PRIMARY_KEY, ANY};


//Crea una columna vacia
TColumna crearColumnaVacia();

//retorna true si col tiene por lo menos una columna
bool tieneColumnas(TColumna col);

//Retorna la cantidad de columnas de col
int cantidadColumnas(TColumna col);

//retorna true si la columna col tiene la columna nombreColumna
bool existeColumna(char *nombreColumna, TColumna col);

//retorna true si la columna col tiene como nombre nombreColumna
bool esColumna(char *nombreColumna, TColumna col);

//inserta una nueva columna al final de col con los datos proporcionados
TColumna insertarColumna(char *nombreCol, TCol tipoCol, TCalif calificadorCol, TColumna &col);

//Pre-cond tieneColumnas(col) == true
//Retorna el nombre de la columna col
char* nombreColumna(TColumna col);

//Pre-cond tieneColumnas(col) == true
//retorna el tipo de columna apuntado por col
TCol tipoColumna(TColumna col);

//Pre-cond tieneColumnas(col) == true
//retorna el calificador de la columna col
TCalif calificadorColumna(TColumna col);

//retorna un puntero a la siguiente columna de col
//pre-cond col no es vacia
TColumna siguienteColumna (TColumna col);

//retorna un puntero a la tupla de la columna col
TTupla obtenerTupla (TColumna col);

//elimina toda la memoria de col
//pre-cond col no tiene tuplas
void removerColumnas(TColumna &col);

#endif
