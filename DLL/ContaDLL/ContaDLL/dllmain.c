
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "dll.h"
#define MIN 0
#define MAX 9

CADDLL void criarConta(int idConta)// Cria a conta com o ID especificado
{
    FILE *arq;

    arq = fopen("database.txt", "a");  // Cria um arquivo texto para gravação. Append o tipo de escrita.
    if (arq == NULL)               // Se nào conseguiu criar exibe a mensagem e não cria
    {
        printf("Nao foi possivel criar o arquivo. Verifique permissoes de leitura e escrita na pasta.\n");
        return;
    }
    else if (idConta < MIN || idConta > MAX)
    {
        printf("Nao foi possivel criar a conta. ID invalido. Por favor, insira um ID entre 0 e 9.\n");
        return;
    }

    fprintf(arq,"%d, %d.\n", idConta, 0); //Escreve no arquivo a conta, que comeca com saldo R$ 0,00

    fclose(arq);
    printf("Conta registrada com sucesso.\n");

}

/*

int someInt = 368;
char str[12];
sprintf(str, "%d", someInt);

*/

CADDLL void verSaldo(int id)
{
    char buffer[100]; //Buffer para o fgets
    char tmpID[12];

    FILE* arq;

    arq = fopen("database.txt", "r");// Cria um arquivo texto. Modo leeitura

    if (arq == NULL)               // Se nào conseguiu criar exibe a mensagem e não cria
    {
        printf("Nao foi possivel ler do arquivo. Verifique permissoes de leitura e escrita na pasta.\n");
        return;
    }
    else if (id < MIN || id > MAX)
    {
        printf("ID invalido. Por favor, insira um ID entre 0 e 9.\n");
        return;
    }

    printf("Pesquisando por id: %d", id);
    puts("");

    sprintf(tmpID, "%d", id);

    while( !feof(arq) ) //Enquanto não for o final do arquivo
    {

        fgets( buffer, 100, arq );

        if (strstr(buffer, tmpID)) //Compara a string retirada do arquivo com o ID fornecido.
        {
            printf("Conta encontrado:\nID e Saldo:\n");
            printf(buffer);
            fclose(arq);

            return;
        }

    }

    fclose(arq);

    printf("Conta nao encontrada.\n");

    return;
}

CADDLL void sacar (int id, int valor){

	char buffer[100]; //Buffer temporario para leitura das linhas do arquivo
	char tmpID[12]; //Buffer para o ID
	int duplicate; //Int para evitar duplicatas

	FILE *pTemp; //Ponteiro de arquivo temporario
	FILE *arq; //Ponteiro para a base de dados atual

	arq = fopen("database.txt","r"); //Abre o arquivo atual
	pTemp = fopen("Temp.txt", "w+"); //Abre um arquivo temporario
	duplicate = 0;

	if(arq == NULL || pTemp == NULL)
	{
        printf("Nao foi possivel ler do arquivo. Verifique permissoes de leitura e escrita na pasta.\n");
        return;
	}
    else if (id < MIN || id > MAX)
    {
        printf("ID invalido. Por favor, insira um ID entre 0 e 9.\n");
        return;
    }

	sprintf(tmpID, "%d", id);

 	while( !feof(arq) )//Enquanto não for eof
    {

        fgets(buffer, 100, arq); //Le uma linha do arquivo

        if (strstr(buffer, tmpID) && duplicate == 0) //Verifica se e igual ao ID fornecido
        {
            char* tempSaldo;
            int saldo;

            tempSaldo = strtok(buffer,",");//Retorna o ID
            tempSaldo = strtok(NULL,",");//Retorna o valor

            saldo = strtol(tempSaldo, NULL, 10);//Transforma o valor de string para long int

            saldo -= valor;

            fprintf(pTemp, "%d, %d.\n", id, saldo);

            printf("Valor sacado da conta:%d\n", valor);
            printf("Valor atual do saldo da conta:%d\n", saldo);

            duplicate = 1;
        }
        else
        {
            fprintf(pTemp, buffer);
        }

	}

	fclose(arq);
	fclose(pTemp);

	remove("database.txt"); //Remove o arquivo original
	rename("Temp.txt", "database.txt"); //Renomeia o temporario para o arquivo original. O arquivo temporario contem uma copia de todos os registros, exceto da conta desejada

	return;
}

CADDLL void depositar (int id, int valor){

	char buffer[100]; //Buffer temporario para leitura das linhas do arquivo
	char tmpID[12]; //Buffer para o ID
	int duplicate; //Int para evitar duplicatas

	FILE *pTemp; //Ponteiro de arquivo temporario
	FILE *arq; //Ponteiro para a base de dados atual

	arq = fopen("database.txt","r"); //Abre o arquivo atual
	pTemp = fopen("Temp.txt", "w+"); //Abre um arquivo temporario
	duplicate = 0;

	if(arq == NULL || pTemp == NULL)
	{
        printf("Nao foi possivel ler do arquivo. Verifique permissoes de leitura e escrita na pasta.\n");
        return;
	}
    else if (id < MIN || id > MAX)
    {
        printf("ID invalido. Por favor, insira um ID entre 0 e 9.\n");
        return;
    }

	sprintf(tmpID, "%d", id);

 	while( !feof(arq) )//Enquanto não for eof
    {

        fgets(buffer, 100, arq); //Le uma linha do arquivo

        if (strstr(buffer, tmpID) && duplicate == 0) //Verifica se e igual ao ID fornecido
        {
            char* tempSaldo;
            int saldo;

            tempSaldo = strtok(buffer,",");//Retorna o ID
            tempSaldo = strtok(NULL,",");//Retorna o valor

            saldo = strtol(tempSaldo, NULL, 10);//Transforma o valor de string para long int

            saldo += valor;

            fprintf(pTemp, "%d, %d.\n", id, saldo);

            printf("Valor depositado na conta:%d\n", valor);
            printf("Valor atual do saldo da conta:%d\n", saldo);

            duplicate = 1;
        }
        else
        {
            fprintf(pTemp, buffer);
        }

	}

	fclose(arq);
	fclose(pTemp);

	remove("database.txt"); //Remove o arquivo original
	rename("Temp.txt", "database.txt"); //Renomeia o temporario para o arquivo original. O arquivo temporario contem uma copia de todos os registros, exceto da conta desejada

	return;
}





