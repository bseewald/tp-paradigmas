#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;

tuple<int, int> go(int mat){

    tuple <int, int> dim;
    
    get<0>(dim) = 0;
    get<1>(dim) = 0;
    
    return dim;
}

int main(){

    int n, p, pw, pb, l, c;
    tuple <int, int> dimensions;

    cin >> n >> p; // dimensao do tabuleiro e numero de pecas

    int board[n][n];
    memset(board, 0, sizeof(board[0][0]) * n * n);

    pb = pw = p;

    // Black stones
    while (pb > 0)
    {
        cin >> l >> c;
        board[l][c] = 0;
        pb--;
    }

    // White stones
    while (pw > 0)
    {
        cin >> l >> c;
        board[l][c] = 1;
        pw--;
    }

    dimensions = go(board);

    // blacks whites
    cout << get<0>(dimensions) << " " << get<1>(dimensions) << endl;
    return 0;
}