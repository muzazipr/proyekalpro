#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char square[15];
char state[15];
int lasttime=0,item,invicibility=0,boostmode=0,clean,printtime=0;
void setcolor(int ForgC);
int checklose(int a);
void board(int a,int b,int c);
void clrscr();
void delay(int second);
int race(char character);
time_t t;

int race(char character)
{
    clrscr();
    for(clean=0;clean<=15;clean++){
    	square[clean]=' ';
    	state[clean]=' ';
	}
	int diff= 4, position=14,i,obs,score=0,skin;
    char mark, choice;
    srand(((unsigned)time(&t)));
	setcolor(4);
	printf("\n\n\tReady\t\n\n");
	setcolor(14);
    delay(20);
    printf("\tSet\t\n\n");
    setcolor(2);
    delay(20);
    printf("\tGo\t");
    setcolor(15);
    delay(20);
    clrscr();
    
	do {
		/*	State from the game updated every time delay, it varies with game difficulties
			state array represent the board state while square array represent the board 
			graphical coordinate
		*/
		if((clock()-printtime)>=(diff*50)){
		score++;
        state[13]=state[10];
        state[10]=state[7];
        state[7]=state[4];
        state[4]=state[1];

        state[14]=state[11];
        state[11]=state[8];
        state[8]=state[5];
        state[5]=state[2];

        state[15]=state[12];
        state[12]=state[9];
        state[9]=state[6];
        state[6]=state[3];

        state[obs]=' ';
		state[item]=' ';
        

        square[13]=square[10];
        square[10]=square[7];
        square[7]=square[4];
        square[4]=square[1];

        square[14]=square[11];
        square[11]=square[8];
        square[8]=square[5];
        square[5]=square[2];

        square[15]=square[12];
        square[12]=square[9];
        square[9]=square[6];
        square[6]=square[3];
        
		square[obs]=' ';
		square[item]=' ';
		/*	Obstacle state show or loaded into the array for every even score with random position
			Item state loaded with same fashion but with probability 5%
		*/
        if((score%2)==0){
        obs=(rand()%3)+1;
        	if((rand()%100+1)<=5){
        		item=(rand()%3)+1;	
        	}
        }
        else{
        obs=0;
        }
		/*	There is two diffrent item boost and inviciblity both with the probability 15%  and 10% respectively
		*/
		if(rand()%100+1<=10){
			square[item]='I';
			state[item]='3';
		}
		else if((rand()%100+1>10)&&((rand()%100+1<=25))){
			square[item]='B';
			state[item]='4';
		}
		
		square[obs]='O';
        /*	While invicibility mode is active the obstacle state won't be counted or in function it's changed to 0 */
        if(invicibility==1){
        state[obs]=' ';
        	if((clock()-lasttime)>=5000){
        		invicibility=0;
			}
		}
		else if(invicibility==0){
			state[obs]='1';
		}
		
        /*	While boost mode is active the diff multiplier for game delay increased and increase the game speed */        
        if(boostmode==1){
        	diff=1;
        	if((clock()-lasttime)>=5000){
        		boostmode=0;
        		diff=4;
			}
		}
		printtime=clock();
		}

		if(kbhit()){
            choice=getch();
		}
		else{
            choice=0;
		}
        if((choice == 'a')&&(13<position)){
            position--;
            square[position+1]=' ';
        }
        else if ((choice == 'd' )&&(position<15)){
            position++;
            square[position-1]=' ';
        }
        
    	square[position]=character;
		board(score,invicibility,boostmode);
		i = checklose(position);
		clrscr();

    }while (i == 0);
    board(score,invicibility,boostmode);
    delay(40);
    return score;
}

/***********************************************
		FUNCTION TO RETURN GAME STATUS
			1 FOR GAME IS OVER
		-1 FOR GAME IS IN PROGRESS
		This function also return the status 
		wether an item obtained or not
 **********************************************/

int checklose(int a)
{
 if(state[a]=='1'){
 square[a]='#';
 return 1;
 }
 else if((state[a]=='3')&&(invicibility==0)){
 	invicibility=1;
 	lasttime=clock();
 }
  else if((state[a]=='4')&&(boostmode==0)){
 	boostmode=1;
 	lasttime=clock();
 }
 return 0;

}


/*******************************************************************
			FUNCTION TO DRAW ROAD WITH CHAR AND OBSTACLE
	This function just prtnting the graph with array as coordinate
 ********************************************************************/


void board(int a,int b,int c)
{
    printf("	=====================");
	setcolor(12);
	printf("\t\n		Go Car\n");
	setcolor(15);
	printf("	=====================\n\n");

    printf("\t|      |     |      |\n");
    printf("\t|  %c   |  %c  |  %c   |\n", square[1], square[2], square[3]);
    printf("\t|      |     |      |\n");
    printf("\t|  %c   |  %c  |  %c   |\n", square[4], square[5], square[6]);
    printf("\t|      |     |      |\n");
    printf("\t|  %c   |  %c  |  %c   |\n", square[7], square[8], square[9]);
    printf("\t|      |     |      |\n");
    printf("\t|  %c   |  %c  |  %c   |\n", square[10], square[11], square[12]);
    printf("\t|      |     |      |\n");
    printf("\t|  %c   |  %c  |  %c   |\n", square[13], square[14], square[15]);
    printf("\t|      |     |      |\n\n");
    printf("	=====================");
	printf("\n		Score: %d\n",a);
	if(b==1){
		printf("\tInvicibility On\n");	
	}
	else if(b==0){
		printf("\tInvicibility Off\n");	
	}
	if(c==1){
		printf("\tBoost Mode On\n");	
	}
	else if(c==0){
		printf("\tBoost Mode Off\n");	
	}
	printf("	=====================\n\n");

}
/***************************************************
 			CLEAR SCREEN FUNCTION
 **************************************************/
void clrscr(){
    system("CLS");
}
/***************************************************
 				DELAY FUNCTION
 **************************************************/
void delay(int time){
    int millis = 50 * time;
    clock_t start_time = clock();
    while(clock()<start_time + millis){
    ;
    }
}

//Change Text Color Function//
void setcolor(int ForgC)
 {
  WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
    //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
    
	/****Color Code*****
	Name         | Value
             |
	Black        |   0
	Blue         |   1
	Green        |   2
	Cyan         |   3
	Red          |   4
	Magenta      |   5
	Brown        |   6
	Light Gray   |   7
	Dark Gray    |   8
	Light Blue   |   9
	Light Green  |   10
	Light Cyan   |   11
	Light Red    |   12
	Light Magenta|   13
	Yellow       |   14
	White        |   15  
    *********************/
 }
 return;
}

/*******************************************************************
END OF PROJECT
 ********************************************************************/
