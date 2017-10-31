#include "circuito_STL.h"

Porta::Porta(unsigned NI){
  Nin = NI;
  saida = UNDEF_3S;
}

Porta::Porta(const Porta &P){
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




void Circuito::copiar(const Circuito &C){
  Nin = C.Nin;
  Nout = C.Nout;
  Nportas = C.Nportas;
  inputs = C.inputs;
  id_out = C.id_out;
  portas = C.portas;
}

void Circuito::limpar(){
  Nin = 0;
  Nout = 0;
  Nportas = 0;
  inputs.erase();
  id_out.erase();
  portas.erase();
}

void Circuito::digitar(){
  string str;
  cout << "Número de entradas: ";
  cin >> Nin;
  cout << "Número de saidas: ";
  cin >> Nout;
  cout << "Número de portas: ";
  cin >> NPortas;
  for(unsigned i=0; i<Nportas; i++){
    cout << "Tipo de porta(Capslock): "
    cin >> str;
    switch (str){
    case 'NOT':
      break;
    }
    case 'AND':
      break;
    }
    case 'NAND':
      break;
    }
    case 'OR':
      break;
    }
    case 'NOR':
      break;
    }
    case 'XOR':
      break;
    }
    case 'NXOR':
      break;
    }
  }
}
