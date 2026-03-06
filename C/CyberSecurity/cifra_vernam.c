#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void criptografia(const char *mensagem, const char *chave, char *resultado){
	int tamanhoMensagem = strlen(mensagem);
	int tamanhoChave = strlen(chave);
	int i;
	
	for(i = 0; i < tamanhoMensagem; i++){
		resultado[i] = mensagem[i] ^ chave[i % tamanhoChave];
	}
	
	resultado[tamanhoMensagem] = '\0';
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char mensagem[256];
	char chave[256];
	char resultado[256];
	int i;
	
	printf("Digite a mensagem a ser cifrada: \n");
	fgets(mensagem, sizeof(mensagem), stdin);
	mensagem[strcspn(mensagem, "\n")] = '\0';
	
	printf("Digite a chave para a criptografia: \n");
	fgets(chave, sizeof(chave), stdin);
	chave[strcspn(chave, "\n")] = '\0';
	
	if(strlen(chave) == 0){
		printf("A chave não pode ser nula\n");
		return 1;
	}
	
	criptografia(mensagem, chave, resultado);
	
	printf("A mensagem criptografada é: \n");
	
	for(i = 0; i < strlen(resultado); i++){
		printf("%02X", (unsigned char) resultado[i]);
	}
	
	printf("\n");
	
	return 0;
}
