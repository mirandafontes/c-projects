#include <stdio.h>
#include <stdlib.h>
#define max 20

/* 5) Uma palavra é um palíndromo se tem a mesma seqüência de letras, quer seja lida da
esquerda para a direita ou da direita para a esquerda (exemplo: raiar). Utilizando uma
pilha, proponha um algoritmo que teste se uma palavra é palíndromo (dicas: uma parte
da palavra será empilhada e comparada a outra parte da palavra, ainda, observar que
palavras com tamanho par tem tratamento um pouco diferente de palavras de tamanho
impar).
 */

int palindromo ( char *str, char pilha[] );

int main() {
    char pilha[max] = { 0,0,0,0,0,0,0,0,0,0 };
    char str[max];

    puts("Insira uma palavra:");
    fgets ( str, max, stdin );


    if ( palindromo( str, pilha ) == -1 ) printf("\nNao eh palindromo");
    else printf("\neh palindromo");


    return 0;
}

int palindromo ( char str[], char pilha[] ) {

    int i,j,tam;
    //RAIAR - 5 (4)
    //RENNER - 6 (5)

    for ( i = 0 ; str[i] ; i++ )

    tam = i - 1;

    printf("tam = %d\n",tam);

    if ( ( tam + 1 ) % 2 == 0 )
        for ( i = 0 ; i <= tam /2; i++ ) pilha[i] = str[i];

    else if ( ( tam + 1 ) % 2 == 1 )
        for ( i = 0 ; i < tam/2 ; i++ ) pilha[i] = str[i];

    for ( i = 0 ; i < tam ; i++ ) printf("pilha = %c\n",pilha[i] );

    for ( i = 0, j = tam ; pilha[i] != 0 && str[j]  ; i++, j-- ) {

        if ( pilha[i] != str[j]) return -1;

    }


    return 0;

}
