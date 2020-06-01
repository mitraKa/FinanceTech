//******************************************************************************
// Filename: Savings.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: Interface class of Savings
// Notes: 
//******************************************************************************

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Debit.h"

using namespace std;
///\brief Derived class of Debit that stimulates a Savings account.
///\author FinanceTech
///\date Oct 25,2017
class Savings : public Debit
{
  public:
   /// Constructor
   Savings();
   Savings(int id, int b,int an);
   
 
};
#endif
