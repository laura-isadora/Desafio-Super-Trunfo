#include <stdio.h>

int main() {
    // Variáveis da carta 1
    char estado1;
    char codigo1[5], nome_cidade1[15];
    unsigned long int populacao1;
    int pontos_turisticos1;
    float area1, pib1;

    // Variáveis da carta 2
    char estado2;
    char codigo2[5], nome_cidade2[15];
    unsigned long int populacao2;
    int pontos_turisticos2;
    float area2, pib2;

    // Variáveis para os cálculos
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float super_poder1, super_poder2;

    // Entrada dados carta 1
    printf("=== Cadastro da carta 1 ===\n");
    printf("Informe o estado: ");
    scanf(" %c", &estado1);

    printf("Informe o código da carta: ");
    scanf(" %s", codigo1);

    printf("Informe o nome da cidade: ");
    scanf(" %s", nome_cidade1);

    printf("Informe a população: ");
    scanf(" %lu", &populacao1);

    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &pontos_turisticos1);

    printf("Informe a área da cidade (km²): ");
    scanf(" %f", &area1);

    printf("Informe o PIB da cidade: ");
    scanf(" %f", &pib1);

    // Entrada dados carta 2
    printf("\n=== Cadastro da carta 2 ===\n");
    printf("Informe o estado: ");
    scanf(" %c", &estado2);

    printf("Informe o código da carta: ");
    scanf(" %s", codigo2);

    printf("Informe o nome da cidade: ");
    scanf(" %s", nome_cidade2);

    printf("Informe a população: ");
    scanf(" %lu", &populacao2);

    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &pontos_turisticos2);

    printf("Informe a área da cidade (km²): ");
    scanf(" %f", &area2);

    printf("Informe o PIB da cidade: ");
    scanf(" %f", &pib2);

    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pib_per_capita1 = pib1 / populacao1;
    pib_per_capita2 = pib2 / populacao2;

    // Para calcular super poder: converter tudo para float na soma
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade1);
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade2);

    // Comparações: 1 se carta 1 vence, 0 se carta 2 vence
    int pop_vence = (populacao1 > populacao2) ? 1 : 0;
    int area_vence = (area1 > area2) ? 1 : 0;
    int pib_vence = (pib1 > pib2) ? 1 : 0;
    int pontos_vence = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0;

    // Para densidade, menor vence
    int densidade_vence = (densidade1 < densidade2) ? 1 : 0;

    int pib_per_capita_vence = (pib_per_capita1 > pib_per_capita2) ? 1 : 0;
    int super_poder_vence = (super_poder1 > super_poder2) ? 1 : 0;

    // Mostrar resultados
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", pop_vence);
    printf("Área: Carta 1 venceu (%d)\n", area_vence);
    printf("PIB: Carta 1 venceu (%d)\n", pib_vence);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos_vence);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade_vence);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita_vence);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder_vence);

    return 0;
}
