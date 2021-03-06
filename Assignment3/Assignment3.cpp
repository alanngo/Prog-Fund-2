//******************************************************************
// Template Program
// Programmer: Alan Ngo
// Completed : OCT 11,2016
// Status    : Complete
//
// This program will be used help you balance your checkbook at the end of the month.
// The program should have the user enter the initial balance followed by a
//series of transactions.
//******************************************************************

#include <iostream>				// for cin, cout, endl
#include <iomanip>      // std::setprecision
using namespace std;


// function prototypes
void menu();
void processCheck(double &, double& , double& , int &, double&);
void depositCheck(double&, double &, double &, int& );

int main()
{
 //variables
 cout<<fixed<<showpoint<<setprecision(2);
 char choice;
 double balance;
 double accumulation;
 double transactionAmount;
 double serviceCharge=0.25;
 int numCharge=1;
 double finalBalance=0;
 double totalCharge=0;
 

//input
 cout<<"Enter begining balance "<<endl;
 cin>>balance;

 while (choice!='e'|| choice !='E')//while choice is c or d
{
   menu();
  cin>>choice;

  //decision
  if (choice=='c'|| choice =='C')//process check
  {
   processCheck(transactionAmount, balance, serviceCharge, numCharge, totalCharge);
  }

  else if (choice=='d'|| choice =='D')//deposit check
  {
   depositCheck(transactionAmount, balance, serviceCharge, numCharge);
  }
  else if (choice=='e'|| choice =='E')//final display
  {
  //totalCharge=serviceCharge*numCharge;
  balance=balance-totalCharge;
  cout<<"Total Charge: $"<<totalCharge<<endl;
  cout<<"Processing end of month"<<endl;
  cout<<"Final balance: $"<<balance<<endl;
  exit(0);
  }

  else
 {
 cout<<"Wrong selection"<<endl;
 }

}
 return 0;
}   // end of main function

void menu()
{
 cout<<"Enter transaction type "<<endl;
 cout<<"Choose an action"<<endl;
 cout<<"C= Process Check"<<endl;
 cout<<"D= Depoist Check"<<endl;
 cout<<"E= End Program and display final results"<<endl;
}//end of menu

void processCheck(double &transactionAmount, double& balance, double& serviceCharge, int &numCharge, double&totalCharge)
{
   double fiveDollarCharge=5;
   double negativeFee=25;
   double charge;
 
   cout<<"Enter transaction amount: "<<endl;
   cin>>transactionAmount;
   cout<<"Processing check for $"<<transactionAmount<<endl;
   balance = balance-transactionAmount;
   charge=serviceCharge*numCharge;
   cout<<"Balance: $"<<balance<<endl;
   //cout<<"Total Service Charge: $"<<serviceCharge<<endl;
   if (balance<0)
   {
   	//negativeFee=charge+25;
   	cout<<"Negative Charge: "<<negativeFee<<endl;
   }
   if (balance<800)
   {
    cout<<"Balance Charge: $"<<fiveDollarCharge<<endl;
    totalCharge=charge+fiveDollarCharge+negativeFee;
    cout<<"Total Service Charge: $"<<totalCharge<<endl;
   }
   else
   {
   	totalCharge=charge;
    cout<<"Balance Charge: NONE"<<endl;
    cout<<"Total Service Charge: $"<<totalCharge<<endl;
   }
	numCharge++;
}//end of processCheck

void depositCheck(double &transactionAmount, double& balance, double& serviceCharge, int &numCharge)
{
 //double fiveDollarCharge=5.00;
 int balanceCount;
 cout<<"Enter transaction amount: "<<endl;
   cin>>transactionAmount;
   cout<<"Processing check for $"<<transactionAmount<<endl;
   balance = balance+transactionAmount;
   //totalCharge=serviceCharge;
   cout<<"Balance: $"<<balance<<endl;
   //cout<<"Total Service Charge: $"<<totalCharge<<endl;
   //cout<<"Balance Charge: $"<<fiveDollarCharge<<endl;
    
}//end of depositCheck
