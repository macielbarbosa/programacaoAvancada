#include "loja_heranca.h"

istream Produto::digitar(istream &I)
{
    cout << "Nome do produto: ";
    I >> nome;
    cout << "Preco do produto: ";
    I >> preco;
}

ostream & Produto::imprimir(ostream &O)
{
    O << '"' << nome << "\";$" << preco/100 << '.' << preco%100;
}

istream & Produto::ler(istream &I)
{
    unsigned float aux;
    I.ignore(numeric_limits<streamsize>::max(),'"');
    getline(I,nome,'"');
    I.ignore(numeric_limits<streamsize>::max(),'$');
    I >> aux;
    preco = int(aux*1000);
}

istream Livro::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Autor do livro: ";
    I >> autor;
}

ostream & Livro::imprimir(ostream &O)
{
    Produto::imprimir(O);
    O << ";\"" << autor << '"';
}

istream & Livro::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),'"');
    getline(autor,'"');
}

istream CD::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Quantidade de faixas: ";
    I >> faixas;
}

ostream & CD::imprimir(ostream &O)
{
    Produto::imprimir(O);
    O << ";" << faixas;
}

istream & CD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> faixas;
}

istream DVD::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Duracao: ";
    I >> duracao;
}

ostream & DVD::imprimir(ostream &O)
{
    Produto::imprimir(O);
    O << ";" << duracao;
}

istream & DVD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> duracao;
}

ListaLivro::ListaLivro()
{

}

ListaLivro::~ListaLivro()
{

}

void ListaLivro::incluir(const Livro &L)
{

}

void ListaLivro::excluir(unsigned id)
{

}

void ListaLivro::imprimir()
{

}

void ListaLivro::ler(istream &I)
{

}

void ListaLivro::salvar(ostream &O)
{

}

ListaCD::ListaCD()
{

}

ListaCD::~ListaCD()
{

}

void ListaCD::incluir(const CD &c)
{

}

void ListaCD::excluir(unsigned id)
{

}

void ListaCD::imprimir()
{

}

void ListaCD::ler(istream &I)
{

}

void ListaCD::salvar(ostream &O)
{

}

ListaDVD::ListaDVD()
{

}

ListaDVD::~ListaDVD()
{

}

void ListaDVD::incluir(const DVD &d)
{

}

void ListaDVD::excluir(unsigned id)
{

}

void ListaDVD::imprimir()
{

}

void ListaDVD::ler(istream &I)
{

}

void ListaDVD::salvar(ostream &O)
{

}
