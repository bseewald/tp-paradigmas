#include <stdio.h>

// M (1 ≤ M ≤ 10ˆ3) e V (1 ≤ V ≤ 10ˆ5)
bool states[1005][100005];

//Mi (1 ≤ Mi ≤ 10ˆ5)
long int array_coins[1005];

int answer = 0;
int n_coins;
long int value;

int can_i_pay(int coin, long int sum){

    // Estado nao foi visitado
    if(!states[coin][sum]){

        // Marca estado visitado
        states[coin][sum] = 1;

        // Exato valor ?
        if(sum == value){
            answer = 1;
            return 0;
        }
        // Acabaram as moedas ou a soma ja eh maior que o value
        if(coin > n_coins-1 || sum > value)
            return 0;

        // Proximos estados possiveis
        can_i_pay(coin+1, sum + array_coins[coin]);
        can_i_pay(coin+1, sum);
    }
    return 0;
}


int main(){

    // Leitura do input: valor da compra e numero de moedas
    scanf("%li", &value);
    scanf("%d", &n_coins);

    // Leitura dos valores das moedas do input
    for (int i = 0; i < n_coins; i++)
        scanf("%li", &array_coins[i]);

    // Programacao Dinamica: algoritmo top-down
    can_i_pay(0, 0);

    if(answer){
        printf("S\n");
    }
    else{
        printf("N\n");
    }
    return 0;
}