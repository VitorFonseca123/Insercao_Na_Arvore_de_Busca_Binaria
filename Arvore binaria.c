#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura
{
    int chave;
    struct estrutura *esq;
    struct estrutura *dir;
} NO;

void inicializarArvore(NO **raiz)
{
    *raiz = NULL;
}

bool arvoreVazia(NO *raiz)
{
    if (!raiz)
        return (true);
    else
        return (false);
}
NO *buscaNo(NO *raiz, int ch, NO **pai)
{
    NO *atual = raiz;
    *pai = NULL;
    while (atual)
    {
        if (atual->chave == ch)
            return (atual);
        *pai = atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return (NULL);
}
bool inserir(NO **raiz, int ch)
{
    NO *pai = NULL;
    NO *atual = buscaNo(*raiz, ch, &pai);
    if (atual)
        return false;
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    if (pai)
    {
        if (ch < pai->chave)
            pai->esq = novo;
        else
            pai->dir = novo;
    }
    else
        *raiz = novo;
    return true;
}
void exibir(NO *p)
{ // pré ordem
    if (p)
    {
        printf("%d ", p->chave);
        exibir(p->esq);
        exibir(p->dir);
    }
}

int main()
{

    NO *A;
    int n = 5;
    int vetor[5] = {5, 2, 3, 1, 4};

    for (int i = 0; i < n; i++)
    {
        inserir(&A, vetor[i]);
    }
    exibir(A);
}
