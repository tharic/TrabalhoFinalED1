#include "InicEstoque.h"

void inicializarLista(LISTA *l){ //Iniciando a lista
    l->inicio = NULL;
}

void inserirProdOrdQtd(LISTA *l, REGISTRO elemento){ //Inserir o produto no estoque ordenando pela quantidade
    PONT anterior = NULL, atual = NULL, novoElemento = NULL;

    novoElemento = (PONT) malloc(sizeof(ELEMENTO));

    novoElemento->reg = elemento; 
    novoElemento->prox = NULL;

    atual = l->inicio;

    while (atual!=NULL && atual->reg.qtdEstoque<elemento.qtdEstoque){
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL){
        l->inicio = novoElemento;
    } else {
        anterior->prox = novoElemento;
    }
}

void inserirProdOrdTamanho(LISTA *l, REGISTRO elemento){ //Inserir o produto no estoque ordenando pelo tamanho
    PONT anterior = NULL, atual = NULL, novoElemento = NULL;
    novoElemento = (PONT) malloc(sizeof(ELEMENTO));

    novoElemento->reg = elemento;
    novoElemento->prox = NULL; 

    atual = l->inicio;

    while (atual != NULL && strcmp(atual->reg.tamanho, elemento.tamanho) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        l->inicio = novoElemento;
    } else {
        anterior->prox = novoElemento;
    }
}

void adicionarEstoque(Produto produto){

    Estoque *novoEstoque = malloc(sizeof(Estoque));
    Estoque *aux = estoque;
    novoEstoque->produto = produto;
    aux->anterior = novoEstoque;
    novoEstoque->prox = &aux;
    novoEstoque->anterior = NULL;
    estoque = novoEstoque;
}

Estoque buscar(Estoque* l, Produto pesquisaProduto){
    Estoque* procura = l->inicio;
    while(procura != NULL){
        if(procura->produto.roupa == pesquisaProduto)
            return procura;
        procura = procura -> prox;
    }
    return (Estoque) NULL;
}

void reinicializarEstoque(LISTA *l){ //Apaga o estoque anterior

    PONT end = l->inicio;

    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
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
            buscar( );
            break;


            //teste commit
    }

    return 0;
}
