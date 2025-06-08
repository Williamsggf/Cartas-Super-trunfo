#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CARTAS (NUM_ESTADOS * CIDADES_POR_ESTADO)

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void cadastrarCartas(Carta cartas[]) {
    char estados[NUM_ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    printf("Cadastro de cartas do Super Trunfo - Países\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 1; j <= CIDADES_POR_ESTADO; j++) {
            snprintf(cartas[index].codigo, sizeof(cartas[index].codigo), "%c%02d", estados[i], j);

            printf("\nCadastro da cidade: %s\n", cartas[index].codigo);

            printf("Digite a população: ");
            scanf("%d", &cartas[index].populacao);

            printf("Digite a área (em km²): ");
            scanf("%f", &cartas[index].area);

            printf("Digite o PIB (em bilhões de USD): ");
            scanf("%f", &cartas[index].pib);

            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cartas[index].pontos_turisticos);

            // Cálculo da densidade populacional e PIB per capita
            cartas[index].densidade_populacional = (cartas[index].area > 0) ? (cartas[index].populacao / cartas[index].area) : 0.0;
            cartas[index].pib_per_capita = (cartas[index].populacao > 0) ? (cartas[index].pib / cartas[index].populacao) : 0.0;

            // Cálculo do Super Poder (soma de todas as propriedades)
            cartas[index].super_poder = cartas[index].populacao + cartas[index].area + cartas[index].pib + cartas[index].pontos_turisticos;

            index++;
        }
    }
}

void exibirCartas(Carta cartas[], int totalCartas) {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCidade: %s\n", cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de USD\n", cartas[i].pib);
        printf("PIB per capita: %.2f USD\n", cartas[i].pib_per_capita * 1e6); // PIB per capita em milhões
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
        printf("Super Poder: %.2f\n", cartas[i].super_poder);
    }
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação entre %s e %s:\n", c1.codigo, c2.codigo);

    printf("População: %s vence\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Densidade populacional: %s vence\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("Área: %s vence\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: %s vence\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("PIB per capita: %s vence\n", (c1.pib_per_capita > c2.pib_per_capita) ? c1.codigo : c2.codigo);
    printf("Pontos turísticos: %s vence\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("Super Poder: %s vence\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
}

int main() {
    Carta cartas[TOTAL_CARTAS];

    cadastrarCartas(cartas);
    exibirCartas(cartas, TOTAL_CARTAS);

    // Comparação de cartas
    int idx1, idx2;
    printf("\nDigite os índices das cartas para comparar (0 a %d): ", TOTAL_CARTAS - 1);
    scanf("%d %d", &idx1, &idx2);

    if (idx1 >= 0 && idx1 < TOTAL_CARTAS && idx2 >= 0 && idx2 < TOTAL_CARTAS) {
        compararCartas(cartas[idx1], cartas[idx2]);
    } else {
        printf("Índices inválidos!\n");
    }

    return 0;
}

