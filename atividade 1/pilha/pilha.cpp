#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct Celula *Apontador;

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

void InicializaPilhaVazia (TipoPilha *Pilha){
    Pilha->Topo = (Apontador) malloc(sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->tamanho = 0;
}

int PilhaVazia (TipoPilha Pilha) {
    return (Pilha.Topo == Pilha.Fundo);
}

void Empilhar (TipoItem X, TipoPilha *Pilha) {
    Apontador aux;

    aux = (Apontador)malloc(sizeof(Celula));

    Pilha->Topo->Item = X;
    aux->Prox = Pilha->Topo;
    Pilha->Topo = aux;
    Pilha->tamanho++;
}

void Desempilhar (TipoPilha *Pilha, TipoItem *Item) {
    Apontador Q;

    if (PilhaVazia (*Pilha)) {
        cout << "\nERRO - Pilha está vazia!";
        Item->Codigo = -1;
        
    }else
    {
        Q = Pilha->Topo;
        Pilha->Topo = Q->Prox;
        *Item = Pilha->Topo->Item;
        free(Q);
        Pilha->tamanho--;
    }
    
}

int TamanhoPilha (TipoPilha Pilha) {
    return Pilha.tamanho;
}

int Menu() {
    int Opcao = 5;
    do
    {
        
        cout << "\n\n 1 - Empilhar";
        cout << "\n 2 - Desempilhar";
        cout << "\n 3 - Verificar Tamanho da Pilha";
        cout << "\n 0 - Sair\n\n";

        cout << "Escolha uma opção: ";

        setbuf(stdin,NULL);
        cin >> Opcao;
        
    } while ((Opcao < 0) || (Opcao > 3));

    return Opcao;
    
}

int main (){
    TipoPilha Pilha; /*Cria uma pilha*/
    TipoItem aux;
    int Opcao; 


    InicializaPilhaVazia(&Pilha);

    Opcao = Menu();

    while (Opcao !=0)
    {
        switch (Opcao)
        {
        case 1:
            //cout << "Inserir Item";
            aux.Codigo = 1;
            cout << "\n\nDigite um elemento para ser inserido: ";

            setbuf(stdin,NULL);
            fgets(aux.Nome,10,stdin);

            Empilhar(aux,&Pilha);
            break;
        case 2:
            //cout << "\n\nExcluir Item\n";
            Desempilhar(&Pilha, &aux);

            if (aux.Codigo != -1) {
                cout << "\n\nO item foi removido da Pilha";
            }
        
            break;

        case 3:
            cout << "\n\nQuantidades de itens na pilha: "<< TamanhoPilha(Pilha);
            break;
        
        default:
            break;
        }
        Opcao = Menu();
    }

    cout << "Saiu" << endl;
    return 0;
    
}


/*
implementação de pilha dinâmica

a pilha cresce a medida que os elementos dão inseridos, e diminue a medida que são removidos

*/


