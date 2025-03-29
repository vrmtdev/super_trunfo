#include <stdio.h>
#include <string.h>

typedef struct

// ~~~~Variáveis
{
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
}

Carta;
// ~~~~Leitura dos dados da carta
void lerCarta(Carta *carta)
{
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf(" %s", carta->codigo);

    printf("Digite o nome da cidade: ");
    getchar();
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, " ")] = 0;

    printf("Digite a população: ");
    scanf(" %d", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf(" %f", &carta->area);

    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta->pontosTuristicos);
}

// ~~~~Exibição dos dados da carta
void exibirCarta(Carta carta)
{
    printf("Estado: %c ", carta.estado);
    printf("Código: %s ", carta.codigo);
    printf("Cidade: %s ", carta.nomeCidade);
    printf("População: %d habitantes ", carta.populacao);
    printf("Área: %.2f km² ", carta.area);
    printf("PIB: %f ", carta.pib);
    printf("Pontos turísticos: %d ", carta.pontosTuristicos);
}

int main()
{
    Carta carta1, carta2;

    printf("Cadastro da carta número 1: ");
    lerCarta(&carta1);

    printf("\nCadastro da carta número 2: ");
    lerCarta(&carta2);

    printf("\nDados das cartas cadastradas: ");
    exibirCarta(carta1);
    exibirCarta(carta2);

    return 0;
}