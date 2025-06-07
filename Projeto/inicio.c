#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char titulo[100];
    char artista[100];
    char genero[50];
    int ano;
    int favorita; // 1 = sim, 0 = não
} Musica;

// Função para remover o '\n' do final da string, se existir
void removerNovaLinha(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void cadastrarMusica(Musica musicas[], int *qtd) {
    printf("Título: ");
    fgets(musicas[*qtd].titulo, 100, stdin);
    removerNovaLinha(musicas[*qtd].titulo);

    printf("Artista: ");
    fgets(musicas[*qtd].artista, 100, stdin);
    removerNovaLinha(musicas[*qtd].artista);

    printf("Gênero: ");
    fgets(musicas[*qtd].genero, 50, stdin);
    removerNovaLinha(musicas[*qtd].genero);

    printf("Ano: ");
    scanf("%d", &musicas[*qtd].ano);
    getchar(); // limpar buffer do teclado

    musicas[*qtd].favorita = 0;
    (*qtd)++;

    printf("Música cadastrada com sucesso!\n");
}

void listarMusicas(Musica musicas[], int qtd) {
    printf("\n--- Lista de Músicas ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d - %s (%s) - %s - %d %s\n", i + 1,
               musicas[i].titulo,
               musicas[i].artista,
               musicas[i].genero,
               musicas[i].ano,
               musicas[i].favorita ? "[Favorita]" : "");
    }
}

void salvarMusicas(Musica musicas[], int qtd) {
    FILE *f = fopen("musicas.txt", "w");
    if (f == NULL) {
        printf("Erro ao salvar músicas.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(f, "%s;%s;%s;%d;%d\n",
                musicas[i].titulo,
                musicas[i].artista,
                musicas[i].genero,
                musicas[i].ano,
                musicas[i].favorita);
    }

    fclose(f);
}

void carregarMusicas(Musica musicas[], int *qtd) {
    FILE *f = fopen("musicas.txt", "r");
    if (f == NULL) return; // arquivo não existe, inicia vazio

    while (fscanf(f, "%99[^;];%99[^;];%49[^;];%d;%d\n",
                  musicas[*qtd].titulo,
                  musicas[*qtd].artista,
                  musicas[*qtd].genero,
                  &musicas[*qtd].ano,
                  &musicas[*qtd].favorita) == 5) {
        (*qtd)++;
    }

    fclose(f);
}

void marcarFavorita(Musica musicas[], int qtd) {
    int id;
    listarMusicas(musicas, qtd);
    printf("Digite o número da música para marcar como favorita: ");
    scanf("%d", &id);
    getchar();

    if (id > 0 && id <= qtd) {
        musicas[id - 1].favorita = 1;
        printf("Música marcada como favorita!\n");
    } else {
        printf("Número inválido.\n");
    }
}

void listarFavoritas(Musica musicas[], int qtd) {
    printf("\n--- Músicas Favoritas ---\n");
    for (int i = 0; i < qtd; i++) {
        if (musicas[i].favorita) {
            printf("%s (%s) - %s - %d\n",
                   musicas[i].titulo,
                   musicas[i].artista,
                   musicas[i].genero,
                   musicas[i].ano);
        }
    }
}

void buscarPorGenero(Musica musicas[], int qtd) {
    char genero[50];
    printf("Digite o gênero para buscar: ");
    fgets(genero, 50, stdin);
    removerNovaLinha(genero);

    printf("\n--- Músicas do gênero '%s' ---\n", genero);
    for (int i = 0; i < qtd; i++) {
        if (strcmp(musicas[i].genero, genero) == 0) {
            printf("%s (%s) - %d\n",
                   musicas[i].titulo,
                   musicas[i].artista,
                   musicas[i].ano);
        }
    }
}

void removerMusica(Musica musicas[], int *qtd) {
    int id;
    listarMusicas(musicas, *qtd);
    printf("Digite o número da música para remover: ");
    scanf("%d", &id);
    getchar();

    if (id > 0 && id <= *qtd) {
        for (int i = id - 1; i < *qtd - 1; i++) {
            musicas[i] = musicas[i + 1];
        }
        (*qtd)--;
        printf("Música removida.\n");
    } else {
        printf("Número inválido.\n");
    }
}

int main() {
    Musica musicas[MAX];
    int qtd = 0;
    int opcao;

    carregarMusicas(musicas, &qtd);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar música\n");
        printf("2. Listar músicas\n");
        printf("3. Marcar como favorita\n");
        printf("4. Listar favoritas\n");
        printf("5. Buscar por gênero\n");
        printf("6. Remover música\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarMusica(musicas, &qtd); break;
            case 2: listarMusicas(musicas, qtd); break;
            case 3: marcarFavorita(musicas, qtd); break;
            case 4: listarFavoritas(musicas, qtd); break;
            case 5: buscarPorGenero(musicas, qtd); break;
            case 6: removerMusica(musicas, &qtd); break;
            case 0: salvarMusicas(musicas, qtd); printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
