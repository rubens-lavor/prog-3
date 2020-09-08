#ifndef Pilha_hpp
#define Pilha_hpp

typedef struct Celula *Apontador; //apontador refere-se a celula no main

typedef struct TipoItem
{
    int Codigo;
    char Nome[10];
};

typedef struct Celula 
{
    TipoItem Item;
    Apontador Prox;
};

typedef struct TipoPilha
{
    Apontador Topo;
    Apontador Fundo;
    int tamanho;
};



#endif