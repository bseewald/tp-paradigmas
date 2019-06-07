#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

// Funcao que calcula o histograma
// Baseado no problema "Largest Rectangle in Histogram"
int histogram(int blueprint_row[], int row_size, int house_measures[]){

    int stack_top, width;
	stack<int> hist;

    int i = 0;
	while(i < row_size){
		if(hist.empty() || blueprint_row[hist.top()] <= blueprint_row[i]){
            hist.push(i++);
        }
		else{
			stack_top = blueprint_row[hist.top()];
			hist.pop();
            width = i;
			
            if(!hist.empty()){
                width = i - hist.top() - 1;
            }

            if(house_measures[stack_top] < width){
                house_measures[stack_top] = width;
            }
		}
	}

	while(!hist.empty()){
        stack_top = blueprint_row[hist.top()];
		hist.pop();
        width = i;

        if(!hist.empty()){
            width = i - hist.top() - 1;
        }

        if(house_measures[stack_top] < width){
            house_measures[stack_top] = width;
        }
	}
    return 0;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, c, l;

    // Casa com dimensao n x m
    cin >> n >> m;
    int blueprint[n][m];

    // Zera matriz
    memset(blueprint, 0, sizeof(blueprint[0][0]) * n * m);

    // Planta da casa:
    // . -> espaco vazio
    // # -> espaco preenchido
    string space;
    cin.ignore();
    for (int i = 0; i < n; i++){
        getline(cin, space);
        for (int j = 0; j < m; j++){
            if(space[j] == '.'){
                blueprint[i][j] = 1;
            }
        }
    }

    int house_measures_size = min(500, max(n, m));
    int house_measures[house_measures_size+1];
    for(int i=0; i<=house_measures_size; i++){
        house_measures[i] = -1;
    }

    // Quantidade de mesas
    // c -> comprimento da mesa
    // l -> largura da mesa
    cin >> k;
    int tables[3][k];
    for (int i = 0; i < k; i++){
        cin >> c >> l;
        tables[0][k] = c;
        tables[1][k] = l;
        tables[2][k] = c*l;
    }

    // Baseado no problema "Maximum Size Rectangle of All 1's"
    int aux_table[m];
    memset(aux_table, 0, sizeof(aux_table));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(blueprint[i][j] == 1)
                aux_table[j] = 1 + aux_table[j];
            else
                aux_table[j] = 0;
        }
        histogram(aux_table, m, house_measures);
    }

    // Associar area com maior mesa possivel
    int area = 0, table_selected = 0;
    for(int i=1; i<=house_measures_size; i++){ // vetor com as medidas dos quartos
        if(house_measures[i] != -1){
            area = house_measures[i] * i;
            for (int i = 0; i<k; i++){
                if(tables[2][i] <= area && tables[1][i] <= house_measures[i] && tables[0][i] <= i){
                    if(){
                       // a mesa selecionada
                       table_selected = i;
                    }
                }
            }
        }
    }

    // Dimensoes da mesa de maior area que cabe na casa
    // cout << table/l << " " << l << "\n";;
    return 0;
}