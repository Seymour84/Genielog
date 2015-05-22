#include <iostream>

#include "OperationM.h"
#include "OperationC.h"

using namespace std;

int main(){
    int dim;
    cout<<"Dimension matrice:"<<endl;
    cin>>dim;
    OperationC a(dim, "matrice.txt");


    cout << a << endl;
    return 0;
}