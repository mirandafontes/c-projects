#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Paulo Ricardo Miranda Fontes
//  Email: mirandafontes.paulo@gmail.com
//  Matrícula: 2016116044
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################




int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

void StrToInt( int num[3], char str[] );
void IntToVet( int vet[], int num );
int LimiteMes ( int Data[3] );

int q1(char *data){
    int datavalida = 1;

    int anoB = 0;
    int i,DataInt[3]; // DataInt[0] = Dia ; DataInt[1] = Mês ; DataInt[2] = Ano;

    char str[12];

    for ( i = 0 ; data[i] ; i++ ) str[i] = data[i];

    str[i] = '/';


    StrToInt (DataInt,str);

    /*dia = num[0];
    mes = num[1];
    ano = num[2];*/

    if (( DataInt[2] % 4 == 0 && DataInt[2] % 100 !=0 ) || DataInt[2] % 400 == 0 ) anoB = 1;

    if ( ( DataInt[0] > 31 || DataInt[0] == 0 ) || ( DataInt[1] > 12 || DataInt[1] == 0 )  ) datavalida = 0;

    if ( DataInt[2]  <= 50 ) DataInt[2]+=2000;

    else DataInt[2]+=1000;

    switch (DataInt[1]) {

        case 1 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 2 : {

            if (anoB) {
                if ( DataInt[0] > 29 ) datavalida = 0;
            }

            else if ( DataInt[0] > 28) datavalida = 0;

            break;
        }

        case 3 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 4 : {

            if ( DataInt[0] > 30 ) datavalida = 0;
            break;
        }

        case 5 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 6 : {

            if ( DataInt[0] > 30 ) datavalida = 0;
            break;
        }

        case 7 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 8 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 9 : {

            if ( DataInt[0] > 30 ) datavalida = 0;
            break;
        }

        case 10 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

        case 11 : {

            if ( DataInt[0] > 30 ) datavalida = 0;
            break;
        }

        case 12 : {

            if ( DataInt[0] > 31 ) datavalida = 0;
            break;
        }

    }

    return datavalida;

}

void StrToInt ( int num[3], char str[] ) {

    int aux = 1,ultimaBarra = 0;
    int i,j,k = 0;
    int digitos = 0;

    for ( i = 0 ; i < 3 ; i++ ) num[i] = 0;

    for ( i = 0 ; str[i] ; i++ ) {

            if ( str[i] != '/' ) ++digitos;

            if ( str[i] == '/') {

                for ( j = 1 ; j < digitos ; j++ ) aux *= 10;


                for ( j = ultimaBarra ; j <= i ; ) {

                        if ( str[j] == '/' ) ++j;

                        else if ( str[j] == '0') {
                            ++j;
                            aux /= 10;
                        }

                        else {

                            if ( (str[j] < '0' || str[j] > '9') ) return;

                            else {

                                num[k] += ( str[j] - '0' ) * aux;
                                aux /= 10;
                                ++j;

                            }

                        }

                }

                ++k;
                aux = 1;
                ultimaBarra = i;
                digitos = 0;

            }

   }


    return;
}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){

    *qtdDias = 0;
    *qtdMeses = 0;
    *qtdAnos = 0;


    int i,limiteDias = 0;
    int limiteDiasFixo = 0;
    int DataIni[3],DataFin[3]; // Data''[0] = Dia ; Data''[1] = Mês ; Data''[2] = Ano;

    char Data_Ini[12],Data_Fin[12];

    for ( i = 0 ; datainicial[i] ; i++ ) Data_Ini[i] = datainicial[i];

    Data_Ini[i] = '/';

    for ( i = 0 ; datafinal[i] ; i++ ) Data_Fin[i] = datafinal[i];

    Data_Fin[i] = '/';


    for ( i = 0 ; i < 3 ; i++ ) DataIni[i] = DataFin[i] = 0;


    if ( q1(datainicial) == 0 ) return 2;

    if ( q1(datafinal) == 0) return 3;


    StrToInt ( DataIni, Data_Ini);
    StrToInt ( DataFin, Data_Fin);


    if ( ( DataIni[2] > DataFin[2] ) || ( ( DataIni[1] > DataFin[1] ) && ( ( DataIni[1] != 2 ) && ( DataFin[1] != 2 ) ) ) || ( DataIni[0] > DataFin[0] ) ) return 4;

    *qtdAnos = DataFin[2] - DataIni[2]; // POR ENQUANTO, DPS FAZER USANDO DIAS MESMO (?)


    if ( ( DataIni[1] == DataFin[1] ) && ( DataIni[2] == DataFin[2] || DataIni[2] == DataFin[2] - 1 ) ) {

        *qtdDias = DataFin[0] - DataIni[0];

        if ( *qtdDias < 0 ) *qtdDias = 0;

        return 1;
    } // Se no mesmo mês e mesmo dia

    if ( DataIni[1] == DataFin[1] && DataIni[0] > DataFin[0] ) // Diferença de Anos apenas
        return 1;

    if ( DataIni[0] == DataFin[0] && DataIni[1] == DataIni[1] )
        if (  ( DataIni[2] % 4 == 0 && DataIni[2] % 100 !=0 ) || DataIni[2] % 400 == 0 )
            if (  ( DataFin[2] % 4 == 0 && DataFin[2] % 100 !=0 ) || DataFin[2] % 400 == 0 )
                *qtdDias+=1;

    limiteDiasFixo = LimiteMes( DataIni );

    for ( i = 1 ; ; ) {

        limiteDias = LimiteMes( DataIni );

        if ( ( DataIni[0] == DataFin[0] ) && ( DataIni[1] == DataFin[1] ) ) break;

        DataIni[0]++;
        i++;

        *qtdDias = i;

        if ( *qtdDias == limiteDiasFixo ) {

            limiteDiasFixo = LimiteMes( DataIni );
            *qtdMeses += 1;
            *qtdDias = 0;
            i = 0;

        }

        if ( DataIni[0] >= limiteDias ) { // VER AS CONDIÇÕES E ALTERAÇÕES NAS QTD! // O FATO DE  DATAINI ALCANÇAR LIMITE DIAS NÃO INDICA Q SE PASSOU UM MÊS; VER I

            DataIni[0] = 1;
            DataIni[1]++;

        }

    }

    return 1;

}

int LimiteMes ( int Data[3] ) {

    int limite_Em_Dias;

        if ( ( Data[1] == 1 ) || ( Data[1] == 3 ) || ( Data[1] == 5 ) || ( Data[1] == 7 ) || ( Data[1] == 8 ) || ( Data[1] == 10 ) || ( Data[1] == 12 ) )
            limite_Em_Dias = 31;

        else if ( ( Data[1] == 4 ) || ( Data[1] == 6 ) || ( Data[1] == 9 ) || ( Data[1] == 11 )  )
            limite_Em_Dias = 30;

        else if ( Data[1] == 2 ) {

            if ( ( Data[2] % 4 == 0 && Data[2] % 100 !=0 ) || Data[2] % 400 == 0 )

                limite_Em_Dias = 29;

            else

                limite_Em_Dias = 28;

        }


        return limite_Em_Dias;
}

int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;
    int i;

    if ( isCaseSensitive == 1 ){

        qtdOcorrencias = 0;

        for ( i = 0 ; texto[i] ; i++)
            if ( texto[i] == c) ++qtdOcorrencias;
    }


    else { //APARENTA FUNCIONAMENTO CORRETO

        if ( c >= 'A' && c <= 'Z' ) {

            qtdOcorrencias = 0;
            for ( i = 0 ; texto[i] ; i++)
                if ( texto[i] == c || texto[i] == ( c - 'A' + 'a') ) ++qtdOcorrencias;

        }

        else if ( c >= 'a' && c <= 'z') {

            qtdOcorrencias = 0;
                for ( i = 0 ; texto[i] ; i++)
                    if ( texto[i] == c || texto[i] == ( c - 'a' + 'A') ) ++qtdOcorrencias;

        }

    }


    return qtdOcorrencias;

}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = -1;

    int i,j,tam;
    int aux = 0;

    for ( tam = 0 ; strBusca[tam] ; tam++ );

    for ( i = 0 ; strTexto[i] ; i++ ) {

        if ( strTexto [i] == strBusca[0] ) {

                posicoes[aux] = i;

                for ( j = 0 ; j <= tam - 1 ; j++, i++ ) {

                    if ( strTexto[i] != strBusca [j] ) break;

                    else if ( j == tam - 1 ) {

                        aux++;
                        posicoes[aux] = i;
                        qtdOcorrencias++;
                        aux++;

                }
            }
        }
    }

    for ( i = 0 ; i < 30 ; i++ ) posicoes[i]++;

    if ( qtdOcorrencias >= 0 ) qtdOcorrencias++;

    return qtdOcorrencias;

}

int q5(int num) {

    int vet[9];
    int i,aux = 0;
    int dec;

    dec = 100000000;

    for ( i = 0 ; i < 9 ; i++ ) vet[i] = 0;

    IntToVet( vet, num );

    for ( i = 8 ; i >= 0 ; i-- ) {

        aux += vet[i] * dec;
        dec/=10;

    }



    return aux;
}

int q6( int numerobase, int numerobusca){
    int qtdOcorrencias = 0;

    int i,j,k,aux,aux2;

    int VetBase[9];
    int VetBusca[9];

    for ( i = 0 ; i < 9 ; i++ ) VetBase[i] = VetBusca[i] = -1;


    IntToVet(  VetBase, numerobase );

    for ( aux = 0 ; VetBase[aux] != -1 ; aux++ );

    if ( numerobusca >= 0 && numerobusca <= 9 ) {

        for ( i = 0 ; i < aux ; i++ ) if ( VetBase[i] == numerobusca ) qtdOcorrencias++;

        return qtdOcorrencias;

    }


    else {


        IntToVet( VetBusca, numerobusca );

        for ( aux2 = 0 ; VetBusca[aux2] != -1 ; aux2++ );



        for ( i = 0 ; i < aux ; i++ ) {

            if ( VetBase[i] == VetBusca[0] ) {

                for ( j = 0 , k = i ; j < aux2 ; j++ , k++ ) {

                    if ( VetBase[k] != VetBusca[j] ) break;

                    else if ( j == aux2 - 1) qtdOcorrencias++;
                }
            }
        }

    }

    return qtdOcorrencias;
}

void IntToVet( int vet[], int num ) {
    int i, resto, tam = 0, aux;

    aux = num;

    while ( aux != 0 ) {

        tam++;
        aux /= 10;

    } // Pega o 'tamanho' do número

    for ( i = 0 ; i < tam ; i++ ) vet[i] = 0;

    for ( i = 0 ; i < tam ; i++ ) {

        resto = num % 10; // Pega o resto
        num /= 10; // Tira uma casa do numero

        vet[ tam - ( i + 1 ) ] = resto; // Evita a construção ao contrária do número. Começa da Ultima posição até a 1. Exemplo > 159753 = 1  5  9  7  5  3
    }                                                                                                                                   // 0  1  2  3  4  5 = Posições

    return;
}
