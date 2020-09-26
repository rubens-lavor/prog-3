#ifndef Pilha_hpp
#define Pilha_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Celula *Apontador; //apontador refere-se a celula no main

struct TipoItem
{
    int Codigo;
    char Nome[10];
};

struct Celula 
{
    TipoItem Item;
    Apontador Prox;
};

struct TipoPilha
{
    Apontador Topo;
    Apontador Fundo;
    int tamanho;
};

void InicializaPilhaVazia(TipoPilha *Pilha);

int PilhaVazia(TipoPilha Pilha);

int Empilhar(TipoItem X, TipoPilha *Pilha);

int Desempilhar(TipoPilha *Pilha, TipoItem *Item);

int TamanhoPilha(TipoPilha *Pilha);

void imprime_Pilha(TipoPilha *Pilha, TipoItem *Item);

void destroi_Pilha (TipoPilha *Pilha, TipoItem *Item);
int Menu();

#endif