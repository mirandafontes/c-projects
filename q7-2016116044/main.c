#include <stdio.h>
#include <stdlib.h>
#define l 3 //tamanho
#define c 7



void imprimirTela ();
void jogadaValida ( int player );
int go ( int numeroJogadas );

int mat[l][c] = { {218,0,194,0,194,0,191},
                  {179,0,197,0,197,0,179},
                  {192,0,193,0,193,0,217} };

int main()
{
    int jgds,jogador = 1;

    printf("Posicoes:\n 1 2 3\nA\nB\nC\n\n");

    for ( jgds = 0 ; jgds < 9 ; jgds++ ) {


            imprimirTela ();

            if ( jogador == 1) {

                printf("\nJogador 1 , informe sua jogada:");
                jogadaValida( jogador );

            }

                else if ( jogador == -1) {

                    printf("\nJogador 2 , informe sua jogada:");
                    jogadaValida( jogador );

            }

            jgds = go ( jgds );

            if ( jgds == -1 ){

                if ( jogador == 1)  printf("\n\nJogador 1 venceu! \n\n");
                else if ( jogador == -1)    printf("\n\nJogador 2 venceu! \n\n");
                imprimirTela ();
                return 1;
            }


            //go ( jgds ); // VERIFICAR DEPOIS POR QUE NÃO ESTÁ INDO AS CONDIÇÕES

            jogador*=-1;

    }

    printf("\nDeu Velha!\n");

    return 0;
}


void imprimirTela ( ) { //USAR UMA MATRIZ DE INT'S E PRINTAR COMO %C MOVE BITCH VARIÁVEL GLOBAL OP

    int i,j;

    printf("\n");

    for ( i = 0 ; i < l ; i++ ) {

        for ( j = 0 ; j < c ; j++ ) {

            printf("%c",mat[i][j]);

            if ( j == c - 1) printf("\n");

        }

    }

    return;
}

void jogadaValida ( int player) {
    char jogadas[2];
    int valido = 0;
    int p1,p2,peca = 0;

    for ( ; valido != 2 ; ) {

        for ( ; valido != 1 ;) { //A verificação se uma casa está disponível para jogar tem que ser feita aqui // Outro laço For por cima deste com os comandos embaixo

            gets(jogadas);
            if ( ( jogadas[0] < 'A' || jogadas[0] > 'C' ) ||  ( jogadas[1] < '1' || jogadas[1] > '3' ) ) valido = 0;
            else valido = 1;
        }

        if ( valido == 1 ) {

            switch ( jogadas[0] ) {

                case 'A' : {
                    p1 = 0;
                    break;
                }

                case 'B' : {
                    p1 = 1;
                    break;
                }

                case 'C' : {
                    p1 = 2;
                    break;
                }


            }

            switch ( jogadas[1] ) {

                case '1' : {
                    p2 = 1;
                    break;
                }

                case '2' : {
                    p2 = 3;
                    break;
                }

                case '3' : {
                    p2 = 5;
                    break;
                }


            }

    }

        if ( mat[p1][p2] != 0) valido = 0;
        else if ( mat[p1][p2] == 0) valido = 2;

    }


    if ( player == 1 ) peca = 88; //X
    else if ( player == -1) peca = 79; //O

    mat[p1][p2] = peca;

        return;
}

int go ( int numeroJogadas ) {

    if ( ( mat[0][1] == 88 ) && ( mat[0][3] == 88 ) && ( mat[0][5] == 88) ) numeroJogadas = -1;
    else if ( ( mat[1][1] == 88 ) && ( mat[1][3] == 88 ) && ( mat[1][5] == 88) ) numeroJogadas = -1;
    else if ( ( mat[2][1] == 88 ) && ( mat[2][3] == 88 ) && ( mat[2][5] == 88) ) numeroJogadas = -1; // Retas na Horizontal X

    if ( ( mat[0][1] == 79 ) && ( mat[0][3] == 79 ) && ( mat[0][5] == 79) ) numeroJogadas = -1;
    else if ( ( mat[1][1] == 79 ) && ( mat[1][3] == 79 ) && ( mat[1][5] == 79) ) numeroJogadas = -1;
    else if ( ( mat[2][1] == 79 ) && ( mat[2][3] == 79 ) && ( mat[2][5] == 79) ) numeroJogadas = -1; // Retas na Horizontal O

    if ( ( mat[0][1] == 88 ) && ( mat[1][1] == 88 ) && ( mat[2][1] == 88 ) ) numeroJogadas = -1;
    else if ( ( mat[0][3] == 88 ) && ( mat[1][3] == 88 ) && ( mat[2][3] == 88 ) ) numeroJogadas = -1;
    else if ( ( mat[0][5] == 88 ) && ( mat[1][5] == 88 ) && ( mat[2][5] == 88 ) ) numeroJogadas = -1; // Retas na Vertical X

    if ( ( mat[0][1] == 79 ) && ( mat[1][1] == 79 ) && ( mat[2][1] == 79 ) ) numeroJogadas = -1;
    else if ( ( mat[0][3] == 79 ) && ( mat[1][3] == 79 ) && ( mat[2][3] == 79 ) ) numeroJogadas = -1;
    else if ( ( mat[0][5] == 79 ) && ( mat[1][5] == 79 ) && ( mat[2][5] == 79 ) ) numeroJogadas = -1; // Retas na Vertical O

    if ( ( mat[0][1] == 88 ) && ( mat[1][3] == 88 ) && ( mat[2][5] == 88 ) ) numeroJogadas = -1;
    else if ( ( mat[2][1] == 88 ) && ( mat[1][3] == 88 ) && ( mat[0][5] == 88 ) ) numeroJogadas = -1; // Retas Diagonal X

    if ( ( mat[0][1] == 79 ) && ( mat[1][3] == 79 ) && ( mat[2][5] == 79 ) ) numeroJogadas = -1;
    else if ( ( mat[2][1] == 79 ) && ( mat[1][3] == 79 ) && ( mat[0][5] == 79 ) ) numeroJogadas = -1; // Retas Diagonal O

    return numeroJogadas;
}
