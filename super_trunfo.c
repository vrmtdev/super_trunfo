#include <stdio.h>
#include <string.h>

typedef struct
{
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// ~~~~Leitura dos dados da carta
void lerCarta(Carta *carta)
{
    printf("Digite a sigla do estado (ex: RJ):\n");
    scanf(" %3s", carta->estado);

    printf("Digite o código da carta (ex: RJ01):\n");
    scanf(" %4s", carta->codigo);

    printf("Digite o nome da cidade:\n");
    getchar();
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0;

    printf("Digite a população:\n");
    scanf("%d", &carta->populacao);

    printf("Digite a área (km²):\n");
    scanf("%f", &carta->area);

    printf("Digite o PIB:\n");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &carta->pontosTuristicos);
}

// ~~~~Exibição dos dados da carta
void exibirCarta(Carta carta)
{
    printf("\nLetra do estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
}

// ~~~~Funções de cálculo
float calcularDensidadePopulacional(Carta carta)
{
    return carta.populacao / carta.area;
}

float calcularPIBPerCapita(Carta carta)
{
    return carta.pib / carta.populacao;
}

// ~~~~Função para comparar as cartas com base em um atributo
void compararCartas(Carta carta1, Carta carta2)
{
    float atributo1 = calcularPIBPerCapita(carta1);
    float atributo2 = calcularPIBPerCapita(carta2);

    printf("\nComparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, atributo1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, atributo2);

    // ~~~~Carta vencedora
    if (atributo1 > atributo2)
    {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    }
    else if (atributo1 < atributo2)
    {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }
    else
    {
        printf("Resultado: Empate!\n");
    }
}

int main()
{
    Carta carta1, carta2;

    printf("Cadastro da carta número 1:\n");
    lerCarta(&carta1);

    printf("\nCadastro da carta número 2:\n");
    lerCarta(&carta2);

    printf("\nDados das cartas cadastradas:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // ~~~~Comparação das cartas
    compararCartas(carta1, carta2);

    return 0;
}