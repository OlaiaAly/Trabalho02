#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include "hJogador.h"
#define tamanho 50

	
	 	   	/*_***************Declaracoes Basicas*******************_*/
	   	   	   	   	   	   	
   	   	   		   	 char menuPrincipal();
					 void ajuda();	
					 int idEquipaPerferido;	
												 
					int vetIdEquipas[tamanho];
					int totalDeEquippes = 0;
					int totalJogadores =0;
					int vetJogadoresId [tamanho];
					int vetJogadoresGolos[tamanho];
					
					
	//	 bool verficacao(int num, int vetNum[], int size);	
	/*___________________JOGADOR___________________*/
						int linhas=0;
						int vetIdJogadore[tamanho] ={0};
						int vetGoloJogador[tamanho] = {0};
						void criarJogador();
						FILE *abrirAquivo(char modo, char caminho[30]);
						void fecharArquivo(FILE* arquivo);
						void adicionarBD();
						void listarJogador();
							
							/*___________________FIM___________________________*/
							
							
/*___________________EQUIPAS___________________*/
				
					void listarEquipas();
					
					char verficacao(int id, int size, int vetNum[]);
								
/*_____________________FIM_____________________*/							

/*____________Inicio contruindo a estrutura logica do jogador__________*/
						

						
												
char  menuPrincipal(){
	setbuf(stdin, NULL);
	system("cls");
    printf("\n\n\t\t_____________Bem vindo_________________\n\n\t\t\t\tMENU PRINCIPAL\n");
	printf("\n1.Criar Equipa \n2. Listar Equipas\n3.Ajuda?\n");
	printf("\nDigite a sua opcao: ");
	
	return getchar();
};

void ajuda(){
	printf("\n_____________________________BEM_VINDO A AJUDA___________________________\n\n");
	printf("\n A opcao 1, cria a equipa, basicamente ela recebe o codigo id e posteriormente o nome/sigla da mesma.\n\t Para relalizar algumas operacoes operacoes tais como inserir, listar ou mesmo apagar jogadores, sega os seguinte passsos:\n");
	printf("\n\t\t PASSO 1 - lista as  equipas com a OPCAO 2 -> no MENU PRINCIPAL; \n\t\t PASSO 2 - lista ecolha o id da equipa que deseja alterar!\n");
	printf("\n Sigua os PASSOS adiante!\n");	
}						


struct Jogador {
    int id;
    int idEquipa;
	char nome[20];
	char apelido[20];
	int estado;
	char inicioCotrato[12];
	char fimContracto [12];
	int golos;
} jogador;

/*___________________________comandos CRUD___________________________*/


void adicionarBD( struct Jogador jogador){
	FILE *arquivo = abrirAquivo('a', "pJogador/jogarlist.txt");
	
		
		fprintf(arquivo, "%d %d %s %s %d %s %s %d\n", jogador.id, jogador.idEquipa, jogador.nome, jogador.apelido, jogador.estado, jogador.inicioCotrato,  jogador.fimContracto , jogador.golos);
		
	  fecharArquivo(arquivo);
}


void criarJogador(struct Jogador jogador){	
	printf("\n_______________________Criando Jogador __________________________\n ");
	fflush(stdin);
	
	int codigo=0;	
		do{	
			if(codigo != 0){
				system("cls");
				printf("\r\r\tO ID %d, ja existe tente com um outro! ou digite 0 (zero) para sair!", codigo);
				scanf("%d", &codigo);
				if(codigo==0) menuPrincipal();
			}
			system("cls");
			printf("\n Entre com o id do Jogador * (o id deve ser unico para cada jogador):  ");
			scanf("%d", &codigo);
			
		}while(verficacao(codigo, totalJogadores, vetJogadoresId)=='1');
	jogador.id = codigo;
	system("cls");
	printf("\n\n\tO ID foi definido com sucesso!\n\t ID *: %d", jogador.id);

	printf("\n\tNome *: ");
	scanf("%s", &jogador.nome);
	setbuf(stdin, NULL);
	
	printf("\n\tApelido *: ");
	scanf("%s", &jogador.apelido);
	setbuf(stdin, NULL);
	
	jogador.idEquipa = idEquipaPerferido;
	printf("\n\tID * da Equipa: %d (automatizado!)\n", jogador.idEquipa);
	
	
	printf("\n\tNumero Golos: ");
	scanf("%d", &jogador.golos);
	setbuf(stdin, NULL);
	
	printf("\n\tAtivo * (1/0): ");
	scanf("%d", &jogador.estado);
	setbuf(stdin, NULL);

	
	printf("\n\tData* de incio de contrato no formato dd/MM/YY: ");
	scanf("%s", &jogador.inicioCotrato);
	setbuf(stdin, NULL);
		
	printf("\n\tData* de incio de contrato no formato dd/MM/YY: ");
	scanf("%s", &jogador.fimContracto);
	setbuf(stdin, NULL);

 	adicionarBD(jogador);// adicionado o na BD

}
	 
void listarJogador(struct Jogador jogador){
		
	
		FILE *arquivo = abrirAquivo('l', "pJogador/jogarlist.txt");
	
    	printf("\n\n\tLista de jogadores\n");
    		   
    //!feof(arquivo)
   int i=0, j = 0;
   while(fscanf(arquivo, "%d %d %s %s %d %s %s %d\n", &jogador.id, &jogador.idEquipa, &jogador.nome, &jogador.apelido, &jogador.estado, &jogador.inicioCotrato, &jogador.fimContracto, &jogador.golos) != EOF)
   {
   	 
   	   // So para listar jogadores de uma equipa selectionada
	   	if(idEquipaPerferido == jogador.idEquipa){
			printf(" %03d %03d %10s %10s    %03d    %10s    %10s     %5d\n", jogador.id, jogador.idEquipa, jogador.nome, jogador.apelido, jogador.estado, jogador.inicioCotrato,  jogador.fimContracto , jogador.golos);
			j++;
		}
			
		vetJogadoresId[i] = jogador.id;
		vetJogadoresGolos[i] = jogador.golos;
		i++;
   }
   
   
	printf("\n\tTotal de Jogador: %d\n", j);
	fecharArquivo(arquivo);
	totalJogadores = i;
	printf("\n");
	

}

/*_____________________________________fim_comandos_CRUD___________________________*/



	/*________________________________ESTRURAA DA EQUIPA__________________________________*/
	
	

	struct tp_equipa{ // entidade de equipa
	   	int id;
		char nome[30];
	} equipa;	
	
	
char verficacao(int id, int size, int vetNum[]){
	int i=0;
	
	for(i = 0; i < size; i++){
		if(id ==vetNum[i]){
			return '1';
		}
	}	
	return '0';
}

	
void criarEquipa(struct tp_equipa equipa){
	
		printf("\n_______________________________CRIANDOO EQUIPA_____________________________________\n\tTotal de equipas: %d \n", totalDeEquippes);
 	    fflush(stdin);
   
	
		int codigo=0;	
		do{	
			if(codigo != 0){
				system("cls");
				printf("\r\r\tO ID %d, ja existe tente com um outro! ou digite 0 (zero) para sair!", codigo);
				scanf("%d", &codigo);
				if(codigo==0) menuPrincipal();
			}
			system("cls");
			printf("n\t\tIntroduza o id para nova equipe ID *: ");
			scanf("%d", &codigo);
			
		}while(verficacao(equipa.id, totalDeEquippes, vetIdEquipas)=='0');
			
			
 	 	 	 equipa.id = codigo;
	
			  FILE * arquivo;
			  arquivo = abrirAquivo('a', "pJogador/equipas.txt");
			  
			
			
			  printf("\n\t\tNome *: ");
			  scanf("%s", &equipa.nome);
			  setbuf(stdin, NULL);
			
			
			  fprintf(arquivo,"%s %i\n" ,equipa.nome, equipa.id);
			  system("cls");
			  printf("\n\t\t\tEquipe Criada com sucesso! \n\tNome da Equipa: %s \n\tCogigo: %i\n", equipa.nome, equipa.id);
			  fecharArquivo(arquivo);
			  listarEquipas(0);
	

	//	printf("\nA equipa com esse Id ja existe!\nTente um outro ID!\n\n");
					  
	}



void operarEquipa();
int messagem();
char opcoesDaEquipa(struct tp_equipa equipa);

void listarEquipas(int a){


    printf("\n\n\tLista de equipes\nNomes:\n");
    FILE *arquivo;
    
    arquivo = abrirAquivo('l', "pJogador/equipas.txt");
		int i= 0;
        while(!feof(arquivo)){

        fscanf(arquivo, "%s %d\n", &equipa.nome, &equipa.id);
        printf("%d %s\n" , equipa.id, equipa.nome);
        vetIdEquipas[i] = equipa.id;
        i++;
        }

    fecharArquivo(arquivo);
    totalDeEquippes = i;
    printf("Total de equipas: %d", totalDeEquippes);
 	
	if(a ==1){
	   	operarEquipa(messagem());
	}
	


}



void operarEquipa(){
 	 
 	 FILE *arquivo;
    int i=0;
    arquivo = abrirAquivo('l', "pJogador/equipas.txt");

        while(!feof(arquivo)){

        fscanf(arquivo, "%s %d\n", &equipa.nome, &equipa.id);
        if(idEquipaPerferido==equipa.id){
	         
			printf("\n\tDados da equipe seleciondada! \n\t\tID : %d \n\t\tNome: %s\n" , equipa.id, equipa.nome);
	        fecharArquivo(arquivo);
	  	 	 mostrarDaequipa(opcoesDaEquipa(equipa));
	  	 	 break;
	        }
		}
	fecharArquivo(arquivo);
	 			
}
int messagem(){
	printf("\n\tEntre com id que equipa que deseja efectuar operacao: ");
	return scanf("%d", &idEquipaPerferido);
}
char opcoesDaEquipa(struct tp_equipa equipa){
	system("cls");
	printf("\n\n Que operacoo deseja fazer com equipa %s \n", equipa.nome);
	printf("\n__________________Opcoes_________________");
	printf("\n\t1.Criar um novo jogador. \n\t2.Listar jogadores da equipe \n\t3.Ecluir o terceiro com mais golos;\n\n\t\tEntre com a pocao: ");
	setbuf(stdin, NULL);
	return getchar();
}
void mostrarDaequipa(char opcao){
	system("cls");
	switch(opcao){
		
		case '1':
				criarJogador(jogador);
			break;
			  
		
		case '2':
				listarJogador(jogador);
			break;		
	}

}

/*__________________incio____MANIPUCAO DE ARQUIVOS__________________*/


  FILE* abrirAquivo(char modo, char caminho[30]){
         FILE *arquivo;
          switch(modo){
        case 'a':
                arquivo = fopen(caminho, "a");
            break;
        case 'l':
                arquivo = fopen(caminho, "rt");
            break;
        case 'g':
                arquivo = fopen(caminho, "wt");
            break;

          }

        if(arquivo ==NULL){
            system("cls");
            printf("\nNenhum jogador registado ainda!\nOcorreu falha com abertura do arquivo!");
            exit(0);
        }

    return arquivo;
}

 void fecharArquivo(FILE *arquivo){
        fclose(arquivo);
 }


/*________________________fim__MANIPUCAO DE ARQUIVOS__________________*/



