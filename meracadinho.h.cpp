#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

 typedef struct fruta {
    int codigo;
    char nome[50];
    int qtd;
    double preco;
    struct fruta *prox; // Corrigido: deve apontar para a pr�pria estrutura
} Fruta;

Fruta* criarLista();
Fruta* inserirLista(Fruta* lista, int codigo, const char* nome, int qtd, double preco);
Fruta* buscarNaLista(Fruta* f, int v);
Fruta* alterarProduto(Fruta* lista, int codigo, const char* novoNome, int novaQtd, double novoPreco);
Fruta* excluirFruta(Fruta* lista, int codigo);
Fruta* vendaFruta(Fruta* lista, int codigo, int quantidade);
void salvaVendas(int codigo, const char* nome, int quantidade, double preco);
void sair(Fruta* lista);

void salvaVendas(int codigo, const char* nome, int quantidade, double preco){
	FILE *arquivo = fopen("vendas.txt", "a");
	if(arquivo == NULL){
		printf("Erro na abertura do arquivo\n");
		return;
	}
	
	fprintf(arquivo, "C�digo: %d, Nome: %s, Quantidade: %d, Pre�o: %.2f\n", codigo, nome, quantidade, preco);
    fclose(arquivo); // Fecha o arquivo
}


Fruta* vendaFruta(Fruta* lista, int codigo, int quantidade) {
    Fruta* produto = buscarNaLista(lista, codigo);
    
    if (produto == NULL) {
        printf("Produto com c�digo %d n�o encontrado.\n", codigo);
        return lista;
    }
    
    if (quantidade <= produto->qtd) {
        produto->qtd -= quantidade;
        printf("Produto vendido: C�digo %d, Quantidade vendida: %d\n", codigo, quantidade);
        
        salvaVendas(produto->codigo, produto->nome, quantidade, produto->preco);
    } else {
        printf("Quantidade comprada � maior que o estoque.\n");
    }

    return lista; // Retorna a lista atualizada
}


Fruta* alterarProduto(Fruta* lista, int codigo, const char* novoNome, int novaQtd, double novoPreco) {
    // Busca o produto na lista
    Fruta* produto = buscarNaLista(lista, codigo);
    
    // Verifica se o produto foi encontrado
    if (produto != NULL) {
        // Atualiza os dados do produto
        strcpy(produto->nome, novoNome);
        produto->qtd = novaQtd;
        produto->preco = novoPreco;
        printf("Produto com c�digo %d alterado com sucesso!\n", codigo);
    } else {
        printf("Produto com c�digo %d n�o encontrado.\n", codigo);
    }

    return lista; // Retorna a lista (n�o alterada, mas pode ser �til em outros contextos)
}


Fruta* buscarNaLista(Fruta *f, int v) {
    Fruta *p;
    for (p = f; p != NULL; p = p->prox) {
        if (p->codigo == v) {
            return p; // Retorna o n� se o valor for encontrado
        }
    }
    return NULL; // Retorna NULL se n�o encontrado
}
Fruta* excluirFruta(Fruta* lista, int codigo) {
    Fruta* ant = NULL;
    Fruta* atual = lista;

    // Percorre a lista para encontrar a fruta com o c�digo especificado
    while (atual != NULL && atual->codigo != codigo) {
        ant = atual;
        atual = atual->prox;
    }

    // Se a fruta n�o for encontrada, retorna a lista original
    if (atual == NULL) {
        printf("Produto com c�digo %d n�o encontrado.\n", codigo);
        return lista;
    }

    // Verifica se a quantidade � zero
    if (atual->qtd > 0) {
        printf("N�o � poss�vel excluir o produto com c�digo %d, quantidade em estoque: %d.\n", codigo, atual->qtd);
        return lista; // Retorna a lista sem altera��es
    }

    // Se a fruta a ser exclu�da � a primeira da lista
    if (ant == NULL) {
        lista = atual->prox; // Remove o primeiro elemento
    } else {
        ant->prox = atual->prox; // Remove o elemento do meio ou fim
    }

    free(atual); // Libera a mem�ria do elemento exclu�do
    printf("Produto com c�digo %d exclu�do com sucesso.\n", codigo);
    
    return lista; // Retorna a lista atualizada
}




Fruta* inserirLista(Fruta* lista, int codigo, const char* nome, int qtd, double preco) {
	
	
	Fruta* p = lista;
    while (p != NULL) {
        if (p->codigo == codigo) {
            printf("Erro: C�digo %d j� existe na lista. Inser��o n�o permitida.\n", codigo);
            return lista; // Retorna a lista sem altera��es
        }
        p = p->prox;
    }
    // Cria uma nova fruta
    Fruta* novaFruta = (Fruta*)malloc(sizeof(Fruta));
    if (!novaFruta) {
        printf("Erro ao alocar mem�ria.\n");
        return lista;
    }

    // Preenche os dados da nova fruta
    novaFruta->codigo = codigo;
    strcpy(novaFruta->nome, nome);
    novaFruta->qtd = qtd;
    novaFruta->preco = preco;
    novaFruta->prox = lista; // Insere no in�cio da lista

    return novaFruta; // Retorna a nova lista com a fruta inserida
}

Fruta* criarLista(){
    return NULL;
};

void sair(Fruta* lista) {
    Fruta* atual = lista;
    while (atual != NULL) {
        Fruta* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    printf("Saindo do programa...\n");
    exit(0);
}




