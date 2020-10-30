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

int le_cabecario(char *nome);

jogador_t *le_jogadores(char *nome, int *njogadores);

int statj_mais_arremessos(jogador_t *jogadores, int njogadores, char tipo);

int statj_mais_cestas(jogador_t *jogadores, int njogadores, char tipo);

int statj_melhor_percentual(jogador_t *jogadores, int njogadores, char tipo);

int statj_jogos(jogador_t *jogadores, int njogadores, char tipo);

int statj_idade(jogador_t *jogadores, int njogadores, char tipo);

int statj_minutos(jogador_t *jogadores, int njogadores, char tipo);

int statj_pontos(jogador_t *jogadores, int njogadores, char tipo);

int statt_soma_pontos(jogador_t jogadores, int njogadores, char time);

float statt_media_pontos(jogador_t jogadores, int njogadores, char time);

float statt_media_idade(jogador_t jogadores, int njogadores, char time);

int statt_posicao(jogador_t jogadores, int njogadores, char *time, char posicao);

#endif