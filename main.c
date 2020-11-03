#include <stdio.h>
#include <stdlib.h>

typedef struct roupa{

    char tamanho; //P , M, G, GG, etc
    int quantidade;
    char* tipo;

    float precoCusto;
    float precoVenda;
    float lucro;
}Produto;

typedef struct estoque{

    Produto produto;
    struct estoque* prox;
    struct estoque* anterior;

}Estoque;

Estoque *estoque;

void novoEstoque(Produto produto){
    estoque = malloc(sizeof(Estoque));
    estoque->produto = produto;
    estoque->prox = NULL;
    estoque->anterior = NULL;
};

void adicionarEstoque(Produto produto){

    Estoque *novoEstoque = malloc(sizeof(Estoque));
    Estoque *aux = estoque;
    novoEstoque->produto = produto;
    aux->anterior = novoEstoque;
    novoEstoque->prox = &aux;
    novoEstoque->anterior = NULL;
    estoque = novoEstoque;
}

void buscar(){


}

void removerEstoque(Produto produto){

//buscar produto

}

void vender(){

//buscar produto
//reduzir quantidade

}

void atualizarEstoque(){

//buscar produto
//alterar quantidade

}



void novoProduto(char* tipo, char tamanho,  int qtd, float precoCusto){

    Produto *p = malloc(sizeof(Produto));

    p->quantidade = qtd;
    p->tipo = tipo;
    p->precoCusto = precoCusto;
    p->tamanho = tamanho;

    if(estoque == NULL){
        novoEstoque(*p);
    }
    else{
        adicionarEstoque(*p);
    }

    //else if quantidade do produto != 0 -> atualizar estoque

}

int main() {

    return 0;
}
