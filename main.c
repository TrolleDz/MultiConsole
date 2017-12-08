#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

main(){
	menu();
}

void altmenu(){
	time_t ora;
	ora = time(NULL);
	system("cls");
	printf("\n\n********** Alternative-Menu **********\n\n");
	printf("[0] per visualizzare questa lista\n");
	printf("[1] per iniziare la funzione timeout\n");
	printf("[2] per iniziare la funzione random\n");
	printf("[3] per la funzione Min-Max\n");
	printf("[4] per la funzione matematica Addizione\n");
	printf("[5] per iniziare la funzione timeout e successivamente random\n");
	printf("[6] per cambiare colore del testo e dello sfondo\n");
	printf("[7] per l'orario attuale\n");
	printf("[8] [ESC] per tornare al menu classico\n");
	printf("[BACKSPACE] per pulire la console\n");
	printf("[i] [I] per info\n");	
	printf("[c] [C] per visualizzare l'orologio live update\n");
	printf("		Premi ESC per uscire dall'orologio live update\n");
	while(1){
		char stringg;
		printf("\n\n[0]   >   ");
		stringg = getch();
		if(stringg == 48 /* 0 */){
			altmenu();
		}
		if(stringg == 49 /* 1 */){
			timeout();
		}
		if(stringg == 50 /* 2 */){
			random();
		}
		if(stringg == 51 /* 3 */){
			minmax();
		}
		if(stringg == 52 /* 4 */){
			addizione();
		}
		if(stringg == 53 /* 5 */){
			tar();
		}
		if(stringg == 54 /* 6 */){
			colors();
		}
		if(stringg == 55 /* 7 */){
			printf("\n			%s	\n",asctime(localtime(&ora)));
		}
		if(stringg == 56 /* 8 */ || stringg == 27 /* ESC */){
			break;
		}
		if(stringg == 8 /* BackSlash */){
			system("cls");
		}
		if(stringg == 73 /* I */ || stringg == 105){
			info();
		}
		if(stringg == 67 /* C */ || stringg == 99 /* c */){
			dynclock();				
		}
	}
}
void dynclock(){
	time_t ora;
	while(1){
		system("cls");
		ora = time(NULL);
		printf("\n\n\n\n\n\n\n");
		printf("\n			%s	\n",asctime(localtime(&ora)));
		char k;
		if(kbhit()){
			k = getch();
    		if(k==27){
    		break;
			}
		}
		Sleep(100);
	}
}

void ttime(){
	system("cls");
	time_t ora;
	ora = time(NULL);
	printf("\n\nData e Ora:	%s",asctime(localtime(&ora)));
}

void info(){
	system("cls");
	printf("\n\n* * * * * * / Developer : Gabriele Gatti \ * * * * * *\n\n");
	printf("* * * * * * / Email : udatgatti@gmail.com \ * * * * * *	\n\n");
}

void minmax(){
	system("cls");
	int nmin;
	int nm;
	int NNum;
	int nG;
	int NNMax;
	
	printf("\nInserisci il numero di valori da inserire: ");
	scanf("%d",&NNMax);
	
	for(nG=0; nG<NNMax; nG++){
		printf("\nDigita il valore: ");
		scanf("%d",&NNum);
		if(nG==0){
			nmin=NNum;
			nm=NNum;
		}
		if(NNum<nmin){
			nmin=NNum;
		}
		if(NNum>nm){
			nm=NNum;
		}
	}
	
	printf("\nValore Minimo: %d",nmin);
	printf("\nValore Massimo: %d\n",nm);
}

void addizione(){
	int COUNT,G,A;
	int I = 0;
	COUNT = 0;
	printf("\n\nInserisci il numero di valori da sommare\n\n   >   ");
	scanf("%d",&G);
	while(I<G){
		printf("\nInserisci il valore numero  %d \n\n   >   ",I+1);
		scanf("%d",&A);
		COUNT += A;
		I++;
	}
	printf("\n   Somma :   %d\n\n",COUNT);
}

void timeout(){
	system("cls");
	system("color EC");
	printf("\nDammi il timeout in secondi:\n     ");
	int a;
	scanf("   %d",&a);
	for( ; a>=0; a--){
		system("cls");
		printf("\n	%d\n",a);
		Sleep(1000);
	}
	system("cls");
	system("color 0F");
}

void colors(){
	system("cls");
	printf("\n0 = Black       8 = Gray\n1 = Blue        9 = Light Blue\n2 = Green       A = Light Green\n3 = Aqua        B = Light Aqua\n4 = Red         C = Light Red\n5 = Purple      D = Light Purple\n6 = Dark Yellow E = Light Yellow\n7 = White       F = Bright White");
	char input[8];
	char color[8];
	printf("\n\nBackGround and Text colors? (without the space) :   ");
	scanf("%s",input);
	sprintf(color,"color %s",input);
	system(color);
}

void random(){
	system("cls");
	int min,max;
	printf("\n\nRandom Min: ");
	scanf("%d",&min);
	printf("\n\nRandom Max: ");
	scanf("%d",&max);
	srand(time(NULL));
	int r = rand() % max + min;
	printf("\n%d\n",r);
}

void tar(){
	char classe[256];
	printf("\n\nIndica la classe: ");
	scanf("%s",classe);
	timeout();
	srand(time(NULL));
	int r = rand() %22 + 1;
	system("cls");
	if(!strcmp(classe,"3BE") || !strcmp(classe,"3be")){
		printf("\n%d   :   ",r);
		if(r==1){
			printf("Beltrami");
		}
		if(r==2){
			printf("Boselli");
		}
		if(r==3){
			printf("Bulgarelli");
		}
		if(r==4){
			printf("Ceroni");
		}
		if(r==5){
			printf("Costa");
		}
		if(r==6){
			printf("D'Arsi");
		}
		if(r==7){
			printf("Dallari");
		}
		if(r==8){
			printf("Faccone");
		}
		if(r==9){
			printf("Fatima");
		}
		if(r==10){
			printf("Fazal");
		}
		if(r==11){
			printf("Gatti");
		}
		if(r==12){
			printf("Lo Monaco");
		}
		if(r==13){
			printf("Lombardo");
		}
		if(r==14){
			printf("Magnani");
		}
		if(r==15){
			printf("Morelli");
		}
		if(r==16){
			printf("Pivetti");
		}
		if(r==17){
			printf("Prandi");
		}
		if(r==18){
			printf("Realdon");
		}
		if(r==19){
			printf("Regonati");
		}
		if(r==20){
			printf("Rossi");
		}
		if(r==21){
			printf("Subazzoli");
		}
		if(r==22){
			printf("Zhang");
		}
		if(r==23){
			printf("Zullo");
		}
	}
	printf("\n");
}

void cls(){
	system("cls");
}

void menu(){
	time_t ora;
	ora = time(NULL);
	system("cls");
	printf("\n\n********** Menu **********\n\n");
	printf("Digita 'menu' per visualizzare questa lista\n");
	printf("Digita 'timeout' per iniziare la funzione timeout\n");
	printf("Digita 'random' per iniziare la funzione random\n");
	printf("Digita 'mm' per la funzione Min-Max\n");
	printf("Digita 'somma' per la funzione matematica Addizione\n");
	printf("Digita 'tar' per iniziare la funzione timeout e successivamente random\n");
	printf("Digita 'color' per cambiare colore del testo e dello sfondo\n");
	printf("Digita 'cls' per pulire la console\n");
	printf("Digita 'info' per info\n");
	printf("Digita 'time' per l'orario attuale\n");
	printf("Digita 'clock' per visualizzare l'orologio live update\n");
	printf("		Premi ESC per uscire dall'orologio live update\n");
	printf("Digita 'altmenu' per visualizzare il menu alternativo\n");
	printf("Digita 'exit' per uscire\n");
	printf("\n****** Scrivi un comando! ******		%s\n\n---=== Digita 'menu' per la lista dei comandi ===---",asctime(localtime(&ora)));
	while(1){
		char string[256];
		printf("\n\n   >   ");
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
		if(!strcmp(string,"tar")){
			tar();
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
		if(!strcmp(string,"mm")){
			minmax();
		}
		if(!strcmp(string,"somma")){
			addizione();
		}
		if(!strcmp(string,"info")){
			info();
		}
		if(!strcmp(string,"ora") || !strcmp(string,"time")){
			ttime();
		}
		if(!strcmp(string,"clock")){
			dynclock();
		}
		if(!strcmp(string,"altmenu")){
			altmenu();
		}
	}
}
