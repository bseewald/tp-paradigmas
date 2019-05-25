#include <stdio.h>
#include <stdlib.h>

int inversions;

void merge(int array[], int init, int mid, int final){

    int left = init;
    int right = mid + 1;

    int *arrayAux;
    int aux = 0;

    arrayAux = (int*)malloc((final-init+1) * sizeof(int));

    // Ainda nao percorreu uma das metades
    while(left <= mid && right <= final)
    {
        // Adiciona no array auxiliar, se a da esquerda for menor
        if(array[left] < array[right]) {
            arrayAux[aux++] = array[left++];
        }
        else {
            arrayAux[aux++] = array[right++];
            // Quando um elemento da segunda metade eh menor, entao ocorre a inversao
            inversions += (mid - left + 1);
        }
    }

    // Ja percorreu uma metade, so adicionar os elementos da outra metade
    while(left <= mid)
        arrayAux[aux++] = array[left++];

    while(right <= final)
        arrayAux[aux++] = array[right++];

    // Copia tudo para o array original
    for(int i = init; i <= final; i++){
        array[i] = arrayAux[i-init];
    }
}

void mergeSort(int array[], int init, int final){

    if(init < final){
        int mid = (init + final)/2;

        mergeSort(array, init, mid);
        mergeSort(array, mid+1, final);
        merge(array, init, mid, final);
   }
}

int main(){

    int n, i;
    int array_size, array_size_aux;

    while(true)
    {
        i = 0;
        inversions = 0;

        // Leitura do tamanho do array de entrada
        scanf("%d", &array_size_aux);
        array_size = array_size_aux;

        // Array que ira guardar os numeros fornecidos no input
        int array_numbers[array_size];

        // Leitura dos numeros do input
        while(array_size_aux != 0)
        {
            scanf("%d", &n);
            array_numbers[i] = n;
            array_size_aux--;
            i++;
        }

        // Caso de saida, terminou a execucao
        if(array_size == 0){
            break;
        }
        else {
            // Paradigma: divisao e conquista
            mergeSort(array_numbers, 0, array_size);
        }

        // Se o total de inversoes for PAR entao Carlos eh o vencedor, IMPAR eh Marcelo
        if(inversions % 2 == 0){
            printf("Carlos\n");
        }
        else{
            printf("Marcelo\n");
        }
    }
    return 0;
}