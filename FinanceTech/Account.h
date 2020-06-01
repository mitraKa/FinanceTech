//******************************************************************************
// Filename: Account.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:simulates basics of a bank account
// Notes: 
//******************************************************************************

#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>
#include <iomanip>

#include "Data.h"
#include "RecTrans.h"
#include "LogItem.h"

using namespace std;

/// \brief Derived class of Data that simulates basics of a bank account.
/// \author FinanceTech
/// \date Oct 25,2017
class Account : public Data
{
  public:

   Account();
   ///constructor
   Account(int id, int b,int an);
 
   /// Edits Accounts Info, such as Interest Rate, fee amount,etc.
   void editInfo();

   /// Prints transaction history in order
   void printTransactionHistory();

   /// Updates the account balance (per recurring transactions, rate and fees
   /// where applicable ) as if time period (month) has passed. 
   void update();

   /// Read function
   void read(istream& in_stream);
   /// write Function
   void write(ostream& out_stream) const;

   virtual void withdraw(){}

   virtual void deposit(){}

   virtual void transfer(int){}

   /// The identifying Account number
   int account_number_;

   /// The Account balance.
   int balance_;
   
   /// List of recurring transaction, to be applied to balance each time
   /// period (month)
   vector<RecTrans> recur_vector_;

   /// Vector of actions/ transactions which have occured on the account.
   vector<LogItem> logitem_vector_;

   /// ID assigned to the customer tracks the user in every input file. 
   int id_;
   /// The interest rate of an account
   int interest_rate_;

  private:
  
   /// ID assigned to the customer tracks the user in every input file. 
   //int id_;

   /// Minimum Account info, such as interest rate, fee amount,etc.
   int min_balance_;


   ///the Logitem vector for creating the TransactionHistory
   vector<LogItem> tempVect;
   

};
#endif
