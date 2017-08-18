#include <iostream>

class Ponto{
    private:
        double x,y;
    public:
        Ponto();
        Ponto(Ponto P);
        ~Ponto();

        friend istream &operator>>(istream &i, const Ponto &P);
        friend ostream &operator<<(ostream &i, const Ponto &P);
};
