#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2
#define LAGARTO 4
#define SPOCK 5
/*
Nesta primeira versC#o, vamos traduzir as regras da forma mais direta possC-vel.
Usaremos ifs aninhados (um dentro do outro). A lC3gica C): primeiro, verificamos a escolha do jogador.
Depois, dentro de cada verificaC'C#o, analisamos todas as possibilidades para a escolha do computador.
*/
void versao_01() {
	int jogador, computador;
	printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
	scanf("%d", &jogador);
	computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
	printf("Computador escolheu: %d\n", computador);
	if (jogador == PEDRA) {
		if (computador == PEDRA) {
			printf("Empate!\n");
		} else if (computador == PAPEL) {
			printf("Computador vence!\n");
		} else { // computador == TESOURA
			printf("Jogador vence!\n");
		}
	} else if (jogador == PAPEL) {
		if (computador == PEDRA) {
			printf("Jogador vence!\n");
		} else if (computador == PAPEL) {
			printf("Empate!\n");
		} else { // computador == TESOURA
			printf("Computador vence!\n");
		}
	} else { // jogador == TESOURA
		if (computador == PEDRA) {
			printf("Computador vence!\n");
		} else if (computador == PAPEL) {
			printf("Jogador vence!\n");
		} else { // computador == TESOURA
			printf("Empate!\n");
		}
	}
}

/*
Vamos refatorar o cC3digo para reduzir o nC:mero de estruturas if/else a partir do uso de operadores lC3gicos
(&& para"E", || para "OU"). A ideia C) agrupar todas as condiC'C5es de vitC3ria do jogador em uma C:nica expressC#o.
*/
void versao_02() {
	int jogador, computador;
	printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
	scanf("%d", &jogador);
	computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
	printf("Computador escolheu: %d\n", computador);
	if (jogador == computador) {
		printf("Empate!\n");
	} else if ((jogador == PEDRA && computador == TESOURA) ||
	           (jogador == PAPEL && computador == PEDRA) ||
	           (jogador == TESOURA && computador == PAPEL)) {
		printf("Jogador vence!\n");
	} else {
		printf("Computador vence!\n");
	}
}

/*
Para que o jogo possa ser jogado vC!rias vezes sem precisar reiniciar o programa, vamos colocar toda a lC3gica dentro de um laC'o de repetiC'C#o.
O laC'o do-while C) ideal aqui, pois garante que o jogo seja executado pelo menos uma vez antes de perguntar se o jogador quer continuar.
*/
void versao_03() {
	int jogador, computador;
	char jogar_novamente;
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate!\n");
		} else if ((jogador == PEDRA && computador == TESOURA) ||
		           (jogador == PAPEL && computador == PEDRA) ||
		           (jogador == TESOURA && computador == PAPEL)) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}

	} while (jogar_novamente == 's' || jogar_novamente == 'S');
}
void versao_04() {
	int jogador, computador;
	printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura), 3 (Lagarto), 4(Spock): ");
	scanf("%d", &jogador);
	computador = rand() % 5; // Gera um nC:mero aleatC3rio entre 0 e 2
	printf("Computador escolheu: %d\n", computador);
	if (jogador == computador) {
		printf("Empate!\n");
	} else if ((jogador == PEDRA   && computador == TESOURA) ||
	           (jogador == PAPEL   && computador == PEDRA)   ||
	           (jogador == TESOURA && computador == PAPEL)   || 
	           (jogador == PEDRA   && computador == LAGARTO) ||
	           (jogador == PAPEL   && computador == SPOCK)   ||
	           (jogador == TESOURA && computador == LAGARTO)){
		printf("Jogador vence!\n");
	} else {
		printf("Computador vence!\n");
	}
}



void versao_05() {
	int jogador, computador;
	char jogar_novamente;
	int jogador_ganha[] = {TESOURA, PEDRA, PAPEL};
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate!\n");
		} else if (jogador_ganha[jogador] == computador) {
			printf("jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}

int main() {
	srand(time(NULL)); // Inicializa o gerador de nC:meros aleatC3rios
	printf("Versão 01:\n");
	versao_01();
	printf("\nVersão 02:\n");
	versao_02();
	printf("\nVersão 03:\n");
	versao_03();
	printf("\nVersão 04\n");
	versao_04();
	printf("\nVersão 05:\n");
	versao_05();
	return 0;
}
