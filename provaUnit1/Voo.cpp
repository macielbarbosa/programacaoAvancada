#include "Voo.h"

Voo(){
    numero = NULL;
    origem = "indefinido";
    destino = "indefinido";
    partida = NULL;
    chegada = NULL;
}

Voo(const Voo &v){
    numero = v.numero;
    origem = v.origem;
    destino = v.destino;
    partida = v.partida;
    chegada = v.chegada;
}

~Voo(){
    numero = NULL;
    origem = " ";
    destino = " ";
    partida = NULL;
    chegada = NULL;
}

istream &operator>>(istream &I, const Voo &v){
    cout << "Numero de voo: ";
    I >> v.numero;
    cout << endl <<"Aeroporto de origem: ";
    I >> v.origem;
    cout << endl <<"Aeroporto de destino: ";
    I >> v.destino;
    cout << endl <<"Hora da partida: ";
    I >> v.partida;
    cout << endl <<"Hora da chegada: ";
    I >> v.chegada;

    return I;
}

ostream &operator<<(ostream &I, const Voo &v){
    cout << "Numero de voo: ";
    I >> v.numero;
    cout << endl <<"Aeroporto de origem: ";
    I >> v.origem;
    cout << endl <<"Aeroporto de destino: ";
    I >> v.destino;
    cout << endl <<"Hora da partida: ";
    I >> v.partida;
    cout << endl <<"Hora da chegada: ";
    I >> v.chegada;
}
