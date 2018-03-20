#include <stdio.h>
#include <stdlib.h>

/* 3) A figura abaixo mostra uma lista simplesmente encadeada, onde cada nó possui o
ponteiro para o próximo e um valor. O ponteiro inicio indica o inicio da lista (aponta
para NULO se a lista for vazia). Apresente os algoritmos corretos para:
a) Inserir um novo nó;
b) Buscar um elemento com um dado valor val retornando o mesmo ou indicar que o
elemento não existe na lista;
c) Apagar um nó existente.
 */

typedef struct lista {

    int valor;
    struct lista *prox;

} celula;

void inserir ( celula *inicio , int v );
void buscar ( celula *ponteiro , int numero );
void listar ( celula *inicio );
void excluir ( celula * ponteiro );

int main() {
   int i = 0,v = 0;
   celula *inicio;

   inicio = NULL;

   inicio = ( celula * ) malloc ( sizeof ( celula ) );
   inicio -> prox = NULL;

   for ( ;  i != 5 ; ) {

        puts("|| MENU ||");
        puts("1- Inserir");
        puts("2- Buscar");
        puts("3- Excluir");
        puts("4- Listar");
        puts("5- Sair");
        fflush(stdin);
        scanf("%d",&i);

        switch ( i ) {

            case 1 : {

                printf("Elemento a ser inserido:");
                scanf("%d",&v);

                inserir ( inicio, v );


                break;
            }

            case 2 : {

                fflush(stdin);
                printf("Elemento a ser buscado: ");
                scanf("%d",&v);

                buscar ( inicio, v );

                break;
            }

            case 3 : {

                printf("Ultimo na memoria sera excluido\n");
                excluir ( inicio );

            }


            case 4 : {

                printf("\\Listando\\\n\n");
                listar ( inicio );
                break;
            }










        }


   }

   free( inicio );


    return 0;
}

void inserir ( celula *inicio , int v ) {

    celula *novo;

    novo = NULL;

    novo = ( celula * ) malloc ( sizeof ( celula ) );

    novo -> valor = v;
    novo -> prox = inicio -> prox;
    inicio -> prox = novo;

    return;
}

void buscar ( celula *ponteiro , int numero ) {

    celula * busca;
    int i = -1; // Já que inicio não possui valor

    busca = ponteiro;

    while ( busca != NULL ) {

       ++i;

       printf(".");

        if ( busca -> valor == numero ) {
            printf("O numero %d esta na posicao [%d] \n\n", numero, i);
            free ( busca );
            return;
        }
        busca = busca -> prox;
    }

    printf("\n\nElemento nao encontrado\n\n");
    free( busca );

    return;
}

void listar ( celula *inicio ) {

    celula *tmp;

    tmp = NULL;

    tmp = inicio -> prox;

    while ( tmp != NULL ) {

        printf("%d\t--->\t", tmp -> valor );

        tmp = tmp -> prox;
    }


    printf("NULL");
    puts("");

    free( tmp );

    return;
}

void excluir ( celula * ponteiro ) {

    if ( ponteiro -> prox == NULL ) {   printf("\nLista vazia!\n"); return; }

    ponteiro -> prox = ( ponteiro -> prox) -> prox;

    return;
}
