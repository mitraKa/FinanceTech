
//******************************************************************************
// Filename: Chequing.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: Interface class of Chequing class.
// Notes: 
//*****************************************************************************
#ifndef CHEQUING_H
#define CHEQUING_H

#include "Debit.h"

using namespace std;

///\brief Derived class of Debit that simulates a Chequing account.
///\author FinanceTech
///\date Oct 25,2017
class Chequing : public Debit
{
  public:

   ///default constructor
   Chequing();
   
   /// Constructor
   Chequing(int id, int b,int an);
  

  private:
   /// amount user is allowed to spend per day
   int daily_spending_limit_;
};
#endif
