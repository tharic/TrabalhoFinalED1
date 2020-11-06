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

void buscar(Produto produto){

}

void removerEstoque(Produto produto){

//buscar produto

}

void vender(){//adicionar parâmetros

//buscar produto
//reduzir quantidade
    //quantidade = 0 => remover estoque

}

void atualizarEstoque(){//adicionar parâmetros

//buscar produto
//consultar quantidade
//alterar quantidade ou cadastrar novo produto

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
        //if qtd == 0
        adicionarEstoque(*p);
    }

    //else if quantidade do produto != 0 -> atualizar estoque

}

int main() {

    //menu
    int opcao;
    printf("\n\t\tO que voce deseja fazer?\n");
    printf("\n1 - Vender Produto");
    printf("\n2 - Adicionar algo ao estoque");
    printf("\n3 - Consultar produtos em estoque");
    printf("\n\nOPCAO: ");

    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("Vendendo: ");
            scanf("");
            printf("Quantidade: ");
            scanf("");
            printf("Preço:" );
            scanf("");
            vender();
            break;

        case 2:
            printf("Produto: ");
            scanf("");

            atualizarEstoque();
            break;

        case 3:
            printf("O que deseja buscar? ");
            scanf(" ");
            buscar();
            break;


            //teste commit
    }

    return 0;
}
