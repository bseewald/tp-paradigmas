#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 1000000
#define KEYBOARD_SIZE 128

char text[TEXT_SIZE];
int keyboard[KEYBOARD_SIZE];
int keys;

int bigger_substring_size = 0;

void bigger_substring(){

    int substring_counter[KEYBOARD_SIZE];
    int keys_used = 0, counter_aux = 0;
    int curr_start = 0, curr_end = keys-1;

    // Zera contadores
    for (int i = 0; i < KEYBOARD_SIZE; ++i)
        substring_counter[i] = 0;

    // Contadores para cada caractere
    for (int i = 0; i < keys; ++i){
        if(substring_counter[text[i]] == 0){
            // Quantidade de caracteres diferentes
            keys_used++;
        }
        substring_counter[text[i]]++;
    }

    while(curr_end < (strlen(text)-2)){
        // Ainda nao atingiu o limite de teclas
        while(keys_used <= keys)
        {
            curr_end++;
            if(substring_counter[text[curr_end]] == 0){
                keys_used++;
            }
            substring_counter[text[curr_end]]++;
        }
        if(keys_used > keys){
            curr_start++;
        }

        if((curr_end - curr_start + 1) > bigger_substring_size){
            bigger_substring_size = curr_end - curr_start + 1;
        }

        if(substring_counter[text[curr_start-1]] > 0){
            substring_counter[text[curr_start-1]]--;
            counter_aux = substring_counter[text[curr_start-1]];
            if(counter_aux == 0){
                keys_used--;
            }
        }
    }
}

int main()
{
    while(true){

        bigger_substring_size = 0;

        // Leitura do input: numero de teclas restantes
        scanf("%d", &keys);
        getchar();

        if(keys != 0){
            // Leitura do texto
            if(fgets(text, TEXT_SIZE, stdin) != NULL){
                bigger_substring();
            }
            printf("%d\n", bigger_substring_size);
        }
        else{
            // Ultimo caso de teste
            break;
        }
    }
    return 0;
}