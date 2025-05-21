#include <stdio.h>

int main() {
    float altura, largura, profundidade,preco, area, volume,total;
    int quantidade;
    
    // Entrada de dados
    printf("Entre com a altura (m): ");
    scanf("%f", &altura);
    printf("Entre com a largura (m): ");
    scanf("%f", &largura);
    printf("Entre com a profundidade (m): ");
    scanf("%f", &profundidade);

    // Cálculo da área da superfície e volume
    area = 2 * (altura * largura + altura * profundidade + largura * profundidade);
    volume = altura * largura * profundidade;

    // Exibição dos resultados
    printf("A área é %.2f m² e o volume é %.3f m³.\n", area, volume);

    printf("Entre com o preço por metro quadrado: ");
    scanf("%f", &preco);

    printf("Entre com a quantidade de caixas: ");
    scanf("%d", &quantidade);

    total=quantidade*preco*area;
    printf("Total %f: ", total);
    

    return 0;
}
