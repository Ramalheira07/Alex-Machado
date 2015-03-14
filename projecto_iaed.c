#include <stdio.h>
# define TAMANHO_NOME 40
# define TAMANHO_MATRIZ_MAX 1000; 

typedef struct{
	int NumeroRegisto,Classificacao;
	char Nome[TAMANHO_NOME];
}Banco;

typedef struct{
    Banco banco;
    int Credito_UM;
}Elemento;

Elemento Matriz[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX];
int NumBancosExistentes=0;

Banco RegistarBanco(int numero,char nome,int classificacao,Elemento Matriz[][],NumBancosExistentes);
Banco AlterarClassificacao(Banco banco,int classificacao);
int CompararBancos(Banco banco1,Banco banco2);
int E_Banco(Banco banco);
int VerClassificacao(Banco banco);

