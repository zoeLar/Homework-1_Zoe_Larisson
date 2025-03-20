
#include "ejercicio_1.h";


//ejercicio 1-a

vector<vector<int>> create_matrix(int n){
    vector<vector<int>> matrix (n,vector<int>(n));
    int counter=1;

    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            matrix[i][j]=counter;
            counter++;
        }
    }
    return matrix;
}

void print_square_matrix(vector<vector<int>> matrix, int n){
    if(n==0){
        cout<< "La matriz esta vacia"<<endl;
        return;
    }
    int column=n-1;                 //mi primera posicion en la columna es n-1, ya que leo del mayor al menor
    int row=n-1;                    //lo mismo pero para la fila
    for (int i=n*n; i>0;i--){       //i= nxn y lo decremento cada iteracion, hasta llegar a 0 //es nxn por que hay n filas y n columnas (filas x columnas)
        
        cout<< "m["<< row << "]["<<column <<"] =" << matrix[row][column]<<endl;     //m[fila][columna] = valor\n
        
        if(column==0){              //Decremento columna cada iteracion, y cuando llega a 0 empiezo otra vez decrementando columna desde n
            row--;
            column=n;               //empieza en n por que despues se decrementa en 1, en la linea siguiente 
        }
        column--;

    }
    return;
}



int main (void){
    int n; //recibe input del usuario para el parametro n

    cout << "ingrese el tamaño (n) de su matriz cuadrada (nxn): ";
    cin >> n;
    
    vector<vector<int>> mine= create_matrix(n);
    print_square_matrix(mine, n); 

}
