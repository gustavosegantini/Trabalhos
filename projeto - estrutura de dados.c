#include <stdio.h>
#include <stdlib.h>

typedef struct divida{
    int dia, mes, ano;
    double valor, valorPago;
    struct ponto *proximo;
}t_ponto;



int main(int argc, char *argv[]){
    t_ponto * inicio_ponto;
    t_ponto * proximo_ponto;
    int respostaUsuario;

    inicio_ponto = (t_ponto *)malloc(sizeof(t_ponto));
    if(inicio_ponto == NULL)
        exit(1);
    proximo_ponto = inicio_ponto;
    while(1){
        printf("Digite o dia: ");
        scanf("%i", &proximo_ponto->dia);
        printf("Digite o mes: ");
        scanf("%i", &proximo_ponto->mes);
        printf("Digite o ano: ");
        scanf("%i", &proximo_ponto->ano);
        printf("Valor da conta: ");
        scanf("%lf", &proximo_ponto->valor);
        printf("Valor pago: ");
        scanf("%lf", &proximo_ponto->valorPago);

        printf("Deseja continuar? '1' SIM 'Outro valor' NAO: ");
        scanf("%i", &respostaUsuario);
        if(respostaUsuario == 1){
            proximo_ponto->proximo = (t_ponto*)malloc(sizeof(t_ponto));
            proximo_ponto = proximo_ponto->proximo;
        }else   
            break;
        
    }
    printf("\n");
    proximo_ponto->proximo = NULL;
    proximo_ponto = inicio_ponto;
    while(proximo_ponto != NULL){
        printf("dia: %i, mes: %i, ano: %i, valor: %lf, valorPago: %lf\n", proximo_ponto->dia, proximo_ponto->mes, proximo_ponto->ano, proximo_ponto->valor, proximo_ponto->valorPago);
        proximo_ponto = proximo_ponto->proximo;
    }
    return 0;
}
