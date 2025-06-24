#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main (){
//declaração para criar o tabulerio
char tabuleiro [10][10] ; // matriz para o tabuleiro
int c, l; //variáveis para linhas e colunas
// declaração de navios
int navioH [3] = {3,3,3}; // navio horizontal ocupando 3 posições
int navioV [3] =  {3,3,3}; // navio vertical ocupando 3 posições

// cordenadas dos navio
int linhaH = 1; // linha horizontal do navio
int colH  = 3; // coluna horizontal do navio

int linhaV = 3;   // Linha inicial do navio vertical
int colV = 6;     // Coluna do navio vertical


for (c=0; c < 10; c++){ //para percorrer as colunas do tabuleiro
   for (l = 0 ; l < 10 ; l++){ // para percorrer as linhas do tabuleiro
    tabuleiro[l][c] = '0'; // para preencher o tabuleiro com 0 representando a água
   }
}

// posicionando o navio horizontal
 for (int i = 0 ; i<3; i++){
 	tabuleiro[linhaH  ][colH+i]  = '3';
 }
//posicionando os navios na vertical
for (int i = 0 ; i<3; i++){
 	tabuleiro[linhaV + i][colV] = '3';
}

//imprimir o tabulerio[
printf("   "); // para alinha as linhas com as colunas
for (c = 0; c <10; c++){
	printf("%2d", c +1);
}
printf("\n"); // imprimiu as linhas

for (l = 0; l<10; l++){
	printf("  %c ",'A'+ l);
	for(c = 0; c <10; c++){
		 if (tabuleiro[l][c] == '3'){
		 	printf("  3 ");
		 } else {
		 	printf(" 0  ");
		 }
	}
	printf("\n");
}
return 0;
}


   