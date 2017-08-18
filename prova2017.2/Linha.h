#include <iostream>

class Linha{
    private:
        unsigned n;
        Ponto *p;
        void criar();
        void copiar(Linha L);
        void limpar();
    public:
        inline Linha() {criar();};
        inline Linha(Linha) {copiar(L);};
        inline ~Ponto() {limpar();};

        friend istream &operator>>(istream &i, const Linha &L);
        friend ostream &operator<<(ostream &i, const Linha &L);

        void adicionar(const Ponto &P);
};
