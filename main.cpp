#include <iostream>

#include "OperationM.cpp"

using namespace std;

int main(){
    int dim;
    cout<<"Dimension matrice:"<<endl;
    cin>>dim;
    matrice a(dim, "matrice.txt");


    cout << a << endl;
    return 0;
}