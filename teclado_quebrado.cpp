#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 1000010
#define KEYBOARD_SIZE 128

char text[TEXT_SIZE];
int keys;

int bigger_substring_size = 0;

int bigger_substring(){

    int substring_counter[KEYBOARD_SIZE];
    int curr_start = 0, curr_end = keys-1;
    int text_actual_size = strlen(text);
    int keys_used = 0, counter_aux = 0;

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

    // Enquanto o texto nao terminou
    while(curr_end < text_actual_size-2){
        // Ainda nao atingiu o limite de teclas
        while(keys_used <= keys && (curr_end < text_actual_size-2))
        {
            // Verifica o caractere seguinte no final da substring
            curr_end++;
            // Novo caractere ?
            if(substring_counter[text[curr_end]] == 0){
                keys_used++;
            }
            // Aumenta o contador do caractere
            substring_counter[text[curr_end]]++;
        }
        // Se ultrapassou o limite de teclas, entao avanca em 1 caractere
        // no inicio da substring
        if(keys_used > keys){
            curr_start++;
        }

        // Essa substring eh maior que as computadas antes ?
        if((curr_end - curr_start + 1) > bigger_substring_size){
            bigger_substring_size = curr_end - curr_start + 1;
        }

        // Decrementa o contador do caractere que foi retirado da
        // substring. Se ele voltou para zero, entao temos um caractere
        // unico a menos e precisamos decrementar o contador de teclas
        // usadas
        if(substring_counter[text[curr_start-1]] > 0){
            substring_counter[text[curr_start-1]]--;
            counter_aux = substring_counter[text[curr_start-1]];
            if(counter_aux == 0){
                keys_used--;
            }
        }
    }
    return 0;
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