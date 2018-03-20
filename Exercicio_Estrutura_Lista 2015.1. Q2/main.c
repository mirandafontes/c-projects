#include <stdio.h>
#include <stdlib.h>

/* 2) A figura abaixo mostra uma lista duplamente encadeada circular, onde cada nó possui o
ponteiro para o anterior, o ponteiro para o próximo e um valor. O ponteiro inicio indica
o inicio da lista (aponta para NULO se a lista for vazia). Apresente, ou em C, ou em
pseudo-linguagem, um passo a passo adequado para:
a) Inserir um novo nó, de forma ordenada (ex: o nó de valor 5 tem que ficar antes do
de valor 6 e depois do de valor 4);
b) Buscar um elemento com um dado valor val retornando o mesmo ou indicar que o
elemento não existe na lista.
 */

 typedef struct lista {

    int valor;
    struct lista * ant;
    struct lista * prox;

 } celula;

int inserir ( celula * ponteiro, int v );
void listar ( celula *ponteiro );
int buscar ( int v, celula * ponteiro );

int main() {

    int i= 0, run = 0, v = 0, vant = 0;
    celula *inicio;

    inicio = NULL;

    inicio = ( celula * ) malloc( sizeof ( celula ) );

    inicio -> prox = NULL;
    inicio -> ant = NULL;

    for ( run = 0 ; i != 4 ; ) {

        puts("|| MENU ||");
        puts("1- Inserir");
        puts("2- Buscar");
        puts("3- Listar");
        puts("4- Sair");
        scanf("%d",&i);

        switch ( i ) {

            case 1 : {

                printf("Qual valor deseja inserir? ");
                scanf("%d",&v);
                if ( !run )
                    vant = inserir ( inicio, v );

                if ( v < vant) printf("O valor informado e menor!\n");
                else if ( v == vant && run ) printf("O valor informado e igual!\n");
                else if ( v > vant ) vant = inserir ( inicio, v );
                run = 1;

                break;

            }

            case 2 : {

                printf("Qual elemento deseja buscar? :");
                scanf("%d",&v); // NÃO USAR SCANF!!!!

                if ( buscar ( v, inicio ) == -1 ) printf("Elemento nao esta na lista\n");
                else printf("Elemento na posicao : %d\n", buscar( v, inicio ) );

                break;
            }

            case 3 : {

                printf("\n\\listando\\\n");
                listar ( inicio );
                break;

            }

        }

    }

    free(inicio);

    return 0;
}

int inserir ( celula * ponteiro, int v ) {

    celula *novo;

    if ( ( novo = ( celula * ) malloc( sizeof ( celula ) ) ) == NULL ){

        printf("Sem memoria! \n\n;");
        return -1;
    }

    novo -> prox = NULL;
    novo -> ant = NULL;

    novo -> valor = v;
    novo -> prox = ponteiro -> prox;
    ponteiro -> prox = novo;
    novo -> ant = ponteiro;


    //ponteiro -> prox = novo;

    /*( ponteiro -> prox ) -> ant = novo;
    ponteiro -> prox = novo;
    ponteiro -> ant = novo -> prox;

    novo_elemento>anterior = NULL;
  novo_elemento>seguinte = lista>início;
  lista>início>anterior = novo_elemento;
  lista>início = novo_elemento;   */




    return v;
}

void listar ( celula *ponteiro  ) {

    if( ponteiro -> prox == NULL ) {

        printf("Lista vazia\n");
        return;
    }

    celula *tmp = NULL;

    tmp = ponteiro -> prox;

    while( tmp != NULL ){

        printf("%5d     -->",tmp -> valor );
        tmp = tmp -> prox;

    }

    free(tmp);

    printf("\t NULL");
    puts("\n");

    return;
}

int buscar ( int v, celula * ponteiro ) {

    celula * tmp;
    int i = 0;

    tmp = ponteiro;

    while ( tmp != NULL ) {

        if ( tmp -> valor == v ) return i;

        tmp = tmp -> prox;
        i++;

    }

    free( tmp );

    return -1;
}
