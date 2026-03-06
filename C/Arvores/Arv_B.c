#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3

struct NoB {
    char *elementos[2 * T - 1];
    struct NoB *filhos[2 * T];
    int m;
    int folha;
};

struct NoB *criarNo() {
    struct NoB *novoNo = (struct NoB *)malloc(sizeof(struct NoB));
    novoNo->m = 0;
    novoNo->folha = 1;
    int i;

    for (i = 0; i < 2 * T; i++) {
        novoNo->filhos[i] = NULL;
        novoNo->elementos[i] = NULL;
    }

    return novoNo;
}

void separarFilhos(struct NoB *pai, int indiceFilho, struct NoB *filho) {
    struct NoB *novoFilho = criarNo();
    novoFilho->folha = filho->folha;
    novoFilho->m = T - 1;
    int i;

    for(i = 0; i < T - 1; i++) {
        novoFilho->elementos[i] = filho->elementos[i + T];
    }

    if (!filho->folha) {
        for (i = 0; i < T; i++) {
            novoFilho->filhos[i] = filho->filhos[i + T];
        }
    }

    filho->m = T - 1;

    for (i = pai->m; i >= indiceFilho + 1; i--) {
        pai->filhos[i + 1] = pai->filhos[i];
    }

    pai->filhos[indiceFilho + 1] = novoFilho;

    for (i = pai->m - 1; i >= indiceFilho; i--) {
        pai->elementos[i + 1] = pai->elementos[i];
    }
    pai->elementos[indiceFilho] = strdup(filho->elementos[T - 1]);
    pai->m++;
}

struct NoB *inserir(struct NoB *raiz, char *elementos) {
    if (raiz->m == 2 * T - 1) {
        struct NoB *novoNo = criarNo();
        novoNo->folha = 0;
        novoNo->filhos[0] = raiz;
        separarFilhos(novoNo, 0, raiz);
        raiz = novoNo;
    }

    int indiceFilho = raiz->m - 1;

    while (indiceFilho >= 0 && strcmp(elementos, raiz->elementos[indiceFilho]) < 0) {
        indiceFilho--;
    }

    indiceFilho++;

    if (raiz->folha) {
    	int i;
        for (i = raiz->m; i > indiceFilho; i--) {
            raiz->elementos[i] = raiz->elementos[i - 1];
        }

        raiz->elementos[indiceFilho] = strdup(elementos);
        raiz->m++;
    } else {
        if (raiz->filhos[indiceFilho]->m == 2 * T - 1) {
            separarFilhos(raiz, indiceFilho, raiz->filhos[indiceFilho]);
            if (strcmp(elementos, raiz->elementos[indiceFilho]) > 0) {
                indiceFilho++;
            }
        }

        raiz->filhos[indiceFilho] = inserir(raiz->filhos[indiceFilho], elementos);
    }

    return raiz;
}

void imprimir(struct NoB *raiz, int camada) {
    if (raiz != NULL) {
        int i;
        for (i = 0; i < raiz->m; i++) {
            imprimir(raiz->filhos[i], camada + 1);
            printf("%s ", raiz->elementos[i]);
        }
        imprimir(raiz->filhos[i], camada + 1);
    }
}

int main() {
    struct NoB *raiz = criarNo();
    char *meses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    int i;

    int m = sizeof(meses) / sizeof(meses[0]);

    for (i = 0; i < m; i++) {
        raiz = inserir(raiz, meses[i]);
    }

    printf("Árvore B: ");
    imprimir(raiz, 0);
    printf("\n");

    return 0;
}
