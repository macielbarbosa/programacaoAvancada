#include "circuito_STL.h"

Porta::Porta(unsigned NI){
  Nin = NI;
  saida = UNDEF_3S;
  id_in[0] = 1;
  id_in[1] = 2;
  id_in[2] = 3;
  id_in[3] = 4;
}

Porta::Porta(const &Porta &P){
  Nin = P.Nin;
  for(unsigned i=0; i<Nin; i++){
    id_in[i] = P.id_in[i];
  }
  saida = P.saida;
}

void Porta::setSaida(bool_3S s){
  saida = s;
}

int Porta::getId_in(unsigned i) const{
  return id_in[i];
}

void Porta::setId_in(unsigned i, int N){
  id_in[i] = N;
}
