/*
  Módulo de definición de 'TTupla'.

  Los elementos de tipo 'TTupla' son punteros a una estructura (que debe
  definirse en tupla.cpp) compuesta por un char* o un int.

  Laboratorio de Tecnologo informatico turno nocturno.
  UTU-LATU
 */

#ifndef _TUPLA_H
#define _TUPLA_H
#include <cstddef>


typedef struct _rep_tupla *TTupla;

/* Operaciones de TTupla */

//Crea la tupla vacia
TTupla crearTupla();

//retorna true si la tupla es vacia
bool esVaciaTupla (TTupla tup);

//agrega una nueva tupla en tup del tipo char*
void agregarTuplaString (char* dato, TTupla &tup);

//agrega una nueva tupla en tup del tipo intiger
void agregarTuplaIntiger (int dato, TTupla &tup);


//retorna true si la tupla es de tipo char*
bool esTuplaString (TTupla tup);

//retorna el siguiente nodo tupla fila
//pre-cond tup no es vacia
TTupla siguienteTuplaFila (TTupla tup);

//retorna el siguiente nodo tupla columna
//pre-cond tup no es vacia
TTupla siguienteTuplaColumna (TTupla tup);

//retorna el dato int de la tupla tup
//pre-cond tup no es vacia
int datoIntiger(TTupla tup);

//retorna el dato char* de la tupla tup
//pre-cond tup no es vacia
char* datoString(TTupla tup);

//inserta una tupla del tipo intiger en la ultima posicion
void insertarTuplaIntiger (int dato,TTupla &tup);

//inserta una tupla del tipo char* en la ultima posicion
void insertarTuplaSring (char* dato,TTupla &tup);

//libera toda la memoria de tup
void eliminarTupla (TTupla &tup);

#endif
