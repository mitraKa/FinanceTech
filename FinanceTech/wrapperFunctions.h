#include "Administrator.h"
#include "Customer.h"
#include "Debit.h"
Administrator admin("password");

using namespace std;

int getCustomerId();
void cleanCin(istream& is);
string readDebitInfo(Customer*);
string printRecur_vector_(Account*);
extern Customer* customerPtr;

///GLOBAL WRAPPER FUNCTIONS FOR ADMINISTRATOR

///createCustomerWrapper
/// \brief Global wrapper function to contain createCustomer function 
void createCustomerWrapper()
{
   admin.createCustomer();
}

///editProfileWrapper
///\brief Global wrapper function to contain editProfile function 
///id is defined outside this file (in main.cc)
extern int id;
void editProfileWrapper()
{
   admin.editProfile(getCustomerId());
}

///editAccountWrapper
///\brief Global wrapper function to contain editAccount function
//extern Account* variable name;
void editAccountWrapper()
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *custPtr = ulist_ptr->findCustomer(getCustomerId());
  
   
   Account* accountPtr;
   int select;
   
   string info = "";
   int count = 0;
   
   if(custPtr)
   {
      for(auto it = custPtr->account_vector_.begin(); it !=
	     custPtr->account_vector_.end(); ++it)
      { 
	 info += to_string(count) + ": " + "Account #: " +
	    to_string((*it)->account_number_) + " Balance: " +
	    to_string((*it)->balance_) + " Interest rate: " +
	    to_string((*it)->interest_rate_) + '\n';
	 
	 count++;
      }
   }
   else
      cout << "No Customer selected" << endl;
   
   cout << info << endl;
   
   cout << "Enter the account you want to edit: ";
   cin >> select;
   
   accountPtr = custPtr->account_vector_.at(select);

   admin.editAccount(accountPtr);
   
}

///deleteCustomerWrapper
///\brief Global wrapper function to contain deleteCustomer function
void deleteCustomerWrapper()
{
   admin.deleteCustomer(getCustomerId());

}

///openAccountWrapper
///\brief Global wrapper function to contain openAccount function
void openAccountWrapper()
{
   admin.openAccount(getCustomerId());
}

///closeAccountWrapper
///\brief Global wrapper function to contain closeAccount function 
void closeAccountWrapper()
{
   admin.closeAccount(getCustomerId());
}

void transferWrapperDebit()
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *custPtr = ulist_ptr->findCustomer(getCustomerId());
   
   Account* accountPtr;
   int select;
   
   cout << readDebitInfo(customerPtr);

   cout << "Enter the account you want to transfer from: ";
   cin >> select;

   accountPtr = custPtr->account_vector_.at(select);

   cout << "Enter the account number you want to transfer to: ";
   cin >> select;

   accountPtr->transfer(select);

}

void setupRecurringWrapperDebit()
{
   UserList *ulist_ptr = UserList::getInstance();
   Customer *custPtr = ulist_ptr->findCustomer(getCustomerId());
   
   //Account* accountPtr;
   int select;
   
   cout << readDebitInfo(custPtr);

   cout << "Enter the account you want to setup a recurring payment for: ";

   cin >> select;

   //Account* accountPtr = custPtr->account_vector_.at(select);


   
}
///GLOBAL WRAPPER FUNCTIONS FOR CUSTOMER

///editProfileWrapperC
///\breif Global wrapper function to contain editProfile function for customer
void editProfileWrapperC()
{  
   customerPtr->editProfile(id);
}
   
///printTransactionHistoryWrapperDebit
///\brief Helper function that prints out all of a customers Debit accounts
void printTransactionHistoryWrapperDebit()
{
   
   int count = 0;
   for(auto it = customerPtr->account_vector_.begin(); it !=
	  customerPtr->account_vector_.end(); ++it)
   {
      if( (*it)->account_number_ >= 100000000 && // if its debit
	  (*it)->account_number_ < 101000000)
      {
	 (*it)->printTransactionHistory();
	 count++;
      }
      else
	 continue;
   }
   
   if(count == 0)
      cout << "No debit accounts to print" << endl;

}

///printTransactionHistoryWrapperCredit
///\brief Helper function that prints out all of a customers Credit accounts
void printTransactionHistoryWrapperCredit()
{
   int count = 0;
   for(auto it = customerPtr->account_vector_.begin(); it !=
	  customerPtr->account_vector_.end(); ++it)
   {
      if( (*it)->account_number_ >= 110000000 && // if its credit
	  (*it)->account_number_ < 111000000)
      {
	 (*it)->printTransactionHistory();
	 count++;
      }
      else
	 continue;
   }
   
   if(count == 0)
      cout << "No credit accounts to print" << endl;

}

// checks if a user ID is in the userlist
int getCustomerId()
{
   UserList *ulist_ptr = UserList::getInstance();
   cout << "Enter User ID: ";

   while(!(cin >> id) || !ulist_ptr->findCustomer(id))
   {
      cout << "Invalid user, try again" << endl;
      cleanCin(cin);
   }

   return id;
}

// reads all balance and account # from a passed customer
// and returns it as a string to be used by the CreditAcc Interface
string readCreditInfo(Customer* customerPtr)
{
   string info = "";
   int count = 0;
   
   if(customerPtr)
   {
      for(auto it = customerPtr->account_vector_.begin(); it !=
	     customerPtr->account_vector_.end(); ++it)
      {
	 if( (*it)->account_number_ >= 110000000 && // if its credit
	     (*it)->account_number_ < 111000000)
	 {

	    info += to_string(count) + ": " + "Account #: " +
	       to_string((*it)->account_number_) + " Balance: " +
	       to_string((*it)->balance_) + " Interest rate: " +
	       to_string((*it)->interest_rate_) + '\n';

	    count++;
	 }
	 else
	    continue;
      }
   }
   else
      return "No Customer selected";
   return info;
}

// reads all balance and account # from a passed customer
// and returns it as a string to be used by the DebitAcc Interface
string readDebitInfo(Customer* customerPtr)
{
   string info = "";
   int count = 0;
   
   if(customerPtr)
   {
      for(auto it = customerPtr->account_vector_.begin(); it !=
	     customerPtr->account_vector_.end(); ++it)
      {
	 if((*it)->account_number_ >= 100000000 && // if its debit
	     (*it)->account_number_ < 101000000)
	 {
	    info += to_string(count) + ": " + "Account #: " +
	       to_string((*it)->account_number_) + " Balance: " +
	       to_string((*it)->balance_) + " Interest rate: " +
	       to_string((*it)->interest_rate_) + '\n' +
	       '\t' + printRecur_vector_((*it)) + '\n';
	    
	    count++;
	 }
      }
   }
   else
      return "No Customer selected";
   return info;
}

/// withdrawWrapper
///\brief withdraws money from a debit account
void withdrawWrapper()
{     
   int select;
   cout << readDebitInfo(customerPtr);

   cout << "Enter the account: ";
   cin >> select;
   
   Account* accountPtr = customerPtr->account_vector_.at(select);
   
   accountPtr->withdraw();
}

/// depositWrapper
///\brief deposits money from a debit account
void depositWrapper()
{
   int select;
   cout << readDebitInfo(customerPtr);

   cout << "Enter the account: ";
   cin >> select;
   
   Account* accountPtr = customerPtr->account_vector_.at(select);
   
   accountPtr->deposit();
}

/// cleanCin
///\brief cleans the passed stream after incorrect input
void cleanCin(istream& is)
{
   is.clear();
   while (is.peek() != '\n') {
      // eats until the end of line
      is.ignore();
   }
   is.ignore();
}

string printRecur_vector_(Account* accountPtr)
{
   string recurList = "";
   
   for(auto it = accountPtr->recur_vector_.begin();
       it != accountPtr->recur_vector_.end(); ++it)
   {
      recurList +=
	 "RecTrans ID: " + to_string(it->id_) 
	 + " Day: " + to_string(it->day_rec_)
	 + " Name: " + it->name_rec_ +
	 " Amount: " + to_string(it->amount_rec_);
   }

   return recurList;
}
