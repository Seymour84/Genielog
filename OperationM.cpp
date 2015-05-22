#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "OperationM.h"

using namespace std;

matrice::matrice(){
    dimension=0;

}

matrice::matrice(int dim,string text){
    dimension=dim;
    ifstream matr(text.c_str());

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            matr>>mat[i][j];
        }
    }
    matr.close();


}
matrice::matrice(int dim){
    dimension=dim;
    srand(time(NULL));

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            mat[i][j]=rand()%10;
        }
    }
}

void matrice::afficher(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            cout<<" "<<mat[i][j]<<" ";
        }cout<<endl;
    }
}


matrice matrice::operator +(matrice A){
    matrice X(dimension,"matrice.txt");

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.mat[i][j]=mat[i][j]+A.mat[i][j];
        }
    }
    return X;

}
matrice matrice::operator -(matrice A){
    matrice X(dimension,"matrice.txt");

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.mat[i][j]=mat[i][j]-A.mat[i][j];
        }
    }
    return X;

}

matrice matrice::operator *(matrice A){
    matrice X(dimension,"matrice.txt");
    int k=0;
    X=X-X;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            k=0;
            while(k<dimension){
               X.mat[i][j]=X.mat[i][j]+(mat[i][k]*A.mat[k][j]);
               k++;
            }
        }
    }



    return X;


}


ostream& operator<<(ostream &out,matrice& A)
{

  for(int i=0;i<A.dimension;i++){
        for(int j=0;j<A.dimension;j++){
             out<<" "<<A.mat[i][j]<<" ";
        }out<<endl;
    }
  return out;
}

