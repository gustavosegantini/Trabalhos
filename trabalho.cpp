#include <stdio.h>
#include <stdlib.h>

typedef struct dividas Dividas;

typedef struct Conta {
    Dividas *primeiro;
    int size;
};

struct dividas {
  int dia;
  int mes;
  int ano;
  double preco;
  Dividas *proximo;
};

Dividas* novaDivida(int dia, int mes, int ano, double preco);
Conta* novaConta();

bool VerificadorVazio(Conta *conta);

void novoItemPrimeiro(int dia, int mes, int ano, double preco, Conta *conta);

void removerItemPrimeiro(Conta *conta);
void removerItemUltimo(Conta *conta);

void buscarDividas(Conta *conta, int index);

void printList(Conta *conta);
void imprimirDividas(Dividas *dividas);

int pegarTamanho(Conta *conta);


int main() {
    
    Conta *minhaConta = novaConta();
    
    novoItemPrimeiro(40, 32.21, 1, 1, minhaConta);
    novoItemPrimeiro(85, 12.21, 1, 1, minhaConta);
    novoItemPrimeiro(5, 87.41, 1, 1, minhaConta);
    novoItemPrimeiro(74, 96.21, 1, 1, minhaConta);
    novoItemPrimeiro(10, 2.21, 1, 1, minhaConta);
    printList(minhaConta);
    printf("\n Tamanho da Conta: %d\n", pegarTamanho(minhaConta));
    
    buscarDividas(minhaConta, 3);
    buscarDividas(minhaConta, 1);
    buscarDividas(minhaConta, 5);
    
    
    buscarDividas(minhaConta, 8);
    buscarDividas(minhaConta, 0);
    buscarDividas(minhaConta, -8);
    
    return 0;
}

Dividas* novaDivida(int dia, int mes, int ano, double preco) {
    Dividas *novaDivida = (Dividas *) malloc(sizeof(Dividas));
    
    novaDivida->dia = dia;
    novaDivida->mes = mes;
    novaDivida->ano = ano;
    novaDivida->preco = preco;
    novaDivida->proximo = NULL;
    
    return novaDivida;
}

Conta* novaConta() {
    Conta *novaD = (Conta *) malloc(sizeof(Conta));
    
    novaD->primeiro = NULL;
    novaD->size = 0;
    
    return novaConta();
}

bool VerificadorVazio(Conta *conta) {
    return conta->primeiro == NULL;
}

void novoItemPrimeiro(int dia, int mes, int ano, double preco, Conta *conta) {
    // criar novo item
    Dividas *novo = novaDivida(dia, mes, ano, preco);
    
    // Ajustar o ponteiro PROX
    novo->proximo = conta->primeiro;
    
    // Alterar o indicador de início da lista
    conta->primeiro = novo;
    
    conta->size++;
}

void imprimirDividas(Dividas *dividas) {
    printf("dia: %d \t mes: %d \t ano: %d \t preco: %.2f\n", dividas->dia, dividas->mes, dividas->ano, dividas->preco);
}

void printList(Conta *conta) {
            
    if (VerificadorVazio(conta)) {
        printf("\n Lista Vazia \n\n");
    } else {
        printf("\n Minha Conta: \n\n");
        
        Dividas *atual = conta->primeiro;
        
        while(atual != NULL) {
            imprimirDividas(atual);
            atual = atual->proximo;
        }
    }
}

int pegarTamanho(Conta *conta) {
    return conta->size;
}

void removerItemPrimeiro(Conta *conta) {
    
    if (VerificadorVazio(conta)) {
        printf("Lista vazia. Impossível realizar exclusăo!! \n");
    } else {
        // Obter primeiro item
        Dividas *primeiro = conta->primeiro;
        
        // Transformar segundo item da lista em primeiro
        conta->primeiro = primeiro->proximo;
        
        // Eliminar referencias do primeiro
        primeiro->proximo = NULL;
        
        // Liberar memória
        free(primeiro);
        
        // Diminuir tamanho da lista
        conta->size--;
    }
}

void removerItemUltimo(Conta *conta) {
    
    if (VerificadorVazio(conta)) {
        printf("Lista vazia. Impossível realizar exclusăo!! \n");
    } else {
        // Obter primeiro item da lista
        Dividas *atual = conta->primeiro;
        Dividas *anterior = conta->primeiro;
        
        // Percorrer toda a lista
        while (atual->proximo != NULL) {
            anterior = atual;
            atual = atual->proximo;
        }
        
        // Exclusăo
        if(anterior->proximo == NULL) {
            conta->primeiro = NULL;
        }
        anterior->proximo = NULL;
        free(atual);
        
        // Diminuir tamanho da lista
        conta->size--;
    }
}

void buscarDividas(Conta *conta, int index) {
    
    if (VerificadorVazio(conta)) {
        printf("\n Lista nao contem produtos \n");
    } else if(index <= 0 || index > pegarTamanho(conta)) {
        printf("\n Indice %d informado fora dos limites \n", index);
    }
    else {
        Dividas *dividas = conta->primeiro;
        int i = 1;
        
        while (i < index && dividas->proximo ) {
            dividas = dividas->proximo;
            i++;
        }
    
        imprimirDividas(dividas);
    }
    
}

