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

void adicionarEstoque(REGISTRO produto){

    REGISTRO *novoEstoque = malloc(sizeof(REGISTRO));
    REGISTRO *aux = estoque;
    novoEstoque->nome = produto;
    aux->anterior = novoEstoque;
    novoEstoque->prox = &aux;
    novoEstoque->anterior = NULL;
    estoque = novoEstoque;
}

void buscarProduto(LISTA *l, int codigoBuscar){ // Procura um produto no estoque por código

    PONT auxiliar = l->inicio;

    if(auxiliar == NULL){
        
    } else {

        while(auxiliar != NULL && auxiliar->reg.codigo < codigoBuscar){

            auxiliar = auxiliar->prox; 
        }
            if(auxiliar != NULL && auxiliar->reg.codigo == codigoBuscar){
                printf("\n Codigo: %d \n\n Nome: %s \n Preco de venda: %f \n\n Pais: %s \n Quantidade em estoque: %d \n\n",auxiliar->reg.codigo,auxiliar->reg.nome,auxiliar->reg.precoVenda,auxiliar->reg.tamanho,auxiliar->reg.qtdEstoque);
            } else {
                printf("\n Produto nao encontrado!\n");
            }
    }
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

void exibirEstoque(LISTA *l) {
    if(end==NULL) {
        printf("\n Nenhum elemento inserido no estoque.\n");
    } else {
        printf("\n Estoque:\n\n");
        while(end!=NULL) {
            printf(" Codigo: %d \n\n Nome: %s \n Preco de venda: %f \n\n Tamanho: %s \n Quantidade em estoque: %d \n\n",end->reg.codigo,end->reg.nome,end->reg.precoVenda,end->reg.tamanho,end->reg.qtdEstoque);
            printf("\n------------------------------------------------------------------------------------------------\n");
            
            end = end->prox;
        }
    }

}
void excluirProduto(LISTA *l, int elementoExcluir) {
    PONT anterior, atual;
    anterior = NULL;

    atual = l->inicio;

    while(atual!=NULL && atual->reg.codigo<elementoExcluir) {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual==NULL){
        printf("\n O produto informado nao esta cadastrado.\n");
    } else {
        if(anterior==NULL) {
            l->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        printf("\n O produto %d foi excluido.\n",elementoExcluir);
    }
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

void menuInicial() {
    printf("\n [1] Iniciar o estoque");
    printf("\n [0] Sair\n\n");
    printf("Digite a opcao para continuar: ");
}

void menuCompleto() {
    printf("\n [1] Inserir uma roupa no estoque");
    printf("\n [2] Exibir o estoque de roupas");
    printf("\n [3] Excluir/vender uma roupa do estoque");
    printf("\n [4] Buscar uma roupa no estoque");
    printf("\n [5] Refazer o estoque");
    printf("\n [0] Sair\n\n");
    printf("Digite a opcao para continuar: ");
}



int main() {

    int opcao=NULL, registroExcluir, registroBuscar;

    LISTA listaEstoque;
    REGISTRO elemento;
    printf(" ************************");
    printf("\n Estoque de roupa 1.0.net\n");
    printf(" ************************\n");
    menuInicio:
    menuInicial();
    scanf("%d",&opcao);
    if(opcao==0){
        limparTela();
        return 0;
    } else if(opcao==1){
        inicializarEstoque(&listaEstoque);
        limparTela();
        printf("\n Estoque inicializada!\n");
    } else {
        limparTela();
        printf("\n Opcao invalida!\n");
        goto menuInicio;
    }
    iniciarPrograma:
    menuCompleto();
    scanf("%d",&opcao);
    switch(opcao) {
        case 0 :
            limparTela();
            return 0;
        case 1 :
            limparTela();
            printf("\n Informe o codigo: ");
            scanf("%i", &elemento.codigo);
            printf("\n Informe o nome: ");
            setbuf(stdin, NULL);
            fgets(elemento.nome, 75, stdin);
            printf("\n Informe o Tamanho: ");
            setbuf(stdin, NULL);
            fgets(elemento.tamanho, 50, stdin);
            printf("\n Informe o preco de venda: R$");
            scanf("%f", &elemento.precoVenda);
            printf("\n Informe a quantidade em estoque: ");
            scanf("%i", &elemento.qtdEstoque);
            escolherOrdenacao:
            printf("\n Como deseja inserir o elemento na lista ?\n");
            printf("\n [1] Inserir elemento ordenando por quantidade");
            printf("\n [2] Inserir peca ordenando por tamanho\n\n");
            printf("Digite a opcao para continuar: ");
            scanf("%d",&opcao);
            switch(opcao) {
                case 1 :
                    inserirProdutoOrdenadoQuantidade(&listaEstoque,elemento);
                    limparTela();
                    printf("\n Produto inserido com sucesso!\n");
                    goto iniciarPrograma;
                case 2 :
                    inserirProdutoOrdenadoTamanho(&listaEstoque,elemento);
                    limparTela();
                    printf("\n Produto inserido com sucesso!\n");
                    goto iniciarPrograma;
                default :
                    limparTela();
                    printf("\n Opcao invalida! Escolha a forma de ordenacao corretamente.\n");
                    goto escolherOrdenacao;
            }
        case 2 :
            limparTela();
            exibirEstoque(&listaEstoque);
            goto iniciarPrograma;
        case 3 :
            limparTela();
            printf("\n Qual produto deseja excluir ?  ");
            scanf("%d",&registroExcluir);
            excluirProduto(&listaEstoque,registroExcluir);
            goto iniciarPrograma;
        case 4 :
            limparTela();
            printf("\n Qual produto deseja buscar ?  ");
            scanf("%d",&registroBuscar);
            buscarProduto(&listaEstoque, registroBuscar);
            goto iniciarPrograma;
        case 5 :
            reinicializarEstoque(&listaEstoque);
            limparTela();
            printf("\n Lista de estoque reinicializada! \n");
            goto menuInicio;
        default :
            limparTela();
            printf("\n Opcao invalida!\n");
            goto iniciarPrograma;
    }
    return 0;
}
