#ifndef __operationM_h__
#define __operationM_h__

const int N=999;
class matrice
{
    private:
    int dimension;
    friend std::ostream& operator << (std::ostream& O, matrice& B);
    int mat[N][N];
    public:
    matrice();
    matrice(int);
    matrice(int,std::string);
    ~matrice();
    matrice operator +(matrice);
    matrice operator -(matrice);
    matrice operator *(matrice);
    void afficher();
};

#endif
