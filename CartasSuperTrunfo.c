#include <stdio.h>

typedef struct {
    char nome[50];
    int codigo;
    char estado[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade_populacional(unsigned long int populacao, float area) {
    return populacao / area;
}

float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    return pib / populacao;
}

float calcular_super_poder(Carta carta) {
    // Inverso da densidade populacional
    float inverso_densidade = 1 / carta.densidade_populacional;
    // Soma de todos os atributos numéricos
    return carta.populacao + carta.area + carta.pib + carta.pontos_turisticos + carta.pib_per_capita + inverso_densidade;
}

void comparar_atributos(Carta carta1, Carta carta2) {
    printf("Comparação de Cartas:\n");

    // Comparação da População
    printf("População: ");
    if (carta1.populacao > carta2.populacao)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação da Área
    printf("Área: ");
    if (carta1.area > carta2.area)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação do PIB
    printf("PIB: ");
    if (carta1.pib > carta2.pib)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação dos Pontos Turísticos
    printf("Pontos Turísticos: ");
    if (carta1.pontos_turisticos > carta2.pontos_turisticos)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação da Densidade Populacional
    printf("Densidade Populacional: ");
    if (carta1.densidade_populacional < carta2.densidade_populacional)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação do PIB per Capita
    printf("PIB per Capita: ");
    if (carta1.pib_per_capita > carta2.pib_per_capita)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");

    // Comparação do Super Poder
    printf("Super Poder: ");
    if (carta1.super_poder > carta2.super_poder)
        printf("Carta 1 venceu (1)\n");
    else
        printf("Carta 2 venceu (0)\n");
}

int main() {
    Carta carta1, carta2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Nome: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    printf("Código: ");
    scanf("%d", &carta1.codigo);
    getchar();  // Consumir o newline após o número
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta1.super_poder = calcular_super_poder(carta1);

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    printf("Código: ");
    scanf("%d", &carta2.codigo);
    getchar();  // Consumir o newline após o número
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);
    carta2.super_poder = calcular_super_poder(carta2);

    // Comparação entre as cartas
    comparar_atributos(carta1, carta2);

    return 0;
}