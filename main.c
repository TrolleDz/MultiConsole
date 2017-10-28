#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

main(){
	menu();
}

void timeout(){
	system("color EC");
	printf("\nDammi il timeout in secondi:\n     ");
	int a,b;
	scanf("%d",&a);
	for(b=1; b<=a; b++){
		Sleep(1000);
		if(b==1){
			printf("%d",b);
		}else{
			printf("-%d",b);
		}
	}
	printf("\n");
	system("color 0F");
}

void colors(){
	printf("\n0 = Black       8 = Gray\n1 = Blue        9 = Light Blue\n2 = Green       A = Light Green\n3 = Aqua        B = Light Aqua\n4 = Red         C = Light Red\n5 = Purple      D = Light Purple\n6 = Dark Yellow E = Light Yellow\n7 = White       F = Bright White");
	char input[8];
	char color[8];
	printf("\n\nBackGround and Text colors? (without the space) :   ");
	scanf("%s",input);
	sprintf(color,"color %s",input);
	system(color);
}

void random(){
	int min,max;
	printf("\n\nRandom Min: ");
	scanf("%d",&min);
	printf("\n\nRandom Max: ");
	scanf("%d",&max);
	srand(time(NULL));
	int r = rand() % max + min;
	printf("\n%d\n",r);
}

void cls(){
	system("cls");
}

void menu(){
	printf("\n\n********** Menu **********\n\n");
	printf("Digita 'menu' per visualizzare questa lista\n");
	printf("Digita 'timeout' per iniziare la funzione timeout\n");
	printf("Digita 'random' per iniziare la funzione random\n");
	printf("Digita 'color' per cambiare colore del testo e dello sfondo\n");
	printf("Digita 'cls' per pulire la console\n");
	printf("Digita 'exit' per uscire\n");
	while(1){
		char string[256];
		printf("\n****** Scrivi un comando! ******\n\n---=== Digita 'menu' per la lista dei comandi ===---\n\n   >   ");
		scanf("%s",string);
		if(!strcmp(string,"menu") || !strcmp(string,"help")){
			menu();
		}
		if(!strcmp(string,"timeout") || !strcmp(string,"countdown")){
			timeout();
		}
		if(!strcmp(string,"random") || !strcmp(string,"rand")){
			random();
		}
		if(!strcmp(string,"exit") || !strcmp(string,"quit")){
			system("exit");
			break;
		}
		if(!strcmp(string,"color")){
			colors();
		}
		if(!strcmp(string,"cls")){
			cls();
		}
	}
}
