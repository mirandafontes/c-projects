#include <stdio.h>
#include <stdlib.h>

typedef struct lista {

    int valor;

    struct lista *prox;

} celulas;

void inserir( celulas *ponteiro, int numero );
void buscar ( celulas *ponteiro, int numero );
void remover( celulas *ponteiro, int numero );
void listar ( celulas *ponteiro );

int main()
{
    int i,d;
    celulas *inicio;

    inicio = NULL;

    inicio = ( celulas *) malloc( sizeof ( celulas ) );

    inicio -> prox = NULL;

    printf("O inicio aqui serve apenas como um cabecalho, sem valor atribuido!\n");

    for ( i = 0 ; i != 5 ; ) {

        printf("\n[ Menu ]\n");
        printf("\n\n1-Inserir:\n2-Buscar:\n3-Remover:\n4-Listar:\n5-Sair\n");
        printf("CHOOSE YOUR DESTINY : ");
        scanf("%d",&i);

        switch ( i ) {

            case 1 : {

                printf("Insira um valor:");
                scanf("%d",&d);
                inserir( inicio, d );
                break;
            }

            case 2 : {

                printf("Insira um valor:");
                scanf("%d",&d);
                buscar( inicio, d );
                break;

            }

            case 3 : {

                printf("Insira um valor para remocao:");
                scanf("%d",&d);
                remover( inicio, d );

                printf("\nLista apos a remocao:\t");
                listar( inicio );
                break;

            }

            case 4 : {

                printf("\nListando\n");
                listar ( inicio );
                break;
            }

            case 5 : return 1;

            default : printf("\nOpcao incorreto!\n");
        }
    }

    return 0;
}


void inserir ( celulas *ponteiro, int numero ) {

    celulas *novo;

    novo = NULL;

    novo = ( celulas *) malloc( sizeof ( celulas ) );

    novo -> valor = numero;
    novo -> prox = ponteiro -> prox;
    ponteiro -> prox = novo;

    return;
}

void listar ( celulas *ponteiro ) {

    if ( ponteiro -> prox == NULL ) {
        printf("Lista vazia;");
        return;
    }

    celulas *tmp;

    tmp = ponteiro -> prox;

    while ( tmp != NULL ) {

        printf("%5d     -->",tmp -> valor );
        tmp = tmp -> prox;
    }

    printf("     NULL");

    free(tmp);

    return;
}

void buscar ( celulas *ponteiro , int numero ) {

    celulas * busca;
    int i = -1; // Já que inicio não possui vaor

    busca = ponteiro;

    while ( busca != NULL ) {

       ++i;

        if ( busca -> valor == numero ) {
            printf("O numero %d esta na posicao [%d] \n\n", numero, i);
            return;
        }
        busca = busca -> prox;
    }

    free(busca);

    return;
}

void remover ( celulas *ponteiro, int numero ) {

    celulas *tmp;//q
    celulas *aux;//p

    aux = ponteiro;//p
    tmp = ponteiro -> prox;//q

    while ( tmp != NULL ) {

            if ( tmp -> valor == numero ) { aux -> prox  = tmp -> prox; free(tmp); return; }

        aux = tmp; //Guardando a posicao anterior
        tmp = tmp -> prox;
    }

    return;
}
