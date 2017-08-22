#include <iostream>
#include <string>
using namespace std;

class Voo
{
private:
    unsigned int numero;
    string origem;
    string destino;
    unsigned int partida;
    unsigned int chegada;
public:
    Voo();
    Voo(const Voo &v);
    ~Voo();

    inline void setNumero(unsigned int n) {numero=n;}
    inline void setOrigem(const string &o) {origem=o;}
    inline void setDestino(const string &d) {destino=d;}
    inline void setPartida(unsigned int p) {partida=p;}
    inline void setChegada(unsigned int c) {chegada=c;}

    inline unsigned int getNumero() const {return numero;}
    inline string getOrigem() const {return origem;}
    inline string getDestino() const {return destino;}
    inline unsigned int getPartida() const {return partida;}
    inline unsigned int getChegada() const {return chegada;}

    friend istream &operator>>(istream &I, const Voo &v);
    friend ostream &operator<<(ostream &I, const Voo &v) const;
};
