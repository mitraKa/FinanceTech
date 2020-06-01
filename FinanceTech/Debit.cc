//******************************************************************************
// Filename: Debit.cc
// Author(s): FinanceTech
// Date created:Nov 8,2017
// Purpose:implementation of Debit
// Notes: 
//******************************************************************************

#include "Debit.h"

#include <cassert>
#include <stdexcept>
#include <map>

///Default Constructor
Debit::Debit()
{
   fee_= 0 ;
   transpermonth_= 0;
   transremaining_ = 0;
   
}

///Constructor
Debit::Debit(int id, int b, int an)
   :Account(id,b,an),fee_{300},transpermonth_{10},transremaining_{10}
{
   

}

void Debit::transfer(int account_to)
{
   UserList *ulist_ptr = UserList::getInstance();
   
   int customer_id;
   int amount;
   
   cout << "Please enter ID # of customer you would like to transfer to" <<endl;
   cin >> customer_id;

   cout << "Please enter amount you would like to transfer: "<< endl;
   cin >> amount;
   
   if(this->balance_ > amount)
   {
     
      Customer* cust_to =ulist_ptr->findCustomer(customer_id);
      cout<<"chequing cust_to" << cust_to->password_ <<endl;
      
      vector<Account*>::iterator it;
      	  cout<<"test:we are here"<<endl;
	  for(it=cust_to->account_vector_.begin();
	      it!=cust_to->account_vector_.end();it++)
      {

	 if((*it)->account_number_ == account_to)
	 {
	    int am;
	    string dsc;
	    int day;
	    int month;
	    int year;

	    cout<<"Enter the day"<<endl;
	    cin>>day;
	    cout<<"Enter the month"<<endl;
	    cin>>month;
	    cout<<"Enter the year"<<endl;
	    cin>>year;
	    cout<<"Enter the amount to transfer"<<endl;
	    cin>>am;
	    cout<<"Enter the description"<<endl;
	    cin>>dsc;

	    //Making LogItem here:
	    map<char,int> tempMap;
	    tempMap.insert(pair<char,int>('d',day));
	    tempMap.insert(pair<char,int>('m',month));
	    tempMap.insert(pair<char,int>('y',year));
	    LogItem log(tempMap , am , dsc);
	    
	    //we have to push it back to logitem
	    logitem_vector_.push_back(log);
	    this->balance_ =  this->balance_ - amount;
	    (*it)->balance_ += amount;
	 }
      }
	     
   }

   // --transremaining_ ;
}

void Debit::deposit()
{
   int amount;
   cout << "Please enter amount you would like to deposit: " << endl;
   cin >> amount;
   
   string dsc;
   int day;
   int month;
   int year;
   
   this->balance_ += amount;
   cout<<"Enter the day"<<endl;
   cin>>day;
   cout<<"Enter the month"<<endl;
   cin>>month;
   cout<<"Enter the year"<<endl;
   cin>>year;
   cout<<"Enter the description"<<endl;
   cin>>dsc;

   //Make LogItem
   map<char,int> tempMap;
   tempMap.insert(pair<char,int>('d',day));
   tempMap.insert(pair<char,int>('m',month));
   tempMap.insert(pair<char,int>('y',year));

   LogItem log(tempMap, amount, dsc);
   logitem_vector_.push_back(log);
   
}

void Debit::withdraw()
{
   int amount;
   cout<<"Please enter amount you would like to deposit: "<<endl;
   cin >> amount;
   
   string dsc;
   int day;
   int month;
   int year;
   
   amount = amount * -1 ; 
   this->balance_ += amount;
   cout<<"Enter the day"<<endl;
   cin>>day;
   cout<<"Enter the month"<<endl;
   cin>>month;
   cout<<"Enter the year"<<endl;
   cin>>year;
   cout<<"Enter the description"<<endl;
   cin>>dsc;
   
   map<char,int> tempMap;
   tempMap.insert(pair<char,int>('d',day));
   tempMap.insert(pair<char,int>('m',month));
   tempMap.insert(pair<char,int>('y',year));
   LogItem log(tempMap , amount , dsc);
   logitem_vector_.push_back(log);
   --transremaining_ ;
   
}
