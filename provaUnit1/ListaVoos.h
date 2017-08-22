#include <iostream>
#include <string>

using namespace std;

class ListaVoos
{
private:
    unsigned int numero;
    Voo *v;
    void criar();
    void copiar(const Voo &v);
    void limpar();
public:
    ListaVoos();
    inline ListaVoos(const ListaVoos &lv) {copiar(lv);}
    inline ~ListaVoos() {limpar();}

    void inserir(const Voo &v);
    void imprimir() const;
    void imprimir(const string &s) const;
};
