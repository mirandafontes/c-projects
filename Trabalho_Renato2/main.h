#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4( unsigned char *strTexto, unsigned char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

void StrToInt( int num[3], char str[] );
void IntToVet( int vet[], int num );
int LimiteMes ( int Data[3] );

#endif // MAIN_H_INCLUDED
