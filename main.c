#include "myBank.h"

//======================================== MAIN ====================================================================//
int main (void) {
//////// VARIABLES INITIALIZATION /////////////////////////////////////
double AccountList [3][50] ;
int option = 0 ;
Initialize2DArray (AccountList);
///////////////////////////////////////////////////////////////////////


while (option != 88) {
PrintLogo();
PrintMenu ();
option = (int)AskOptionNumber ();

////////////////////////////////   START SWITCH   //////////////////////////////////////////////
switch (option) {
//_________________________________NEW ACCOUNT CREATION IF POSSIBLE______________________________________________//
case 79:
PrintLogo();
if (BinarySearch1(-1 , AccountList) >= 0){
	printf("\n\n\tNEW ACCOUNT CREATED , ACCOUNT NUMBER : %.0f\n\n\n\n" , AccountList[0][BinarySearch1(-1 , AccountList)-1]);
	printf("\t\tPLEASE DEPOSIT TO YOUR ACCOUNT : ");
	AccountList[1][BinarySearch1(-1 , AccountList)-1] = Deposit () ;
}
InsertionSort1(AccountList);
delay(2000);
break;
//_______________________________________________________________________________________________//

//_________________________________DEPOSIT TO ACCOUNT IF POSSIBLE____________________________________________//
case 68:
PrintLogo();
InsertionSort2(AccountList);
int RequestedAccount = AskAccountNumber ();
int loc2 = BinarySearch2(RequestedAccount , AccountList)-1 ;
if (AccountList[1][loc2] >= 0 && RequestedAccount >= 900 && RequestedAccount <= 950) {
	printf("\n\n\tHOW MUCH DO YOU WANT TO DEPOSIT TO YOUR ACCOUNT : ");
	AccountList[1][loc2] = AccountList[1][loc2] + Deposit () ;
	printf("\n\t\tACCOUNT %d HAS %.2f USD\n\n\n" , RequestedAccount , AccountList[1][loc2] );

}else {
printf("\tWE DON'T HAVE ACCOUNT WITH THIS NUMBER \n\n");
}
delay(2000);
break;
//_______________________________________________________________________________________________//

//_____________________________WITHDRAW FROM ACCOUNT IF POSSIBLE___________________________________________//
case 87:
PrintLogo();
InsertionSort2(AccountList);
RequestedAccount = AskAccountNumber ();
loc2 = BinarySearch2(RequestedAccount , AccountList)-1 ;
if (AccountList[1][loc2] >= 0 && RequestedAccount >= 900 && RequestedAccount <= 950) {
    printf("\n\t\tACCOUNT %d HAS %.2f USD\n\n\n" , RequestedAccount , AccountList[1][loc2] );
	printf("\n\n\tHOW MUCH DO YOU WANT TO WITHDRAW FROM YOUR ACCOUNT : ");
	int withdraw = Deposit();
	if (AccountList[1][loc2] >= withdraw ){
    AccountList[1][loc2] = AccountList[1][loc2] - withdraw ;
    printf("\n\t\tACCOUNT %d HAS %.2f USD\n\n\n" , RequestedAccount , AccountList[1][loc2] );
	}else {
		printf("\n\t\tYOU DON'T HAVE ENOUGH CASH\n\n");
	}
}else {
printf("\tWE DON'T HAVE ACCOUNT WITH THIS NUMBER \n\n");
}
delay(1500);
break;
//_______________________________________________________________________________________________//

//____________________________CHECK BALANCE IF ACCOUNT EXIST_____________________________________________//
case 66:
PrintLogo();
InsertionSort2(AccountList);
RequestedAccount = AskAccountNumber ();
loc2 = BinarySearch2(RequestedAccount , AccountList)-1 ;
if (AccountList[1][loc2] >= 0 && RequestedAccount >= 900 && RequestedAccount <= 950) {
	printf("\n\n\t\tACCOUNT %d HAS %.2f USD -- WITH TOTAL INTEREST RATE TAKEN OF %.2f %%\n\n\n\n" , RequestedAccount , AccountList[1][loc2] , AccountList[2][loc2] );
printf("[BACK]- NUMBER/CHAR+'ENTER'              OR              [EXIT]- 'X'+'ENTER' : ");
if (AskBackOrExit() == 0){
option = 0;
}
}else {
printf("\tWE DON'T HAVE ACCOUNT WITH THIS NUMBER \n\n");
printf("[BACK]- NUMBER/CHAR+'ENTER'              OR              [EXIT]- 'X'+'ENTER' : ");
if (AskBackOrExit() == 0){
option = 0;
}
}

break;
//_______________________________________________________________________________________________//

//________________________________SINGLE ACCOUNT DELETION IF EXIST_____________________________________________//
case 67:
PrintLogo();
InsertionSort2(AccountList);
RequestedAccount = AskAccountNumber ();
loc2 = BinarySearch2(RequestedAccount , AccountList)-1 ;
if (AccountList[1][loc2] >= 0 && RequestedAccount >= 900 && RequestedAccount <= 950) {
	printf("\n\n\tACCOUNT %d DELETING.. \n\n" , RequestedAccount);
	AccountList[1][loc2] = -1 ;
}else {
printf("\tWE DON'T HAVE ACCOUNT WITH THIS NUMBER \n\n");
}
delay(1500);
break;
//_______________________________________________________________________________________________//

//_________________________________SHOW ALL EXISTING ACCOUNTS______________________________________________//
case 80:
PrintLogo();
Print2DArray(AccountList);
printf("[BACK]- NUMBER/CHAR+'ENTER'              OR              [EXIT]- 'X'+'ENTER' : ");
if (AskBackOrExit() == 0){
option = 0;
}
break;
//_______________________________________________________________________________________________//

//________________________________DELETE ALL ACTIVE ACCOUNTS_____________________________________________//
case 69:
printf("\n\n\tALL ACCOUNTS DELETING.. \n\n");
for (int i = 0; i < 50; ++i){
if (AccountList[1][i] >= 0){AccountList[1][i] = -1 ;}
}
delay(5);
option = 88 ;
break;
//_______________________________________________________________________________________________//

//_______________THE BANK TAKE INTEREST PERCENTAGE 0%-100% FROM ALL EXISTING ACCOUNTS___________________//
case 73:
printf("\n\n\tPLEASE PROVIDE PERCENTAGE OF INTEREST : ");
double rate = InterestRate() ;
for (int i = 0; i < 50; ++i){
if (AccountList[1][i] >= 0){
	AccountList[1][i] = AccountList[1][i] - ((AccountList[1][i]/100)*rate) ;
	AccountList[2][i] = AccountList[2][i] + rate ;
}
}
delay(1500);
break;
//_______________________________________________________________________________________________//

//_____________________________________EXIT______________________________________________________//
case 88:
PrintLogo();
printf("\n\n\tExit\n\n\n");
break;
//_______________________________________________________________________________________________//

//___________________________________DEFAULT___________________________________________________//
default:
PrintLogo();
printf("\nPLEASE USE CAPITAL LETTERS [O,B,D,W,C,I,P,E,X] \n\n");
break;
//_______________________________________________________________________________________________//

}
////////////////////////////////////////// END SWITCH ////////////////////////////////////////////////
}
//////////////////////////////////////////END WHILE //////////////////////////////////////////////////
printf("\t\tGOODBYE !\n\n\n");
}
//=============================================  END MAIN  =======================================================//