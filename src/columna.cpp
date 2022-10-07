/* 1111111 */ // sustituiir con los 7 dígitos de la cédula
#include "../include/columna.h"

struct _rep_columnas {};


//Crea una estructura de columnas vacio
TColumna crearColumna() {
    return NULL;
}


//retorna true si col no es NULL
bool tieneColumnas(TColumna col){
	return true;
}


//Retorna la cantidad de columnas de col
int cantidadColumnas(TColumna col) {
	return 0;
}


//retorna true si la columna col tiene la columna
bool existeColumna(char *nombreColumna, TColumna col) {
	return false;
}


//inserta una nueva columna al final de col con los datos proporcionados
TColumna insertarEnColumnas(char *nombreCol, TCol tipoCol, TCalif calificadorCol, TColumna &col) {
	return col;
}


//Pre-cond tieneColumnas(col) == true
//Retorna el nombre de lo apuntado por col
char* nombreColumnaLista(TColumna col) {
	return NULL;
}


//Pre-cond tieneColumnas(col) == true
//retorna el tipo de columna apuntado por col
TCol tipoColumna(TColumna col) {
	return INT;
}

//Pre-cond tieneColumnas(col) == true
//retorna el calificador de la columna col
TCalif calificadorColumna(TColumna col) {
	return ANY;
}


//elimina toda la memoria de col
void removerColumnas(TColumna &col) {
}
