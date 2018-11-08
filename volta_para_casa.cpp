#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int volume;
    int price;
    float density;
} greedy_choice;

int density(const void *item_a, const void *item_b){

    greedy_choice *a = (greedy_choice *)item_a;
    greedy_choice *b = (greedy_choice *)item_b;

    unsigned int ratio_a = a->density;
    unsigned int ratio_b = b->density;

    if (ratio_a > ratio_b) {
        return -1;
    }
    else if (ratio_a == ratio_b) {
        return 0;
    }
    return 1;
}

int *fractional_knapsack(int total_itens, int knapsack_size, greedy_choice *itens){

    int j = total_itens-1;
    int k_size = knapsack_size;

    qsort(itens, total_itens, sizeof(greedy_choice), density);

    while(j >= 0)
    {
        if(density[j] <= size)
        {
            size -=
        }
        else{

        }
        j--;
    }
    return 0;
}

int main(){

    int cheese, budget, array_size, n, i;

    while(true)
    {
        scanf("%d", &cheese);
        scanf("%d", &budget);

        array_size = cheese;
        greedy_choice array[array_size];

        i = 0;

        // Leitura dos numeros do input
        while(array_size != 0)
        {
            scanf("%d", &n);
            array[i].volume = n;
            array_size--;
            i++;
        }

        array_size = cheese;
        i = 0;
        while(array_size != 0)
        {
            scanf("%d", &n);
            array[i].price = n;
            array_size--;
            i++;
        }

        for(i = 0; i < cheese; ++i)
        {
            array[i].density = (float) array[i].volume/array[i].price;
        }

        fractional_knapsack(cheese, budget, array);

    }
    return 0;
}