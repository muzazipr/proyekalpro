#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Char_Race.h"

void tutorial();
char return_val;
void menuakhir(char user,char topuser,char car,char topcar,int score,int topscore);
void setcolor(int ForgC);
int main()
{
 int menu, score, difficulty, diff, topscore;	
 char car, user[100], topuser[100], topcar;
 /****LOAD TOP FILE *******/
 	FILE *fptr;

    if ((fptr = fopen("topscore.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1); }
    fscanf(fptr,"%d", &topscore);
    
        if ((fptr = fopen("car.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1); }
    fscanf(fptr,"%c", &topcar);
    
	    if ((fptr = fopen("user.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1); }   
    fscanf(fptr,"%s", &topuser);
	    
    fclose(fptr);
/********************************/
 
	system("CLS");
    printf("\t==========================================\n");
    setcolor(12);
    printf("\t   Welcome to Character Race 3000 Ultra\n");
    setcolor(15);
    printf("\t==========================================\n\n");
    
	tutorial();
	
    printf("\tPlease insert your Username  : ");
    scanf("%s", &user);
	
	
    printf("\n\tPlease insert your Character : ");
    scanf(" %c", &car);
	
    score = race(car);
    
	system("CLS");
	setcolor(12);
    printf("\n\tYou have crashed %s!\n", user);
	setcolor(15);
    printf("\n\tYour Score is : %d\n\n", score);
    
    
 /**********Check High Score**********/
 	if(score>topscore){    
	FILE *fptr;
    fptr = fopen("C:\\Users\\Ahli Irfan\\Desktop\\Proyek Akhir\\topscore.txt","w");
    fprintf(fptr,"%d",score);
    
    fclose(fptr);
    
    fptr = fopen("C:\\Users\\Ahli Irfan\\Desktop\\Proyek Akhir\\user.txt","w");
    fprintf(fptr,"%s",user);
 
 	fclose(fptr);
 
 	fptr = fopen("C:\\Users\\Ahli Irfan\\Desktop\\Proyek Akhir\\car.txt","w");
    fprintf(fptr,"%c",car);
 
 	fclose(fptr);
    
 	}
/***************************************/   

	printf("\tMenu:\n");
    printf("\t1. Retry\n");
    printf("\t2. High Score\n");
    printf("\t3. Quit\n");

    printf("\n\tPlease select menu : ");
	/*Error handling for menu input*/
	do{
		return_val = getch();
	}while((return_val!=49)&&(return_val!=50)&&(return_val!=51));
	menu=return_val-48;
	return_val=0;
	printf("%d\n",menu);
	delay(10);
	/*								*/
  	switch(menu){
	case 1: main();
			break;
	case 2: clrscr();
			/*Showing the current high score, if the current score is greater than the previously saved score print the current score and loaded it to the file */
			if (score>topscore){
			printf("\n\n\t==================================================================");
			setcolor(12);
			printf("\n\t\tCurrent top score is %d by %s using %c as character\n", score, user, car);
			setcolor(15);
			printf("\t==================================================================\n\n");
			}
   			else  {
   			printf("\n\n\t==================================================================");
			setcolor(12);
			printf("\n\t\tCurrent top score is %d by %s using %c as character\n", topscore, topuser, topcar);
			setcolor(15);
			printf("\t==================================================================\n\n");
			}
			
			printf("\tMenu:\n");
    		printf("\t1. Retry\n");
    		printf("\t2. Quit\n");

    		printf("\n\tPlease select menu : ");
    		do{
			return_val = getch();
			}while((return_val!=49)&&(return_val!=50));
			menu=return_val-48;
			return_val=0;
			printf("%d\n",menu);
			delay(10);
    		if(menu==1){
    			main();
			}
			break;
	case 3: 
			break;
	}

    return 0;
}
/*Function to print the tutorial how to play the game*/
void tutorial(){
	printf("\tUse 'D' & 'A' to move your char around\n");
	printf("\tPress 'D' to move your char to the right\n");
	printf("\tPress 'A' to move your char to the left\n");
	printf("\tYou can insert your own character into the race\n");
	printf("\tYour character must consist only 1 ASCII character\n\n");	
}


