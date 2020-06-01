//******************************************************************************
// Filename: CreditCard.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:CreditCard derived from Credit
// Notes: 
//******************************************************************************

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include<iostream>
#include<string>
#include "Credit.h"

using namespace std;

///\brief Derived class of Credit that simulates a credit card.
///\author FinanceTech
///\date Oct 25,2017
class CreditCard : public Credit
{
  public:
   CreditCard();
   ///constructor
   CreditCard(int id, int b,int an,int d,int sl, int mp);
   
   
};

#endif
