#include <stdio.h>
#include <algorithm>
#include <tuple>

using namespace std;

tuple<int, int> maxSubarray(int array[], int days, int cost){

    tuple <int, int> profit;

    if(days == 1){
        get<0>(profit) = max(array[0]-cost, 0);
        get<1>(profit) = get<0>(profit);
        return profit;
    }

    profit = maxSubarray(array, days-1, cost);
    get<0>(profit) = max(get<0>(profit), get<1>(profit) + array[days-1] - cost);
    get<1>(profit) = max(0, get<1>(profit) + array[days-1] - cost);

    return profit;
}

int main(){

    int i, n;
    int nDays, dayCosts, arraySize;

    tuple <int, int> maxProfit;

    while(scanf("%d", &nDays) != EOF) // Numero de dias do circo na cidade
    {
        // Custo por dia
        scanf("%d", &dayCosts);

        // Array que ira guardar os numeros fornecidos no input
        int arrayNumbers[nDays];

        arraySize = nDays;
        i=0;

        // Leitura dos numeros do input
        while(arraySize!=0){
            scanf("%d", &n);
            arrayNumbers[i] = n;
            arraySize--;
            i++;
        }

        // Subvetor de soma maxima
        maxProfit = maxSubarray(arrayNumbers, nDays, dayCosts);

        // max de dinheiro que George pode ganhar
        printf("%d\n", get<0>(maxProfit));
    }
    return 0;
}