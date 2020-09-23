#ifndef Resultado_vestibular_hpp
#define Resultado_vestibular_hpp

#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>

class Resultado_vestibular
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

    //vetor_curso armazena as informaçoes dos inscritos do respectivo curso
    int vetor_curso_11[230 * 4] = {}; //cada curso consegue ter no máximo 226 inscritos * 4 pois cada aluno gera 4 numeros
    int vetor_curso_12[230 * 4] = {};
    int vetor_curso_13[230 * 4] = {};
    int vetor_curso_14[230 * 4] = {};
    int vetor_curso_15[230 * 4] = {};
    int vetor_curso_16[230 * 4] = {};

public:
    Resultado_vestibular(/* args */);
    ~Resultado_vestibular();

    int busca_curso(char *vetor_de_busca, int pos_contra_barra);
    int busca_numero(char *vetor_de_busca, int pos_contra_barra, int qtde_pos, int pos_inicio);

    void insere_no_vetor_do_curso(int *vetor_curso, char *vetor_de_busca, int pos_contra_barra, int i);
    void ordena(int *vet, int inscritos);
    void imprime_resultado(int *vetor_curso, int contador_curso);

    void inicializa_resultado();
    void mostra_aprovados();

};

#endif