#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================
// Estrutura de dados
// ============================================

// Representa uma sala da mansão (nó da árvore binária)
typedef struct Sala {
    char nome[50];            // Nome do cômodo
    struct Sala *esquerda;    // Caminho à esquerda
    struct Sala *direita;     // Caminho à direita
} Sala;

// ============================================
// Funções auxiliares
// ============================================

// criarSala() – cria dinamicamente uma sala com nome
Sala* criarSala(const char *nome) {
    Sala *novaSala = (Sala*) malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala!\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// explorarSalas() – permite a navegação do jogador pela árvore
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Caso seja um nó-folha, encerra a exploração
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim da exploração. Não há mais caminhos.\n");
            break;
        }

        printf("Deseja ir para (e) esquerda, (d) direita ou (s) sair? ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("Não há caminho à esquerda!\n");
            }
        } 
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não há caminho à direita!\n");
            }
        } 
        else if (opcao == 's' || opcao == 'S') {
            printf("Exploração encerrada.\n");
            break;
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// ============================================
// Função principal
// ============================================

int main() {
    // Montagem manual da mansão (árvore binária fixa)

    /*
                [Hall de Entrada]
                /                \
         [Sala de Estar]       [Cozinha]
           /       \             /      \
     [Biblioteca] [Jardim]  [Despensa] [Garagem]
    */

    Sala *hall        = criarSala("Hall de Entrada");
    Sala *salaEstar   = criarSala("Sala de Estar");
    Sala *cozinha     = criarSala("Cozinha");
    Sala *biblioteca  = criarSala("Biblioteca");
    Sala *jardim      = criarSala("Jardim");
    Sala *despensa    = criarSala("Despensa");
    Sala *garagem     = criarSala("Garagem");

    // Ligações da árvore
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->esquerda = despensa;
    cozinha->direita = garagem;

    // Início da exploração
    printf("=== Bem-vindo à Mansão Misteriosa! ===\n");
    explorarSalas(hall);

    // Libera memória (opcional para este exercício)
    free(biblioteca);
    free(jardim);
    free(despensa);
    free(garagem);
    free(salaEstar);
    free(cozinha);
    free(hall);

    printf("\nObrigado por explorar a mansão!\n");
    return 0;
}
