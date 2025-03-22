#include "ejercicio_2.h"

//---------------------------------------------------------------------//

void logMessage(string mensaje, etiqueta etiq_message ){

    string  valor_etiqueta;

    switch (etiq_message){ //segun que etiqueta se elije, es el string correspondiente
        case (DEBUG):{ 
            valor_etiqueta="[DEBUG]"; 
            break;}
        case (INFO): {
            valor_etiqueta="[INFO]";
            break;}
        case (WARNING):{ 
            valor_etiqueta="[WARNING]";
            break;}
        case (ERROR): {
            valor_etiqueta="[ERROR]";
            break;}
        case (CRITICAL): {
            valor_etiqueta="[CRITICAL]";
            break;}
        default: {valor_etiqueta="[UNDEFINED]"; 
            }
    }   
    
    ofstream archivo("LogMessages.txt",ios ::app);                  //abro archivo     

    if(archivo.is_open())                                           //Verifico si abrio correctamente 
        archivo << valor_etiqueta << " = <" << mensaje << ">\n";    //mensaje a escribir en el archivo
    else
        cerr<<"ERROR: No se pudo crear el archivo\n";               //si falla corta el programa
    archivo.close();                                                //cierra archivo
}

//---------------------------------------------------------------------//

void logMessage(string Msj_error, string archivo_err, int linea_codigo ){
    ofstream archivo("LogMessages.txt",ios ::app);                  //abro archivo

    if(archivo.is_open())                                           //Verifico si abrio correctamente 
        archivo << "[ERROR]" << " = Mensaje: <" << Msj_error << "> - Archivo: <"<<archivo_err<<"> - Linea de codigo: <"<< linea_codigo<<">\n";
    else
        cerr<<"ERROR: No se pudo crear/abrir el archivo\n";         //si falla corta el programa
    archivo.close();                                                //cierra archivo
}

//---------------------------------------------------------------------//

void logMessage(string msj_Acceso, string n_usuario){
    ofstream archivo("LogMessages.txt",ios ::app);                  //abro archivo
    if(archivo.is_open())
        archivo << "[SECURITY]" << " <" << msj_Acceso << "> USUARIO: ["<< n_usuario<<"]\n";
    else
        cerr<<"ERROR: No se pudo crear/abrir el archivo\n";
    archivo.close();                                                //cierra archivo
}

//---------------------------------------------------------------------//

etiqueta consigue_etiqueta(void){
    
    int n_etiq, continuar=1;
    etiqueta etiq;
    
    while(continuar){        //continua hasta que el usuario decida terminar 
        cout << "Ingrese el tipo de etiqueta con el numero correspondiente:"<< endl;
        cout <<"DEBUG=0  INFO=1  WARNING=2  ERROR=3  CRITICAL=4 "<< endl;
        cin >> n_etiq;

        //CASO etiqueta invalida
        if(n_etiq<0 or n_etiq>4){
            cout<< "etiqueta invalida, intentar otra vez?: \n [si=1] [no=0]" <<endl;
            cin >> continuar;
            n_etiq=-1;      //si el usuario decide terminar el proceso n_etiqueta se queda como -1, indicando que no se va a escribir nada
            continue;
        }
        //si es valida entra en el switch
        switch (n_etiq){
            case 0:{
                etiq=DEBUG;
                break;}
            case 1:{
                etiq=INFO;
                break;}
            case 2:{
                etiq=WARNING;
                break;}
            case 3:{
                etiq=ERROR;
                break;}
            case 4:{
                etiq=CRITICAL;
                break;}   
            default:
                etiq=UNDEFINED;
                break;
        }
        continuar=0;
    }

    if(n_etiq==-1) return UNDEFINED;    //CASO etiqueta invalida y el usuario decide terminar el proceso
    return etiq;                        //retorna una etiqueta
}

//---------------------------------------------------------------------//

unsigned int multiplicacion_pos(int a, int b){
    try{
        if(a<0 xor b<0){
            throw runtime_error("Multiplicacion con resultado negativo");           
        }
    }
    catch (const runtime_error& e) {
        
        logMessage(e.what(),"ejercicio_2.cpp",117);}
     
    return (a*b);
}
    

