#include <stdio.h>
#include <stdlib.h>
#define m 20
/* 9) Implemente 2 filas, uma de menor e uma de maior prioridade. Ao inserir um valor deve
ser perguntado qual fila utilizar. Ao pedir a retirada de um valor, retirar da fila de maior
prioridade, caso esta esteja vazia, então deve-se utilizar a de menor prioridade. */

typedef struct {

    int vet[m];
    int inicio;
    int fim;

} Fila;

void enqueue ( Fila *fila, int value );
int denqueue ( Fila *fila );
void listar ( Fila *fila );

int main() {
    Fila high,low;
    int i,v;

    for ( i = 0 ; i < m ; i++ ) high.vet[i] = 0;
    high.inicio = 0;
    high.fim = 0;

    for ( i = 0 ; i < m ; i++ ) low.vet[i] = 0;
    low.inicio = 0;
    low.fim = 0;



    for ( ; i != 4 ; ) {

        puts("\n\n||Menu||");
        puts("Inserir elemento - 1");
        puts("Retirar elemento - 2");
        puts("Listar - 3");
        puts("Sair - 4");
        scanf("%d",&i); // PARAR DE USAR SCANF!!!!!!!

        switch ( i ) {

            case 1 : {

                do {

                    puts("Em qual lista? ( 0 - Low || 1 - High )");
                    scanf("%d",&i);

                } while ( i > 1 && i < 0 );

                printf("\n\nValor a ser inserido :");
                scanf("%d",&v);

                if ( i == 1 ) enqueue ( &high, v );
                else if ( i == 0 ) enqueue ( &low, v );

                break;
            }

            case 2 : {

                puts("\n\nRetira da High e entao, caso esteja vazia, retira da Low");
                if ( denqueue( &high ) == -1 )
                    denqueue( &low );


            }

            case 3 : {

                puts("High :");
                listar ( &high );

                puts("Low :");
                listar ( &low );

            }

        }

    }



    return 0;
}

void enqueue ( Fila *fila, int value ) {

    if ( fila -> fim == m ) {   printf("Fila Cheia!\n\n");  return; }

    fila -> vet[ (fila -> fim)++ ] = value;


    return;
}

int denqueue ( Fila *fila ) {

    if ( fila -> inicio == fila -> fim ) {  printf("Fila vazia!\n\n");  return -1; }

    printf("Valor denqueued : %d\n\n", fila -> vet[ (fila -> inicio)++ ] );

    return 0;
}

void listar ( Fila *fila ) {

    int i;

    for ( i = fila -> inicio ; i < fila -> fim ; i++ )
        printf("%d\n", fila -> vet[i] );

    return;
}
