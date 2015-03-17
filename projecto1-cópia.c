#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define TAMANHO_NOME 40
# define TAMANHO_MATRIZ_MAX 1000

typedef struct{
	int NumeroRegisto,Classificacao,posicao_Matriz;
	char Nome[TAMANHO_NOME];
}Banco;

/* Variaveis Globais */
/* NBE NUMERO DE BANCOS EXISTENTES */
int Matriz[TAMANHO_MATRIZ_MAX][TAMANHO_MATRIZ_MAX],NBE=0;
Banco bancos[TAMANHO_MATRIZ_MAX];

/* Definiçcoes das funçcoes */
void amortizacao(int numero1,int numero2,int valor,int NBE);
void emprestimo(int numero1,int numero2,int valor,int NBE);
void RegistarBanco(char nome[],int Classificacao,int numero,int NBE);
void AlterarClassificacao(int numero,int classificacao,int NBE);
void listagem_Tipo0(int NBE);
void listagem_Tipo1(int NBE);
int dividas(Banco banco,int NBE);
void numBancosTotaleBons(int NBE);
int CompararBancos(Banco banco1,Banco banco2);
int E_Banco(Banco banco);
int VerClassificacao(Banco banco);

/*===========================================================================================*/

/* Funcoes Basicas (testes,reconhecedores,construtores,selectores e modificadores) */


int VerClassificacao(Banco banco){
return banco.Classificacao;
}
/* Registar um novo banco na matriz */
void RegistarBanco(char nome[],int Classificacao,int numero,int NBE){
	bancos[NBE].NumeroRegisto = numero;
	strcpy(bancos[NBE].Nome,nome);
	bancos[NBE].Classificacao = Classificacao;
	bancos[NBE].posicao_Matriz = NBE;
}

/*===========================================================================================*/


void emprestimo(int numero1,int numero2,int valor,int NBE){
    if (numero1!=numero2){
        int i,j;

        for(i=0; i<NBE; i++){
            if (bancos[i].NumeroRegisto == numero1)
                for(j=0; j<NBE; j++){
                if (bancos[j].NumeroRegisto == numero2)
                        Matriz[i][j] = valor;
                }
        }
    }

}

/*===========================================================================================*/


void amortizacao(int numero1,int numero2,int valor,int NBE){
   if (numero1!=numero2){
        int i,j;
        for(i=0; i<NBE; i++){
            if (bancos[i].NumeroRegisto == numero1)
                for(j=0; j<NBE; j++){
                if (bancos[j].NumeroRegisto == numero2)
                        Matriz[j][i] -= valor;
                }
        }
    }
}

/*===========================================================================================*/

void AlterarClassificacao(int numero,int classificacao,int NBE){
   int i=0;
   for(i=0; i<NBE; i++){
    if (bancos[i].NumeroRegisto == numero)
        bancos[i].Classificacao = classificacao;
   }
}

/*===========================================================================================*/

void DespromoveBanco(int NBE){
   int i=0,j=0,soma=0,maiorSoma=0,ref=0;

   for(i=0; i<NBE; i++){

        if ( bancos[i].Classificacao == 1)
            for(j=0; j<NBE; j++){
                if (bancos[j].Classificacao == 0 && Matriz[i][j]>0)
                    soma += Matriz[i][j];
            }
        if (maiorSoma<=soma){
                ref=bancos[i].NumeroRegisto;maiorSoma=soma;soma=0;
                printf("%d",maiorSoma);
        }
   }

   for(i=0; i<NBE; i++){
    if (bancos[i].NumeroRegisto == ref)
         bancos[i].Classificacao = 0;
   }


}

/*===========================================================================================*/
/* Lista todos os bancos ordenados pela ordem de introducao no sistema */
void listagem_Tipo0(int NBE){
    int i;
    for(i=0; i<NBE; i++)
        printf("%d %s %d\n",bancos[i].NumeroRegisto,bancos[i].Nome,bancos[i].Classificacao);
}

/*===========================================================================================*/
void listagem_Tipo1(int NBE){
  int i=0;
    for (i = 0; i < NBE; i++){
      printf("%d %s %d %d\n",bancos[i].NumeroRegisto,bancos[i].Nome,bancos[i].Classificacao,\
        dividas(bancos[i],NBE));
    }
}

int dividas(Banco banco,int NBE){
  int i,cont=0;
    for(i=0; i < NBE; i++)
      if((Matriz[i][banco.posicao_Matriz])>0)
        cont++;
    return cont;  
}
/*===========================================================================================*/
void numBancosTotaleBons(int NBE){
    int bons=0,i;
    for(i=0;i< NBE;i++)
        if(bancos[i].Classificacao==1)
            bons++;
    printf("%d %d\n",NBE,bons);
}

/*===========================================================================================*/
int main(){

    char comando,nome[40];
    int numero,classificacao,numero2,valor,i,j;


while (1) {
        comando = getchar(); /* le o comando */
        switch (comando) {
        case 'a':
            /* Chama a funcao responsavel pela execucao do comando a */
            scanf("%s%d%d",&nome,&classificacao,&numero);
            RegistarBanco(nome,classificacao,numero,NBE);
            NBE++;
            break;
        case 'k':
               scanf("%d",&numero);
               AlterarClassificacao(numero,0,NBE);
            /* Chama a funcao responsavel pela execucao do comando k */
            break;
        case 'K':
               DespromoveBanco(NBE);
            /* Chama a funcao responsavel pela execucao do comando K */
            break;
         case 'r':
               scanf("%d",&numero);
               AlterarClassificacao(numero,1,NBE);
            /* Chama a funcao responsavel pela execucao do comando r */
            break;
         case 'e':
               scanf("%d%d%d",&numero,&numero2,&valor);
               emprestimo(numero,numero2,valor,NBE);
            /* Chama a funcao responsavel pela execucao do comando e */
            break;
          case 'p':
               scanf("%d%d%d",&numero,&numero2,&valor);
               amortizacao(numero,numero2,valor,NBE);
            /* Chama a funcao responsavel pela execucao do comando p */
            break;
        case 'l':
               scanf("%d",&numero);
               if (numero == 0)
                    listagem_Tipo0(NBE);
               if (numero == 1)
                    listagem_Tipo1(NBE);
            /* Chama a funcao responsavel pela execucao do comando l 0 , l 1 , l 2 */
            break;
          case 'v':
              for(i=0;i<NBE;i++){
                    for (j=0;j<NBE;j++)
                      printf("[ %d ]",Matriz[i][j]);
                    printf("\n");
               }
            break;

        case 'x':
            numBancosTotaleBons(NBE);
            return EXIT_SUCCESS; /* Termina o programa com sucesso (STDLIB) */
        default:
            printf("ERRO: Comando desconhecido\n");
        }
        getchar(); /* le o '\n' introduzido pelo utilizador */
    }
return EXIT_FAILURE; /* se chegou aqui algo correu mal (STDLIB)*/
}
