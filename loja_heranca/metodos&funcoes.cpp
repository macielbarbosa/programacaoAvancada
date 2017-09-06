#include "loja_heranca.h"

istream & Produto::digitar(istream &I)
{
    cout << "Nome do produto: ";
    I >> nome;
    do
    {
        cout << "Preco do produto: ";
        I >> preco;
        if(preco<0)
            cout << "Insira o preco positivo" << endl;
    }
    while(preco<0);
}

ostream & Produto::imprimir(ostream &O) const
{
    O << '"' << nome << "\";$" << preco/100 << '.' << preco%100;
    return O;
}

istream & Produto::ler(istream &I)
{
    float aux;
    I.ignore(numeric_limits<streamsize>::max(),'"');
    getline(I,nome,'"');
    I.ignore(numeric_limits<streamsize>::max(),'$');
    I >> aux;
    preco = (int)aux*1000;
    return I;
}

istream & Livro::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Autor do livro: ";
    I >> autor;
}

ostream & Livro::imprimir(ostream &O) const
{
    Produto::imprimir(O);
    O << ";\"" << autor << '"';
    return O;
}

istream & Livro::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),'"');
    getline(I,autor,'"');
    return I;
}

istream & CD::digitar(istream &I)
{
    Produto::digitar(I);
    do
    {
        cout << "Quantidade de faixas: ";
        I >> faixas;
        if(faixas<=0)
            cout << "Insira a quantidade de faixas maior que zero" << endl;
    }
    while(faixas<=0);
}

ostream & CD::imprimir(ostream &O) const
{
    Produto::imprimir(O);
    O << ";" << faixas;
    return O;
}

istream & CD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> faixas;
    return I;
}

istream & DVD::digitar(istream &I)
{
    Produto::digitar(I);
    do
    {
        cout << "Duracao: ";
        I >> duracao;
        if(duracao<=0)
            cout << "Insira a duracao maior que zero" << endl;
    }
    while(duracao<=0);
}

ostream & DVD::imprimir(ostream &O) const
{
    Produto::imprimir(O);
    O << ";" << duracao;
    return O;
}

istream & DVD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> duracao;
    return I;
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
            aux[i]=x[i+1];
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaLivro::imprimir(void) const
{
    cout << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") L: ";
        x[i].imprimir(cout);
        cout << endl;
    }
}

void ListaLivro::ler(istream &I)
{
    string str;
    I >> str;
    if(str!="LISTALIVRO"){
        cerr << "Nao eh uma lista de livros" << endl;
        return;
    }
    I >> N;
    for(unsigned i=0; i<N; i++)
        x[i].ler(I);
}

void ListaLivro::salvar(ostream &O) const
{
    O << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++){
        x[i].salvar(O);
    }
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
            aux[i]=x[i+1];
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaCD::imprimir(void) const
{
    cout << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") C: ";
        x[i].imprimir(cout);
        cout << endl;
    }
}

void ListaCD::ler(istream &I)
{
    string str;
    I >> str;
    if(str!="LISTACD"){
        cerr << "Nao eh uma lista de livros" << endl;
        return;
    }
    I >> N;
    for(unsigned i=0; i<N; i++)
        x[i].ler(I);
}

void ListaCD::salvar(ostream &O) const
{
    O << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++){
        x[i].salvar(O);
    }
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
            aux[i]=x[i+1];
    }
    N--;
    delete[] x;
    x = aux;
}

void ListaDVD::imprimir(void) const
{
    cout << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++)
    {
        cout << i << ") D: ";
        x[i].imprimir(cout);
        cout << endl;
    }
}

void ListaDVD::ler(istream &I)
{
    string str;
    I >> str;
    if(str!="LISTADVD"){
        cerr << "Nao eh uma lista de livros" << endl;
        return;
    }
    I >> N;
    for(unsigned i=0; i<N; i++)
        x[i].ler(I);
}

void ListaDVD::salvar(ostream &O) const
{
    O << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++){
        x[i].salvar(O);
    }
}

void Loja::ler(const char* arq)
{
    ifstream arquivo(arq);
    if(!arquivo.is_open())
    {
        cerr << "Erro na leitura do arquivo" << endl;
        return;
    }
    LL.ler(arquivo);
    LC.ler(arquivo);
    LD.ler(arquivo);
}

void Loja::salvar(const char* arq) const
{
    ofstream arquivo(arq);
    if(!arquivo.is_open())
    {
        cerr << "Erro na leitura do arquivo" << endl;
        return;
    }
    LL.salvar(arquivo);
    LC.salvar(arquivo);
    LD.salvar(arquivo);
}
