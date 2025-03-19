#include <fstream>
#include <iostream>
using namespace std;

enum etiqueta{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    UNDEFINED};

void logMessage(string mensaje, etiqueta etiq_message ){

    string  valor_etiqueta;
    switch (etiq_message){
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
    
    ofstream archivo("LogMessages.txt",ios ::app);

    if(archivo.is_open())
        archivo << valor_etiqueta << " = <" << mensaje << ">\n";
    else
        cerr<<"ERROR: No se pudo crear el archivo\n";
    archivo.close();
}

etiqueta consigue_etiqueta(void){
    
    int n_etiq, continuar=1;
    etiqueta etiq;
    
    while(continuar){
        cout << "Ingrese el tipo de etiqueta con el numero correspondiente:"<< endl;
        cout <<"DEBUG=0  INFO=1  WARNING=2  ERROR=3  CRITICAL=4 "<< endl;
        cin >> n_etiq;

        //CASO etiqueta invalida
        if(n_etiq<0 or n_etiq>4){
            cout<< "etiqueta invalida, intentar otra vez?: \n [si=1] [no=0]" <<endl;
            cin >> continuar;
            n_etiq=-1;
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

    if(n_etiq==-1) return UNDEFINED;
    return etiq;
}
int main (void){
    
    int continuar=1;
    string mensaje;
    etiqueta etiq;

    while(continuar){
        etiq=consigue_etiqueta();

        if(etiq==UNDEFINED){break;}

        cout << "Ingrese mensaje:" <<endl;

        cin.ignore();
        getline(cin,mensaje);

        logMessage(mensaje, etiq);

        cout<< "Completado. Desea ingresar otro mensaje? \n [si=1] [no=0]"<<endl;
        cin >> continuar;

        }
        
}
    

