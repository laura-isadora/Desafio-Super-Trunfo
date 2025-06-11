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

    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade1);
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade2);

    // MENU DE COMPARAÇÃO FINAL
    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;

    printf("\n=== Escolha de Atributos ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (MENOR vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1) {
                switch (i) {
                    case 1: printf("%d - População\n", i); break;
                    case 2: printf("%d - Área\n", i); break;
                    case 3: printf("%d - PIB\n", i); break;
                    case 4: printf("%d - Pontos Turísticos\n", i); break;
                    case 5: printf("%d - Densidade Populacional (MENOR vence)\n", i); break;
                    case 6: printf("%d - PIB per Capita\n", i); break;
                }
            }
        }
        printf("Escolha o segundo atributo: ");
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1);

    // Atribuir valores do primeiro atributo
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos_turisticos1; valor1_c2 = pontos_turisticos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pib_per_capita1; valor1_c2 = pib_per_capita2; break;
    }

    // Atribuir valores do segundo atributo
    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos_turisticos1; valor2_c2 = pontos_turisticos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pib_per_capita1; valor2_c2 = pib_per_capita2; break;
    }

    // Comparação individual com regra especial para densidade
    int resultado1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    int resultado2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    // Soma dos valores
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // Exibir resultado
    printf("\n=== Resultado da Rodada ===\n");
    printf("Cidade 1: %s\n", nome_cidade1);
    printf("Cidade 2: %s\n", nome_cidade2);

    printf("\nAtributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional (MENOR vence)\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("Valores: %.2f (Cidade 1) vs %.2f (Cidade 2)\n", valor1_c1, valor1_c2);

    printf("\nAtributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional (MENOR vence)\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("Valores: %.2f (Cidade 1) vs %.2f (Cidade 2)\n", valor2_c1, valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome_cidade1, soma1);
    printf("%s: %.2f\n", nome_cidade2, soma2);

    if (soma1 > soma2) {
        printf("\n🏆 %s venceu a rodada!\n", nome_cidade1);
    } else if (soma2 > soma1) {
        printf("\n🏆 %s venceu a rodada!\n", nome_cidade2);
    } else {
        printf("\n🤝 Empate!\n");
    }

    return 0;
}