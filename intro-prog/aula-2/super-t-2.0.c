#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura da carta
typedef struct {
    char cidade[20];
    char estado[3];    // 2 caracteres + '\0'
    char codigo[4];    // 3 caracteres + '\0'
    int populacao;
    float area;
    float pib;
    int turismo;
    float pib_per_capita;
    float densidade;
} Carta;

// Enumeração dos atributos
typedef enum {
    POPULACAO,
    AREA,
    PIB,
    TURISMO,
    PIB_PER_CAPITA,
    DENSIDADE
} Atributo;

int main(void) {
    srand(time(NULL));  // Inicializa a semente do rand

    printf("Seja bem-vindo ao Super Trunfo! Hoje nós iniciaremos criando 2 cartas.\n");
    printf("Nosso jogo será um Super Trunfo de cidades. Precisaremos que você escolha\n");
    printf("2 cidades e preencha os campos solicitados para cada cidade, respectivamente.\n");

    // Declaração das cartas
    Carta carta1, carta2;

    // ENTRADA DE DADOS CARTA 1
    printf("\nVamos começar com a primeira carta.\n");
    printf("Qual o nome da cidade da primeira carta?\n");
    scanf(" %19s", carta1.cidade);

    printf("Qual o estado da cidade da primeira carta? (1 letra entre A e H)\n");
    scanf(" %2s", carta1.estado);

    printf("Qual o código da primeira carta? (1 letra + 2 números, ex: A01)\n");
    scanf(" %3s", carta1.codigo);

    printf("Qual a população da cidade da primeira carta?\n");
    scanf("%d", &carta1.populacao);

    printf("Qual a área da cidade da primeira carta?\n");
    scanf("%f", &carta1.area);

    printf("Qual o PIB da cidade da primeira carta?\n");
    scanf("%f", &carta1.pib);

    printf("Qual o número de pontos turísticos da cidade da primeira carta?\n");
    scanf("%d", &carta1.turismo);

    // Calcula PIB per capita e densidade
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta1.densidade = carta1.populacao / carta1.area;

    // ENTRADA DE DADOS CARTA 2
    printf("\nAgora vamos para a segunda carta.\n");
    printf("Qual o nome da cidade da segunda carta?\n");
    scanf(" %19s", carta2.cidade);

    printf("Qual o estado da cidade da segunda carta? (2 letras, ex: SP)\n");
    scanf(" %2s", carta2.estado);

    printf("Qual o código da segunda carta? (1 letra + 2 números, ex: A01)\n");
    scanf(" %3s", carta2.codigo);

    printf("Qual a população da cidade da segunda carta?\n");
    scanf("%d", &carta2.populacao);

    printf("Qual a área da cidade da segunda carta?\n");
    scanf("%f", &carta2.area);

    printf("Qual o PIB da cidade da segunda carta?\n");
    scanf("%f", &carta2.pib);

    printf("Qual o número de pontos turísticos da cidade da segunda carta?\n");
    scanf("%d", &carta2.turismo);

    // Calcula PIB per capita e densidade
    carta2.pib_per_capita = carta2.pib / carta2.populacao;
    carta2.densidade = carta2.populacao / carta2.area;

    // EXIBIÇÃO DAS CARTAS
    printf("\n--- Carta 1 ---\n");
    printf("Cidade: %s\nEstado: %s\nCódigo: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: R$ %.2f\nPontos turísticos: %d\nPIB per Capita: R$ %.2f\nDensidade: %.2f pessoas/km²\n",
           carta1.cidade, carta1.estado, carta1.codigo, carta1.populacao, carta1.area, carta1.pib, carta1.turismo, carta1.pib_per_capita, carta1.densidade);

    printf("\n--- Carta 2 ---\n");
    printf("Cidade: %s\nEstado: %s\nCódigo: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: R$ %.2f\nPontos turísticos: %d\nPIB per Capita: R$ %.2f\nDensidade: %.2f pessoas/km²\n",
           carta2.cidade, carta2.estado, carta2.codigo, carta2.populacao, carta2.area, carta2.pib, carta2.turismo, carta2.pib_per_capita, carta2.densidade);

    printf("\nParabéns pela criação das cartas! Agora vamos ao jogo.\n");

    // Sorteia o atributo
    int atributoSorteado = rand() % 6;  // De 0 a 5

    printf("\nAtributo sorteado: ");
    switch (atributoSorteado) {
        case POPULACAO:
            printf("População\n");
            break;
        case AREA:
            printf("Área\n");
            break;
        case PIB:
            printf("PIB\n");
            break;
        case TURISMO:
            printf("Turismo\n");
            break;
        case PIB_PER_CAPITA:
            printf("PIB per Capita\n");
            break;
        case DENSIDADE:
            printf("Densidade Demográfica\n");
            break;
    }

    // Comparação
    float valor1 = 0, valor2 = 0;

    switch (atributoSorteado) {
        case POPULACAO:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case AREA:
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case PIB:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case TURISMO:
            valor1 = carta1.turismo;
            valor2 = carta2.turismo;
            break;
        case PIB_PER_CAPITA:
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            break;
        case DENSIDADE:
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            break;
    }

    printf("\nValor da Carta 1: %.2f\n", valor1);
    printf("Valor da Carta 2: %.2f\n", valor2);

    // Se for densidade, vence quem tiver MENOR valor
    if (atributoSorteado == DENSIDADE) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 venceu! Menor densidade.\n");
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 venceu! Menor densidade.\n");
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {  // Para os demais atributos, vence quem tiver MAIOR valor
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 venceu!\n");
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 venceu!\n");
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}