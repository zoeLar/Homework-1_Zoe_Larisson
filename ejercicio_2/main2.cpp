#include "ejercicio_2.h";

int main (void){
    
    int continuar=1;
    string mensaje;
    etiqueta etiq;
    //2-a

    while(continuar){                       //pregunta al usuario todos los mensajes que quiera ingresar 
        etiq=consigue_etiqueta();           //consigo el tipo de etiqueta

        if(etiq==UNDEFINED){break;}         //Si es undefined no continua el proceso de ingresar el mensaje 

        cout << "Ingrese mensaje:" <<endl;  

        cin.ignore();
        getline(cin,mensaje);               //consigue el mensaje completo como input

        logMessage(mensaje, etiq);          //utilizo la funcion para escribir en el archivo

        cout<< "Completado. Desea ingresar otro mensaje? \n [si=1] [no=0]"<<endl;
        cin >> continuar;                   

    }

    //2-b (i, ii, iv)

    multiplicacion_pos(2,-32);
    //2-b (iii)

    logMessage("Acceso denegado", "Maria Paz Janicki");
    logMessage("Access granted", "Zoe Larisson");
    
}