/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/tupla.h"
#include <stdio.h>
#include <stdlib.h>

struct _rep_tupla {};

//Crea la tupla vacia
TTupla crearTupla() {
    return NULL;
}

//retorna true si tup es vacia
bool esVaciaTupla (TTupla tup){
	return true;
}

//agrega una nueva tupla en tup del tipo string
void agregarTuplaString (char* dato, TTupla &tup){
}

//agrega una nueva tupla en tup del tipo intiger
void agregarTuplaIntiger (int dato, TTupla &tup){
}

//retorna el dato string de la tupla tup
//pre-cond tup no es vacia
//tup es del tipo string

char* datoString (TTupla tup) {
  return NULL;
}

//retorna true si la tupla es de tipo string
bool esTuplaString (TTupla tup) {
  return true;
}

//retorna el siguiente nodo tupla fila
//pre-cond tup no es vacia
TTupla siguienteTuplaFila (TTupla tup){
   return NULL;
}

//retorna el siguiente nodo tupla columna
//pre-cond tup no es vacia
TTupla siguienteTuplaColumna (TTupla tup){
    return NULL;
}

//retorna el dato int de la tupla tup
//pre-cond tup no es vacia
int datoIntiger(TTupla tup) {
  return 0;
}


//inserta una tupla del tipo string en la ultima posicion
void insertarTuplaString (char dato,TTupla &tup){
}

//inserta una tupla del tipo intiger en la ultima posicion
void insertarTuplaIntiger (int dato,TTupla &tup){
}

//libera toda la memoria de tup
void eliminarTupla (TTupla &tup){
}


