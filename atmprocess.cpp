#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#define p printf
#define s scanf

float amount=10000,dep,w;
char pw[6];
char ans;
int ctr,trans,incorrect=1;
void delay();
void deposit();
void withdraw();
void balance();
void loading();
main()
{
p("####### ##### ######\n");
p("## ## # ## \n");
p("## ##### #### \n");
p("## ## ## \n");
p("###### ## ######\n");
begin:

p("\nWELCOME TO COESS BANK");
p("\nEnter Password: ");
for(ctr=0;ctr<=5;ctr++)
{pw[ctr]=getch();
putch('*');
}

if(strcmp(pw,"COESS1")==0)
{
loading();
do
{system("cls");
p("\nWELCOME TO COESS BANK");
p("\n[1] DEPOSIT");
p("\n[2] WITHDRAW");
p("\n[3] BALANCE INQUIRY");
p("\nPlease enter transaction: ");
s("%d",&trans);
if(trans==1)
deposit();
else if (trans==2)
withdraw();
else if (trans==3)
balance();
else
p("invalid transaction");
p("\nContinue[y/n]? ");
ans=getche();
}while (ans=='y');
}
else
{
if(incorrect<=2)
{p("\nIncorrect password");
incorrect=incorrect+1;
goto begin;
}

else
{system("cls");
p("\n\nSYSTEM BLOCKED");
goto end;
}
}

end:
p("\nThank you for trusting COESS bank");
getch();
}
void loading()
{
for(ctr=0;ctr<=1;ctr++)
{ p(".");
delay();
system("cls");
p("..");
delay();
system("cls");
p("...");
delay();
system("cls");
p("....");
delay();
system("cls");
p(".....");
delay();
system("cls");
}
}

void delay()
{for (int x=0;x<=0x5FFF;x++)
for(int y=0;y<=0xFFFF;y++)
{}
}
void deposit()
{
p("\nenter amount to deposit: ");
s("%f",&dep);
amount=amount+dep;
p("\n%0.2f was deposited in your account, Current balance is %0.2f", dep,amount);

}
void withdraw()
{
p("\nEnter amount to withdraw: ");
s("%f",&w);
if(w>amount)
p("\nInsufficient balance");
else
{amount=amount-w;
p("\n%0.2f was withdrawn in your account, Current balance is %0.2f", w,amount);
}
}

void balance()
{
p("\nPresent Balance %0.2f ",amount);

}