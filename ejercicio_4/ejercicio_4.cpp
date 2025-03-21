#include "ejercicio_4.h"

const int j=80;

bool comparar_texto(string texto_1, string texto_2,int size_1,int size_2, int i){
    if(size_1==0 && size_2==0)
        return true;
    
    if(size_1!=size_2)
        return false;

    if(texto_1[i]!=texto_2[i])
        return false;
    
    if ((size_1-1)==i)  
        return true;
    
    return comparar_texto(texto_1,texto_2, size_1,size_2,i+=1);

}//memoria dinamica

bool comparar_texto(const char *  texto_1, const char *  texto_2, int size_1, int size_2, int i){
    if(size_1==0 && size_2==0)
        return true;
    
    if(size_1!=size_2)
        return false;
    
    if(texto_1[i]!=texto_2[i])
        return false;
    
    if ((size_1-1)==i)  
        return true;
    

    return comparar_texto(texto_1,texto_2, size_1, size_2, i+=1);
    
}

constexpr bool comparar_texto_comp(const char* texto_1, const char* texto_2, const int size_1,const int size_2, int i){
    if(size_1==0 && size_2==0)
        return true;
    
    if(size_1!=size_2)
        return false;
    
    if(texto_1[i]!=texto_2[i])
        return false;
    
    if ((size_1-1)==i)  
        return true;
    

    return comparar_texto_comp(texto_1,texto_2, size_1, size_2, i+=1);
    
}

void comparar_velocidad(string str1, string str2, const char *  char1, const char *  char2){
    //-----------------------------------------
    //cronometro para string
    //-----------------------------------------
    int s_size1=str1.size();
    int s_size2=str2.size();

    auto startTime = std::chrono::high_resolution_clock::now();
    
    bool result=comparar_texto(str1,str2, s_size1,s_size2);
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);

    cout<<"\nResultado de la comparacion de strings : " <<result<< endl;
    cout << "A comparar_texto para strings le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
    
    //----------------------------------------------
    //cronometro para char *
    cout<<"-----------------------------------------"<<endl;
    int c_size1=strlen(char1);
    int c_size2=strlen(char2);

    auto start = std::chrono::high_resolution_clock::now();
    //funcion a analizar
    result=comparar_texto(char1,char2, c_size1, c_size2);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start);

    cout<<"Resultado de la comparacion de const char * : " <<result<< endl;
    cout << "A comparar_texto para const char * le tomó: " << elapsed.count() << " nanosegundos" << std::endl;
    
}

void comparar_velocidad(const char *  char1, const char *  char2){
    int c_size1=strlen(char1);
    int c_size2=strlen(char2);

    auto startTime = std::chrono::high_resolution_clock::now();
    
    bool result=comparar_texto(char1,char2, c_size1,c_size2);
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);

    cout<<"Resultado de la comparacion de const char *: " <<result<< endl;
    cout << "A comparar_texto para const char *  le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
    
    cout<<"-----------------------------------------"<<endl;
    //------------------------------------------------------------------------
    
    auto start = std::chrono::high_resolution_clock::now();

    constexpr bool resultado= comparar_texto_comp("Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?","Buenos dias, como estas, espero que bien, nos vemos mañana cuando estes libre?",80,80,0);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start);

    cout<<"Resultado de la comparacion en tiempo de compilacion  : " <<resultado<< endl;
    cout << "A comparar_texto_comp le tomó: " << elapsed.count() << " nanosegundos" << std::endl;
}
