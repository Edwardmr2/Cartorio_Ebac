#include <stdio.h> //biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

 int registro() // Fun��o responsavel por cadastrar usu�rios
{
	
	
	
	//Inicio cria��o de variaveis/strings
	
    setlocale(LC_ALL, "Portuguese");

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
		//FINAL cria��o de variaveis/strings
	    
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��o de usu�rio  
	  scanf("%s", cpf); //%s refere-se a string
	 
	  strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	 
	  FILE *file; //cria o arquivos
	  file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	  fprintf(file,cpf); //salvo valor variavel
	  
	  fclose(file); //fecha arquivo 
 
		 system("cls");
		 
	  file = fopen(arquivo, "a");
	     fprintf(file,"\nNome:");
	     fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	  scanf("%s", nome);
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,nome);
	  fclose(file);
	  
	     system("cls");
	
	  file = fopen(arquivo, "a");
	     fprintf(file,"\nSobrenome:");
	     fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	  scanf("%s", sobrenome);
	 
	  file = fopen(arquivo,"a");
	  fprintf(file,sobrenome);
	  fclose(file);
	  
	     system("cls");  
	    
	  file = fopen(arquivo, "a");
	     fprintf(file,"\nCargo:");
	      fclose(file);
            	    
	printf("Digite o cargo a ser cadastrado: ");
	  scanf("%s", cargo);
	  
	  file = fopen(arquivo,"a");
	  fprintf(file,cargo);
	  fclose(file);
	  
	     system("cls");
	  
         system("pause");

	}

int consulta()
{
   setlocale(LC_ALL, "Portuguese");
  
// Inicio cria��o de variaveis 
    char cpf[40];
    char conteudo[200];

// Final cria��o de variaveis
    
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usu�rio 
      scanf("%s",cpf); //%s Refere-se a string
    
     FILE *file; //Acessar arquivo "file"
	 file = fopen(cpf,"r"); //Em "file" acessar informa��es de "CPF"
	
	     system("cls"); //Apagar mensagens escritas nas escolhas de op��o
    
	 if(file == NULL) //Se n�o localizar arquivo tomar as seguintes medidas 
  	{
		printf("Usu�rio n�o encontrado!\n"); //Mensagem de aviso para usu�rio
 	}
 	     
printf("Essas s�o as informa��es do usu�rio!\n\nCPF:");
    while(fgets(cpf,40, file) != NULL) //Salvar enquanto conseguir informa��o e parar quando resultado for nulo  
 	{
 		
 		printf("%s", cpf); 
	     printf("\n\n");
	      }
	      
	      
	 fclose(file);
     system("pause"); //Pausar programa para o us�ario conseguir ler
     
 }

int deletar()
{
	setlocale(LC_ALL, "Portuguese");

//Inicio cria��o de variaveis
	char cpf[40];
//Final cria��o de variaveis
	
     	printf("Digite o CPF do usu�rio a ser deletado:");//Coletando informa��es
     	scanf("%s",cpf);//%s refere-se a string da variavel cpf
     	
     	
     	remove(cpf); //Remover usu�rio usando variavel cpf como modelo de busca
		 
			
		FILE *file; //Acessar arquivo "file"
     	file = fopen(cpf,"r"); //No arquivo file ler("r") variavel cpf
     	
    
     	if(file == NULL) //Se n�o achar arquivo tomar as seguintes medidas 
     	    { 
     		printf("Usu�rio n�o se encontra no sistema!\n\n");
     		system("pause");
     		
	         }  
	         fclose(file);
		    	
}

int main()
{
	int opcao=0;	//definindo variaveis
    int laco=1;
    char senhadigitada[10]="a";
    char login[18]="b";
	int comparacao;
		
		setlocale(LC_ALL, "Portuguese");
		
	printf ("### Cart�rio da EBAC ### \n\n");

     printf ("Digite seu login: ");
     scanf ("%s", login);
    
     comparacao = strcmp(login, "admin");
    
     if(comparacao == 0)
     {
	
	 printf ("Digite sua senha: ");
	 scanf ("%s",senhadigitada);
	
	 comparacao = strcmp(senhadigitada, "admin");
 	 if(comparacao == 0)
	 {
		
     for(laco=1;laco=1;)
     {
	
	     system("cls");
    
	     setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
	     printf ("### Cart�rio da EBAC ### \n\n"); //inicio do menu
	     printf("Escolha a op��o desejada do menu: \n\n");
	     printf("\t1 - Registrar nomes\n");
	     printf("\t2 - Consultar nomes\n");
	     printf("\t3 - Deletar nomes\n"); 
	     printf("\t4 - Sair do sistema\n\n");
	     printf("Op��o: ");//fim do menu
	
	     scanf("%d", &opcao); //armazenando a escolha do usu�rio 
	
	     system("cls");
	  
	  switch(opcao) //Inicio sele��o do menu
	  {
	  	case 1:
	  		 registro(); //Chamada de fun��es
	  	     break; //Parar programa
	  	case 2: 
	  	     consulta(); //Chamada de fun��es
	  	     break; //Parar programa
	  	case 3: 
	  	     deletar(); //Chamada de fun��es
             break; //Parar programa
        case 4: 
		      printf("Obrigado por utilizar o sistema Ebac!\n");
			  return 0;
			  break;     
                 
        
        default: //Qualquer outra op��o que n�o esteja dentro dos casos acima
        	 printf("Essa op��o n�o est� disponivel, tente novamente!\n");
	         system("pause");
	         break;
        	
	     }
	  
	 
     }
 }
 
     else
     printf("Senha incorreta!");
 }
     else
     printf("Login incorreto");
}
