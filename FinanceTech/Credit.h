//******************************************************************************
// Filename: Account.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:derived class of Account that simulates a credit account 
// Notes: 
//******************************************************************************

#ifndef CREDIT_H
#define CREDIT_H

#include<iostream>
#include<string>

#include "Account.h"

using namespace std;

///​\brief derived class of Account that simulates a credit account.
///\author FinanceTech
///\date Oct 25,2017
class Credit : public Account
{
  public:
   Credit();
   
   ///constructor of Credit class
   Credit(int id, int b,int an,int d,int sl, int mp);
   
  private:
   ///Day of the month minimum payment is due.
   ///after this date interest rate is applied
   int duedate_;

   ///Fixed amount that can be spent in a month
   int spending_limit_;

   ///Minimum amount that must be paid into account by the due date
   ///to avoiincurring a fee
   int  min_payment_;
   
  
};

#endif
