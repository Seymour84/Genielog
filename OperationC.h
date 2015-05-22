#ifndef __operationC_h__
#define __operationC_h__


struct clematcreuse
{
    int x;
    int y;
};
    
class OperationC
{

    class compareClematcreuse
    {
    public:
        bool operator()(const clematcreuse &a, const clematcreuse &b)
        {
            if(a.x > b.x)
                return true;
            else if(a.x < b.x)
                return false;
            else if(a.y > b.y)
                return true;
            return false;
        };
    };

    std::map <clematcreuse, int, compareClematcreuse> matcreuse;
    friend std::ostream& operator << (std::ostream& O, OperationC& B);
    int dimension;
    std::string text;
    clematcreuse creer_clematcreuse(int, int);
public:
    OperationC();
    OperationC(int);
    OperationC(int,std::string);
    OperationC operator +(OperationC);
    OperationC operator -(OperationC);
    OperationC operator *(OperationC);
    void afficher();
};
#endif
