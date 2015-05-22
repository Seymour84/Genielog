#ifndef __operationM_h__
#define __operationM_h__

const int N=999;
class OperationM
{
    private:
    int dimension;
    friend std::ostream& operator << (std::ostream& O, OperationM& B);
    int mat[N][N];
    public:
    OperationM();
    OperationM(int);
    OperationM(int,std::string);
    OperationM operator +(OperationM);
    OperationM operator -(OperationM);
    OperationM operator *(OperationM);
    void afficher();
     void ecriture();
};

#endif
