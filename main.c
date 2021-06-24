#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "pJogador/hJogador.h"


int main()
{			
	//Caregando os dados para memoria
	listarEquipas(0);
	listarJogador();
	system("cls");
	
		
	//Inicio da aplicacao
	  
	while(1){
		  system("cls");
		  setbuf(stdin, NULL);
		  switch(menuPrincipal()){
			  
			  case '1':
				  system("cls");
					  criarEquipa();
					  system("pause");	  	
			  	break;
			  
			  case '2':
			  	system("cls");
			  		listarEquipas(1);
			  	system("pause");
			  	break;
			  
			  case '3':
				  	system("cls");
			  		ajuda();
			  	   	system("pause");			  	
			  	break;
			  
			  default: 
			  	   printf("\n\nOpcao invalida tente novamente!\n\n");
	  	   	   	   system("pause");
		  }
		  
	  
	}
	
    system("pause");
    return 0;
}