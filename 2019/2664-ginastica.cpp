#include <iostream>
#include <cstring>

long long mod = 100000LL * 10000LL + 7;

long long add(long long x, long long y) {
  x += y;
  if (x < mod) return x;
  return x % mod;
}

int main(){

    int t, m, n;
    long long diffTraining;

    // t: minutos exercicios
    // m: min dificuldade
    // n: max dificuldade
    cin >> t >> m >> n; 

    long long matrix[n-m+1][n-m+1];

    // Zera matriz
    memset(matrix, 0, sizeof(matrix));

    // Primeira linha 1 movimento
    for(int i=1; i<n; i++) {
        matrix[0][i] = 1;
    }

    int k = 1;
    for(int i=1; i<t; k=(++i%2)){
        for(int j=1; j<m; j++){
            // Soma quantidade de movimentos para cada posicao
            matrix[k][j] = matrix[1-k][j-1] + matrix[1-k][j+1];
        }
    }

    // Soma quantidade total
    

    cout << diffTraining << endl;
    return 0;
} 