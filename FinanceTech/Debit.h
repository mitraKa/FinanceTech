//******************************************************************************
// Filename: Debit.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: Interface class of Debit
// Notes: 
//******************************************************************************

#ifndef DEBIT_H
#define DEBIT_H

#include "Account.h"
#include "LogItem.h"
#include "Customer.h"
#include "UserList.h"

#include <stdexcept>

using namespace std;

/// \brief Derived class of Account that simulates a debit account.
/// \author FinanceTech
/// \date Oct 25,2017
class Debit : public Account
{
  public:

   ///Defult Constructor
   Debit();
   /// Constructor 
   Debit(int id, int b, int an);

   /// Transfer money to account from current account
   void transfer(int account_to);

   /// Deposit money to current account
   void deposit();

   /// Withdraw money from current account
   void withdraw();

  private:
   /// Monthy fees to be applied to account balance
   int fee_;

   /// Number of transactions allowed per Month
   int transpermonth_;

   /// Number of allowed monthly transactions remaining this month
   int transremaining_;
};
#endif
