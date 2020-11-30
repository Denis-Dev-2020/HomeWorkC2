#include <stdio.h>
#include <math.h>  
#include <stdlib.h> 
#include <time.h> 

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ TIME DELAY FOR UI ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
void delay(int number_of_seconds) { 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ BANK LOGO FOR UI ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
void PrintLogo () {
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("\v\v||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||| WELCOME TO BANK OF DENIS |||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\v\a");
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ MENU PRINT UI ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
void PrintMenu () {printf("\tFunctions :\n\n\t\tCREATE NEW ACCOUNT --------------------- O\n\t\tDEPOSIT -------------------------------- D\n\t\tWITHDRAW ------------------------------- W\n\t\tBALANCE -------------------------------- B\n\t\tCLOSE ACCOUNT -------------------------- C\n\t\tPRINT ALL ACCOUNTS INFO ---------------- P\n\t\tDELETE ALL ACCOUNTS AND EXIT ----------- E\n\t\tADD INTEREST TO ALL OPEN ACCOUNTS ------ I\n\t\tEXIT ----------------------------------- X\n\n\tWHICH OPTION DO YOU WANT TO EXECUTE (USE CAPITAL LETTERS) ? :  ");}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ASKING THE USER FOR VALUES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
int AskAccountNumber () {
int x;
printf("\tPLEASE ENTER YOUR ACCOUNT NUMBER : ");
if (scanf("%d" , &x) == 1 && x >= 900 && x <= 950) {
	PrintLogo();
        printf("\n\nProccesing ..\n\n");
        return x;
    } else {
    	PrintLogo();
        printf(" ");
        return 0;
    }
}
int AskOptionNumber () {
char x;
if (scanf("%c" , &x) == 1 && x >= 65 && x <= 90) {
	PrintLogo();
        printf("Proccesing ..\n\n");
        return (int)x;
    } else {
    	PrintLogo();
        printf("PLEASE USE CAPITAL LETTERS [O,B,D,W,C,I,P,E,X] \n");
        return 1;
    }
}
int AskBackOrExit () {
int x;
if (scanf("%d" , &x) == 1 && x >= 0 && x <= 1) {
	PrintLogo();
        printf("\n\n");
        return x;
    } else {
    	PrintLogo();
        printf("ANY NUMBER - GO BACK            0 - EXIT       \n");
        return 1;
    }
}
double Deposit () {
float x;
if (scanf("%f" , &x) == 1 && x >= 0 && x <= 10000000) {
	PrintLogo();
        printf("COUNTING ..\n\n");
        return x;
    } else {
    	PrintLogo();
        printf("YOU CAN DEPOSIT ONLY 0 - 10,000,000 USD \n");
        return 0;
    }
}
double InterestRate () {
float x;
if (scanf("%f" , &x) == 1 && x >= 0 && x <= 100) {
	PrintLogo();
        printf("\n\t\t%.2f%% TAKEN FROM ALL OPEN ACCOUNTS..\n\n" , x);
        delay(1500);
        return x;
    } else {
    	PrintLogo();
        printf("YOU CAN TAKE ONLY 0%%-100%% \n");
        return 0;
    }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ARRAY PRINT AND INITIALIZE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
void Print2DArray (double x[3][50]) {
printf("\n______________________________________________________________________________________\n\n");
for (int i = 0; i < 50; ++i){
if (x[1][i] >= 0){
	printf("\tACCOUNT %.0f HAS %.2f USD      WITH TOTAL INTEREST RATE TAKEN OF %.2f %%\n", x[0][i] , x[1][i] , x[2][i]);
}
}
printf("\n______________________________________________________________________________________\n\n\n");
}
void Initialize2DArray (double x[3][50]) {
for (int i = 0; i < 50; ++i){x[0][i]=900+i;}
for (int i = 0; i < 50; ++i){x[1][i]=-1;}
for (int i = 0; i < 50; ++i){x[2][i]=0;}
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

//^^^^^^^^^^^^^^ SEARCHING AND SORTING FIRST BY THE ARRAY[0] AND THEN BY ARRAY[1]  ^^^^^^^^^^^^^^^^^^^^^^^^^^//
int BinarySearch1 (int search ,double x[3][50]) {
  int first = 0 , last = 49 , middle = 24 ;
  while (first <= last) {
    if (x[1][middle] < search)
      first = middle + 1;
    else if (x[1][middle] == search) {
      return middle+1;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last){
  	printf("THERE IS NO MORE ROOM IN OUR BANK\n\n");
  	return -1;
  }
return -1;
}
int BinarySearch2 (int search ,double x[2][50]) {
  int first = 0 , last = 49 , middle = 24 ;
  while (first <= last) {
    if (x[0][middle] < search)
      first = middle + 1;
    else if (x[0][middle] == search) {
      return middle+1;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
      	return -1;
return -1;
}
void InsertionSort1 (double x[3][50]) {
int temp = 0 , temp2 = 0 , temp3 = 0, i , j ;
for (i = 1 ; i <= 50 - 1; i++){
	j = i;
    while ( j > 0 && x[1][j-1] > x[1][j]){	        
    temp = x[1][j];
    x[1][j]   = x[1][j-1];
    x[1][j-1] = temp;
    temp2 = x[0][j];
    x[0][j]   = x[0][j-1];
    x[0][j-1] = temp2;
        temp3 = x[2][j];
    x[2][j]   = x[2][j-1];
    x[2][j-1] = temp3;
    j--;
    }
  }
}
void InsertionSort2 (double x[3][50]) {
int temp = 0 , temp2 = 0 , temp3 = 0, i , j ;
for (i = 1 ; i <= 50 - 1; i++){
	j = i;
    while ( j > 0 && x[0][j-1] > x[0][j]){	        
    temp = x[0][j];
    x[0][j]   = x[0][j-1];
    x[0][j-1] = temp;
    temp2 = x[1][j];
    x[1][j]   = x[1][j-1];
    x[1][j-1] = temp2;
        temp3 = x[2][j];
    x[2][j]   = x[2][j-1];
    x[2][j-1] = temp3;
    j--;
    }
  }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//