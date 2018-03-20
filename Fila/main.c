#include <stdio.h>
#include <stdlib.h>
#define max 100

int fila[max];

int enf ( int v, int *fim );
int desenf ( int *ini, int fim );
void listar ( int ini, int fim );


int main() {
    int ini = 0,fim = 0;
    int v,op;


    do {

        printf("1 -- Enqueue\n");
        printf("2 -- Denqueue\n");
        printf("3 -- Listar\n");
        printf("4 -- Sair\n");
        fflush(stdin);
        scanf("%d",&op);


        switch ( op ) {

            case 1 : {

                printf("\nDigite um valor para a entrada na fila:");
                scanf("%d",&v); // EVITAR USAR SCANF

                enf( v, &fim );
                break;

            }

            case 2 : {

                printf("\nDeque: %d\n", desenf( &ini, fim ) );
                 //EVITAR USAR SCANF
                break;
            }


            case 3 : {

                listar( ini, fim );
                break;
            }

            case 4 : return 0;

            default : printf("Op invalida\n");

        }


        puts("\n");

     } while ( op != 4 );


    return 0;
}

int enf ( int v, int *fim ) {

    if ( *fim == max ) {

        printf("Fila cheia\n");
        return -1;
    }

    fila[*fim] = v;
    *fim+=1;

    return 0;
}

int desenf ( int *ini, int fim ) {
    int v;

    if ( *ini == fim ) {

        printf("Fim da fila atingido\\Sem elementos\n");
        return -2;
    }

    v = fila[*ini];

    *ini+=1;

    return v;
}

void listar ( int ini, int fim ) {
    int i;

    if ( ini == fim ) {

        printf("Nao ha elementos para listar");
        return;
    }

    for ( i = ini; i < fim ; i++ ) printf("Fila[%d] --> %d\n", i, fila[i] );

    return;
}
