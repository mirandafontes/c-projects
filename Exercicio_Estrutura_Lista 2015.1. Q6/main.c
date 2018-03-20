#include <stdio.h>
#include <stdlib.h>
#define m 10

/* 6) Suponha que temos duas pilhas ordenadas de forma crescente, P1 e P2. Desempilhe os
elementos destas pilhas e empilhe em P3, de modo que os elementos fiquem ordenados
de forma decrescente.

Exemplo: P1 = {1, 4, 8} e P2 = {2, 6, 7, 9}, onde o topo de P1 é 1 e o topo de P2 é 2.
P3 será {9, 8, 7, 6, 4, 2, 1}

7) P3 ao contrário
 */
 void push ( int pilha[], int v, int *top );
 int pop ( int pilha[], int *top );
 int decrescente ( int p1[], int p2[], int p3[], int *top1, int *top2, int *top3 );
 int crescente ( int p1[], int p2[], int p3[], int *top1, int *top2, int *top3 );


int main() {
    int p1[m],p2[m / 2],p3[2 * m];
    int top1 = 0, top2 = 0, top3 = 0;
    int i;

    for ( i = 0 ; i < m ; i++) p1[i] = ( 2 * m )- i;
    for ( i = 0 ; i < m / 2 ; i++ ) p2[i] = m - ( i * 2 );
    for ( i = 0 ; i < 2 * m ; i++ ) p3[i] = 0;

    for ( i = 0 ; i < m ; i++ ) printf("Pilha1[%d] = %d\n", i, p1[i] );
    puts("\n\n");

    for ( i = 0 ; i < m / 2 ; i++ ) printf("Pilha2[%d] = %d\n", i, p2[i] );
    puts("\n\n");

    top1 = m - 1;
    top2 = ( m / 2 ) - 1;

    top3 = decrescente( p1, p2, p3, &top1, &top2, &top3 );

    puts("Decrescente :");
    for ( i = 0 ; i < top3 ; i++ ) printf("Pilha3[%d] = %d\n", i, p3[i] );
    puts("\n\n");





    for ( i = 0 ; i < 2 * m ; i++ ) p3[i] = 0;

    top1 = m - 1;
    top2 = ( m / 2 ) - 1;
    top3 = 0;

    top3 = crescente( p1, p2, p3, &top1, &top2, &top3 );

    puts("Crescente :");
    for ( i = 0 ; i < top3 ; i++ ) printf("Pilha3[%d] = %d\n", i, p3[i] );

    return 0;
}

void push ( int pilha[], int v, int *top ) {

    if ( *top + 1 == 2 * m ) return;

    pilha[*top] = v;

    *top+=1;

    return;
}

int pop ( int pilha[], int *top ) {

    int v;

    if ( *top == -1 ) return -1;

    v = pilha[*top];

    *top-=1;

    return v;
}

int decrescente ( int p1[], int p2[], int p3[], int *top1, int *top2, int *top3 ) {

    int aux = 0,aux2 = 0;
    int t1,t2,t3;

    t1 = *top1;
    t2 = *top2;
    t3 = *top3;

    for (  ; t3 < m * 2 ; ) {

        aux = pop( p1, &t1 );
        aux2 = pop ( p2, &t2 );
        if ( aux == -1 && aux2 == -1 ) return t3;
        else if ( aux == -1 ) push ( p3, aux2, &t3 );
        else if ( aux2 == - 1 ) push ( p3, aux, &t3 );

        if ( aux < aux2 && aux != -1 ) {    push( p3, aux, &t3 );    t2+=1;    }
        else if ( aux2 < aux && aux2 != -1 ) {    push ( p3, aux2, &t3 );    t1+=1;    }

        /* Exemplo: P1 = {1, 4, 8} e P2 = {2, 6, 7, 9}, onde o topo de P1 é 1 e o topo de P2 é 2.
        P3 será {9, 8, 7, 6, 4, 2, 1} */

    }

    return t3;
}

int crescente ( int p1[], int p2[], int p3[], int *top1, int *top2, int *top3 ) {

    int aux = 0,aux2 = 0;
    int t1,t2,t3;

    t1 = *top1;
    t2 = *top2;
    t3 = t1 + t2 + 1;

    for (  ; t3 < m * 2 ; ) {

        aux = pop( p1, &t1 );
        aux2 = pop ( p2, &t2 );

        if ( aux == -1 && aux2 == -1 ) return *top1 + *top2 + 2;
        else if ( aux == -1 ) { push ( p3, aux2, &t3 );    t3-=2;   }
        else if ( aux2 == - 1 ) { push ( p3, aux, &t3 );    t3-=2;  }

        if ( aux < aux2 && aux != -1 ) {    push( p3, aux, &t3 );    t2+=1;    t3-=2;    }
        else if ( aux2 < aux && aux2 != -1 ) {    push ( p3, aux2, &t3 );    t1+=1;  t3-=2;    }

        /* Exemplo: P1 = {1, 4, 8} e P2 = {2, 6, 7, 9}, onde o topo de P1 é 1 e o topo de P2 é 2.
        P3 será { 1, 2, 4, 6, 7, 8, 9 } */

    }

    return *top1 + *top2 + 2;
}
