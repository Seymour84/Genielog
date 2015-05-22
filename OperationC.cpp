#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "OperationC.h"

using namespace std;

clematcreuse OperationC::creer_clematcreuse(int x, int y)
{
	clematcreuse c;
	c.x = x;
	c.y = y;

	return c;
} 

OperationC::OperationC(){
    dimension=0;

}

OperationC::OperationC(int dim,string text){
    dimension=dim;
    this->text = text;
    ifstream matr(text.c_str());

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
        	clematcreuse k;
        	k.x = i;
        	k.y = j;
            matr>>matcreuse[k];
        }
    }
    matr.close();


}
OperationC::OperationC(int dim){
    dimension=dim;
    srand(time(NULL));

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
        	clematcreuse k;
        	k.x = i;
        	k.y = j;
           	matcreuse[k]=rand()%10;
        }
    }
}

void OperationC::afficher(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            cout<<" "<<matcreuse[creer_clematcreuse(i, j)]<<" ";
        }
        cout<<endl;
    }
}


OperationC OperationC::operator +(OperationC A){
    OperationC X(dimension,text.c_str());

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.matcreuse[creer_clematcreuse(i, j)]=matcreuse[creer_clematcreuse(i, j)]+A.matcreuse[creer_clematcreuse(i, j)];
        }
    }
    return X;

}
OperationC OperationC::operator -(OperationC A){
    OperationC X(dimension,text.c_str());

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.matcreuse[creer_clematcreuse(i, j)]=matcreuse[creer_clematcreuse(i, j)]-A.matcreuse[creer_clematcreuse(i, j)];
        }
    }
    return X;

}

OperationC OperationC::operator *(OperationC A){
    OperationC X(dimension,text.c_str());
    int k=0;
    X=X-X;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            k=0;
            while(k<dimension){
               X.matcreuse[creer_clematcreuse(i, j)]=X.matcreuse[creer_clematcreuse(i, j)]+(matcreuse[creer_clematcreuse(i, k)]*A.matcreuse[creer_clematcreuse(k, j)]);
               k++;
            }
        }
    }



    return X;


}


ostream& operator<<(ostream &out,OperationC& A)
{

  for(int i=0;i<A.dimension;i++){
        for(int j=0;j<A.dimension;j++){
        	clematcreuse c;
        	c.x = i;
        	c.y = j;
             out<<" "<<A.matcreuse[c]<<" ";
        }out<<endl;
    }
  return out;
}

