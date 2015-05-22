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
	OperationC b(dim);
	OperationC d(dim);
	cout<< c <<endl;
	a=c.transpo();
	cout<< a <<endl;
  	b=(c*a);
	d=b*b;
d.ecriture();
cout << d <<endl;
    return 0;
}
