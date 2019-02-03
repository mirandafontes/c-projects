#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define SIZEOF_ARRAY( a ) (sizeof( a ) / sizeof( a[ 0 ] ))

typedef void (WINAPI *callback)();
callback funcaoTemp;

int main(int argc, char** argv) {

    int op;
    int idConta, valor;

	HINSTANCE hLib;

	hLib = LoadLibrary("ContaDLL.dll");

	if (!hLib) { printf("Nao foi possivel carregar a dll."); return 0; }

	printf("Trabalho de Sistemas Distribuidos\n");
	printf("2018.2 ; 1- Parte: Sistema de cadastro de conta via DLL\n");
	printf("Aluno: Paulo Ricardo Miranda Fontes\n");
	printf("Professor: Alan Edgard\n");
	puts("");

    do {

    	printf("Digite 1 para Criar uma Conta\n");
        printf("Digite 2 para Ver seu saldo\n");
        printf("Digite 3 para Sacar\n");
        printf("Digite 4 para Depositar\n");
        printf("0 para sair: ");

		scanf("%d", &op);

		if(op >0 || op <= 4)
		{

	    	switch(op)
	        {
	            case 1:

	                printf("\nCadastro de Conta\n\n");

	                printf("Digite o ID da conta que deseja criar: ");
	                scanf("%d", &idConta);


			        fflush(stdin);

			        funcaoTemp = (callback) GetProcAddress((HMODULE)hLib, "criarConta");
			        funcaoTemp(idConta);

			        puts("");

			        break;
	        	case 2:

	                printf("\nVer saldo da Conta\n\n");

                    printf("Digite o ID da conta que deseja ver o saldo: ");
			        scanf("%d", &idConta);

			        fflush(stdin);

			        funcaoTemp = (callback) GetProcAddress((HMODULE)hLib, "verSaldo");
			        funcaoTemp(idConta);

			        puts("");

			        break;
	            case 3:
	                printf("\nSacar da Conta\n\n");

                    printf("Digite o ID da conta que deseja sacar: ");
			        scanf("%d", &idConta);

			        printf("\nDigite o valor que deseja sacar: ");
			        scanf("%d", &valor);

			        fflush(stdin);

			        funcaoTemp = (callback) GetProcAddress((HMODULE)hLib, "sacar");
			        funcaoTemp(idConta, valor);

			        puts("");

	                break;

                case 4:
	                printf("\nDepositar na Conta\n\n");

                    printf("Digite o ID da conta que deseja depositar: ");
			        scanf("%d", &idConta);

			        printf("\nDigite o valor que deseja depositar: ");
			        scanf("%d", &valor);

			        fflush(stdin);

			        funcaoTemp = (callback) GetProcAddress((HMODULE)hLib, "depositar");
			        funcaoTemp(idConta, valor);

			        puts("");

	                break;
	        }

		}
		else
		{
			printf("Opcao invalida \n ");

            printf("Digite 1 para Criar uma Conta\n");
            printf("Digite 2 para Ver seu saldo\n");
            printf("Digite 3 para Sacar\n");
            printf("Digite 4 para Depositar\n");
            printf("0 para sair: ");

			scanf("%d", &op);
		}

 	}
 	while (op != 0);

    return 0;

}
