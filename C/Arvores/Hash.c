#include <stdio.h>
#include <stdlib.h>

#define m  11


struct tabela_entrada {
    int chave;
    int excluido;
};

typedef struct tabela_entrada tb_in;

int hash1(int chave){
    return chave % m;
};

int hash2(int chave){
    return (int)(m * (chave * 0.9 - (int)(chave * 0.9)));
};

int busca(int chave, tb_in tabela1[], tb_in tabela2[]){
    int id1 = hash1(chave);
    int id2 = hash2(chave);

    if (tabela1[id1].chave == chave && !tabela1[id1].excluido){
        return id1;
    } else if (tabela2[id2].chave == chave){
        return id2;
    } else {
        return -1;
    };
};

void inserir(int chave, tb_in tabela1[], tb_in tabela2[]){
    int id1 = hash1(chave);
    int id2 = hash2(chave);

    if (tabela1[id1].chave == 0 || tabela1[id1].excluido){
        tabela1[id1].chave = chave;
        tabela1[id1].excluido = 0;
    } else {
        int current_key = tabela1[id1].chave;
        tabela1[id1].chave = chave;
        tabela1[id1].excluido = 0;

        inserir(current_key, tabela2, tabela1);
    };
};

void excluir(int chave, tb_in tabela1[], tb_in tabela2[]){
    int id1 = hash1(chave);
    int id2 = hash2(chave);

    if (tabela2[id2].chave == chave){
        tabela2[id2].chave = 0;
    } else {
        tabela1[id1].chave = 0;
        tabela1[id1].excluido = 1;
    };
};

void printTabela(tb_in tabela1[], tb_in tabela2[]){
	int i;
	
    printf("T1: ");
    
    for (i = 0; i < m; i++){
        if (tabela1[i].chave == 0){
            printf("[ ] ");
        } else if (tabela1[i].excluido){
            printf("[X] ");
        } else {
            printf("[%d] ", tabela1[i].chave);
        };
    };

    printf("\nT2: ");
    
    for (i = 0; i < m; i++){
        if (tabela2[i].chave == 0){
            printf("[ ] ");
        } else {
            printf("[%d] ", tabela2[i].chave);
        };
    };

    printf("\n");
};

int main(){
    tb_in tabela1[m] = {0};
    tb_in tabela2[m] = {0};

    int chave[] = {10, 22, 4, 15, 59};
    int i;

    for (i = 0; i < sizeof(chave) / sizeof(chave[0]); i++){
        inserir(chave[i], tabela1, tabela2);
        printTabela(tabela1, tabela2);
        printf("\n");
    };

    int chave_excluida[] = {15, 22, 59};
    for (i = 0; i < sizeof(chave_excluida) / sizeof(chave_excluida[0]); i++){
        excluir(chave_excluida[i], tabela1, tabela2);
        printTabela(tabela1, tabela2);
        printf("\n");
    };

    return 0;
};

