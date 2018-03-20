#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 60

// CRIAR UM PROGRAMA QUE SORTEIE OS NUMEROS DA MEGA SENA USANDO UM VETOR[60] SENDO QUE O VALOR DENTRO DO VETOR SÃO SEUS PESOS
// E O INDICE E O NUMERO SORTEADO
// USAR A FUNÇAO RANDOM PARA GERAR UM NUMERO ALEATORIO
// PEGAR 2 DESSES NUMEROS ALEATORIOS E COMPARAR O PESO, QUEM TIVER MAIOR PESO
// E PRINTADO || ALIMENTADO COM SEED POR FAVOR

// PREENCHER O VETOR A MAO A PRINCIPIO ( Q BELEZA DE TRABALHO )
// USAR A MEGASENA DE 1916 :: 29/03/2017 || ATUAL MEGASENA : 1920 :: 12/04/2017
// PESOS: 2 - EU ACERTEI || 1 - FOI SORTEADO
        //     1           5             10              15             20            25              30             35            40              45             50             55            60
int vet[m] = { 0, 0, 2, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 3, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1  };


int main() {

    int i, num1, num2, num3, num4, num5, num6, aux;

    srand( time(NULL) );

    puts("Gerador horrendo de numero para a mega sena ;~;");
    puts("Gerando infinitamente\n\n");

    for ( ; ; ) {

        puts("\n\n");
        getchar();

        for ( i =  0 ; i < 6 ; i++ ) {

            // random int between 0 and 19
            // int r = rand() % 20;
            num1 = rand () % m + 1;
            num2 = rand () % m + 1;
            num3 = rand () % m + 1;
            num4 = rand () % m + 1;
            num5 = rand () % m + 1;
            num6 = rand () % m + 1;


            if ( ( vet[num1] > vet[num2] ) && ( vet[num1] > vet[num3] ) && ( vet[num1] > vet[num4] ) && ( vet[num1] > vet[num5] ) && ( vet[num1] > vet[num6] ) ) printf("%d\n", num1 );
            else if ( ( vet[num2] > vet[num1] ) && ( vet[num2] > vet[num3] ) && ( vet[num2] > vet[num4] ) && ( vet[num2] > vet[num5] ) && ( vet[num2] > vet[num6] ) ) printf("%d\n", num2 );
            else if ( ( vet[num3] > vet[num1] ) && ( vet[num3] > vet[num2] ) && ( vet[num3] > vet[num4] ) && ( vet[num3] > vet[num5] ) && ( vet[num3] > vet[num6] ) ) printf("%d\n", num3 );
            else if ( ( vet[num4] > vet[num1] ) && ( vet[num4] > vet[num2] ) && ( vet[num4] > vet[num3] ) && ( vet[num4] > vet[num5] ) && ( vet[num4] > vet[num6] ) ) printf("%d\n", num4 );
            else if ( ( vet[num5] > vet[num1] ) && ( vet[num5] > vet[num2] ) && ( vet[num5] > vet[num3] ) && ( vet[num5] > vet[num4] ) && ( vet[num5] > vet[num6] ) ) printf("%d\n", num5 );
            else if ( ( vet[num6] > vet[num1] ) && ( vet[num6] > vet[num2] ) && ( vet[num6] > vet[num3] ) && ( vet[num6] > vet[num4] ) && ( vet[num6] > vet[num5] ) ) printf("%d\n", num6 );

            else if ( ( vet[num1] == vet[num2] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num2

                if ( aux ) printf("(%d)\n", num2) ;
                else printf("(%d)\n", num1 );

            }

            else if ( ( vet[num1] == vet[num3] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num3

                if ( aux ) printf("(%d)\n", num3) ;
                else printf("(%d)\n", num1 );

            }

            else if ( ( vet[num1] == vet[num4] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num4

                if ( aux ) printf("(%d)\n", num4) ;
                else printf("(%d)\n", num1 );

            }

            else if ( ( vet[num1] == vet[num5] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num5

                if ( aux ) printf("(%d)\n", num5) ;
                else printf("(%d)\n", num1 );

            }

            else if ( ( vet[num1] == vet[num6] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num6

                if ( aux ) printf("(%d)\n", num6) ;
                else printf("(%d)\n", num1 );

            }

            else if ( ( vet[num2] == vet[num3] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num3

                if ( aux ) printf("(%d)\n", num3) ;
                else printf("(%d)\n", num2 );

            }

            else if ( ( vet[num2] == vet[num4] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num4

                if ( aux ) printf("(%d)\n", num4) ;
                else printf("(%d)\n", num2 );

            }

            else if ( ( vet[num2] == vet[num5] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num5

                if ( aux ) printf("(%d)\n", num5) ;
                else printf("(%d)\n", num2 );

            }

            else if ( ( vet[num2] == vet[num6] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num6

                if ( aux ) printf("(%d)\n", num6) ;
                else printf("(%d)\n", num2 );

            }

            else if ( ( vet[num3] == vet[num4] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num4

                if ( aux ) printf("(%d)\n", num4) ;
                else printf("(%d)\n", num3 );

            }

            else if ( ( vet[num3] == vet[num5] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num5

                if ( aux ) printf("(%d)\n", num5) ;
                else printf("(%d)\n", num3 );

            }

            else if ( ( vet[num3] == vet[num6] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num6

                if ( aux ) printf("(%d)\n", num6) ;
                else printf("(%d)\n", num3 );

            }

            else if ( ( vet[num4] == vet[num5] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num5

                if ( aux ) printf("(%d)\n", num5) ;
                else printf("(%d)\n", num4 );

            }

            else if ( ( vet[num4] == vet[num6] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num6

                if ( aux ) printf("(%d)\n", num6) ;
                else printf("(%d)\n", num4 );

            }

            else if ( ( vet[num5] == vet[num6] ) ) {

                aux = rand () % 2;
                // Entre 0 e 1 . 0 = num1 || 1 = num6

                if ( aux ) printf("(%d)\n", num6) ;
                else printf("(%d)\n", num5 );

            }


        }

        puts("\n\n");

    }


    return 0;
}
