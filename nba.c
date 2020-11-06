#ifndef nba_stats

#define nba_stats

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definição da estrutura de estatísticas de cestas e arremessos
 */
typedef struct {
    int cestas;
    int arremessos;
    float percentual;
} arremessos_t;

/**
 * Definição da estrutura de informações de jogador
 */
typedef struct {
    char nome[128];   // Nome
    int idade;        // Idade
    char time[16];    // Sigla do time
    char posicao[8];  // Sigla da posição
    int jogos;        // Número de jogos
    int minutos;      // Número de minutos jogados
    int pontos;       // Total de pontos feitos

    arremessos_t a2;  // Estatísticas de arremessos de 2 pontos
    arremessos_t a3;  // Estatísticas de arremessos de 3 pontos
    arremessos_t aT;  // Estatística combinada de arremessos de 2 e 3 pontos
    arremessos_t aL;  // Estatísticas de arremessos livres (lances livres)
} jogador_t;

/******************************/
/* Leitura do arquivo																	*/
/******************************/

/**
 * @brief 	Leitura do cabeçario do arquivo
 * @details Lê o cabeçario de arquivo, ou seja, o número inteiro que especifica o número
 * 			de jogadores total que é armazenado no arquivo
 * 
 * @param nome 	Uma string contendo o nome do arquivo
 * @return 		Retorna -1 se a string for nula; 0 se o arquivo não existe; O número de 
 * 				jogadores contindo no arquivo, se conseguir fazer a leitura
 */
int le_cabecario(char *nome) {
    if (nome == NULL) {
        return -1;
    }

    FILE *pont = fopen(nome, "r");

    if (pont == NULL) {
        return 0;
    }

    /*ler a quantidde de jogadores*/
}

/**
 * @brief   Faz a leitura dos jogadores armazenados no arquivo
 * @details Lê os jogadores armazenados no arquivo. A função cria um vetor do dinâmico
 *          onde os jogadores lidos são armazenados. Ao final, o ponteiro deste vetor
 *          é retornado pela função
 * 
 * @param nome  	 O nome do arquivo a partir de onde a leitura deve ser feita
 * @param njogadores Parâmetro passado por referência para armazenar o número de jogadores
 * 
 * @return 			 Se nome ou njogadores forem nulos, a função irá retornar NULL. Se o 
 * 					 nome do arquivo é válido, mas o arquivo não existe, a função retorna 
 * 					 NULL. A função retorna um vetor alocado dinamicamente que contém as 
 * 					 informações dos jogadores, lidas do arquivo e seta njogadores
 */
jogador_t *le_jogadores(char *nome, int *njogadores) {
    if (njogadores == NULL || nome == NULL) {
        return NULL;
    }

    FILE *ptr;

    ptr = abre_nome(nome);

    if (ptr == NULL) return NULL;

    double *armazena, aux;

    *njogadores = 0;

    if (fscanf(ptr, "%lf", &aux) == EOF) {
        fclose(ptr);
        return NULL;
    }

    rewind(ptr);

    fscanf(ptr, "%lf", &aux);

    while (!feof(ptr)) {
        *njogadores += 1;
        fscanf(ptr, "%lf", &aux);
    }

    armazena = (double *)malloc(sizeof(double) * *njogadores);

    if (armazena == NULL) return NULL;

    rewind(ptr);

    for (int i = 0; i < *njogadores; i++) {
        fscanf(ptr, "%lf", &aux);
        armazena[i] = aux;
    }

    return armazena;
}

/******************************/
/* Estatísticas de Jogadores (statj)													*/
/******************************/

/**
 * @brief   Estatísticas referentes ao maior número de arremessos
 * @details Esta função retorna o índice do jogador que possui o maior número de 
 *          arremessos de um determinado tipo
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de arremesso ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar arremessos de 2 pontos (a2)
 * 					 '3' : considerar arremessos de 3 pontos (a3)     
 * 					 'T' : considerar os valores totais      (aT)
 * 					 'L' : considerar lances livres          (aL)
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador que mais fez arremessos do tipo
 * 					 especificado, se os parâmetros estiverem corretamente especificados. 
 * 					 Caso haja empates, retorna o menor índice que satisfaz a condição.
 */
int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_mais_arremessos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_mais_arremessos = jogadores[0].a2.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].a2.arremessos) {
                    statj_mais_arremessos = jogadores[i].a2.arremessos;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_mais_arremessos = jogadores[0].a3.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].a3.arremessos) {
                    statj_mais_arremessos = jogadores[i].a3.arremessos;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_mais_arremessos = jogadores[0].aT.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].aT.arremessos) {
                    statj_mais_arremessos = jogadores[i].aT.arremessos;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_mais_arremessos = jogadores[0].aL.arremessos;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_arremessos < jogadores[i].aL.arremessos) {
                    statj_mais_arremessos = jogadores[i].aL.arremessos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes ao maior número de cestas
 * @details Esta função retorna o índice do jogador que possui o maior número de 
 *          cestas de um determinado tipo
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de cestas ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar cestas de 2 pontos     (a2)
 * 					 '3' : considerar cestas de 3 pontos     (a3)     
 * 					 'T' : considerar os valores totais      (aT)
 * 					 'L' : considerar lances livres          (aL)
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador que mais fez cestas (tipo) se 
 * 					 os parâmetros estiverem corretamente especificados. Caso haja empa-
 * 					 tes, retorna o menor índice que satisfaz a condição.
 */
int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_mais_cestas = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_mais_cestas = jogadores[0].a2.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].a2.cestas) {
                    statj_mais_cestas = jogadores[i].a2.cestas;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_mais_cestas = jogadores[0].a3.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].a3.cestas) {
                    statj_mais_cestas = jogadores[i].a3.cestas;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_mais_cestas = jogadores[0].aT.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].aT.cestas) {
                    statj_mais_cestas = jogadores[i].aT.cestas;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_mais_cestas = jogadores[0].aL.cestas;

            for (i = 1; i < njogadores; i++) {
                if (statj_mais_cestas < jogadores[i].aL.cestas) {
                    statj_mais_cestas = jogadores[i].aL.cestas;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes ao melhor percentual de cestas/arremessos
 * @details Esta função retorna o índice do jogador que possui o melhor percentual
 * 			cestas/arremessos
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de percentual ao qual a estatística se refere, conforme abaixo:
 * 					 '2' : considerar percentual de 2 pontos      (a2)
 * 					 '3' : considerar percentual de 3 pontos      (a3)     
 * 					 'T' : considerar percentual total            (aT)
 * 					 'L' : considerar percentual de lances livres (aL)
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador com melhor percentual (tipo) se 
 * 					 os parâmetros estiverem corretamente especificados. Caso haja empa-
 * 					 tes, retorna o menor índice que satisfaz a condição.
 */
int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo) {
    float statj_melhor_percentual = 0.0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '2':
            statj_melhor_percentual = jogadores[0].a2.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].a2.percentual) {
                    statj_melhor_percentual = jogadores[i].a2.percentual;
                    indice = i;
                }
            }

            break;

        case '3':
            statj_melhor_percentual = jogadores[0].a3.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].a3.percentual) {
                    statj_melhor_percentual = jogadores[i].a3.percentual;
                    indice = i;
                }
            }
            break;

        case 'T':
            statj_melhor_percentual = jogadores[0].aT.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].aT.percentual) {
                    statj_melhor_percentual = jogadores[i].aT.percentual;
                    indice = i;
                }
            }
            break;

        case 'L':
            statj_melhor_percentual = jogadores[0].aL.percentual;

            for (i = 1; i < njogadores; i++) {
                if (statj_melhor_percentual < jogadores[i].aL.percentual) {
                    statj_melhor_percentual = jogadores[i].aL.percentual;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes ao número de jogos
 * @details Esta função retorna o jogador com maior ou menor número de jogos, dependendo
 * 	        do tipo específicado
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com maior número de jogos
 * 					 '-' : retorna o índice do jogados com menor número de jogos
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador com maior/menor número de jogos. 
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int statj_jogos(jogador_t *jogadores, int njogadores, char tipo) {
    int statj_jogos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_jogos = jogadores[0].jogos;

            for (i = 1; i < njogadores; i++) {
                if (statj_jogos < jogadores[i].jogos) {
                    statj_jogos = jogadores[i].jogos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_jogos = jogadores[0].jogos;

            for (i = 1; i < njogadores; i++) {
                if (statj_jogos > jogadores[i].jogos) {
                    statj_jogos = jogadores[i].jogos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes à idade
 * @details Esta função retorna o jogador com maior ou menor idade, dependendo
 * 	        do tipo específicado
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com maior idade
 * 					 '-' : retorna o índice do jogados com menor idade
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador com maior/menor idade. 
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int statj_idade(jogador_t *jogadores, int njogadores, char tipo){
    int statj_idade = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_idade = jogadores[0].idade;

            for (i = 1; i < njogadores; i++) {
                if (statj_idade < jogadores[i].idade) {
                    statj_idade = jogadores[i].idade;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_idade = jogadores[0].idade;

            for (i = 1; i < njogadores; i++) {
                if (statj_idade > jogadores[i].idade) {
                    statj_idade = jogadores[i].idade;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes à minutos jogados
 * @details Esta função retorna o jogador com mais ou menos minutos jogados, dependendo
 * 	        do tipo específicado
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com mais minutos
 * 					 '-' : retorna o índice do jogados com menos minutos
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador com mais/menos minutos.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int statj_minutos(jogador_t *jogadores, int njogadores, char tipo){
    int statj_minutos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_minutos = jogadores[0].minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos < jogadores[i].minutos) {
                    statj_minutos = jogadores[i].minutos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_minutos = jogadores[0].minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos > jogadores[i].minutos) {
                    statj_minutos = jogadores[i].minutos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Estatísticas referentes à pontos
 * @details Esta função retorna o jogador com mais ou menos pontos, dependendo
 * 	        do tipo específicado
 * 
 * @param jogadores  Vetor contendo as informações dos jogadores
 * @param njogadores Número de jogadores do vetor
 * @param tipo       Tipo de estatística, conforme abaixo:
 * 					 '+' : retorna o índice do jogador com mais pontos
 * 					 '-' : retorna o índice do jogados com menos pontos
 * 					 
 * @return           Se jogadores é nulo, retorna -1. Se o tipo é diferente dos válidos, 
 * 					 retorna -2. Retorna o índice do jogador com mais/menos pontos.
 *                   Caso haja empate retorna o menor índice que satisfaz a condição.
 */
int statj_pontos(jogador_t *jogadores, int njogadores, char tipo){
    int statj_pontos = 0;
    int indice = 0;
    int i = 0;

    if (jogadores == NULL) {
        return -1;
    }

    switch (tipo) {
        case '+':
            statj_pontos = jogadores[0].pontos;

            for (i = 1; i < njogadores; i++) {
                if (statj_pontos < jogadores[i].pontos) {
                    statj_pontos = jogadores[i].pontos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_pontos = jogadores[0].pontos;

            for (i = 1; i < njogadores; i++) {
                if (statj_pontos > jogadores[i].pontos) {
                    statj_pontos = jogadores[i].pontos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/******************************/
/* Estatísticas de Times (statt)												     	*/
/******************************/

/**
 * @brief   Soma de pontos dos jogadores de um time
 * @details Retorna a soma de pontos feita por os jogadores de um time
 * 
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a soma de pontos
 *                   feita pelos jogadores do time especificado. Se o nome do time for in-
 *                   válido (time sem jogadores), retorna 0.
 */
int statt_soma_pontos(jogador_t jogadores, int njogadores, char time){
    int statj_minutos = 0;
    int indice = 0;
    int i = 0;

    if (&jogadores == NULL) {
        return -1;
    }

    switch (time) {
        case '+':
            statj_minutos = jogadores.minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos < jogadores.minutos) {
                    statj_minutos = jogadores.minutos;
                    indice = i;
                }
            }

            break;

        case '-':
            statj_minutos = jogadores.minutos;

            for (i = 1; i < njogadores; i++) {
                if (statj_minutos > jogadores.minutos) {
                    statj_minutos = jogadores.minutos;
                    indice = i;
                }
            }
            break;

        default:
            return -2;
            break;
    }

    return indice;
}

/**
 * @brief   Média de pontos dos jogadores de um time
 * @details Retorna a média de pontos feita por os jogadores de um time
 * 
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a média de pontos
 *                   feita pelos jogadores do time especificado. Se o nome do time for in-
 *                   válido (time sem jogadores), retorna 0.
 */
float statt_media_pontos(jogador_t jogadores, int njogadores, char time);

/**
 * @brief   Média de idade dos jogadores de um time
 * @details Retorna a média de idade dos jogadores de um time
 * 
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @return           Se jogadores ou time forem nulos, retorna -1. Retorna a média de idade
 *                   dos jogadores do time especificado. Se o nome do time for inválido 
 *                   (time sem jogadores), retorna 0.
 */
float statt_media_idade(jogador_t jogadores, int njogadores, char time);

/**
 * @brief   Número de jogadores de uma posição no time
 * @details Retorna o número de jogadores de uma determinada posição que o time possui
 * 
 * @param jogadores  Vetor com os jogadores
 * @param njogadores Número de jogadores
 * @param time 		 String com o nome do time
 * @param posicao	 String com o nome da posição
 * @return           Se jogadores, time ou posição forem nulos, retorna -1. Retorna o número 
 * 					 de jogadores de uma dada posição que o time possui. Se o nome do time 
 * 					 ou posição forem inválidos (não estiverem no arquivo), retorna 0.
 */
int statt_posicao(jogador_t jogadores, int njogadores, char *time, char posicao);

#endif