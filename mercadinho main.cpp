#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meracadinho.h.cpp"


int main() {
    Fruta* listaFrutas = criarLista();
    
    // Exemplo de inser��o
    listaFrutas = inserirLista(listaFrutas, 1, "Banana", 50, 0.99);
    listaFrutas = inserirLista(listaFrutas, 2, "Ma�a", 30, 1.50);
    listaFrutas = inserirLista(listaFrutas, 3, "Laranja", 20, 1.20); 

    // Lista frutas cadastradas
    Fruta* atual = listaFrutas;
    printf("Frutas cadastradas:\n");
    while (atual != NULL) {
        printf("C�digo: %d, Nome: %s, Quantidade: %d, Pre�o: %.2f\n", atual->codigo, atual->nome, atual->qtd, atual->preco);
        atual = atual->prox;
    }

    // Libera��o de mem�ria (n�o implementado aqui, mas necess�rio em um programa real)
    
    Fruta* x = buscarNaLista(listaFrutas, 2); // Buscando 10
    if (x != NULL) {
        printf("Codigo do produto %d : \n", x->codigo);
        printf("Nome do produto %s : \n", x->nome);
        printf("Preco : %f\n", x->preco);
        printf("Quantidade em estoque: %d\n" , x->qtd);
    } else {
        printf("Elemento n�o encontrado.\n");
    }
    
    listaFrutas = alterarProduto(listaFrutas, 2, "Maca", 0, 1.30);
    
    printf("\nFrutas cadastradas ap�s a altera��o:\n");
    atual = listaFrutas;
    while (atual != NULL) {
        printf("C�digo: %d, Nome: %s, Quantidade: %d, Pre�o: %.2f\n", atual->codigo, atual->nome, atual->qtd, atual->preco);
        atual = atual->prox;
    }
    
    listaFrutas = excluirFruta(listaFrutas, 2); 

    printf("\nFrutas cadastradas ap�s a exclus�o:\n");
    atual = listaFrutas;
    while (atual != NULL) {
        printf("C�digo: %d, Nome: %s, Quantidade: %d, Pre�o: %.2f\n", atual->codigo, atual->nome, atual->qtd, atual->preco);
        atual = atual->prox;
    }
    
    listaFrutas = vendaFruta(listaFrutas, 2, 4); 

	printf("\nFrutas ap�s a venda:\n");
	atual = listaFrutas;
	while (atual != NULL) {
	    printf("C�digo: %d, Nome: %s, Quantidade: %d, Pre�o: %.2f\n", atual->codigo, atual->nome, atual->qtd, atual->preco);
	    atual = atual->prox;
	}
    
  

    return 0;
}
