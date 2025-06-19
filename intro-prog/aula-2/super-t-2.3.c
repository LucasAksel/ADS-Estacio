#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Quais os atributos das cartas
typedef struct {
    char nome [50];
    long int populacao; // Corrigido para long int
    float area;
    long long pib;
    float pib_per_capita;
    float densidade;
    long int turismo; // Corrigido para long int
} CartaCity;

// Declarações das cartas
// Estas são variáveis globais, acessíveis por todas as funções.
CartaCity carta1;
CartaCity carta2;

// Função para exibir o menu de atributos disponíveis
void exibirMenuAtributos(int ja_escolhido) {
    printf("Escolha um atributo para comparar:\n");
    if (ja_escolhido != 1) { // Corrigido de =! para !=
        printf("1. População (em milhões de hab.)\n");
    }
    if (ja_escolhido != 2) { // Corrigido de =! para !=
        printf("2. Área (em milhões de km²)\n");
    }
    if (ja_escolhido != 3) { // Corrigido de =! para !=
        printf("3. PIB (em bilhões de USD)\n");
    }
    if (ja_escolhido != 4) { // Corrigido de =! para !=
        printf("4. PIB per Capita (em mil USD)\n");
    }
    if (ja_escolhido != 5) { // Corrigido de =! para !=
        printf("5. Densidade Demográfica (hab/km²) - MENOR VALOR VENCE\n"); // Adicionada regra
    }
    if (ja_escolhido != 6) { // Corrigido de =! para !=
        printf("6. Turistas (turistas/ano)\n");
    }
    printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
    printf("Digite sua opção: ");
}

// Função para obter o valor numérico
float funValorAtributo(CartaCity carta, int atributo_idx) {
    // Usando switch para escolher o atributo baseado no número
    switch (atributo_idx) {
        case 1:
            return (float)carta.populacao;
        case 2:
            return carta.area;
        case 3:
            return (float)carta.pib;
        case 4:
            return carta.pib_per_capita;
        case 5:
            return carta.densidade;
        case 6:
            return (float)carta.turismo;
        default:
            return -1.0; // Dessa forma ele retorna um valor inválido caso o atributo_idx não for reconhecido
    }
}

// Função para obter a string do atributo
const char* funNomeAtributo(int atributo_idx) {
    // Usando switch para escolher o nome baseado no número
    switch (atributo_idx) {
        case 1:
            return "População";
        case 2:
            return "Área";
        case 3:
            return "PIB";
        case 4:
            return "PIB per Capita";
        case 5:
            return "Densidade Demográfica";
        case 6:
            return "Turismo";
        default:
            return "Desconhecido";
    }
}

// Funções para as opções do menu principal (cada uma executa uma vez e retorna)

void mostrarCartas() {
    // Carta 1
    printf("\n~-~ Mostrar Cartas ~-~\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("  População: %ld milhões de hab.\n", carta1.populacao); // Usar %ld para long int
    printf("  Área: %.2f milhões de km²\n", carta1.area);
    printf("  PIB: $%lld USD\n", carta1.pib);
    printf("  PIB per Capita: $%.2f mil USD\n", carta1.pib_per_capita);
    printf("  Densidade Demográfica: %.2f hab/km²\n", carta1.densidade);
    printf("  Turismo: %ld turistas/ano\n", carta1.turismo); // Corrigido formato e texto

    // Carta 2
    printf("\nCarta 2: %s\n", carta2.nome); // Removido título duplicado
    printf("  População: %ld milhões de hab.\n", carta2.populacao); // Usar %ld para long int
    printf("  Área: %.2f milhões de km²\n", carta2.area);
    printf("  PIB: $%lld USD\n", carta2.pib);
    printf("  PIB per Capita: $%.2f mil USD\n", carta2.pib_per_capita);
    printf("  Densidade Demográfica: %.2f hab/km²\n", carta2.densidade);
    printf("  Turismo: %ld turistas/ano\n", carta2.turismo); // Corrigido formato e texto
    printf("\n~-~ Fim da exibição de cartas ~-~\n"); // Mensagem de fim
}

void mostrarRegras() {
    printf("\n~-~ Regras do Jogo Super Trunfo (Expandido) ~-~\n");
    printf("1. Duas cartas de paises sao selecionadas para comparacao.\n");
    printf("2. O jogador escolhe um ou dois atributos para comparar.\n");
    printf("3. Na comparacao de atributo individual, o MAIOR valor vence, EXCETO para Densidade Demografica (MENOR valor vence).\n");
    printf("4. No modo 'somatorio', os valores dos atributos escolhidos sao somados para cada carta. A carta com a MAIOR soma vence a rodada.\n");
    printf("5. Em caso de empate na soma, a rodada e declarada como 'Empate!'.\n");
    printf("\nBoa sorte e divirta-se!\n");
    printf("\n~-~ Fim das regras ~-~\n");
}

void jogarComAtributos() {
    int atributo1_idx = 0;
    int atributo2_idx = 0;

    printf("\n~-~ Jogar com atributos ~-~\n"); // Adicionado \n para quebra de linha
    printf("Comparando as cartas: %s vs %s\n\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    scanf("%d", &atributo1_idx);

    // Como lidar com opção inválida
    if (atributo1_idx < 1 || atributo1_idx > 6) {
        printf("Opção de atributo inválida para a primeira escolha! O jogo irá terminar.\n");
        return;
    }

    // Escolha do segundo atributo
    exibirMenuAtributos(atributo1_idx);
    scanf("%d", &atributo2_idx);

    // Como lidar com opção inválida ou repetida para o segundo atributo
    if (atributo2_idx < 1 || atributo2_idx > 6 || atributo2_idx == atributo1_idx) { // Corrigido atributo1_idx para atributo2_idx
        printf("Opção de atributo inválida ou já selecionada para a segunda escolha! O jogo irá terminar.\n"); // Corrigida a mensagem de erro
        return;
    }

    printf("\nAtributos escolhidos: %s e %s\n\n",
           funNomeAtributo(atributo1_idx),
           funNomeAtributo(atributo2_idx));

    // --- Comparação e Cálculo da Soma ---
    // CORRIGIDO: Chamar funValorAtributo, não funNomeAtributo
    float valor1_attr1 = funValorAtributo(carta1, atributo1_idx);
    float valor2_attr1 = funValorAtributo(carta2, atributo1_idx);

    float valor1_attr2 = funValorAtributo(carta1, atributo2_idx);
    float valor2_attr2 = funValorAtributo(carta2, atributo2_idx);

    // Densidade Demográfica é o atributo de índice 5
    int is_densidade_attr1 = (atributo1_idx == 5);
    int is_densidade_attr2 = (atributo2_idx == 5);

    // Variáveis para armazenar os resultados
    const char* resultado_attr1;
    const char* resultado_attr2;
    const char* vencedor_final;

    // Comparação do primeiro atributo (usando operador ternário)
    // Condição ? Valor_se_verdadeiro : Valor_se_falso
    resultado_attr1 = (is_densidade_attr1) ?
                      (valor1_attr1 < valor2_attr1 ? carta1.nome : (valor2_attr1 < valor1_attr1 ? carta2.nome : "Empate")) :
                      (valor1_attr1 > valor2_attr1 ? carta1.nome : (valor2_attr1 > valor1_attr1 ? carta2.nome : "Empate"));

    // Comparação do segundo atributo (usando operador ternário)
    resultado_attr2 = (is_densidade_attr2) ?
                      (valor1_attr2 < valor2_attr2 ? carta1.nome : (valor2_attr2 < valor1_attr2 ? carta2.nome : "Empate")) :
                      (valor1_attr2 > valor2_attr2 ? carta1.nome : (valor2_attr2 > valor1_attr2 ? carta2.nome : "Empate"));

    // Soma dos atributos para cada carta
    float soma_carta1 = valor1_attr1 + valor1_attr2;
    float soma_carta2 = valor2_attr1 + valor2_attr2;

    // Determina o vencedor da rodada pela soma (usando operador ternário)
    vencedor_final = (soma_carta1 > soma_carta2) ? carta1.nome :
                     (soma_carta2 > soma_carta1) ? carta2.nome :
                     "Empate!";

    // --- Exibição Clara do Resultado ---
    printf("~=~=~=~=~ RESULTADO DA RODADA ~=~=~=~=~\n");
    printf("Cartas: %s vs %s\n\n", carta1.nome, carta2.nome);

    printf("Atributo 1: %s\n", funNomeAtributo(atributo1_idx));
    printf("  %s: %.2f\n", carta1.nome, valor1_attr1);
    printf("  %s: %.2f\n", carta2.nome, valor2_attr1);
    printf("  Vencedor do atributo 1: %s\n\n", resultado_attr1);

    printf("Atributo 2: %s\n", funNomeAtributo(atributo2_idx));
    printf("  %s: %.2f\n", carta1.nome, valor1_attr2);
    printf("  %s: %.2f\n", carta2.nome, valor2_attr2);
    printf("  Vencedor do atributo 2: %s\n\n", resultado_attr2);

    printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
    printf("Soma dos atributos para %s: %.2f\n", carta1.nome, soma_carta1);
    printf("Soma dos atributos para %s: %.2f\n", carta2.nome, soma_carta2);
    printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");

    printf("\n>>> VENCEDOR DA RODADA: %s <<<\n", vencedor_final);
    printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
    printf("\n~-~ Fim do jogo com atributos ~-~\n");
}

int main() {
    int opcao_menu = 0;

    // Inicialização das cartas
    // Carta 1
    strcpy(carta1.nome, "Nova Iorque");
    carta1.populacao = 8804190;
    carta1.area = 81223.59;
    carta1.pib = 1286000000000LL; // Adicionado LL para garantir long long
    carta1.pib_per_capita = 77900.0;
    carta1.densidade = 7195.4;
    carta1.turismo = 14600000;

    // Carta 2
    strcpy(carta2.nome, "ShangHai");
    carta2.populacao = 24870380;
    carta2.area = 6340.5;
    carta2.pib = 541800487420LL; // Adicionado LL para garantir long long
    carta2.pib_per_capita = 21823.0;
    carta2.densidade = 3929.0; // Corrigido o valor da densidade que estava muito baixo (3.92) para Shanghai
    carta2.turismo = 1286200;

    printf("\n\n\nBem vindo ao Super Trunfo Cidades (são só 2 mesmo)\n\n");

    // Menu principal
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Mostrar as cartas\n");
    printf("2. Regras do jogo\n");
    printf("3. Jogar uma rodada com dois atributos\n");
    printf("4. Sair do jogo\n");
    printf("\n----------------------\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao_menu);

    // Tratamento das escolhas
    if (opcao_menu == 1) {
        mostrarCartas();
    } else if (opcao_menu == 2) {
        mostrarRegras();
    } else if (opcao_menu == 3) {
        jogarComAtributos(); // Esta função agora lida com a escolha de 2 atributos e a soma
    } else if (opcao_menu == 4) {
        printf("Obrigado por jogar! Saindo...\n");
    } else {
        // Opção inválida no menu principal
        printf("Opcao inválida. O programa vai terminar.\n");
    }

    printf("\nEnd Game meu parceiro.\n");
    return 0;
}