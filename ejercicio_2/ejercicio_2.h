#pragma once
#include <fstream>
#include <iostream>
using namespace std;

enum etiqueta{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY,
    UNDEFINED, //En caso de que no se elija una etiqueta valida (Mas info en la funcion consigue_etiqueta) 
};            


/*recibe un mensaje con su respectivo nivel de severidad 
y lo escribe en un archivo de .txt llamado LogMessages.txt */ 
void logMessage(string mensaje, etiqueta etiq_message );

/*recibe un mensaje describiendo un error, el archivo en el que ocurrio dicho error y la linea en la que ocurrio 
y lo escribe en un archivo de .txt llamado LogMessages.txt */ 
void logMessage(string Msj_error, string archivo_err, int linea_codigo );

/*Recibe un mensaje de acceso que puede ser "Access granted" o "Access Denied" o cualquier otro mensaje
y lo escribe en un archivo de .txt llamado LogMessages.txt */ 
void logMessage(string msj_Acceso, string n_usuario);

//recibe input del usuario y devuelve la etiqueta correspondiente a la eleccion
etiqueta consigue_etiqueta(void);

/* Funcion para probar log message para errores.
esta funcion multiplica a por b pero el resultado si o si tiene que ser positivo
*/
unsigned int multiplicacion_pos(int a, int b);