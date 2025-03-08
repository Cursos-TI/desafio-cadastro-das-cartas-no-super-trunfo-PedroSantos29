#include <stdio.h>

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char codigo[4];   // Código da cidade (ex: A01, B02)
    int populacao;    // População da cidade
    float area;       // Área da cidade em km²
    float pib;        // PIB da cidade em bilhões
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional
    float pib_per_capita; // PIB per capita
    float super_poder; // Super poder calculado
} Cidade;

void calcular_dados(Cidade *cidade) {
    cidade->densidade_populacional = (cidade->area > 0) ? (cidade->populacao / cidade->area) : 0;
    cidade->pib_per_capita = (cidade->populacao > 0) ? ((cidade->pib * 1e9) / cidade->populacao) : 0;
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos +
                          cidade->densidade_populacional + cidade->pib_per_capita;
}

void exibir_dados(Cidade cidade) {
    printf("\nCidade: %s\n", cidade.codigo);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", cidade.densidade_populacional);
    printf("PIB per capita: %.2f bilhões\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
    printf("------------------------------------\n");
}

void comparar_cartas(Cidade c1, Cidade c2) {
    printf("\nComparação entre %s e %s:\n", c1.codigo, c2.codigo);
    printf("Densidade Populacional: %s vence!\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("População: %s vence!\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Área: %s vence!\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: %s vence!\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("Pontos turísticos: %s vence!\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("Super Poder: %s vence!\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
    printf("------------------------------------\n");
}

int main() {
    int quantidade;
    
    // Pergunta quantas cidades serão cadastradas
    printf("Quantas cidades deseja cadastrar? ");
    scanf("%d", &quantidade);
    
    Cidade cidades[quantidade]; // Array para armazenar as cidades

    // Loop para cadastrar cada cidade
    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro da cidade %d:\n", i + 1);
        
        printf("Código da cidade (Ex: A01, B02): ");
        scanf("%s", cidades[i].codigo);
        
        printf("População: (Ex: 5000000) ");
        scanf("%d", &cidades[i].populacao);
        
        printf("Área (km²): (Ex: 12.65) ");
        scanf("%f", &cidades[i].area);
        
        printf("PIB (bilhões): (Ex: 50.63) ");
        scanf("%f", &cidades[i].pib);
        
        printf("Número de pontos turísticos: (Ex: 25) ");
        scanf("%d", &cidades[i].pontos_turisticos);
        
        // Calcula os dados derivados
        calcular_dados(&cidades[i]);
    }

    // Exibição dos dados cadastrados
    printf("\n===== Cartas Cadastradas =====\n");
    for (int i = 0; i < quantidade; i++) {
        exibir_dados(cidades[i]);
    }
    
    // Comparação de cartas (se houver mais de uma cidade)
    if (quantidade > 1) {
        printf("\n===== Comparação de Cartas =====\n");
        for (int i = 0; i < quantidade - 1; i++) {
            comparar_cartas(cidades[i], cidades[i + 1]);
        }
    }
    
    return 0;
}