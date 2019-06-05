#include <iostream>
#include <cstring>

using namespace std;

long long mod = 1000000007L;

// Funcao que soma os valores e verifica
// se precisa retornar valor como mod
long long add(long long x, long long y) {
  x += y;
  if (x < mod) return x;
  return x % mod;
}

int main(){

    int t, m, n;
    long long totalDiffTraining = 0L;

    // t: minutos exercicios
    // m: min dificuldade
    // n: max dificuldade
    cin >> t >> m >> n;

    int m_size = n-m+1;
    long long matrix[2][m_size];

    // Inicia toda a matriz com 1
    for(int i=0; i<m_size; i++) {
        matrix[0][i] = 1;
        matrix[1][i] = 1;
    }

    int k = 1;
    for(int i=1; i<t; i++){
        for(int j=1; j<(n-m); j++){
            // Soma quantidade de movimentos para cada posicao
            matrix[k][j] = add(matrix[1-k][j-1], matrix[1-k][j+1]);
        }
        // Extremos somente copia o valor do vizinho
        matrix[k][0] = matrix[1-k][1], 0;
        matrix[k][n - m] = matrix[1-k][n - m - 1];

        k = (i+1)%2;
    }

    // Seleciona a ultima linha atualizada
    k = (t%2==0 ? 1:0);

    // Soma quantidade total
    for(int j=0; j<m_size; j++){
        // printf("[%d][%d] : %lld \n", k, j, matrix[k][j]);
        totalDiffTraining = add(totalDiffTraining, matrix[k][j]);
    }

    cout << totalDiffTraining << endl;
    return 0;
}