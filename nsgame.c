#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void logoart();
void loading();
void baseart();
void techart();
void motd();

int aclickers;
int acliv;
int bacCost;
int uacCost;
float cpsac;
float hcpsac;
float dcpsac;
float hdcpsac;
int Booster;
int Liv;
int inc;
float Delay;
float hdelay;
float count;
int cboost;
int dboost;
int fflag;
int cCost;
int dCost;
int timeflag; //Countdown started
int bflag; //Not Enough Boosters
int dflag; //Delay Limit
int mflag; //Not Enough Money
int iflag; //Info Flag
char s;
float pt;
int dinc;

main(){
	reset: loading();
	
	//AutoClickers
	aclickers = 0;
	acliv = 1;
	bacCost = 1000;
	
	Booster = 2;	
	Liv = 1;
	inc = 1;
	Delay = 200;
	hdelay;
	count = 0.00;
	
	cboost = 0; //Clicker Boost enabled when 1
	dboost = 0; //Delay Boost enabled when 1
	
	fflag = 0; //Booster Level Reached
	

	timeflag = 0; //Countdown started
	bflag = 0; //Not Enough Boosters
	dflag = 0; //Delay Limit
	mflag = 0; //Not Enough Money
	iflag = 0; //Info Flag
	s;
	pt = 20;
	
	printf("\n\n* * *	Loading Data	* * *");
	FILE* p;
	p = fopen("data.txt","r");
	fscanf(p,"%d // Level\n",&Liv);
	fscanf(p,"%f // Delay\n",&Delay);
	fscanf(p,"%f // Coins\n",&pt);
	fscanf(p,"%d // Booster\n",&Booster);
	fscanf(p,"%f // Count\n",&count);
	fscanf(p,"%d // cboost\n",&cboost);
	fscanf(p,"%d // dboost\n",&dboost);
	fscanf(p,"%d // acliv\n",&acliv);
	fscanf(p,"%d // aclickers\n",&aclickers);
	fclose(p);
	Sleep(1000);
	
	first: while(1){
		
		if(Liv==1){
			inc = 1;
		}
		if(Liv!=1){
			inc = Liv * 2;
		}
		
		//Auto Clickers
		cpsac = aclickers * acliv;
		hcpsac = cpsac / 2;
		dcpsac = cpsac * (Delay / 1000);
		hdcpsac = dcpsac / 2;
		uacCost = (acliv*50) * acliv + (acliv*5);
		
		hdelay = Delay / 2;
		
		cCost = (Liv*53) * Liv - (Liv*5);
		dCost = (1350 - Delay) + ((200 - Delay) * 2);
		system("cls");
		printf("\n\nCoins:	%.0f			|	Boosters: %d",pt,Booster);
		printf("\nCoins Per Second: %.0f	|	Booster Time: %.2f / 60 seconds",cpsac,count);
		printf("\nAutoClickers:	%d",aclickers);
		printf("\nAutoClickers Level: %d",acliv);
		printf("\nRequired for Clicker Upgrade:	%d",cCost);
		printf("\nRequired for Delay Decrease:	%d",dCost);
		printf("\nRequired for new AC: %d",bacCost);
		printf("\nRequired for ACs Upgrade: %d",uacCost);
		
		if(cboost==1){
			dinc = inc * 2;
			printf("\n\nClicker Increase:	%d",dinc);
		}
		if(cboost==0){
			printf("\n\nClicker Increase:	%d",inc);
		}
		if(dboost==1){
			printf("\n\nClicker Delay:		%.0f",hdelay);
		}
		if(dboost==0){
			printf("\n\nClicker Delay:		%.0f",Delay);
		}
		if(Liv<=50){
			baseart();
		}
		if(Liv>50){
			techart();
		}
		if(fflag==1){
			printf("\n\nYou got a Booster!!");
			fflag = 0;
		}
		if(iflag==1){
			printf("\n\nDeveloper Email Address: udatigatti@gmail.com");
		}
		if(mflag==1){
			printf("\n\nYou Don't Have Enough Coins!!");
		}
		if(dflag==1){
			printf("\n\nAlready at Max Level!");
		}
		if(bflag==1){
			printf("\n\nYou need more Boosters!");
		}
		
		if(!(kbhit())){
			if(cboost==1 || dboost==1){
				count += (hdelay / 1000);
				Sleep(hdelay);
				goto first;
			}
			else{
				pt += hcpsac;
				Sleep(500);
				goto first;
			}
			if(count>=60){
				dboost = 0;
				cboost = 0;
				timeflag = 0;
				count = 0.00;
			}
		}
		
		s = getch();
		
		//Easter Egg
		if(s==101 || s==69) /* E */ {
			system("cls");
			printf("\n\n		D");
			Sleep(5);
			printf("i");
			Sleep(5);
			printf("n");
			Sleep(5);
			printf("k");
			Sleep(5);
			printf("l");
			Sleep(5);
			printf("e");
			Sleep(5);
			printf("b");
			Sleep(5);
			printf("e");
			Sleep(5);
			printf("r");
			Sleep(5);
			printf("g");
			Sleep(5);
			printf("!");
			Sleep(500);
		}
		
		if(s==32) /* SpaceBar */{
			if(cboost==1){
				pt += (2 * inc);
			}
			if(cboost==0){
				pt += inc;
			}
			if(timeflag==1){
				if(dboost==1){
					count += (hdelay / 1000);
				}
				if(dboost==0){
					count += (Delay / 1000);
				}
			}
			if(dboost==1){
				pt += hdcpsac;
				Sleep(hdelay);
			}
			if(dboost==0){
				pt += dcpsac;
				Sleep(Delay);
			}
			mflag = 0; 
			dflag = 0;
			bflag = 0;
			iflag = 0;
			if(count>=60){
				dboost = 0;
				cboost = 0;
				timeflag = 0;
				count = 0.00;
			}
		}
		
		//BOOSTERS
		if(s==98 || s==66) /* B */ {
			printf("\n\n\nWich Booster do you want to use?");
			printf("\n\n[C] Double Clicker | Actual Increase: %d",inc);
			printf("\n[D] Half Delay | Actual Delay: %d", Delay);
			s = getch();
			if(s==99 || s==67) /* C */ {
				system("cls");
				printf("\n\n\nDo you want to double your Clicker for 60sec?");
				printf("\nYou will use a Booster");
				printf("\n\n[Y] - Yes");
				printf("\n[N] - No");
				s = getch();
				if(s==121 || s==89) /* Y */ {
					if(Booster<1){
						bflag = 1;
					}
					if(Booster>=1){
						if(bflag!=1){
							cboost = 1;
							timeflag = 1;
							Booster -= 1;
							count = Delay / 1000;
						}
					}
				}
			}
			if(s==100 || s==68) /* D */ {
				system("cls");
				printf("\n\n\nDo you want to halve the Delay for 60sec?");
				printf("\nYou will use a Booster");
				printf("\n\n[Y] - Yes");
				printf("\n[N] - No");
				s = getch();
				if(s==121 || s==89) /* Y */ {
					if(Booster<1){
						bflag = 1;
					}
					if(Booster>=1){
						if(bflag!=1){
							if(dflag!=1){
								dboost = 1;
								timeflag = 1;
								Booster -= 1;
								count = Delay / 1000;
							}
						}
					}			
				}
			}
		}
		
		//INFO
		if(s==105 || s==73) /* I */ {
			iflag = 1;
		}
		
		//UPGRADE MENU
		if(s==109 || s==77) /* Menu */{
			printf("\n\n\nWhat do you want to Upgrade?");
			printf("\n\n[C] SpaceBar Clicker | Actual Level: %d",Liv);
			printf("\n[D] Less Delay, More Coins! | Actual Delay: %d", Delay);
			printf("\n[A] AutoClickers Menu");
			s = getch();
			if(s==97 || s==65) /* Auto clicker */{
				system("cls");
				printf("\n\n\nWhat do you want to do?");
				printf("\n\n[B] Buy one AutoClicker | Your AutoClickers: %d",aclickers);
				printf("\n[U] Upgrade your AutoClickers	Level | Actual ACs Level: %d",acliv);
				s = getch();
				if(s==98 || s==66) /* Buy autoclickers */{
					printf("\n\n\nDo you want to buy an AutoClicker? | Cost: %d",bacCost);
					printf("\n\n[Y] - Yes");
					printf("\n[N] - No");
					s = getch();
					if(s==121 || s==89) /* Yes */{
						if(pt<bacCost){
							mflag = 1;
						}
						if(pt>=bacCost){
							if(mflag!=1){
								aclickers++;
								pt -= bacCost;			
								if(aclickers==50){
									fflag = 1;
								}
							}					
						}
					}
				}
				if(s==117 || s==85) /* Upgrade autoclickers */{
					printf("\n\n\nDo you want to upgrade your AutoClickers?		Cost: %d",uacCost);
					printf("\n\n[Y] - Yes");
					printf("\n[N] - No");
					s = getch();
					if(s==121 || s==89) /* Yes */{
						if(pt<uacCost){
							mflag = 1;
						}
						if(pt>=uacCost){
							if(mflag!=1){
								acliv++;
								pt -= uacCost;			
								if(acliv==50){
									fflag = 1;
								}
							}					
						}
					}	
				}
				else{
					goto first;
				}
			}
			if(s==99 || s==67) /* Clicker */{
				system("cls");
				printf("\n\n\nDo you want to upgrade your SpaceBar Clicker?		Cost: %d",cCost);
				printf("\n\n[Y] - Yes");
				printf("\n[N] - No");
				s = getch();
				if(s==121 || s==89) /* Yes */{
					if(pt<cCost){
						mflag = 1;
					}
					if(pt>=cCost){
						if(mflag!=1){
							Liv++;
							pt -= cCost;
							if(Liv==50){
								fflag = 1;
							}
						}					
					}
					if(fflag==1){
						Booster++;
					}
				}
				else{
					goto first;
				}
			}
			if(s==100 || s==68) /* Delay */{
				system("cls");
				printf("\n\n\nDo you want to decrease the Delay??		Cost: %d",dCost);
				printf("\n\n[Y] - Yes");
				printf("\n[N] - No");
				s = getch();
				if(s==121 || s==89) /* Yes */{
					if(pt<dCost){
						mflag = 1;
					}
					if(pt>=dCost){
						if(Delay<=50){
							dflag = 1;
						}
						if(dflag!=1){
							if(Delay>10){
								pt -= dCost;
								Delay -= 10;
							}
						}			
					}
				}
				else{
					goto first;
				}
			}
		}
		//EXIT
		if(s==27) /* ESC */{
			printf("\n\n* * *	Saving your Data	* * *");
			FILE* p;
			p = fopen("data.txt","w");
			fprintf(p,"%d // Level\n", Liv);
			fprintf(p,"%f // Delay\n", Delay);
			fprintf(p,"%f // Coins\n", pt);
			fprintf(p,"%d // Booster\n", Booster);
			fprintf(p,"%f // Count\n", count);
			fprintf(p,"%d // cboost\n", cboost);
			fprintf(p,"%d // dboost\n", dboost);
			fprintf(p,"%d // acliv\n", acliv);
			fprintf(p,"%d // aclickers\n", aclickers);
			fclose(p);
			Sleep(1000);
			return 0;
			exit(-1);
		}
		//RESET //WARNING
		if(s==114 || s==82) /* Reset */{
			system("cls");
			printf("\n\n\n\n		Are you sure to reset the game?!");
			printf("\n\n[Y] - Yes");
			printf("\n[N] - No");
			s = getch();if(s==121 || s==89) /* Yes */{
				system("cls");
				printf("\n\n\n		* * * * * RESETTING DATA * * * * *");
				Sleep(2000);
				
				aclickers = 0;
				acliv = 1;
				bacCost = 1000;
				uacCost;
				cpsac;
				hcpsac;
				dcpsac;
				hdcpsac;	
				Booster = 2;	
				Liv = 1;
				inc = 1;
				Delay = 200;
				hdelay;
				count = 0.00;
	
				cboost = 0; //Clicker Boost enabled when 1
				dboost = 0; //Delay Boost enabled when 1
	
				fflag = 0; //Booster Level Reached
	
				cCost;
				dCost;
				timeflag = 0; //Countdown started
				bflag = 0; //Not Enough Boosters
				dflag = 0; //Delay Limit
				mflag = 0; //Not Enough Money
				iflag = 0; //Info Flag
				s;
				pt = 20;
				
				FILE* p;
				p = fopen("data.txt","w");
				fprintf(p,"%d // Level\n", Liv);
				fprintf(p,"%f // Delay\n", Delay);
				fprintf(p,"%f // Coins\n", pt);
				fprintf(p,"%d // Booster\n", Booster);
				fprintf(p,"%f // Count\n", count);
				fprintf(p,"%d // cboost\n", cboost);
				fprintf(p,"%d // dboost\n", dboost);
				fprintf(p,"%d // acliv\n", acliv);
				fprintf(p,"%d // aclickers\n", aclickers);
				fclose(p);
				
				goto reset;
			}
		}
	}
}

void logoart(){
	system("cls");
	printf("\n\n\n");
	printf("		 __        _   ___________   ___________ 	\n");
	printf("		¦¦¦¦      ¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦	\n");
	printf("		¦¦¦¦¦     ¦¦¦ ¦¦¦---------  ¦¦¦--------- 	\n");
	printf("		¦¦¦¦¦¦    ¦¦¦ ¦¦¦           ¦¦¦          	\n");
	printf("		¦¦¦ ¦¦¦   ¦¦¦ ¦¦¦_________  ¦¦¦  _______ 	\n");
	printf("		¦¦¦  ¦¦¦  ¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦  ¦¦¦¦¦¦¦¦	\n");
	printf("		¦¦¦   ¦¦¦ ¦¦¦  ---------¦¦¦ ¦¦¦  -----¦¦¦	\n");
	printf("		¦¦¦    ¦¦¦¦¦¦           ¦¦¦ ¦¦¦       ¦¦¦	\n");
	printf("		¦¦¦     ¦¦¦¦¦  _________¦¦¦ ¦¦¦_______¦¦¦	\n");
	printf("		¦¦¦      ¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦	\n");
	printf("		 -        --   -----------   ----------- 	\n");
	printf("\n\n			Non Sense Game\n\n");
}

void loading(){
	logoart();
	motd();
	Sleep(2000);
	system("cls");
	
	logoart();
	printf("		¦¦¦¦----------------------------------\n");
	Sleep(500);
	
	system("cls");
	
	logoart();
	printf("		¦¦¦¦¦¦¦¦¦¦¦¦--------------------------\n");
	Sleep(500);
	
	system("cls");
	
	logoart();
	printf("		¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦------------------\n");
	Sleep(500);
	
	system("cls");
	
	logoart();
	printf("		¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦----------\n");
	Sleep(500);
	
	system("cls");
	
	logoart();
	printf("		¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦--\n");
	Sleep(1000);
} 

void baseart(){
		printf("\n\n");
    	printf("               ,---------------------------,		\n");
		printf("               |  /---------------------\\  |		\n");
		printf("               | |  Press M for Upgrades | |		\n");
		printf("               | |                       | |		\n");
		printf("               | |  Press B for Boosters | |		\n");
		printf("               | |                       | |		\n");
		printf("               | |                       | |		\n");
		printf("               | |    Hold the SpaceBar  | |		\n");
		printf("               | |      in your kb       | |		\n");
		printf("               | |                       | |		\n");
		printf("               | |                       | |		\n");
		printf("               | |  Press ESC to Save    | |		\n");
		printf("               | |        and Quit       | |		\n");
		printf("               |  \\_____________________/  |		\n");
		printf("               |___________________________|		\n");
		printf("            ,---- \\_____   []   _______ / ------,		\n");
		printf("           /         //______________\\\         /|		\n");
		printf("          /____________________________________/ |___		\n");
		printf("         |                                    |  |   )		\n");
		printf("         |   Press I for Info                 |  |   (		\n");
		printf("         |  _ _ _                 [-------]   |  /    )		\n");
		printf("         |  o o o  R for Reset    [-------]   | /   _(_		\n");
		printf("         |__________________________________  |/   / //		\n");
		printf("       /-------------------------------------/|   ( )/		\n");
		printf("      /-/-/-/E/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//		\n");
		printf("     /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//		\n");
		printf("    /-/-/-/-/-/-/     HERE    /-/-/-/-/-/-//		\n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		\n");
}

void techart(){
		printf("\n\n");
    	printf("        ,------------------------------------,		\n");
		printf("       | / ------------------------------- \\ ||		\n");
		printf("       | |     Press M for Upgrades        | ||		\n");
		printf("       | |                                 | ||		\n");
		printf("       | |                                 | ||		\n");
		printf("       | |       Press B for Boosters      | ||		\n");
		printf("       | |                                 | ||		\n");
		printf("       | |          R for Reset            | ||		\n");
		printf("       | |                                 | ||		\n");
		printf("       | |       Hold the SpaceBar         | ||		\n");
		printf("       | |          in your kb             | ||		\n");
		printf("       | |                                 | ||		\n");
		printf("       | |    Press ESC to Save and Quit   | ||		\n");
		printf("       | |_________________________________| ||		\n");
		printf("       |_____________________________________||		\n");
		printf("      / ------------------------------------- /		\n");
		printf("     /o/-/-/E/-/-/-/-/-/-/-/-/-/-/-/-/-/-/- //		\n");
		printf("    /-/-/-/-/-/_/_/_/_/_/_/-/-/-/-/-/-/-/- //		\n");
		printf("   /-/-/-/-/-/_________/-/-/-/-/-/-/-/-/- //		\n");
		printf("  /         /         / Press I for Info //			\n");
		printf(" /         /_________/                  //			\n");
		printf("/______________________________________//			\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~			\n");
}

void motd(){
	srand(time(NULL));
	int r = rand() % 7 + 1;
	if(r==1){
		printf("\n\nThis game was developed by an 17 years old guy!");
	}
	if(r==2){
		printf("\n\nPlaying this game makes you a Genius!");
	}
	if(r==3){
		printf("\n\nPress I to show the developer email address!");
	}
	if(r==4){
		printf("\n\nI don't know how did you find this game xD");
	}
	if(r==5){
		printf("\n\nWhoops, I forgot to add more MOTDs!");
	}
	if(r==6){
		printf("\n\nEnjoy the Game!");
	}
	if(r==7){
		printf("\n\nGood morning! Or it's evening? IDK LOL");
	}
}
