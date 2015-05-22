

const int N=1;
class matrice{
    private:
    int dimension;
    friend ostream& operator << (ostream& O, matrice& B);
    int mat[N][N];
    public:
    matrice();
    matrice(int);
    matrice(int,string);
    ~matrice();
    matrice operator +(matrice);
    matrice operator -(matrice);
    matrice operator *(matrice);
    void afficher();
};
