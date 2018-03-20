#include <stdio.h>
#include <stdlib.h>
#define m 100

/*  8) Implemente duas pilhas em um �nico vetor de 100 posi��es. Da posi��o 0 at� a posi��o
49 � a pilha A, da posi��o 50 at� a posi��o 99 � a pilha B. Apresente as opera��es de
push e pop para ambas as pilhas.  */

void push ( int vet[], int *top, int v );
int pop ( int vet[], int *top );


int main() {
    int vet[m];
    int topA = 0,topB = 50;

    for( topA = 0 ; topA < m ; topA++ ) vet[topA] = 0;

    topA = 0;

    push ( vet, &topA, 50 );
    push ( vet, &topB, 77 );


    push ( vet, &topA, 32 );
    push ( vet, &topB, 99 );


    printf("A = %d\n", pop( vet, &topA) );
    printf("B = %d\n", pop( vet, &topB) );
    printf("A = %d\n", pop( vet, &topA) );
    printf("B = %d\n", pop( vet, &topB) );


    return 0;
}

void push ( int vet[], int *top, int v ) {

    if ( *top == 49 || *top == 99 ) {   printf("Pilha Cheia\n");  return; }

    vet[ (*top)++ ] = v;

    //printf("v = %d || vet[*top antes] = %d\n", v, vet[*top]);


    //printf("v = %d || vet[*top dps] = %d\n", v, vet[*top]);

    return;
}

int pop ( int vet[], int *top ) {

    if ( *top == 0 || *top == 99 ) {    printf("Pilha vazia. Nao ha o que popar!\n");   return -1; }

    int v = 0;

    v = vet[ --(*top) ];


    return v;
}
