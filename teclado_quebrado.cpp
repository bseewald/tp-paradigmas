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
	int keys_used = 0;

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

	for (unsigned long i = 0; i < strlen(text)-1; i++)
	{
		curr_start = i;

		// Ainda nao atingiu o limite de teclas
		while((keys_used <= keys) && (curr_end < strlen(text)-1))
		{
			curr_end++;
			if(substring_counter[text[curr_end]] == 0){
				keys_used++;
			}
			substring_counter[text[curr_end]]++;
			printf("%c %d %d \n", text[curr_end], substring_counter[text[curr_end]], keys_used);
		}

		if((curr_end - curr_start) > bigger_substring_size)
			bigger_substring_size = curr_end - curr_start;

		substring_counter[text[curr_start]] = 0;
		keys_used--;
	}
}

int main()
{
    while(true){

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