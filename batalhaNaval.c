#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main (){

char tabuleiro [10][10] ; // matriz para o tabuleiro
int c, l; 


for (c=0; c < 10; c++){ //para percorrer as colunas do tabuleiro
   for (l = 0 ; l < 10 ; l++){ // para percorrer as linhas do tabuleiro
    tabuleiro[l][c] = '0'; // para preencher o tabuleiro com 0 representando a água
   }
}

// posicionando o navio horizontal
 int linhaH = 1;//linha horizontal do navio
 int colH = 3; //coluna do navio
 for(int i = 0; i<3;i++){
	if (tabuleiro[linhaH][colH + i] == '3'){
		 printf("Erro: sobreposição no navio horizontal.\n");
            return 1;
	}
	 tabuleiro[linhaH][colH + i] = '3';
 }
//posicionando os navios na vertical
 int linhaV = 3; // linha vertical do navio
 int colV = 6; // coluna vertical do navio
 for(int i = 0; i < 3; i++){
	if(tabuleiro[linhaV+i][colV]) == '3'{
		 printf("Erro: sobreposição no navio vertical.\n");
            return 1;
	}
	tabuleiro[linhaV + i][colV] = '3';
 }

 // ======= NAVIO DIAGONAL PRINCIPAL ======= (linha e coluna aumentam)
    int linhaD1 = 5;
    int colD1   = 1;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaD1 + i][colD1 + i] == '3') {
            printf("Erro: sobreposição na diagonal principal.\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colD1 + i] = '3';
    }

    // ======= NAVIO DIAGONAL SECUNDÁRIA ======= (linha aumenta, coluna diminui)
    int linhaD2 = 0;
    int colD2   = 9;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaD2 + i][colD2 - i] == '3') {
            printf("Erro: sobreposição na diagonal secundária.\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colD2 - i] = '3';
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


   