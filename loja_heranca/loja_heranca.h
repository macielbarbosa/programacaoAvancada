#ifndef _LOJA_HERANCA_
#define _LOJA_HERANCA_

#include <iostream>
#include <string>

using namespace std;


class Produto
{
private:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, Produto &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, const Produto &X) {return X.imprimir(O);}


class Livro: public Produto
{
private:
    string autor;
public:
    inline Livro(const char *N="", unsigned P=0, const char *A=""): Produto(N,P), autor(A) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, Livro &L) {return L.digitar(I);}
inline ostream &operator<<(ostream &O, const Livro &L) {return L.imprimir(O);}


class CD: public Produto
{
private:
    unsigned int faixas;
public:
    inline CD(const char *N="", unsigned P=0, unsigned int f=0): Produto(N,P), faixas(f) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, CD &c) {return c.digitar(I);}
inline ostream &operator<<(ostream &O, const CD &c) {return c.imprimir(O);}


class DVD: public Produto
{
private:
    unsigned int duracao;
public:
    inline DVD(char *N="", unsigned P=0, unsigned int d=0): Produto(N,P), duracao(0) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};
inline istream &operator>>(istream &I, DVD &d) {return d.digitar(I);}
inline ostream &operator<<(ostream &O, const DVD &d) {return d.imprimir(O);}


class ListaLivro
{
private:
    Livro *x;
    unsigned N;
public:
    inline ListaLivro(){x=NULL; N=0};
    inline ~ListaLivro(){if(N!=0) delete[] x;}
    void incluir(const Livro &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};


class ListaCD
{
private:
    CD *x;
    unsigned N;
public:
    inline ListaCD(){x=NULL; N=0};
    inline ~ListaCD(){if(N!=0) delete[] x;}
    void incluir(const CD &c);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};


class ListaDVD
{
private:
    DVD *x;
    unsigned N;
public:
    inline ListaDVD(){x=NULL; N=0};
    inline ~ListaDVD(){if(N!=0) delete[] x;}
    void incluir(const DVD &d);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};


class Loja
{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned id) {LC.excluir(id);}
    inline void imprimir() const {LL.imprimir(); LC.imprimir(); LD.imprimir();}
    void ler(const char* arq);
    void salvar(const char* arq) const;
};
#endif // _LOJA_H_
