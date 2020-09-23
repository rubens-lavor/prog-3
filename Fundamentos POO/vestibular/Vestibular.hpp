#ifndef Vestibular_hpp
#define Vestibular_hpp


class Vestibular
{
private:
    /* data */
    int contador_curso_11 = 0;
    int contador_curso_12 = 0;
    int contador_curso_13 = 0;
    int contador_curso_14 = 0;
    int contador_curso_15 = 0;
    int contador_curso_16 = 0;

    char vetor_de_busca[20000] = {}; //recebe todos os caracteres do arquivo
    int posicao = 0;                 //incrementa a cado novo caractere lido do arquivo

    int vetor_pos_contra_barra[827] = {}; //guarda a posição do todos os \n
    int cont = 0;                         //incrementa cada vez que um \n é lido do arquivo

public:
    Vestibular(/* args */);
    ~Vestibular();

    int numero_aleatorio(int max, int min);
    void criaLista();
    int busca_curso(char *vetor_de_busca, int pos_contra_barra);
    void inicializa_lista();
    bool valida_candidatos_por_vaga();
    void conta_candidatos_por_vaga();
    void imprime_candatos_por_vaga() const;
};

#endif
