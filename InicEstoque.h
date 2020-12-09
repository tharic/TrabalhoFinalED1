#ifndef CONTROLE_ESTOQUE_HEADER
#define CONTROLE_ESTOQUE_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int   codigo;
    char  nome[75];
    float precoVenda;
    char  tamanho[4]; //P, M, G, GG e outros.
    int   qtdEstoque;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

void inicializarEstoque(LISTA *l);
void inserirProdutoOrdenadoQuantidade(LISTA *l, REGISTRO elemento);
void inserirProdutoOrdenadoTamanho(LISTA *l, REGISTRO elemento);
void excluirProduto(LISTA *l, int elementoExcluir);
void exibirEstoque(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void reinicializarEstoque(LISTA *l);
void menuInicial();
void menuCompleto();
void limparTela();

#endif
