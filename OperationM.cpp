#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "OperationM.h"

using namespace std;

OperationM::OperationM(){
    dimension=0;

}

OperationM::OperationM(int dim,string text){
    dimension=dim;
    ifstream matr(text.c_str());

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            matr>>mat[i][j];
        }
    }
    matr.close();


}
OperationM::OperationM(int dim){
    dimension=dim;
    srand(time(NULL));

    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            mat[i][j]=rand()%10;
        }
    }
}

/*!
        * \fn afficher
        * \brief Affichage de la matrice
        
*/
void OperationM::afficher(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            cout<<" "<<mat[i][j]<<" ";
        }cout<<endl;
    }
}

/*!
        * \fn operator +
        * \param A 
        * \brief Surcharge de l'opérateur plus 
       
*/

OperationM OperationM::operator +(OperationM A){
    OperationM X(dimension,"OperationM.txt");

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.mat[i][j]=mat[i][j]+A.mat[i][j];
        }
    }
    return X;

}

/*!
        * \fn operator -
        * \param A 
        * \brief Surchage de l'opérateur moins
        
*/
OperationM OperationM::operator -(OperationM A){
    OperationM X(dimension,"OperationM.txt");

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.mat[i][j]=mat[i][j]-A.mat[i][j];
        }
    }
    return X;

}
/*!
        * \fn operator *
        * \param A 
        * \brief Surchage de l'opérateur multiplier
        
*/
OperationM OperationM::operator *(OperationM A){
    OperationM X(dimension,"OperationM.txt");
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
/*!
        * \fn operator<<
        * \param A 
        * \param out
        * \brief Surchage de sortie
        
*/

ostream& operator<<(ostream &out,OperationM& A)
{

  for(int i=0;i<A.dimension;i++){
        for(int j=0;j<A.dimension;j++){
             out<<" "<<A.mat[i][j]<<" ";
        }out<<endl;
    }
  return out;
}
/*!
        * \fn ecriture
        * \brief Ecriture dans un fichier ( resultat.txt)
        
*/

void OperationM:: ecriture()
{
	 ofstream fichier("resultat.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier)  // si l'ouverture a réussi
        {
            	for(int i=0;i<dimension;i++)
		{
		
        		for(int j=0;j<dimension;j++)
			{
             		fichier<<" "<<mat[i][j]<<" ";
        		}

			fichier<<endl;
   		 }
                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;
 





}
