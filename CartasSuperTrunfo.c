#include <stdio.h>

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char codigo[4];   // Código da cidade (ex: A01, B02)
    int populacao;    // População da cidade
    float area;       // Área da cidade em km²
    float pib;        // PIB da cidade em bilhões
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

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
        
        printf("População: ");
        scanf("%d", &cidades[i].populacao);
        
        printf("Área (km²): ");
        scanf("%f", &cidades[i].area);
        
        printf("PIB (bilhões): ");
        scanf("%f", &cidades[i].pib);
        
        printf("Número de pontos turísticos: ");
        scanf("%d", &cidades[i].pontos_turisticos);
    }

    // Exibição dos dados cadastrados
    printf("\n===== Cartas Cadastradas =====\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nCidade %d:\n", i + 1);
        printf("Código: %s\n", cidades[i].codigo);
        printf("População: %d habitantes\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].pontos_turisticos);
    }

    return 0;
}