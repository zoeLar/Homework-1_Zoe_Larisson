#include <vector>
#include <iostream>
using namespace std;

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
//ejercicio 1-b
void print_square_matrix(vector<vector<int>> matrix, int n){
    int column=n-1;
    int row=n-1;
    for (int i=n*n; i>0;i--){
        
        cout<< "m["<< row << "]["<<column <<"] =" << matrix[row][column]<<endl;

        if(column==0){
            row--;
            column=n;
        }
        column--;

    }
    return;
}



int main (void){
    int n;
    
    cin >> n;
    vector<vector<int>> mine= create_matrix(n);
    print_square_matrix(mine, n); //preguntar q imprimo en caso n=0

}
