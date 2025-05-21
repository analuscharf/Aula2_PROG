#include <stdio.h>

int main() {

    int b = 2;
b =- 2;

    printf("%d", 0.1 < 0.5 < 0.9);

    int opcao;
    
    printf("Escolha uma opção:\n");
    printf("1 - Converter pés + polegadas para metros\n");
    printf("2 - Converter metros para pés + polegadas\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int pes, polegadas;
        float altura_metros;

        printf("Entre com sua altura em pés + polegadas (ex: 5 10): ");
        scanf("%d %d", &pes, &polegadas);

        altura_metros = (pes * 0.3048) + (polegadas * 0.0254);
        printf("Altura em metros: %.2f\n", altura_metros);

    } else if (opcao == 2) {
        float altura_metros;
        int pes, polegadas;

        printf("Entre com sua altura em metros: ");
        scanf("%f", &altura_metros);

        pes = (int)(altura_metros / 0.3048);
        polegadas = (int)((altura_metros - (pes * 0.3048)) / 0.0254);

        printf("Altura em pés + polegadas: %d %d\n", pes, polegadas);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
