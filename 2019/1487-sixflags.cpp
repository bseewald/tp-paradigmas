#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Parametros
// W : peso maximo da mochila
// wt : peso dos itens
// val : valor dos itens
// n : total de itens
//
int knapsack(int W, int wt[], int val[], int n)
{
    int K[W+1];
    memset(K, 0, sizeof(K));

    for (int i=0; i<=W; i++)
        for (int j=0; j<n; j++)
            if (wt[j] <= i)
                K[i] = max(K[i], K[i-wt[j]] + val[j]);
    return K[W];
}

int main(){

    int numberAttractions, timeAvailable, points;
    int arraySize, i, n=1;

    // Leitura do numero de atracoes e tempo disponivel
    while ((cin >> numberAttractions >> timeAvailable) && numberAttractions!= 0)
    {
        // Vetores de peso e valor dos itens
        int arrayAttractionTime[numberAttractions], arrayAttractionPoints[numberAttractions];

        arraySize = numberAttractions;
        i=0;

        // Leitura da duracao de cada atracao e a pontuacao
        while (arraySize != 0)
        {
            cin >> arrayAttractionTime[i] >> arrayAttractionPoints[i];
            arraySize--;
            i++;
        }

        // Retorna o valor maximo que pode ser colocado na mochila (pontuacao total)
        points = knapsack(timeAvailable, arrayAttractionTime, arrayAttractionPoints, numberAttractions);
        cout << "Instancia " << n << "\n" << points << "\n\n";
        n++;
    }
    return 0;
}