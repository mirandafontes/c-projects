#include <stdio.h>
#include <stdlib.h>
#define max 20

/* 1) Apresente a implementação de duas filas circulares em um vetor de 20 posições, de 0 a
19. A primeira fila deve utilizar as posições de 0 a 9, a segunda fila deve utilizar as
posições de 10 a 19. Cada fila circular deve ter as operações incluir na lista, pesquisar
na lista e excluir da lista um valor pesquisado.
 */
int incluir ( int vet[], int lista, int *fim, int ini, int value);
int excluir ( int vet[], int lista, int *ini , int fim );
int buscar  ( int vet[], int value );

void listar ( int vet[] );

;int main() {
    int vet[max],i = 0;
    int op = 0;
    int ini1,fim1,ini2,fim2;

    ini1 = 0;
    fim1 = 0;
    ini2 = 10;
    fim2 = 10;

    printf("Filas circulares, sendo lista 1 ~ 0 - 9 \\ lista 2 ~ 10 - 19 \\ Vetor zerado! \n");

    for ( i = 0 ; i < max ; i++ ) vet[i] = 0;

    for (  ; ;  ) {

        printf("\nMenu\n");
        printf("\nIncluir na lista");
        printf("\nPesquisar na lista");
        printf("\nExcluir da lista");
        printf("\nListar lista\nOperacao : ");
        scanf("%d",&op);

        switch ( op ) {

            case 1 : {

                printf("Em qual lista deseja inserir ( 1 / 2 )? ");
                scanf("%d",&i);//PARAR DE USAR SCANF!

                if ( i == 1 ) {

                    printf("Qual elemento? ");
                    scanf("%d",&i);
                    incluir( vet, 1, &fim1, ini1, i );

                }

                else if ( i == 2 ) {

                    printf("Qual elemento? ");
                    scanf("%d",&i);
                    incluir( vet, 2, &fim2, ini2, i );

                }


                break;
            }

            case 2 : {

                printf("Qual elemento a ser buscado? ");
                scanf("%d",&i);
                i = buscar ( vet, i );

                if ( i == - 1) printf ("Nao esta na lista\n");
                else printf("Esta na posicao %d do vetor.\n", i);

                break;

            }


            case 3 : {

                printf("Em qual lista deseja excluir um elemento? \n");
                scanf("%d",&i);

                if ( i == 1 )   printf("Elemento excluido : %d", excluir ( vet, 1, &ini1, fim1 ));

                else if ( i == 2 )  printf("Elemento excluido : %d", excluir ( vet, 2, &ini2, fim2 ));



            }


            case 4 : {

                listar ( vet );
                break;
            }

            default : { printf("Op invalida"); return -1; }

        }

        puts("");
    }


    return 0;
}
//Automatizar no switch a selecao da lista para evitar fim passado erroneamente
int incluir ( int vet[], int lista, int *fim, int ini, int value ) {

    if ( lista == 1 ) {

            if (  ( *fim + 1 ) % ( max / 2 ) == ini  ) { printf("Lista cheia! Pope um elemento!\n"); return 0; }

        else {

            vet[*fim] = value;
            *fim = ( *fim + 1 ) % ( max / 2 ) ;

            return 1;

        }

   }

    else if ( lista == 2 ) {

        if ( ( ( *fim + 1 ) % max ) + max / 2 == ini ) { printf("Lista cheia! Pope um elemento!\n"); return 0; }

        else {

            vet[*fim] = value;
            *fim = ( ( *fim + 1 ) % max );

            return 1;
        }
    }

    printf("Nao foi possivel adicionar o elemento por motivos desconhecidos!\n");
    return 0;
}

void listar ( int vet[] ) {
    int i;

    puts("\n");

    for ( i = 0 ; i < max ; i++ ) printf("vet[%d] --> %d \n", i, vet[i] );

    return;
}

int buscar ( int vet[], int value ) {

    int i;

    for ( i = 0 ; i < max ; i++ ) {

        if ( vet[i] == value ) return i;

    }


    return -1;
}

int excluir ( int vet[], int lista, int *ini , int fim ) {

    int v;

    if ( *ini == fim ) { printf("\\~Lista vazia~\\\n"); return -1; }

    v = vet[*ini];
    if ( *ini >= max / 2 )  *ini = ( *ini + 1 ) % max;

    else if ( *ini < max / 2 )  *ini = ( *ini + 1 ) % ( max / 2 );

    return v;

}
