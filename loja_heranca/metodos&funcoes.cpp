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

void ListaLivro::incluir(const Livro &L)
{
    Livro *aux = new Livro[N+1];
    for(unsigned i=0; i<N; i++) aux[i]=x[i];
    aux[N] = L;
    N++;
    delete[] x;
    x = aux;
}

void ListaLivro::excluir(unsigned id)
{
    if(id>=N)
    {
        cerr << "id nao existe";
        return;
    }
    Livro *aux = new Livro[N-1];
    for(unsigned i=0; i<(N-1); i++)
    {
        if(i<id)
            aux[i]=x[i];
        else
            aux[i]=x[i+1]
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaLivro::imprimir()
{
    cout << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") L: ";
        cout << Livro[i] << endl;
    }
}

void ListaLivro::ler(istream &I)
{
    cout << "Tamanho da lista de livros: ";
    cin >> N;
    for(unsigned i=0; i<N; i++)
    {
        cin >> Livro[i];
    }
}

void ListaLivro::salvar(ostream &O)
{

}

void ListaCD::incluir(const CD &c)
{
    CD *aux = new CD[N+1];
    for(unsigned i=0; i<N; i++) aux[i]=x[i];
    aux[N] = c;
    N++;
    delete[] x;
    x = aux;
}

void ListaCD::excluir(unsigned id)
{
    if(id>=N)
    {
        cerr << "id nao existe";
        return;
    }
    CD *aux = new CD[N-1];
    for(unsigned i=0; i<(N-1); i++)
    {
        if(i<id)
            aux[i]=x[i];
        else
            aux[i]=x[i+1]
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaCD::imprimir()
{
    cout << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") C: ";
        cout << CD[i] << endl;
    }
}

void ListaCD::ler(istream &I)
{
    cout << "Tamanho da lista de CDs: ";
    cin >> N;
    for(unsigned i=0; i<N; i++)
    {
        cin >> CD[i];
    }
}

void ListaCD::salvar(ostream &O)
{

}

void ListaDVD::incluir(const DVD &d)
{
    DVD *aux = new DVD[N+1];
    for(unsigned i=0; i<N; i++) aux[i]=x[i];
    aux[N] = d;
    N++;
    delete[] x;
    x = aux;
}

void ListaDVD::excluir(unsigned id)
{
    if(id>=N)
    {
        cerr << "id nao existe";
        return;
    }
    DVD *aux = new DVD[N-1];
    for(unsigned i=0; i<(N-1); i++)
    {
        if(i<id)
            aux[i]=x[i];
        else
            aux[i]=x[i+1]
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaDVD::imprimir()
{
    cout << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") D: ";
        cout << DVD[i] << endl;
    }
}

void ListaDVD::ler(istream &I)
{
    cout << "Tamanho da lista de DVDs: ";
    cin >> N;
    for(unsigned i=0; i<N; i++)
    {
        cin >> DVD[i];
    }
}

void ListaDVD::salvar(ostream &O)
{

}
