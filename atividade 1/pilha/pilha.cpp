#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Celula *Apontador;

typedef struct TipoItem
{
    int Codigo;
    char Nome[100];
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

void InicializaPilhaVazia(TipoPilha *Pilha)
{
    Pilha->Topo = (Apontador)malloc(sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->tamanho = 0;
}

int PilhaVazia(TipoPilha Pilha)
{
    return (Pilha.Topo == Pilha.Fundo);
}

int Empilhar(TipoItem X, TipoPilha *Pilha)
{

    if (Pilha == NULL)
    {
        cout << "ERRO Pilha não existe" << endl;
        return 0;
    }

    Apontador aux;
    aux = (Apontador)malloc(sizeof(Celula));

    if (aux == NULL)
    {
        cout << "ERRO Não foi possível alocar espaço na memória" << endl;
        return 0;
    }

    Pilha->Topo->Item = X;
    aux->Prox = Pilha->Topo;
    Pilha->Topo = aux;
    Pilha->tamanho++;

    return 1;
}

int Desempilhar(TipoPilha *Pilha, TipoItem *Item)
{
    if (Pilha == NULL)
    {
        cout << "\nERRO - Pilha não existe";
        return 0;
    }

    if (PilhaVazia(*Pilha))
    {
        cout << "\nERRO - Pilha está vazia!";
        Item->Codigo = -1;
        return 0;
    }

    Apontador Q;

    Q = Pilha->Topo;
    Pilha->Topo = Q->Prox;
    *Item = Pilha->Topo->Item;
    free(Q);
    Pilha->tamanho--;

    return 1;
}

int TamanhoPilha(TipoPilha *Pilha)
{
    if (Pilha == NULL)
        return 0;

    return Pilha->tamanho;
}

void libera_Pilha(TipoPilha *Pilha)
{
    if (Pilha != NULL)
    {
        Apontador no;

        while (Pilha != NULL)
        {
            no = Pilha->Topo;
            Pilha->Topo = Pilha->Topo->Prox;
            free(no);
        }
        free(Pilha);
    }
}



void imprime_Pilha(TipoPilha *Pilha, TipoItem *Item)
{
    if (Pilha == NULL)
    {
        cout << "\nERRO - Pilha não existe";
        return;
    }

    if (PilhaVazia(*Pilha))
    {
        cout << "\nPilha está vazia!";
        Item->Codigo = -1;
        return;
    }

    string nome;
    int cont = Pilha->tamanho;

    Apontador Q;
    Q = Pilha->Topo->Prox;

    cout << "Itens da Pilha: " << endl;
    while (cont > 0)
    {

        *Item = Q->Item;
        nome = Item->Nome;

        cout << " - " << nome;

        Q = Q->Prox;
        if (cont > 1)
        {
            *Item = Q->Item;
        }

        cont--;
    }

    free(Q);
}

void destroi_Pilha (TipoPilha *Pilha, TipoItem *Item){
    while (Pilha->Topo->Prox != NULL){
        Desempilhar(Pilha,Item); 
    }
}

int Menu()
{
    int Opcao = 5;
    do
    {

        cout << "\n\n 1 - Empilhar";
        cout << "\n 2 - Desempilhar";
        cout << "\n 3 - Verificar Tamanho da Pilha";
        cout << "\n 4 - Imprimir Itens da Pilha";
        cout << "\n 0 - Sair\n\n";

        cout << "Escolha uma opção: ";

        setbuf(stdin, NULL);
        cin >> Opcao;

    } while ((Opcao < 0) || (Opcao > 4));

    return Opcao;
}

int main()
{

    TipoPilha Pilha; /*Cria uma pilha*/
    TipoItem aux;
    int Opcao;

    InicializaPilhaVazia(&Pilha);

    Opcao = Menu();

    while (Opcao != 0)
    {
        switch (Opcao)
        {
        case 1:
            //cout << "Inserir Item";
            aux.Codigo = 1;
            cout << "\n\nDigite um elemento para ser inserido: ";

            setbuf(stdin, NULL);
            fgets(aux.Nome, 100, stdin);

            if (Empilhar(aux, &Pilha))
            {
                cout << "Elemento inserido" << endl;
            }
            else
            {
                cout << "ERRO" << endl;
            }

            break;

        case 2:
            if (Desempilhar(&Pilha, &aux))
            {
                cout << "Item foi removido da Pilha";
            }

            break;

        case 3:
            cout << "Quantidades de itens na pilha: " << TamanhoPilha(&Pilha);
            break;

        case 4:
            //cout << "\n\nconsulta\n\n";
            imprime_Pilha(&Pilha, &aux);
            break;

        default:
            break;
        }
        Opcao = Menu();
    }

    destroi_Pilha(&Pilha,&aux);
    return 0;
}

/*
implementação de pilha dinâmica

o espaço de memória é alocado em tempo de execução

a pilha cresce a medida que os elementos dão inseridos, e diminue a medida que são removidos

*/
