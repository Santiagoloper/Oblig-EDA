/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/tabla.h"
#include "../include/columna.h"


struct _rep_tabla {};


//Crea la tabla vacia sin nombre
TTabla crearTablaVacia (){
	return NULL;
}

//Crea la 'Tabla' vacía (sin filas ni columnas) con nombre "nombreTabla" y la agrega a tabla;
void crearTabla(char *nombreTabla, TTabla &tabla){
}

//Libera toda la memoria ocupada por la tabla "tabla".
void eliminarTabla(TTabla &tabla){
}

//Agrega a la tabla de nombre nombreTabla, si éste existe, una nueva columna al final de
//nombre nombreCol, si éste no existe, tipo tipoCol y calificador calificadorCol
void agregarColumnaTabla (TTabla &tabla,char *nombreCol,TCol tipoCol,TCalif calificadorCol){
}

//ver descripcion en la letra del obligatorio INSERTAR TUPLA – intertInto
void insertarTuplaTabla (TTabla &tabla, char *columnasTupla, char *valoresTupla){
}

//ver descripcion en la letra del obligatorio ELIMINAR TUPLA – delete
void eliminarTuplasTabla (TTabla &tabla, char *condicion){
}

//Imprime las tuplas de la tabla de nombre nombreTabla, si éste existe, ordenados de acuerdo a 
//las columnas especificadas en el parámetro ordenadaPor
void imprimirDataTabla(TTabla tabla, char *orednadoPor){
}

//Imprime el esquema de la tabla de nombre nombreTabla, si éste existe. Es decir, 
//imprime el nombre de la Tabla, los nombres de sus columnas en el orden correspondiente, 
//indicando para cada columna su tipo de datos y calificador si lo tuviera
void imprimirEsquemaTabla(TTabla tabla){
}

//Imprime los nombres de las tablas de la base de datos del sistema, 
//ordenados alfabéticamente de menor a mayor.
void imprimirTablas (TTabla tabla){
}

//Retorna true si la tabla "tabla" está vacia (no tiene ninguna túpla).
bool estaVaciaTabla (TTabla tabla){
	return true;
}

//Retorna true si la tabla de nombre nombreTabla existe en TTabla
bool existeTabla (char *nombreTabla, TTabla tabla){
	return true;
}

//Retorna true si la columna "nomCol" exite en la tabla "tabla".
//Pre cond: La tabla tiene columnas definidas.
bool existeColumnaTabla (char *nomCol, TTabla tabla){
	return true;
}

//Retorna true si la tabla "tabla" tiene columnas definidas.
bool tieneColumnasTabla (TTabla tabla){
	return true;
}

//Retorna true si la tabla "tabla" tiene una columna PrimaryKey.
bool existeColumnaPrimaryKeyEnTabla (TTabla tabla){
	return true;
}

//Retorna un puntero TTabla a la tabla con nombre "nombreTabla" de tabla
//pre-cond la tabla nombreTalba existe en TTabla
TTabla obtenerTabla (char *nombreTabla, TTabla tabla){
    return NULL;
}
