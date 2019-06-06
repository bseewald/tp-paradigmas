#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

// Funcao que calcula o histograma
// Baseado no problema "Largest Rectangle in Histogram"
int histogram(int blueprint_row[], int row_size){

    int area = 0, max_area = 0, stack_top;
	stack<int> hist;

    int i = 0;
	while(i < row_size){
		if(hist.empty() || blueprint_row[hist.top()] <= blueprint_row[i]){
            hist.push(i++);
        }
		else{
			stack_top = blueprint_row[hist.top()];
			hist.pop();

			if(!hist.empty())
				area = stack_top * (i - hist.top() - 1);
            else
                area = stack_top * i;

            max_area = max(area, max_area);
		}
	}

	while(!hist.empty()){
        stack_top = blueprint_row[hist.top()];
		hist.pop();

		if(!hist.empty())
			area = stack_top * (i - hist.top() - 1);
        else
            area = stack_top * i;

		max_area = max(area, max_area);
	}
    return max_area;
}

int main(){

    int n, m, k, c, l;
    int length, width;

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

    // Quantidade de mesas
    // c -> comprimento da mesa
    // l -> largura da mesa
    cin >> k;
    int w_tables[k];
    int area_tables[k];

    for (int i = 0; i < k; i++){
        cin >> c >> l;
        w_tables[i] = l;
        area_tables[i] = c*l;
        cout << area_tables[i] << " ";
    }

    // Baseado no problema "Maximum Size Rectangle of All 1's"
    int aux_table[m];
    memset(aux_table, 0, sizeof(aux_table));

    int max_table_area = histogram(blueprint[0], m);

    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if(blueprint[i][j] == 1)
                aux_table[j] = 1 + aux_table[j];
            else
                aux_table[j] = 0;
        }
        max_table_area = max(max_table_area, histogram(aux_table, m));
    }

    // TODO: associar area com maior mesa
    int table = 0;
    for(int i=0; i<k; i++){
        if(area_tables[i] <= max_table_area && table <= area_tables[i] && l < w_tables[i]){
            table = area_tables[i];
            l = w_tables[i];
        }
    }

    // Dimensoes da mesa de maior area que cabe na casa
    cout << l << " " << table/l << endl;
    return 0;
}