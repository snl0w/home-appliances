#include <stdio.h>
#include <conio.h>
#include <locale.h>

struct Eletrodomestico
{
    char nome[50];
    float potencia;
    float tempoAtivo;
};

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    float tempoDias;
    float consumoTotal = 0.0;
    const int numEletrodomesticos = 5;
    struct Eletrodomestico eletrodomesticos[numEletrodomesticos];

    printf("-----Digite os dados dos eletrodom�sticos-----\n");
    for (int i = 0; i < numEletrodomesticos; i++)
    {
        printf("Eletrodom�stico %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", eletrodomesticos[i].nome);
        printf("Pot�ncia (kW): ");
        scanf("%f", &eletrodomesticos[i].potencia);
        printf("Tempo ativo por dia (horas): ");
        scanf("%f", &eletrodomesticos[i].tempoAtivo);
        consumoTotal += eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo;
    }

    printf("Digite o tempo (em dias): ");
    scanf("%f", &tempoDias);

    consumoTotal *= tempoDias;

    printf("\nConsumo total na casa: %.2f kW\n", consumoTotal);

    printf("\nConsumo relativo de cada eletrodom�stico:\n");
    for (int i = 0; i < numEletrodomesticos; i++)
    {
        float consumoRelativo = (eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo * tempoDias) / consumoTotal * 100;
        printf("%s: %.2f%%\n", eletrodomesticos[i].nome, consumoRelativo);
    }

    return 0;
}
