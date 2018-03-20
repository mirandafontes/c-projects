#include <stdio.h>
#include <stdlib.h>
#define max 100


int stack[max];

int push ( int value, int *top );
int pop ( int *top );
int listar ( int top );

int main() {

    int v,op, top = 0;

    do {

        printf("Escolha uma operacao:\n");
        printf("Push -- 1\n");
        printf("Pop -- 2\n");
        printf("Listar -- 3\n");
        printf("Sair -- -1\n");
        fflush(stdin);
        scanf("%d",&op);

        switch ( op ) {

            case 1 : {

                printf("Digite o valor a ser inserido:");
                scanf("%d",&v);

                push( v, &top );
                break;
            }

            case 2 : {

                printf("Valor popado : %d\n", pop( &top ) );
                break;
            }

            case 3 : {

                listar ( top );
                break;
            }

            case -1 : return 0;

            default : printf("Opcao invalida\n");
       }

       puts("\n");

    } while ( op != -1 );

    return 0;
}

int push ( int value, int *top ) {

    if ( *top == max ) {

        printf("Pilha Cheia\n");
        return -1;
    }

    stack[*top] = value;
    *top+=1;

    return 1;
}

int pop ( int *top ) {

    if ( *top == 0 ) {

        printf("Pilha vazia, nao ha como popar\n");
        return -2;
    }

    *top-= 1;

    return stack[*top];
}

int listar( int top ) {

    int i;

    if ( top == 0 ) {

        printf("Nao ha elemento a se listar");
        return -3;
    }

    for ( i = 0 ; i < top ; i++ ) printf("stack[%d] --> %d\n", i, stack[i] );

    return 1;
}
