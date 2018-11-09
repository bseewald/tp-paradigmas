#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int volume;
    int price;
    double density;
} greedy_choice;

// Funcao para ajudar na ordenacao do array de estruturas
int density(const void *item_a, const void *item_b){

    greedy_choice *a = (greedy_choice *)item_a;
    greedy_choice *b = (greedy_choice *)item_b;

    double ratio_a = a->density;
    double ratio_b = b->density;

    if (ratio_a > ratio_b) {
        return -1;
    }
    else if (ratio_a == ratio_b) {
        return 0;
    }
    return 1;
}

double fractional_knapsack(int cheese, int budget, greedy_choice *itens){

    int k_budget = 0;
    double fractional, cube = 0;

    // Ordenacao do array de estruturas pela variavel de densidade
    qsort(itens, cheese, sizeof(greedy_choice), density);

    // Algoritmo guloso
    for(int j = 0; j < cheese; j++)
    {
        if(itens[j].price + k_budget <= budget)
        {
            k_budget += itens[j].price;
            cube += (double)itens[j].volume;
        }
        else{
            fractional = (double)(budget - k_budget)/itens[j].price;
            cube += (double)itens[j].volume * fractional;
            k_budget = budget;
        }
    }
    return cube;
}

int main(){

    int cheese, budget, array_size, n, i;
    double cheese_volume, base;

    while(true)
    {
        // Leitura dos inputs
        scanf("%d", &cheese);
        scanf("%d", &budget);

        array_size = cheese;
        greedy_choice array[array_size];

        i = 0;

        // Leitura dos volumes
        while(array_size != 0)
        {
            scanf("%d", &n);
            array[i].volume = n;
            array_size--;
            i++;
        }

        array_size = cheese;
        i = 0;

        // Leitura dos precos
        while(array_size != 0)
        {
            scanf("%d", &n);
            array[i].price = n;
            array_size--;
            i++;
        }

        // Definicao do valor da densidade = volume / preco
        for(i = 0; i < cheese; ++i)
        {
            array[i].density = (double)array[i].volume/array[i].price;
        }

        // Paradigma da mochila fracionaria
        cheese_volume = fractional_knapsack(cheese, budget, array);

        // Formula que define o valor da base da piramide
        base = (-1 + sqrt(1 + (8 * cheese_volume))) / 2;

        // Valor da base da piramidade de queijo
        printf("%d\n", (int)base);
        break;
    }
    return 0;
}