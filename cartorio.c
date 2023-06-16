#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings


int registro() // fun��o respons�vel por cadastro no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF para cadastro: "); // coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se � string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o w � de writing
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // d� , entre as palavras escritas
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", nome); // refere-se � string
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,nome); // salva o nome do usu�rio
	fclose(file); // fecha o arquivo
		
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // d� v�rgula entre as palavras 
	fclose(file); // fecha o arquivo
		
		
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s",sobrenome); // refere-se � sting
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome); // salva a informa��o
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // adiciona v�rgula entre as informa��es
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s",cargo); // refere-se � string
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,cargo); // salva a informa��o
	fclose(file); // fecha o arquivo
	
	system("pause"); // d� uma pausa antes de seguir
	
}

int consultar() // fun��o respons�vel por consultar a base de dados
{
	setlocale(LC_ALL, "Portuguese"); // define a l�ngua 
	
	// in�cio da cria��o da vari�vel/string
	char cpf[40];
	char conteudo[200];
	// final da vari�vel/string	
	
	printf("Digite o CPF a ser consultado: "); // buscando informa��o do usu�rio
	scanf("%s",cpf);  // %s refere-se � string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r");  // cria o arquivo e r refere-se � reading
	
	if(file == NULL) // comparativo para caso n�o seja encontrado 
	{
		printf("N�o foi poss�vel localizar o arquivo! CPF n�o encontrado!/n/n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); 
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se enconta no sistema. Tente novamente!\n");
		system("pause");
		
	}
	
}

int main()
   {
	int opcao=0; //Definindo as vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela 
	
		setlocale(LC_ALL, "Portuguese");	//Definindo a linguagem
		
		printf ("Pesquisando Nomes\n\n"); //In�cio do menu
		printf ("Escolha a a��o desejada, de acordo com as op��es abaixo: \n\n");	
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
	
		printf("Op��o: ");//Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");
	
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es 
			
			case 2:
			consultar();
			break; 
			
			case 3:
			deletar();
			break; 
						
			default:
			printf("Essa n�o � uma op��o dispon�vel =(\n");
			system("pause");
			
			}
	}
}
	
	
