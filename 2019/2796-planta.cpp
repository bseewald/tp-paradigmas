#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n, m, k, c, l;
    int l_table, w_table;

    // casa com dimensao n x m
    cin >> n >> m;

    // planta da casa:
    // . -> espaco vazio
    // # -> espaco preenchido
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // TODO 1: ler
        }
    }
    
    // quantidade de mesas
    // c -> comprimento da mesa
    // l -> largura da mesa
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> c >> l;
        // TODO 2: guardar mesas
    }
    
    // TODO 3: verificar qual a maior mesa

    // Dimensoes da mesa de maior area que cabe na casa
    cout << l_table << " " << w_table << endl;
    
    return 0;
}