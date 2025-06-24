#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main (){

#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5
#define NAVIO '3'
#define AGUA '0'
#define HABILIDADE '5'

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavios(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][4 + i] = NAVIO;
        tabuleiro[5 + i][1] = NAVIO;
    }
}

void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) ? 1 : 0;
        }
    }
}

void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) ? 1 : 0;
        }
    }
}

void aplicarHabilidade(char tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origem_l - TAM_HAB / 2 + i;
            int coluna = origem_c - TAM_HAB / 2 + j;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int c = 0; c < TAM; c++) {
        printf("%2d", c + 1);
    }
    printf("\n");

    for (int l = 0; l < TAM; l++) {
        printf(" %c ", 'A' + l);
        for (int c = 0; c < TAM; c++) {
            printf(" %c ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 3, 4);       // aplica cone no ponto D5
    aplicarHabilidade(tabuleiro, cruz, 6, 6);       // aplica cruz no ponto G7
    aplicarHabilidade(tabuleiro, octaedro, 1, 8);   // aplica octaedro no ponto B9

    imprimirTabuleiro(tabuleiro);

    return 0;
}
}


   