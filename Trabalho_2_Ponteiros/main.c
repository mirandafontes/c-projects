#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef struct Estrutura_Auxiliar {

    int valor;
    int tamanho;
    int alocado;
    struct Estrutura_Auxiliar * ponteiro;


} EA;

void inserir ( EA inicio[], int valor );
void listar ( EA inicio[] );
void listarEAO ( EA inicio[] );
void listarAll ( EA inicio[] );
void excluir ( EA inicio[], int valor );

int main() {
    EA EP[m];
    int v,i;

    for ( i = 0 ; i < m ; i++ ) EP[i].valor = -1;
    for ( i = 0 ; i < m ; i++ ) EP[i].tamanho = -1;
    for ( i = 0 ; i < m ; i++ ) EP[i].alocado = 0;
    for ( i = 0 ; i < m ; i++ ) EP[i].ponteiro = NULL;

    for ( ; i != 7 ; ) {

        puts("||\tMENU\t||\n");
        puts("Inserir Elemento - 1");
        puts("Listar Elementos - 2");
        puts("Listar Elementos ( De forma ordenada para cada EA ) - 3");
        puts("Listar Elementos ( Todos os valores ordenados ) - 4");
        puts("Excluir Elemento - 5");
        puts("Aumentar Tamanho - 6");
        puts("Sair - 7");
        scanf("%d",&i);

        switch ( i ) {

            case 1 : {

                puts("\nEm qual parte da estrutura principal voce deseja inserir o elemento [0 ~ 9]?");
                scanf("%d",&i);

                if ( i > 9 || i < 0 ) { puts("Invalido"); break; }

                while ( EP[i].tamanho <= 0 ) {

                    puts("\nEstrutura auxiliar nao criada. Digite um tamanho valido ( Maior que 0 ).");
                    scanf("%d",&EP[i].tamanho );


                }

                printf("\nDigite um valor a ser inserido: ");
                scanf("%d",&v);

                inserir ( &EP[i], v );
                break;

            }

            case 2 : {

                listar ( EP );
                break;

            }

            case 3 : {

                puts("Listando cada estrutura auxiliar de forma ordenada\n");

                listarEAO ( EP );
                break;

            }

            case 4 : {

                puts("Listando todos os elementos de todas as estruturas auxiliares de forma ordenada\n");

                listarAll ( EP );
                break;

            }

            case 5 : {

                printf("Insira um valor a ser excluido da estrutura : ");
                scanf("%d",&v);

                excluir( EP , v );
                break;

            }

            case 6 : {

                puts("\nQual estrutura auxiliar voce quer aumentar o tamanho [ 0 ~ 9 ] ?");
                scanf("%d",&i);

                if ( i < 0 || i > 9 ) { puts("Invalido");   break;  }

                if ( EP[i].tamanho == -1 ) { puts("Estrutura auxiliar ainda nao criada! Use a funcao 'Inserir elemento' para criar.");  break;  }

                do {

                    printf("\nInsira o tamanho adicional ( Nao pode ser menor ou igual ao valor atual )\nValor Atual do tamanho (%d): ", EP[i].tamanho );
                    scanf("%d",&v);


                } while ( v <= EP[i].tamanho );

                EP[i].tamanho = v;
                break;

            }



        }

        printf("\nAperte qualquer tecla para limpar a tela e continuar\n");
        fflush( stdin );
        fgetchar();
        fflush( stdin );
        system("cls");

    }

    // printf("%d", ( EP[1].ponteiro ) -> valor );

    return 0;
}

void inserir ( EA inicio[], int v ) {

    if ( inicio -> alocado == inicio -> tamanho ) { puts("Estrutura cheia!\n");   return; }

    EA *novo;
    novo = NULL;

    if ( ( novo = ( EA * ) malloc( sizeof ( EA ) ) ) == NULL ) { puts("Nao foi possivel inserir o novo elemento. Memoria cheia\n ");    return; }

    novo -> ponteiro = inicio -> ponteiro;
    inicio -> ponteiro = novo;

    novo -> valor = v;

    inicio -> alocado++;

    printf("Novo valor inserido : %d\n\n", novo -> valor );

    return;
}

void listar ( EA inicio[] ) {

    int i;
    EA *tmp;

    tmp = NULL;

    puts("\n\n");

    for ( i = 0 ; i < m ; i++ ) {

        if ( inicio[i].tamanho == -1 ) {

            printf("Estrutura Principal [%d] = Sem elementos \n",i);
            puts("Tamanho = NULL\n");

        }

        else {

            printf("Estrutura Principal [%d] = ",i);

             tmp = inicio[i].ponteiro;

             while ( tmp != NULL ) {

                printf("%d  --  ", tmp -> valor);

                tmp = tmp -> ponteiro;

             }

             puts("|");
             printf("Tamanho = %d\n\n", inicio[i].tamanho );

        }


    }

    puts("\n\n");


    return;
}

void listarEAO ( EA inicio[] ) {

    int *vet; //REFAZER!!
    int i, j, k, aux;//, preenchidos;
    EA *tmp;

    tmp = NULL;


    for ( k = 0 ; k < m ; k++ ) {

        //ALOCAR O VETOR DE ACORDO COM O TAMANHO
        if ( inicio[k].tamanho != -1 )
            vet = ( int * ) malloc ( ( inicio[k].alocado * sizeof ( int ) ) + 1 );

        //COPIA DO VALOR PARA O VETOR
        if ( inicio[k].tamanho != -1 )
            for ( i = 0, tmp = inicio[k].ponteiro ; i < inicio[k].alocado && tmp != NULL ; i++ , tmp = tmp -> ponteiro )
                vet[i] = tmp -> valor;



        // OLHAR A FUNÇÃO LISTAR ACIMA PARA USAR AQUI EMBAIXO
        // CRIAR UM PONTEIRO DE EA *TMP
        // NA HORA DE COPIAR OS VALORES, USA-LO!

        //ORDENAÇÃO
        for( i = 0 ; i < inicio[k].alocado ; i++ ) {

                     j = i;

                     while( ( vet[j] < vet[j - 1] ) && ( j != 0 ) ) {

                            aux = vet[j];
                            vet[j] = vet[j - 1];
                            vet[j - 1] = aux;
                            j--;

                    }
        }

        if ( inicio[k].tamanho == -1 ) {

            printf("Estrutura Principal [%d] = Sem elementos \n",k);
            puts("Tamanho = NULL\n");
            free( vet );

        }

        else {

            printf("Estrutura Principal [%d] = ", k );

            for ( i = 0 ; i < inicio[k].alocado ; i++ )    printf("%d  --  ", vet[i] );

            free( vet );

            puts("|");
            printf("Tamanho = %d\n\n", inicio[k].tamanho );

        }

    }

    free ( vet );

    return;
}

void listarAll ( EA inicio[] ) {

    int *vet;
    int i, j, aux, tamT = 0;
    EA *tmp;

    tmp = NULL;

    for ( i = 0, tamT = 0 ; i < m ; i++ )
        if ( inicio[i].tamanho != -1)
            tamT += inicio[i].tamanho; // Pega o tamanho total da estrutura

    if ( tamT != 0 )
        vet = ( int * ) malloc ( tamT * sizeof ( int )  );

    // I varia a EA . J varia no vetor. Aux copia ate o alocado
    for ( i = 0, j = 0 ; i < m ; i++ ) {
        if ( inicio[i].tamanho != -1 )
            for ( tmp = inicio[i].ponteiro ; tmp != NULL ; j++, tmp = tmp -> ponteiro )
                vet[j] = tmp -> valor;
    }


    for( i = 0 ; i < tamT ; i++ ) {

        j = i;

            while( ( vet[j] < vet[j - 1] ) && ( j != 0 ) ) {

                aux = vet[j];
                vet[j] = vet[j - 1];
                vet[j - 1] = aux;
                j--;

            }
    }

    printf("Todos os valores ordenado : ");

    if ( tamT != 0)
        for ( i = 0 ; i < tamT ; i++ ) printf(" %d  --", vet[i] );
    else if ( tamT == 0)
        printf("Sem elementos!");

    puts("\n\n");

    free( vet );


    return;
}

void excluir ( EA inicio[], int valor ) {

    int i;
    EA *tmp, *aux;

    tmp = NULL;
    aux = NULL;

    for ( i = 0 ; i < m ; i++ ){

        if ( inicio[i].tamanho != -1 ) {

            for ( tmp = inicio[i].ponteiro, aux = NULL ; tmp != NULL ; aux = tmp ,tmp = tmp -> ponteiro ) {

                if ( tmp -> valor == valor ) {

                    if ( aux == NULL ) { // Quer dizer que o valor esta no inicio da lista!
                        printf("Valor para exclusao encontrado!\n");
                        inicio[i].alocado-=1;
                        inicio[i].ponteiro = tmp -> ponteiro;
                        return;
                    }

                    else if ( aux != NULL ) {

                        printf("Valor para exclusao encontrado!\n");
                        inicio[i].alocado-=1;
                        aux -> ponteiro = tmp -> ponteiro;
                        return;

                    }
                }
            }
        }
    }


    printf("O valor nao existe na lista!\n");


    return;
}
