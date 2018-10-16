#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiaString();
void comparaString();
void concatenaString();
void tamanhoString();

int main()
{
	int decisao = 0;
	
	menu();
	
	printf("\nEscolha uma opcao de 0 a 4: ");
	scanf("%d", &decisao);
	system("cls");
	
	switch(decisao){
		case 1: {
			copiaString(); //Done
			break;
		}
		case 2: {
			comparaString(); //Incorrect
			break;
		}
		case 3: {
			concatenaString(); //Done
			break;
		}
		case 4: {
			tamanhoString(); //Done
			break;
		}
		case 0: {
			printf("Mas ja? Vai agora nao. :)");
			break;
		}
		default: {
			printf("Codigo invalido");
			break;
		}
	}
	return 0;
}

void menu(){
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#         Menu de funcoes pratica         #\n");
	printf("#                                         #\n");
	printf("#   1 - strcpy();                         #\n");
	printf("#   2 - strcmp();                         #\n");
	printf("#   3 - strcat();                         #\n");
	printf("#   4 - strlen();                         #\n");
	printf("#   0 - Sair;                             #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}

void copiaString(){
	char copia[100], string[100];
	
	printf("Digite uma string que irei copia-la: ");
	scanf("%s", &string);
	
	strcpy(copia, string);
	
	printf("O nome copiado foi: %s", copia);
}

void comparaString(){
	char nome[100] = "Gabriel", resposta[100];
	int comparativo;
	
	printf("Digite o nome do desenvolvedor: ");
	scanf("%s", &resposta);
	
	comparativo = strcmp(nome, resposta); //Porque da dando errado aqui?
	
	printf("%d", comparativo);
	
	if (comparativo == 1){
		printf("Correto!");
	}else{
		printf("Incorreto!");
	}
}

void concatenaString(){
	char string1[100], string2[100];
	
	printf("Digita o seu nome: ");
	scanf("%s", &string1);
	printf("Digita o seu sobrenome: ");
	scanf("%s", &string2);
	
	strcat(string1, string2);
	
	printf("A uniao das strings deu: \n%s", string1);
}

void tamanhoString(){
	char nome[100];
	int tamanho;
	
	printf("Digita o seu nome e direi quantos caracteres ele possui: ");
	scanf("%s", &nome);
	
	tamanho = strlen(nome);
	
	printf("\nO seu nome possui %d caracteres", tamanho);
}