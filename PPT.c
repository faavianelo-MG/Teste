#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char palavracerta[50];
    char display[50];
    int tamanho;
    int vida;
    int vitoria;
    char tentativa;
} jogoforca;

void desenha_forca(int vida) {
    printf("\n ________");
    printf("\n|       |");
    printf("\n|       %s", vida < 6 ? "O" : " ");
    printf("\n|      %s%s%s", vida < 4 ? "/" : " ", vida < 5 ? "|" : " ", vida < 3 ? "\\" : " ");
    printf("\n|      %s %s\n", vida < 2 ? "/" : " ", vida < 1 ? "\\" : " ");
}

void escolhe_palavra(char palavra_secreta[]) {
    FILE* f = fopen("c:\\Users\\0082239\\Desktop\\joca\\Palavras.txt", "r");
if (f == NULL) {
printf("Erro: Banco de palavras nao encontrado.\n");
exit(1);
}
int total_palavras = 0;
fscanf(f, "%d", &total_palavras);
int indice_sorteado = rand() % total_palavras;
for (int i = 0; i <= indice_sorteado; i++) {
fscanf(f, "%s", palavra_secreta);
}
fclose(f);
}


int main() {
    jogoforca jogo;
    
    srand(time(NULL));
    
    escolhe_palavra(jogo.palavracerta);
 
    jogo.tamanho = strlen(jogo.palavracerta);
    jogo.vida = 6;
    jogo.vitoria = 0;
    memset(jogo.display, '_', jogo.tamanho);
    jogo.display[jogo.tamanho] = '\0';

    printf("%d Letras\n", jogo.tamanho);

    while(jogo.vida > 0 && !jogo.vitoria) {
        printf("%s", jogo.display);
        desenha_forca(jogo.vida);

        printf("\n\nDigite o seu chute: ");
        scanf(" %c", &jogo.tentativa);

        int acertou = 0;
        for(int i = 0; i < jogo.tamanho; i++) {
            if(jogo.palavracerta[i] == jogo.tentativa) {
                jogo.display[i] = jogo.tentativa;
                acertou = 1;
            }
        }

        if(!acertou) {
            jogo.vida--;
            printf("Errou!\n");
        }

        if(strcmp(jogo.display, jogo.palavracerta) == 0) {
            jogo.vitoria = 1;
            printf("\n%s\nParabéns, você ganhou!", jogo.palavracerta);
        }
    }

    if(!jogo.vitoria) {
        desenha_forca(0);
        printf("\nGame Over! Você perdeu!");
        printf("\nA palavra era: %s", jogo.palavracerta);
    }

    return 0;
}
