#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //printf fazer perguntas para o usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //fopen abrir o arquivo
	fprintf(file,","); //adicionar espaçamento entre as informações
	fclose(file); // fclose fechando o arquivo
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	system("pause");	
}
int consulta() //Função responsavel por colsultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário:\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	system("pause");
}
int deletar() //Função responsavel por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("Usuário deletado com sucesso!\n");
	system("pause");
	}
}
int main() //Menu visivel para o usuário
{
	int opcao=0; //Definindo variáveis
	int rep=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp comparação de stings
	
	if(comparacao == 0)
	{
		
	system ("cls");
		for(rep=1;rep=1;)
		{	
		system("cls");
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n");	 //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Opção:"); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usúario
	
			system("cls"); //Responsavel por limpar a tela
	
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			} //fim da selecão			
		}
	}
	else
	printf("\nSenha incorreta!");
}
