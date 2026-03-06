#include<stdio.h>
#include<ctype.h>
#include<string.h>

void cifrar(char *texto, int chave){
	while(*texto){
		if(isalpha(*texto)){
			char base = islower(*texto) ? 'a' : 'A';
			*texto = (char) ((*texto - base + chave) % 26 + base);
		}
		texto++;
	}
}

int main(){
	char texto[256];
	int chave;
	
	printf("Digite uma frase a ser codificada:\n");
	fgets(texto, sizeof(texto), stdin);
	
	printf("Digite o valor da chave:\n");
	scanf("%d", &chave);
	
	cifrar(texto, chave);
	
	printf("Texto codificado: %s\n", texto);
	
	return 0;
}
