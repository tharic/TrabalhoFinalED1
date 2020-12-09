#ifndef INC_ESTOQUE_CABECALHO
#define INC_ESTOQUE_CABECALHO
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

void inicializarLista(LISTA *l);
void inserirProdOrdQtd(LISTA *l, REGISTRO elemento);
void inserirProdOrdTamanho(LISTA *l, REGISTRO elemento);
void excluirProduto(LISTA *l, int elementoExcluir);
void exibirEstoque(LISTA *l);
void buscarProduto(LISTA *l, int codigoBuscar);
void reinicializarEstoque(LISTA *l);
void menuInicial();
void menuCompleto();
void limparTela();

#endif
