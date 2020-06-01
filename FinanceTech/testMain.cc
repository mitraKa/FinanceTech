//testMain.cc
//File for testing functions
#include<iostream>
#include<fstream>

#include"Data.h"
#include"User.h"
#include"Profile.h"
#include"Customer.h"
#include"Administrator.h"
#include"UserList.h"
#include"Interface.h"

#include"Account.h"
#include"AccountFactory.h"
#include"Debit.h"
#include"Credit.h"
#include"Savings.h"
#include"Chequing.h"
#include"CreditCard.h"
#include"LineOfCredit.h"
#include"RecTrans.h"

#include"LogItem.h"
using namespace std;

int main()
{

/*
   //for CustomerTest
   ifstream inFile;
   ofstream outFile;
  
   cout<<"testMain Running"<<endl;
   inFile.open("customer.csv");
   outFile.open("customerOut.csv");

   map<char,int> dob = {{'d',01},{'m',01},{'y',01}};
   Profile p("name", "address","email","phone", dob);
   Customer customer(0,"pass",p);
   vector<Customer> customerVector;
   vector<Customer> :: iterator it;
   
   while(!inFile.eof())
   { 
      customer.read(inFile);
      customerVector.push_back(customer);
     
      }

   inFile.close();
   for(it = customerVector.begin(); it!=customerVector.end(); ++it)
   {
      (*it).write(outFile);
   }
   */
   //for AccountTest
   //int lastChequing = 100000001;
   // int lastSaving = 101000001;
   // int lastCreditCard = 110000001;
   //  int lastLineOfCredit = 111000001;

   
   ifstream inFile;
   ofstream outFile;
  
   cout<<"testMain Running"<<endl;
   inFile.open("accountIn.csv");
   outFile.open("accountOut.csv");
   Account account(0,0,0);
  
   vector<Account> accountVector;
   vector<Account>::iterator it2;
   

   while(!inFile.eof())
   { 
      account.read(inFile);
      accountVector.push_back(account);
   }
/*
   AccountFactory* af=new AccountFactory;
   map<char,int> dob = {{'d',01},{'m',01},{'y',01}};
   Profile p("name", "address","email","phone", dob);
   Customer* customer=new Customer(0,"pass",p);
   vector<Customer> customerVector;
   //vector<Customer> :: iterator it;
   account.editInfo();
   af->makeAccount(2 ,customer);
   for (auto it = customer->account_vector_.begin();it != customer->account_vector_.end();it++)
      cout <<"this is the new vector"<<(*it)->account_number_<<endl;
<<<<<<< HEAD
=======

   account.editInfo();
*/

   ///Chequing the transfer function in Account
   /*
   AccountFactory* af=new AccountFactory;
   map<char,int> dob = {{'d',01},{'m',01},{'y',01}};
   Profile p("name", "address","email","phone", dob);
   Customer* customer1=new Customer(0,"pass",p);

   af->makeAccount( 1 , customer1);
   //af->makeAccount( 1 , customer2);
   Chequing t(124,1000,100000002);
   Account* a=new Account();
   a =customer1->account_vector_.at(c);
 
      //Chequing b(123,5000,100000001);
   cout<<"this is the current balance befor transfer"<< b.balance_<<endl;
   b.transfer(100000002);
   cout<<"the balance after the transfer"<<b.balance_<<endl;
   


   
   for (auto it= b.logitem_vector_.begin(); it!=b.logitem_vector_.end(); ++it)
      cout<<"the logitem vector content,amount"<<(*it).amount_<<endl;
>>>>>>> 966d5c4c4cf28115412a9536087a486a9eae0957
   
   for(it2 = accountVector.begin(); it2!=accountVector.end(); ++it2)
   {
      (*it2).write(outFile);
   }
   */
   /*
   //for RecTrans

   ifstream inFile;
   ofstream outFile;

   cout <<"Test Main Running"<<endl;
   inFile.open("rectrans.csv");
   outFile.open("rectransOut.csv");
   RecTrans rec(0,0,"",0);
   vector<RecTrans> recVector;
   vector<RecTrans>::iterator it3;

   while(!inFile.eof())
   {
      rec.read(inFile);
      recVector.push_back(rec);
   }
   inFile.close();
   for (it3 = recVector.begin(); it3!= recVector.end(); ++it3)
   {
      (*it3).write(outFile);
      }*/

   ///***************************************************************************
   ///Chequing the Deposit function of Debit
   ///***************************************************************************
   /*
   Chequing c(123 , 5000 , 100000001);
   cout<<"This is the balance of the account before the deposit"<<c.balance_<<endl;
   c.deposit();
   cout<<"This is the balance of the account after the deposit"<<c.balance_<<endl;
   */
   ///*******************************************************************************
   ///Chequing the withdraw function of the Debit
   ///******************************************************************************
   /*
   Chequing c(123 , 10000 , 100000001);
   cout<<"This is the balance of the account before the withdraw "<<c.balance_<<endl;
   c.withdraw();
   cout<<"This is the balance of the account after the withdraw"<<c.balance_<<endl;
   */
   
   ///****************************************************************************
   ///Chequing the transfer function in Debit
   ///*****************************************************************************/
   /*
   Chequing c(123 , 10000 , 100000001);
   Chequing t(124 , 5000, 100000002);
   cout<<"This is the balance of c the account before the transfer"<<c.balance_<<endl;
   c.transfer(100000002);
   cout<<"This is the balance of the account after the transfer"<<c.balance_<<endl;
   */
   ///******************************************************************************
   ///filling in the logitem vector in Account
   ///Asking the user to fill in the logitem content and push it back to the logItem
   ///vector
   ///******************************************************************************/
/*
   Chequing c(123 , 10000 , 100000001);
   int choise = 1;
   while(choise)
   {
  
   int amount;
   cout<<"Please enter amount: "<<endl;
   cin >> amount;
   string dsc;
   cout<<"Please enter description : "<<endl;
   cin>>dsc;
   int day;
   cout<<"Please enter day : "<<endl;
   cin>>day;
   int month;
   cout<<"Please enter month: "<<endl;
   cin>>month;
   int year;
   cout<<"Please enter year: "<<endl;
   cin>>year;
   map<char,int> tempMap;
   tempMap.insert(pair<char,int>('d',day));
   tempMap.insert(pair<char,int>('m',month));
   tempMap.insert(pair<char,int>('y',year));
   LogItem log(tempMap , amount , dsc);
   c.logitem_vector_.push_back(log);

   cout<<"Do you still want to push back more logitems?1 for yes 0 for no"<<endl;
   cin>>choise;
   }
*/
   ///*********************************************************************************
   ///Chequing the printTransactionHistory in Account.cc
   ///*********************************************************************************/
   /*
     Chequing c(123 , 10000 , 100000001);
  
     c.printTransactionHistory();
  
   */
   
   
}
