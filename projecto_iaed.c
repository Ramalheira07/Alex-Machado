#include <stdio.h>

typedef struct{
	int NumeroRegisto,Classificacao;
	char Nome[TAMANHO_NOME];
}Banco;

Banco RegistarBanco(int numero,char nome,int classificacao);
Banco AlterarClassificacao(Banco banco,int classificacao);
int CompararBancos(Banco banco1,Banco banco2);
int E_Banco(Banco banco);
int VerClassificacao(Banco banco);
