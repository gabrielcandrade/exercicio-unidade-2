#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiaString();
void comparaString();
void concatenaString();
void tamanhoString();
int strlengabriel(char *s);
void strcpygabriel(char *destino, char *origem);
void strcatgabriel(char *destino, char *origem);
int strcmpgabriel(char *string1, char *string2);

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
			comparaString(); //Done
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
	char copia[1024], string[1024];
	
	printf("Digite uma string que irei copia-la: ");
	scanf("%s", &string);
	
	strcpygabriel(copia, string); //Funcionalidade implementada - OK
	
	printf("O nome copiado foi: %s", copia);
}

void comparaString(){
	char nome[100] = "Gabriel\0", resposta[100]="Gabriel\0";
	int comparativo;
	
	printf("Digite o nome do desenvolvedor: ");
	scanf("%s", &resposta);
	
	comparativo = strcmpgabriel(nome, resposta); //Funcionalidade implementada - OK
	
	if (comparativo == 0){
		printf("Correto!");
	}else{
		printf("Incorreto!");
	}
}

void concatenaString(){
	char string1[100], string2[100];
	
	printf("Digita o seu nome: ");
	scanf("%s", &string1);\
	printf("Digita o seu sobrenome: ");
	scanf("%s", &string2);
	
	strcatgabriel(string1, string2); //Funcionalidade implementada - OK
}

void tamanhoString(){
	char nome[100];
	int tamanho;
	
	printf("Digita o seu nome e direi quantos caracteres ele possui: ");
	scanf("%s", &nome);
	
	tamanho = strlengabriel(nome); //Funcionalidade implementada - OK
	
	printf("\nO seu nome possui %d caracteres", tamanho);
}

int strlengabriel(char *s){
	int tam;
	
	//Percorre o char e quando encontrar o \0 ele para de contar.
	for(tam = 0; *s != '\0'; s++){
		tam++;  //Auto-incrementa o valor de tamanho a medida que passa por cada caracter.
	}
	return tam;
}

void strcpygabriel(char *destino, char *origem){
	int i = 0;
	
	// Enquanto o valor da origem couber no destino, ele vai adicionando char por char
	while((destino[i] = origem[i]) != '\0'){
		i++; //Auto-incrementa o valor de i para percorrer o tamanho do char.
	}
}

void strcatgabriel(char *destino, char *origem){
	char aux[1024];
	int i, j, k, tam = 0;
	
	// Percorre toda a string primaria e depois de chegar ao fim, ele pega o tamanho da string e continua na proxima a partir da posicao desta.
	for (i = 0 ; *destino != '\0' ; destino++){
		aux[i] = *destino;
		i++;
		tam++;
	}
	
	aux[tam+1] = ' ';

	// Percorre a nova string a partir do tamanho da anterior para poder incrementar na variavel aux.
	for (j = tam; *origem != '\0' ; origem++){
		aux[j] = *origem;
		j++;
		tam++;
	}
	
	// Percorre toda a variavel aux e imprime na tela todos os caracteres simulando uma concatenacao.
	for (k = 0 ; aux[k] != '\0' ; k++){
		printf("%c", aux[k]);
	}
	
}

int strcmpgabriel(char *string1, char *string2){
	int i, resultado;
	
	// Percorre as duas strings ate chegar em algum \0, caso ele identifique algum caractere diferente do outro, ja retorna 1, caso contrario, for igual, ele retorna 0;
	for (i = 0 ; string1[i] != '\0' || string2[i] != '\0' ; i++){
		if (string1[i] != string2[i]){
			return 1;
		}else{
			return 0;
		}
	}
}