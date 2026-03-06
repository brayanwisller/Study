#include<stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>

#define tam_bloco 8

int mdc(int a, int b){ // funçao para calcular maximo divisor comum
	while(b != 0){
		int temp = b;
		b = a % b;
		a = temp;
    }
    
    return a;
}

int mod_inverso(int e, int phi){ // funçao para calcular o modulo inverso
    int t = 0, novo_t = 1;
    int r = phi, novo_r = e;
    
    while (novo_r != 0) {
        int totiente = r / novo_r;
        t = novo_t;
        novo_t = t - totiente * novo_t;
        r = novo_r;
        novo_r = r - totiente * novo_r;
    }
    
    if (r > 1){
        return -1;  
    }
    if (t < 0){
        t = t + phi;
    }
    return t;
}


void gerar_chaves_rsa(int q, int p, int *e, int *d, int *n){ // funçao para gerar as chaves utilizadas no RSA
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = 3;
    
    while (mdc(*e, phi) != 1){
        (*e) += 2;
    }
    
    *d = mod_inverso(*e, phi);
}


int criptografar_rsa(int texto, int e, int n){ // funçao para criptografar em RSA
	int i;
    int cifratexto = 1;
    for (i = 0; i < e; i++){
        cifratexto = (cifratexto * texto) % n;
    }
    return cifratexto;
}


int descriptografar_rsa(int cifratexto, int d, int n) { // funçao para descriptografar em RSA
    int texto = 1;
    int i;
    
    for (i = 0; i < d; i++){
        texto = (texto * cifratexto) % n;
    }
    return texto;
}

void permutacao_inicial(char *bloco){
	char temp[tam_bloco];
	memcpy(temp, bloco, tam_bloco);
	memcpy(bloco, temp, tam_bloco);
}

void permutacao_final(char *bloco){
	
}

void criptografar_des(char *texto, char *chave){
    char bloco[tam_bloco];
    memcpy(bloco, texto, tam_bloco);
    
    permutacao_inicial(bloco);
    
    int i;
    for (i = 0; i < tam_bloco; i++) {
        bloco[i] ^= chave[i % tam_bloco];
    }
    permutacao_final(bloco);
    
    printf("\nTexto cifrado: ");
    for (i = 0; i < tam_bloco; i++){
        printf("%02x", (unsigned char)bloco[i]);
    }
    printf("\n");
}

void descriptografar_des(char *cifratexto, char *chave){
    char bloco[tam_bloco];
    memcpy(bloco, cifratexto, tam_bloco);
    
    permutacao_inicial(bloco);
    
	int i;
    for (i = 0; i < tam_bloco; i++){
        bloco[i] ^= chave[i % tam_bloco];  
    }
    permutacao_final(bloco);
    
    printf("\nMensagem descriptografada: ");
    for (i = 0; i < tam_bloco; i++){
        printf("%c", bloco[i]);
    }
    printf("\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, escolher, n, q, p, e, d;
	char chave[8];
	char mensagem[8];
	
	printf("Escolha qual das seguintes opções deseja realizar:\n\n");
	printf("1 - RSA\n2 - DES\n\n");
	printf("Opção: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			printf("\nVocê escolheu a criptografia RSA!\n\n");
			printf("Digite dois números para q e p: \n");
			scanf("%d %d", &q, &p);
			
			gerar_chaves_rsa(q, p, &e, &d, &n);
			
			 printf("\nChave pública: (e=%d, n=%d)\n", e, n);
        	printf("Chave privada: (d=%d, n=%d)\n", d, n);
        	
        	printf("\nEscolha se deseja criptografar ou descriptografar:\n\n 1 - Criptografar / 2 - Descriptografar\n\n");
        	
        	printf("Opção: ");
        	scanf("%d", &escolher);
        	
        	if(escolher == 1){
        		int texto;
        		
        		printf("\nVocê escolheu criptografar!\n\n");
        		printf("Digite um numero a ser criptografado: ");
        		scanf("%d", &texto);
        		
        		int cifratexto = criptografar_rsa(texto, e, n);
        		printf("\nTexto cifrado: %d\n", cifratexto);
			} else if(escolher == 2){
				int texto;
				
				printf("\nVocê escolheu descriptografar!\n\n");
				printf("Digite o numero a ser descriptografado: ");
				scanf("%d", &texto);
				
				int cifratexto= descriptografar_rsa(texto, n, e);
				printf("\nTexto Descriptografado: %d\n", cifratexto);
			} else {
				printf("\nOpção Inválida!\n");
			}
			
			break;
			
			case 2:
				printf("\nVocê escolheu a criptografia DES!\n\n");
				printf("Digite a chave de 8 caracteres: ");
				scanf("%s", &chave);
				printf("\nDigite a mensagem a ser utilizada com 8 caracteres: ");
				scanf("%s", &mensagem);
				
				printf("\nEscolha se deseja criptografar ou descriptografar:\n\n 1 - Criptografar / 2 - Descriptografar\n\n");
				printf("Opção: ");
        		scanf("%d", &escolher);
        		
        		if(escolher == 1){
        			printf("\nVocê escolheu criptografar!\n");
        			criptografar_des(mensagem, chave);
				} else if(escolher == 2){
					printf("\nVocê escolheu descriptografar!\n");
					descriptografar_des(mensagem, chave);
				} else {
					printf("\nOpção Inválida!\n");
				}
				break;
				
				default:
					printf("\nOpção Inválida!\n");
					break;
	}
	
	return 0; 
}
