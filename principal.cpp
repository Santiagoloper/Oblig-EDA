/*
  Módulo principal de la tarea 1.

Intérprete de comandos para probar los módulos.

Están creados una TTabla 'tabla' la cual contiene toda la estructura donde estaran las tablas

Cada comando tiene un nombre el cual solicitara los distintos datos


El comando
Fin
termina el programa


  Laboratorio de EDA 2022
  UTU - LATU Nocturno - 
  Profesor Ferando Arrieta
*/

#include "include/tupla.h"
#include "include/tabla.h"
#include "include/columna.h"
#include "include/utils.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>

#define MAX_PALABRA 32
#define MAX_LINEA 256
enum _retorno {OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;

TipoRet createTable (char *nombreTabla);
TipoRet dropTable (char *nombreTabla);
TipoRet addCol (char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
TipoRet dropCol (char *nombreTabla, char *nombreCol);
TipoRet alterCol (char *nombreTabla, char *nombreCol, char *tipoColNuevo, char *calificadorColNuevo, char *nombreColNuevo);
TipoRet insertInto (char *nombreTabla, char *columnaTupa, char *valoresTupla);
TipoRet deleteTupla (char *nombreTabla, char *condicionEliminar);
TipoRet update (char * nombreTabla, char *condicionModificar, char *columnaModificar, char *valorModificar);
TipoRet selectWhere (char *nombreTabla1, char *condicion, char *nombreTabla2);
TipoRet select(char *nombreTabla1, char *columnas, char *nombreTabla2);
TipoRet join(char *nombreTabla1, char *nombreTabla2, char *nombreTabla3);
TipoRet unionTable(char *nombreTabla1, char *nombreTabla2, char *nombreTabla3);
TipoRet printTables();
TipoRet printMetadata(char *nombreTabla);
TipoRet printDataTable (char * NombreTabla, char *ordenadaPor);
	  

// programa principal
int main() {

  char restoLinea[MAX_LINEA + 1];
  char sentencia[MAX_PALABRA];
  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%d>", cont_comandos);	
        // leer el comando
        leerChars(sentencia);
        int largo=strlen(sentencia);
        for (int i=1;i<largo;i++){
            if ((sentencia[i]=='(') || (sentencia [i]==')'))
                sentencia[i]=',';
        }
        char* token = strtok(sentencia,",");
        char nombre_comando[MAX_PALABRA];
        char nombreTabla[MAX_PALABRA];
        char nombreTabla2[MAX_PALABRA];
        char nombreTabla3[MAX_PALABRA];
        char nombreCol[MAX_PALABRA];
        char calificadorCol[MAX_PALABRA];
        char tipoCol[MAX_PALABRA];
        char tipoColNuevo[MAX_PALABRA];
        char calificadorColNuevo[MAX_PALABRA];
        char nombreColNuevo [MAX_PALABRA];
        char columnaTupa[MAX_PALABRA];
        char valoresTupla[MAX_PALABRA];
        char condicionEliminar[MAX_PALABRA];
        char condicionModificar[MAX_PALABRA];
        char columnaModificar[MAX_PALABRA];
        char valorModificar[MAX_PALABRA];
        char condicion[MAX_PALABRA];
        char columnas[MAX_PALABRA];
        char ordenadaPor[MAX_PALABRA];
        strcpy(nombre_comando,token);
        int cont=0;
        while (token != NULL){
            if ((0==strcmp(nombre_comando, "createTable")||(0==strcmp(nombre_comando, "dropTable"))||(0==strcmp(nombre_comando, "printMetadata"))) && (cont==1))
                strcpy(nombreTabla,token); 
            else if (0==strcmp(nombre_comando, "addCol") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "addCol") && (cont==2))
                    strcpy(nombreCol,token);
            else if (0==strcmp(nombre_comando, "addCol") && (cont==3))
                    strcpy(tipoCol,token);
            else if (0==strcmp(nombre_comando, "addCol") && (cont==4))
                    strcpy(calificadorCol,token);
            else if (0==strcmp(nombre_comando, "dropCol") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "dropCol") && (cont==2))
                    strcpy(nombreCol,token);
            else if (0==strcmp(nombre_comando, "alterCol") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "alterCol") && (cont==2))
                    strcpy(nombreCol,token);
            else if (0==strcmp(nombre_comando, "alterCol") && (cont==3))
                    strcpy(tipoColNuevo,token);
            else if (0==strcmp(nombre_comando, "alterCol") && (cont==4))
                    strcpy(calificadorColNuevo,token);
            else if (0==strcmp(nombre_comando, "alterCol") && (cont==5))
                    strcpy(nombreColNuevo,token);
            else if (0==strcmp(nombre_comando, "deleteTupla") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "deleteTupla") && (cont==2))
                    strcpy(condicionEliminar,token);
            else if (0==strcmp(nombre_comando, "selectWhere") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "selectWhere") && (cont==2))
                    strcpy(condicion,token);
            else if (0==strcmp(nombre_comando, "selectWhere") && (cont==3))
                    strcpy(nombreTabla2,token);
            else if (0==strcmp(nombre_comando, "select") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "select") && (cont==2))
                    strcpy(columnas,token);
            else if (0==strcmp(nombre_comando, "select") && (cont==3))
                    strcpy(nombreTabla2,token);
            else if (0==strcmp(nombre_comando, "join") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "join") && (cont==2))
                    strcpy(nombreTabla2,token);
            else if (0==strcmp(nombre_comando, "join") && (cont==3))
                    strcpy(nombreTabla3,token);
            else if (0==strcmp(nombre_comando, "printDataTable") && (cont==1))
                    strcpy(nombreTabla,token);
            else if (0==strcmp(nombre_comando, "printDataTable") && (cont==2))
                    strcpy(ordenadaPor,token);
            token = strtok(NULL, ",");
            cont++;
        }
        // procesar el comando
	if (0 == strcmp(nombre_comando, "Fin")) {
            salir = true;
            printf("Fin.\n");
            // comentario
	}else if (0 == strcmp(nombre_comando, "createTable")) {       
                 TipoRet salida=createTable(nombreTabla);
                 if (salida == OK)
                    printf("OK\n");
                 else if (salida == NO_IMPLEMENTADA )
                         printf("NO_IMPLEMENTADA\n"); 
        } else if (0 == strcmp(nombre_comando, "dropTable")) {
                    TipoRet salida=dropTable(nombreTabla);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "addCol")) {
                    TipoRet salida=addCol(nombreTabla,nombreCol,tipoCol,calificadorCol);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
       	
        } else if (0 == strcmp(nombre_comando, "dropCol")) {
                    TipoRet salida=dropCol (nombreTabla, nombreCol);
                     if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "alterCol")) {
                    TipoRet salida=alterCol (nombreTabla,nombreCol,tipoColNuevo,calificadorColNuevo,nombreColNuevo);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "insertInto")) {
                    TipoRet salida=insertInto (nombreTabla,columnaTupa,valoresTupla);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "deleteTupla")) {
                    TipoRet salida=deleteTupla (nombreTabla,condicionEliminar);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "update")) {
                    TipoRet salida=update (nombreTabla,condicionModificar,columnaModificar,valorModificar);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "selectWhere")) {
                    TipoRet salida=selectWhere (nombreTabla,condicion,nombreTabla2);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        } else if (0 == strcmp(nombre_comando, "select")) {
                    TipoRet salida=select(nombreTabla, columnas, nombreTabla2);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");    
        } else if (0 == strcmp(nombre_comando, "join")){
                    TipoRet salida= join(nombreTabla,nombreTabla2,nombreTabla3);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                             printf("NO_IMPLEMENTADA\n");
        }
        else if (0 == strcmp(nombre_comando, "printTables")) {	
                    TipoRet salida=printTables();
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        }
        else if (0 == strcmp(nombre_comando, "printMetadata")){
                    TipoRet salida= printMetadata(nombreTabla);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
            
        } else if (0 == strcmp(nombre_comando, "printDataTable")) {	
                    TipoRet salida=printDataTable(nombreTabla,ordenadaPor);
                    if (salida == OK)
                        printf("OK\n");
                    else if (salida == NO_IMPLEMENTADA )
                            printf("NO_IMPLEMENTADA\n");
        }else{
                printf("Comando no reconocido.\n");
        } // if
        fgets(restoLinea, MAX_LINEA + 1, stdin);
  } // while
  return 0;
} // main



 //****************************** Funciones a implementar ************************************
   TipoRet createTable (char *nombreTabla){
            return OK;
   }
   
   TipoRet dropTable (char *nombreTabla){
            return OK;
   }
   
   TipoRet addCol (char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
            return OK;
   }
   
   TipoRet dropCol (char *nombreTabla, char *nombreCol){
            return OK;
   }
   
   TipoRet alterCol (char *nombreTabla, char *nombreCol, char *tipoColNuevo, char *calificadorColNuevo, char *nombreColNuevo){
            return NO_IMPLEMENTADA;
   }
   
   TipoRet insertInto (char *nombreTabla, char *columnaTupa, char *valoresTupla){
            return OK;
   }
   
   TipoRet deleteTupla (char *nombreTabla, char * condicionEliminar){
            return OK;
   }
   
   TipoRet update (char *nombreTabla, char *condicionModificar, char *columnaModificar, char *valorModificar){
            return NO_IMPLEMENTADA;
   }
   
   TipoRet selectWhere (char *nombreTabla1, char *condicion, char *nombreTabla2){
            return NO_IMPLEMENTADA;
   }
   
   TipoRet select(char *nombreTabla1, char *columnas, char *nombreTabla2){
            return NO_IMPLEMENTADA;
   }
   
   TipoRet join(char *nombreTabla1, char *nombreTabla2, char *nombreTabla3){
	   return NO_IMPLEMENTADA;
   }
   
   TipoRet printTables(){
	   return OK;
   }
   
   TipoRet printMetadata(char *nombreTabla){
	   return OK;
   }
   
   TipoRet printDataTable (char *NombreTabla, char *ordenadaPor){
	   return OK;
   }
