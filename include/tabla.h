/*
  Módulo de definición de 'TTabla'.

  Laboratorio de EDA Turno Nocturno.
  UTU-LATU
*/

#ifndef _TABLA_H
#define _TABLA_H

#include "../include/columna.h"
#include "../include/tupla.h"
#include <cstddef>


// Representación de 'tabla'.
// Se debe definir en 'tabla.cpp'.
// struct _rep_table;
// Declaración del tipo 'TTable'
typedef struct _rep_tabla *TTabla;



//Crea la tabla vacia sin nombre
TTabla crearTablaVacia ();

//Crea la 'Tabla' vacía (sin filas ni columnas) con nombre "nombreTabla" y la agrega a tabla;
void crearTabla(char *nombreTabla, TTabla &tabla);

//Libera toda la memoria ocupada por la tabla "tabla".
void eliminarTabla(TTabla &tabla);

//Agrega a la tabla de nombre nombreTabla, si éste existe, una nueva columna al final de
//nombre nombreCol, si éste no existe, tipo tipoCol y calificador calificadorCol
void agregarColumnaTabla (TTabla &tabla, char *nombreCol,TCol tipoCol,TCalif calificadorCol);

//ver descripcion en la letra del obligatorio INSERTAR TUPLA – intertInto
void insertarTuplaTabla (TTabla &tabla, char* columnasTupla, char* valoresTupla); 

//ver descripcion en la letra del obligatorio ELIMINAR TUPLA – delete
void eliminarTuplasTabla (TTabla &tabla, char* condicion);

//Imprime las tuplas de la tabla de nombre nombreTabla, si éste existe, ordenados de acuerdo a 
//las columnas especificadas en el parámetro ordenadaPor
void imprimirDataTabla(TTabla tabla, char* orednadoPor);

//Imprime el esquema de la tabla de nombre nombreTabla, si éste existe. Es decir, 
//imprime el nombre de la Tabla, los nombres de sus columnas en el orden correspondiente, 
//indicando para cada columna su tipo de datos y calificador si lo tuviera
void imprimirEsquemaTabla(TTabla tabla);

//Imprime los nombres de las tablas de la base de datos del sistema, 
//ordenados alfabéticamente de menor a mayor.
void imprimirTablas (TTabla tabla);

//Retorna true si la tabla "tabla" está vacia (no tiene ninguna túpla).
bool estaVaciaTabla (TTabla tabla);

//Retorna true si la tabla de nombre nombreTabla existe en TTabla
bool existeTabla (char* nombreTabla, TTabla tabla);

//Retorna true si la columna "nomCol" exite en la tabla "tabla".
//Pre cond: La tabla tiene columnas definidas.
bool existeColumnaTabla (char* nomCol, TTabla tabla);

//Retorna true si la tabla "tabla" tiene columnas definidas.
bool tieneColumnasTabla (TTabla tabla);

//Retorna true si la tabla "tabla" tiene una columna PrimaryKey.
bool existeColumnaPrimaryKeyEnTabla (TTabla tabla);

//Retorna un puntero TTabla a la tabla con nombre "nombreTabla" de tabla
//pre-cond la tabla nombreTalba existe en TTabla
TTabla obtenerTabla (char* nombreTabla, TTabla tabla);

#endif
