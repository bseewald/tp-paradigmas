#include <cstring>
#include <cstdio>
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

    int n, m, k, c, l;

    // Casa com dimensao n x m
    scanf("%d %d", &n, &m);
    int blueprint[n][m];

    // Zera matriz
    memset(blueprint, 0, sizeof(blueprint[0][0]) * n * m);

    // Planta da casa:
    // . -> espaco vazio
    // # -> espaco preenchido
    char space[m];
    for (int i = 0; i < n; i++){
        scanf("%s", space);
        for (int j = 0; j < m; j++){
            if(space[j] == '.'){
                blueprint[i][j] = 1;
            }
        }
    }

    // Baseado no problema "Maximum Size Rectangle of All 1's"
    int house_measures_size = min(500, max(n, m));
    int house_measures[house_measures_size+1];
    for(int i=0; i<=house_measures_size; i++){
        house_measures[i] = -1;
    }

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

    int tables[2][house_measures_size+1];
    for (int i = 0; i <= house_measures_size; i++){
            tables[0][i] = i;
            tables[1][i] = house_measures[i];
    }

    // Quantidade de mesas
    // c -> comprimento da mesa
    // l -> largura da mesa
    int table_c = 0, table_l = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d %d", &c, &l);
        if((tables[0][c] == c && l <= tables[1][c]) || (tables[0][l] == l && c <= tables[1][l])){
            if((c*l > table_c*table_l) || (c*l == table_c*table_l && l > table_l)){
                table_c = c;
                table_l = l;
            }
        }
    }

    // Dimensoes da mesa de maior area que cabe na casa
    printf("%d %d\n", table_c, table_l);
    return 0;
}