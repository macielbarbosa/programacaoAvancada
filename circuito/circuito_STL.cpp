#include "circuito_STL.h"
#include <vector>

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
  for(unsigned i=0; i<Nportas; i++){
    ptr_Porta paux;
    *paux = *(C.portas[i]);
    portas.push_back(paux);
  }
}

void Circuito::alocar(unsigned NI, unsigned NO, unsigned NP){
  return;
}

void Circuito::limpar(){
  Nin = 0;
  Nout = 0;
  Nportas = 0;
  inputs.clear();
  id_out.clear();
  portas.clear();
}

void Circuito::digitar(){
  cout << "Número de entradas: ";
  cin >> Nin;
  digitarEntradas();
  cout << "Número de saidas: ";
  cin >> Nout;
  digitarSaidas();
  cout << "Número de portas: ";
  cin >> Nportas;
  digitarPortas();
}

void Circuito::digitarEntradas(){
  bool_3S b3s;
  string aux;
  for(unsigned i=0; i<Nin; i++){
    cout << "Entrada " << i+1 << " por extenso (capslock): ";
    cin >> aux;
    if(aux=="FALSE_3S")
      b3s = FALSE_3S;
    else if(aux=="TRUE_3S")
      b3s = TRUE_3S;
    else if(aux=="UNDEF_3S")
      b3s = UNDEF_3S;
    inputs.push_back(b3s);
  }
}

void Circuito::digitarSaidas(){
  int saida_aux;
  for(unsigned i=0; i<Nout; i++){
    cout << "ID da saida " << i+1 << " : ";
    cin >> saida_aux;
    id_out.push_back(saida_aux);
  }
}

void Circuito::digitarPortas(){
  string str;
  for(unsigned i=0; i<Nportas; i++){
    cout << "Tipo de porta " << i+1 << " (Capslock): ";
    cin >> str;
    if(str=="NOT"){
      ptr_Porta paux;
      *paux = Porta_NOT();
      paux->digitar();
      portas.push_back(paux);
    }
    else if(str=="AND"){
      ptr_Porta paux;
      *paux = Porta_AND();
      paux->digitar();
      portas.push_back(paux);
    }
    else if(str=="NAND"){
      ptr_Porta paux;
      *paux = Porta_NAND();
      paux->digitar();
      portas.push_back(paux);
    }
    else if(str=="OR"){
      ptr_Porta paux;
      *paux = Porta_OR();
      paux->digitar();
      portas.push_back(paux);
    }
    else if(str=="NOR"){
      ptr_Porta paux;
      *paux = Porta_NOR();
      paux->digitar();
      portas.push_back(paux);
    }
    else if(str=="XOR"){
      ptr_Porta paux;
      *paux = Porta_XOR();
      paux->digitar();
      portas.push_back(paux);
      break;
    }
    else if(str=="NXOR"){
      ptr_Porta paux;
      *paux = Porta_NXOR();
      paux->digitar();
      portas.push_back(paux);
    }
  }
}

void Circuito::ler(const char *c){
  int id;
  this->~Circuito();
  ifstream arq(c);
  string str_aux;
  if(arq.is_open()){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(arq, str_aux, ':');
    if(str_aux!="CIRCUITO"){
        cerr << "Formato de arquivo nao aceito" << endl;
        return;
    }
    arq >> Nin >> Nout >> Nportas;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    arq >> id;
  }
  else{
    cerr << "Erro na abertura do arquivo" << endl;
  }
}
