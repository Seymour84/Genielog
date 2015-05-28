#include <iostream>

#include "OperationM.h"
#include "OperationC.h"

using namespace std;

int main(){
    int dim;
    cout<<"Dimension matrice:"<<endl;
    cin>>dim;
	OperationC c(dim);
    OperationC a(dim);

  	a=c.carre((c+c.transpo()));
	
a.ecriture();
cout << a <<endl;
    return 0;
}
