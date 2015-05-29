#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "OperationC.h"

using namespace std;

/**
        * \fn creer_clematcreuse
        * \param x Entier, première coordonée de l'adresse
        * \param y Entier, seconde coordonnée de l'adresse
        * \brief Crée matcreuse
*/


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
            int v;
            clematcreuse k;
            k.x = i;
            k.y = j;
            if (matr>>v) {
                if (v != 0) {
                    matcreuse[k] = v;
                }
            }
        }
    }
    matr.close();


}


OperationC::OperationC(int dim){
    dimension=dim;
    srand(time(NULL));
    int valeur=0;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            clematcreuse k;
            k.x = i;
            k.y = j;
            int v=rand()%10;
            int compteur=(dimension*dimension)*0.01;
            
            if(valeur==compteur)
            {
                if (v != 0) {
                    matcreuse[k] = v;
                    valeur=0;
                }
            }else{
                valeur++;
            }
        }
    }
}
/**
        * \fn afficher
        * \brief Affichage de la matrice
        *
    */

void OperationC::afficher(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            cout<<" "<<matcreuse[creer_clematcreuse(i, j)]<<" ";
        }
        cout<<endl;
    }
}

/**
        * \fn operator +
        * \param A 
        * \brief Surcharge de l'opérateur plus 
       *
    */
OperationC OperationC::operator +(OperationC A){
    OperationC X(dimension,text.c_str());

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.matcreuse[creer_clematcreuse(i, j)]=matcreuse[creer_clematcreuse(i, j)]+A.matcreuse[creer_clematcreuse(i, j)];
        }
    }
    return X;

}

/**
        * \fn operator -
        * \param A 
        * \brief Surchage de l'opérateur moins
        *
    */
OperationC OperationC::operator -(OperationC A){
    OperationC X(dimension,text.c_str());

     for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            X.matcreuse[creer_clematcreuse(i, j)]=matcreuse[creer_clematcreuse(i, j)]-A.matcreuse[creer_clematcreuse(i, j)];
        }
    }
    return X;

}

/**
        * \fn operator *
        * \param A 
        * \brief Surchage de l'opérateur multiplier
        *
    */

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

OperationC OperationC:: transpo()
{
	OperationC X(dimension);
	for (int i=0; i<dimension;i++)
	{
		for(int j=0; j<dimension;j++)
		{
			clematcreuse c;
			c.x=i;
			c.y=j;
			
			X.matcreuse[creer_clematcreuse(j,i)]=matcreuse[c];

			
		}	
	}
				
	return X;

}
OperationC OperationC:: carre(OperationC Y)
{
    OperationC X(dimension);
	
    
    X=Y*Y;
				
	return X;

}

/**
        * \fn operator<<
        * \param A 
        * \param out
        * \brief Surchage de sortie
        *
    */
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

/**
        * \fn ecriture
        * \brief Ecriture dans un fichier ( resultatMC.txt)
        *
    */
void OperationC:: ecriture()
{
	 ofstream fichier("resultatMC.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier)  // si l'ouverture a réussi
        {
            	for(int i=0;i<dimension;i++)
		{
		
        		for(int j=0;j<dimension;j++)
			{
			clematcreuse c;
            		c.x = i;
           		c.y = j;
             		
             		fichier<<" "<<matcreuse[c]<<" ";
        		}

			fichier<<endl;
   		 }
                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;
 





}

