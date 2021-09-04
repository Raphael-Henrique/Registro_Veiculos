#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

struct veiculo //dados a serem armazenados
	{
		char marca[20];
		char modelo[20];
		int ano;
		char placa[10];
		int existe;
	};
	
veiculo carro[MAX]; 
veiculo carros[MAX];
	
/******************************************************************************Declarando as funções a serem utilizadas*************************************************************************/
	
	//gera uma lista de opções
void menu();	
	//gera um cadastro geral
void Cadastro();
	//lista geral
void list();
	//gera uma lista a partir do modelo
void list_modelo();
	//gera uma lista a partir do ano de fabricação
void list_ano();
	//gera uma lista a partir do ano selecionado com uma tendência em após inserir o ano de fabricação, ele listará os veiculos cadastrados incrementados a partir do ano inserido
void list_anoup();
	//Permite a saida do sistema
void abort();
	//Ordenar os veículos por ano de fabricação em ordem crescente
void ordenar();



	
	
void menu()
{

int opcao;

do{
	system("cls");
	printf("\n-----------------------------------------------------OPCOES-------------------------------------------------------------\n\n\n");
	printf("1 - Cadastrar um veiculo \n");
	printf("2 - Listar veiculos cadatrados \n");
	printf("3 - Listar veiculos por ano de fabricacao \n");
	printf("4 - Listar veiculos cadastrados a partir do ano a ser inserido \n");
	printf("5 - Listar veiculos por modelos \n\n");
	printf("0 - Sair \n\n");
	printf("Digite o numero da opcao: ");
	scanf("%d", &opcao);
	getchar();
	
	switch(opcao)
	{
		case 1:
			Cadastro();
		break;
		case 2:
			list();
		break;
		case 3:
			list_ano();
		break;
		case 4:
			list_anoup();
		break;
		case 5:
			list_modelo();
		break;	
		case 0:
			abort();
		break;
	}
		
	}while(opcao!=0);
}
	
void Cadastro()
{
	char marca[20], modelo[20], placa[10];
	int i, ano, a = 0;
	int op;
do
{
	system("cls");
			
	printf("\n-----------------------------------------------CADASTRO DE VEICULOS-----------------------------------------------------\n\n\n");

		
	if(a < MAX)
	{
		printf("\n\n Marca do veiculo: ");
		fgets(marca, sizeof(marca), stdin);
		printf("\n\n Modelo: ");
		fgets(modelo, sizeof(modelo), stdin);
		printf("\n\n Placa(utilize esse formato xxx-yyyy): ");
		fgets(placa, sizeof(placa), stdin);
		printf("\n\n Ano de fabricacao: ");
		scanf("%d", &ano);
		a++;
		printf("\n\n Cadastro efetuado com sucesso! \n");
		printf("Deseja cadastrar mais um veiculo? \n 1-sim \n 2-nao \n insira um dos numeros acima: ");
		scanf("%d", &op);
		getchar();
	}
	else
	{
		printf("O limite maximo de cadastro e %d veiculos \n\n", MAX);
		printf("Pressione a tecla enter para sair");
		getchar();
		menu();
	}
	
	
	for(i=0; i<MAX; i++)
	{
		if(carro[i].existe==0)
		{
			strcpy(carro[i].marca, marca);
			strcpy(carro[i].modelo, modelo);
			strcpy(carro[i].placa, placa);
			carro[i].ano = ano;
			carro[i].existe=1;
			break;
		}
	}
}while(op != MAX);
				
				
}
void list()
{
	
	int i;
	system("cls");		
	printf("\n-----------------------------------------------LISTAGEM DE VEICULOS CADASTRADOS-----------------------------------------------------\n\n\n");
	
	ordenar();
	for(i=0; i < MAX; i++)
	{
		if(carro[i].existe==1)
		{
			printf("carro: %d", i);
			printf("\n\n Marca do veiculo: %s", carro[i].marca);
			printf("\n\n Modelo: %s", carro[i].modelo);
			printf("\n\n Ano de fabricacao: %d", carro[i].ano);
			printf("\n\n Placa: %s \n\n", carro[i].placa);
			printf("==================================================================================================================================\n\n");
		}
	}
		printf("Aperte enter para voltar");
		getchar();
}
		
void list_modelo()
{
	int i;	
	char modelo[30];					
	system("cls");		
				
				
	printf("\n-----------------------------------------------LISTAGEM DE VEICULOS CADASTRADOS APOS INSERIR O MODELO--------------------------------\n\n\n");
	
	printf("Insira o modelo abaixo: \n");
	fgets(modelo, sizeof(modelo), stdin);
	ordenar();
	for(i=0; i<MAX; i++)
	{
		if(strstr(carro[i].modelo, modelo)!=NULL)
		{
			printf("\n carro: %d", i);
			printf("\n\n Marca do veiculo: %s", carro[i].marca);
			printf("\n\n Modelo: %s", carro[i].modelo);
			printf("\n\n Ano de fabricacao: %d", carro[i].ano);
			printf("\n\n Placa: %s", carro[i].placa);
			printf("\n========================================================================================================================\n\n");
		}
	}
	printf("Aperte enter para voltar");
	getchar();
	
}		
void list_ano()
{
	int i, ano;
	system("cls");
			
	printf("\n-----------------------------------------------LISTAGEM DE VEICULOS CADASTRADOS APOS INSERIR O ANO DE FABRICACAO----------------------------------------------------------\n\n\n");	
	
	printf("\n Digite o ano de fabricacao abaixo: \n");	
	scanf("%d", &ano);
	system("cls");
printf("\n-----------------------------------------------LISTAGEM DE VEICULOS CADASTRADOS APOS INSERIR O ANO DE FABRICACAO----------------------------------------------------------\n\n\n");	
	ordenar();
	for(i=0; i<MAX; i++)
	{
		if(carro[i].ano == ano)
		{
			printf("\n carro: %d", i);
			printf("\n\n Marca do veiculo: %s", carro[i].marca);
			printf("\n\n Modelo: %s", carro[i].modelo);
			printf("\n\n Ano de fabricacao: %d", carro[i].ano);
			printf("\n\n Placa: %s", carro[i].placa);
			printf("\n====================================================================================================\n\n");
		}
	}
	printf("Aperte enter para voltar \n");
	getchar();
	getchar();
}
		
void list_anoup()
{
	int i, ano;
	system("cls");
			
	
	printf("\n Digite o ano de fabricacao abaixo: \n");	
	scanf("%d", &ano);
	system("cls");
	printf("\n-----------------------------------------------LISTAGEM DE VEICULOS CADASTRADOS APOS INSERIR O ANO DE FABRICACAO----------------------------------------------------------\n\n\n");	
	ordenar();
	for(i=0; i<MAX; i++)
	{
		if(carro[i].ano >= ano)
		{
			printf("\n carro: %d", i);
			printf("\n\n Marca do veiculo: %s", carro[i].marca);
			printf("\n\n Modelo: %s", carro[i].modelo);
			printf("\n\n Ano de fabricacao: %d", carro[i].ano);
			printf("\n\n Placa: %s", carro[i].placa);
			printf("\n====================================================================================================\n\n");
		}
	}
	printf("Aperte enter para voltar \n");
	getchar();
	getchar();

}
void ordenar()
{
	int i, j;
	
	for(i=0; i < MAX; i++)
	{
		for(j = i+1; j < MAX -1; j++)
		{
			if(carro[j].ano > carro[j+1].ano)
			{
				carros[j].ano = carro[j].ano;
				carros[j].existe = carro[j].existe;
				strcpy(carros[j].marca, carro[j].marca);
				strcpy(carros[j].modelo, carro[j].modelo);
				strcpy(carros[j].placa, carro[j].placa);
				
				strcpy(carro[j].marca, carro[j+1].marca);
				strcpy(carro[j].modelo, carro[j+1].modelo);
				strcpy(carro[j].placa, carro[j+1].placa);
				carro[j].ano = carro[j+1].ano;
				carro[j].existe = carro[j+1].existe;
				
				strcpy(carro[j+1].marca, carros[j].marca);
				strcpy(carro[j+1].modelo, carros[j].modelo);
				strcpy(carro[j+1].placa, carros[j].placa);
				carro[j+1].ano = carros[j].ano;
				carro[j+1].existe = carros[j].existe;
			}
		}
	}				
}
int main(int argc, char** argv)
{
    menu();
}
