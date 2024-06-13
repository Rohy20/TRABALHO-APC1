#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int idade;
    float nota;
} Aluno;

int main() {
    Aluno alunos[MAX_ALUNOS];
    int opcao, num_alunos = 0;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (num_alunos < MAX_ALUNOS) {
                    printf("\nCadastrar Aluno\n");
                    printf("Nome: ");
                    fgets(alunos[num_alunos].nome, MAX_NOME, stdin);
                    alunos[num_alunos].nome[strcspn(alunos[num_alunos].nome, "\n")] = '\0';

                    printf("Idade: ");
                    while (scanf("%d", &alunos[num_alunos].idade) != 1) {
                        printf("Entrada invalida. Por favor, insira uma idade valida: ");
                        scanf("%*s");
                    }

                    printf("Nota: ");
                    while (scanf("%f", &alunos[num_alunos].nota) != 1) {
                        printf("Entrada invalida. Por favor, insira uma nota valida: ");
                        scanf("%*s");
                    }

                    num_alunos++;
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("\nLimite de alunos atingido!\n");
                }
                break;
            case 2:
                if (num_alunos > 0) {
                    printf("\n=== LISTA DE ALUNOS CADASTRADOS ===\n");
                    printf("Nome\tIdade\tNota\n");
                    for (int i = 0; i < num_alunos; i++) {
                        printf("%s\t%d\t%.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].nota);
                    }
                } else {
                    printf("\nNenhum aluno cadastrado!\n");
                }
                break;
            case 3:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        while (getchar() != '\n');

    } while (opcao != 3);

    return 0;
}
