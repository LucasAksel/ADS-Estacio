#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Seja bem vindo ao Super Trunfo. Hoje nós iniciaremos criando 2 cartas.\n");
    printf("Nosso jogo será um Super Trunfo de cidades. Precisaremos que você escolha\n");
    printf("2 cidades e preencha os campos solicitados para cada cidade, respectivamente.\n");

    // VARIAVEIS
    char cidade1[20], cidade2[20];
    char estado1[2], estado2[2];
    char codigo1[4], codigo2[4];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int turismo1, turismo2;
    float pib_per_capita1, pib_per_capita2;
    float densidade1, densidade2;


    // ENTRADA DE DADOS CARTA 1
    printf("Vamos começar com a primeira carta.\n");
    printf("Qual o nome da cidade da primeira carta?\n");
    scanf("%19s", cidade1);

    printf("Qual o estado da cidade da primeira carta? (1 letra entre A e H)\n");
    scanf(" %1s", estado1); // Espaço antes do %1s para ignorar o newline anterior

    printf("Qual o código da primeira carta? (1 letra + 2 números, ex: A01)\n");
    scanf("%3s", codigo1);

    printf("Qual a população da cidade da primeira carta?\n");
    scanf("%d", &populacao1);
    

    printf("Qual a área da cidade da primeira carta?\n");
    scanf("%f", &area1);
    

    printf("Qual o PIB da cidade da primeira carta?\n");
    scanf("%f", &pib1);
    

    printf("Qual o número de pontos turísticos da cidade da primeira carta?\n");
    scanf("%d", &turismo1);

    pib_per_capita1 = (float) pib1/populacao1;

    densidade1 = (float) populacao1/area1;
   

    // ENTRADA DE DADOS CARTA 2
    {
    printf("Agora vamos para a segunda carta.\n\n\n\n");
    printf("Qual o nome da cidade da segunda carta?\n");
    scanf(" %19s", cidade2);

    printf("Qual o estado da cidade da segunda carta? (1 letra entre A e H)\n");
    scanf(" %1s", estado2);

    printf("Qual o código da segunda carta? (1 letra + 2 números, ex: A01)\n");
    scanf(" %3s", codigo2);

    printf("Qual a população da cidade da segunda carta?\n");
    scanf("%d", &populacao2);
    

    printf("Qual a área da cidade da segunda carta?\n");
    scanf("%f", &area2);
    

    printf("Qual o PIB da cidade da segunda carta?\n");
    scanf("%f", &pib2);
    

    printf("Qual o número de pontos turísticos da cidade da segunda carta?\n");
    scanf("%d", &turismo2);


       pib_per_capita2 = (float) pib2/populacao2;
       densidade2 = (float) populacao2/area2;
       
    }


    // EXIBIÇÃO DOS DADOS
    printf("Carta 1:\nCidade: %s\nEstado: %s\nCódigo: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: $%.2f\nPontos turísticos: %d\nPIB per Capita: R$%.2f per capita\nDensidade Demográfica: %.2f pessoas/km²\n\n\n",
           cidade1, estado1, codigo1, populacao1, area1, pib1, turismo1, pib_per_capita1, densidade1);

    printf("Carta 2:\nCidade: %s\nEstado: %s\nCódigo: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: $%.2f\nPontos turísticos: %d\nPIB per Capita: R$%.2f per capita\nDensidade Demográfica: %.2f pessoas/km² \n\n",
           cidade2, estado2, codigo2, populacao2, area2, pib2, turismo2, pib_per_capita2, densidade2);

    printf("Parabéns pela criação das cartas! Com isso nós encerramos os dois primeiros passos do nosso jogo.\n");

    return 0;
}