#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

 int registro() // Função responsavel por cadastrar usuários
{
	
	
	
	//Inicio criação de variaveis/strings
	
    setlocale(LC_ALL, "Portuguese");

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
		//FINAL criação de variaveis/strings
	    
	printf("Digite o CPF a ser cadastrado:"); //Coletando informação de usuário  
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
  
// Inicio criação de variaveis 
    char cpf[40];
    char conteudo[200];

// Final criação de variaveis
    
	printf("Digite o CPF a ser consultado: "); //Coletando informações do usuário 
      scanf("%s",cpf); //%s Refere-se a string
    
     FILE *file; //Acessar arquivo "file"
	 file = fopen(cpf,"r"); //Em "file" acessar informações de "CPF"
	
	     system("cls"); //Apagar mensagens escritas nas escolhas de opção
    
	 if(file == NULL) //Se não localizar arquivo tomar as seguintes medidas 
  	{
		printf("Usuário não encontrado!\n"); //Mensagem de aviso para usuário
 	}
 	     
printf("Essas são as informações do usuário!\n\nCPF:");
    while(fgets(cpf,40, file) != NULL) //Salvar enquanto conseguir informação e parar quando resultado for nulo  
 	{
 		
 		printf("%s", cpf); 
	     printf("\n\n");
	      }
	      
	      
	 fclose(file);
     system("pause"); //Pausar programa para o usúario conseguir ler
     
 }

int deletar()
{
	setlocale(LC_ALL, "Portuguese");

//Inicio criação de variaveis
	char cpf[40];
//Final criação de variaveis
	
     	printf("Digite o CPF do usuário a ser deletado:");//Coletando informações
     	scanf("%s",cpf);//%s refere-se a string da variavel cpf
     	
     	
     	remove(cpf); //Remover usuário usando variavel cpf como modelo de busca
		 
			
		FILE *file; //Acessar arquivo "file"
     	file = fopen(cpf,"r"); //No arquivo file ler("r") variavel cpf
     	
    
     	if(file == NULL) //Se não achar arquivo tomar as seguintes medidas 
     	    { 
     		printf("Usuário não se encontra no sistema!\n\n");
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
		
	printf ("### Cartório da EBAC ### \n\n");

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
	
	
	     printf ("### Cartório da EBAC ### \n\n"); //inicio do menu
	     printf("Escolha a opção desejada do menu: \n\n");
	     printf("\t1 - Registrar nomes\n");
	     printf("\t2 - Consultar nomes\n");
	     printf("\t3 - Deletar nomes\n"); 
	     printf("\t4 - Sair do sistema\n\n");
	     printf("Opção: ");//fim do menu
	
	     scanf("%d", &opcao); //armazenando a escolha do usuário 
	
	     system("cls");
	  
	  switch(opcao) //Inicio seleção do menu
	  {
	  	case 1:
	  		 registro(); //Chamada de funções
	  	     break; //Parar programa
	  	case 2: 
	  	     consulta(); //Chamada de funções
	  	     break; //Parar programa
	  	case 3: 
	  	     deletar(); //Chamada de funções
             break; //Parar programa
        case 4: 
		      printf("Obrigado por utilizar o sistema Ebac!\n");
			  return 0;
			  break;     
                 
        
        default: //Qualquer outra opção que não esteja dentro dos casos acima
        	 printf("Essa opção não está disponivel, tente novamente!\n");
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
