#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 10

typedef struct {
    int codigo;
    char estado[50];
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaCidade;

// Função para calcular densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para registrar uma carta
void registrarCarta(CartaCidade* carta) {
    printf("\nDigite os dados da cidade:\n");
    printf("Código: ");
    scanf("%d", &carta->codigo);

    printf("Estado: ");
    scanf(" %[^\n]s", carta->estado);

    printf("Nome da cidade: ");
    scanf(" %[^\n]s", carta->nome);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos derivados
    carta->densidadePopulacional = calcularDensidade(carta->populacao, carta->area);
    carta->pibPerCapita = calcularPIBPerCapita(carta->pib * 1e9, carta->populacao);  // PIB em reais
}

// Função para exibir dados de uma carta
void exibirCarta(CartaCidade carta) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Código: %d\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Área: %.2f km²\n", carta.area);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(CartaCidade c1, CartaCidade c2, int atributo) {
    float valor1, valor2;
    valor1 = valor2 = 0;

    switch (atributo) {
        case 1: valor1 = (float)c1.populacao; valor2 = (float)c2.populacao; break;
        case 2: valor1 = c1.pib; valor2 = c2.pib; break;
        case 3: valor1 = c1.area; valor2 = c2.area; break;
        case 4: valor1 = (float)c1.pontosTuristicos; valor2 = (float)c2.pontosTuristicos; break;
        case 5: valor1 = c1.densidadePopulacional; valor2 = c2.densidadePopulacional; break;
        case 6: valor1 = c1.pibPerCapita; valor2 = c2.pibPerCapita; break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\nResultado da rodada:\n");
    printf("%s: %.2f vs %s: %.2f\n", c1.nome, valor1, c2.nome, valor2);
    if (valor1 > valor2) {
        printf("Vencedor: %s\n", c1.nome);
    } else if (valor2 > valor1) {
        printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    CartaCidade cartas[2];
    int atributo;
    int i;  // Declarar fora do for

    printf("=== Registro das Cartas ===\n");
    for (i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        registrarCarta(&cartas[i]);
    }

    for (i = 0; i < 2; i++) {
        exibirCarta(cartas[i]);
    }

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - PIB\n3 - Área\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    compararCartas(cartas[0], cartas[1], atributo);

    return 0;
}
