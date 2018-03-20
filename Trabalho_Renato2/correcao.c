// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include<stdio.h>
#include<string.h>

void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();


int main(){
    
    testQ1();
    testQ2();
    testQ3();
    testQ4();
    testQ5();
    testQ6();

}

void testQ1(){
    char str[11];
    strcpy(str,"45/04/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/01/15");
    printf("%d\n",q1(str) == 1);
}

void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;
    
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/06/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n",retorno == 1);
    printf("%d\n",qtdDias == 0);
    printf("%d\n",qtdMeses == 0);
    printf("%d\n",qtdAnos == 1);
}

void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0) == 3);
    printf("%d\n",q3(str, 'A', 1) == 0);
}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 1);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
}


void testQ5(){
    printf("%d\n",q5(345) == 456);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
}
