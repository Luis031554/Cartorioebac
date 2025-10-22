#include <stdio.h>  //bliblioteca de comunicação de usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> // bliblioteca respon´savel por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];
    //Final criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
    scanf("%s,", cpf);  // %s refere-se a sting
    
    strcpy(arquivo, cpf); // responsável por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo,"w"); // cria o arquivo e o "W" significa escrever
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadrastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
	fclose(file); //fecha o arquivo
		
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadrastado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); // fecha o arquivo
    
    printf("Digite o cargo a ser cadrastado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file); //fecha o arquivo
    
    system("pause");
    
}

int consulta() // Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{ 
		printf("Não foi possivel abrir o arquivo, não localizado!/n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas São as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar() //Função responsável por deletar usuário do sistema
{
    char cpf[40];

    printf("Digite o CPF do usuário ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf); // deleta o usuário do sistema
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    { 
       printf("O Usuário não se encontra no sistema!.\n");
       system("pause");
	}
    
}

int main()
{
	int opcao=0;  //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco==1;)
    {

       system("cls");
	   setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
	
	   printf("### cartório da EBAC ###\n\n");  // Definindo o menu
       printf("Escolha a opção desejada no menu:\n\n");
	   printf("\t1 - Resgistrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");  
	   printf("\t4 - Sair do sitema\n\n");
	   printf("Opção:  ");  // Fim do menu
	
	   scanf("%d", &opcao);  // Armazendo a escolha do usuário
	
	   system("cls"); // responsável por limpar a tela
	   
	   
	   
	   switch(opcao) // inicio da seleção do menu
	   {
	   	  	case 1:
	        registro(); // chamada de funções
	        break;
		    
	        case 2:
		    consulta();
		    break;
	    
		    case 3:
	        deletar();
		    break;
		    
			case 4:
			printf("obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			    
		    default:
		    printf("Essa opção não está disponível!\n");
	        system("pause");
	        break;
		   // fim da seleção    	
	}
	
	
   }
}


