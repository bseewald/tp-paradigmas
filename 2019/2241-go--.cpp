#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n, p, l, c;
    int b_dim, w_dim;

    cin >> n >> p; // dimensao do tabuleiro e numero de pecas

    int board[n][n];

    // Zera matriz: sem pecas
    memset(board, 0, sizeof(board[0][0]) * n * n);

    // Cada jogador coloca suas pecas no tabuleiro
    for(int player=1; player<3; player++){
        for(int i=0; i<p; i++){
            cin >> l >> c;
            board[l-1][c-1] = player;
        }
    }

    // Valores do tabuleiro
    // 0: regiao sem peca
    // 1: regiao com peca preta
    // 2: regiao com peca branca
    // 3: regiao com ambas as pecas

    // Start Go--
    b_dim = p;
    w_dim = p;

    if(n > 2){
        for (int k = n; k > 2; k--){
            for (int i = 0; i < k-1; i++){
                for (int j = 0; j < k-1; j++){
                    if(board[i][j] == 3 || board[i][j+1] == 3 || board[i+1][j+1] == 3 || board[i+1][j] == 3){
                        //regiao mista
                        board[i][j] = 3;
                    }
                    else{
                        if(board[i][j] == 1){ // peca preta
                            if(board[i][j+1] != 2 && board[i+1][j+1] != 2 && board[i+1][j] != 2){ // nao tem vizinhos brancos
                                board[i][j] = 1; // regiao preta
                                b_dim += 1;
                            }
                            else
                                board[i][j] = 3; // regiao mista
                        }
                        else{
                            if(board[i][j] == 2){ // peca branca
                                if(board[i][j+1] != 1 && board[i+1][j+1] != 1 && board[i+1][j] != 1){ // nao tem vizinhos pretos
                                    board[i][j] = 2; //regiao branca
                                    w_dim += 1;
                                }
                                else
                                    board[i][j] = 3; // regiao mista
                            }
                            else{ // regiao sem peca
                                if((board[i][j+1] == 1 || board[i+1][j+1] == 1 || board[i+1][j] == 1) &&
                                    (board[i][j+1] != 2 && board[i+1][j+1] != 2 && board[i+1][j] != 2)){
                                    board[i][j] = 1; // regiao preta
                                    b_dim += 1;
                                }
                                else{
                                    if((board[i][j+1] == 2 || board[i+1][j+1] == 2 || board[i+1][j] == 2) &&
                                        (board[i][j+1] != 1 && board[i+1][j+1] != 1 && board[i+1][j] != 1)){
                                        board[i][j] = 2; // regiao branca
                                        w_dim += 1;
                                    }
                                    else{
                                        if ((board[i][j+1] == 2 || board[i+1][j+1] == 2 || board[i+1][j] == 2) &&
                                            (board[i][j+1] == 1 || board[i+1][j+1] == 1 || board[i+1][j] == 1)){
                                            board[i][j] = 3; // regiao mista
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Total de dimensoes de cada jogador
    cout << b_dim << " " << w_dim << endl;
    return 0;
}