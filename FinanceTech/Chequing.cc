//******************************************************************************
// Filename: Chequing.cc
// Author(s): FinanceTech
// Date created: Nov 8,2017
// Purpose: Implementation of Chequing class.
// Notes: 
//*****************************************************************************

#include "Chequing.h"

///Default constructor
Chequing::Chequing()
{
   daily_spending_limit_ = 0;
}

///Constructor of the chequing 
Chequing:: Chequing(int id, int b,int an)
   :Debit(id,b,an)
{
   if(id>1999 || id< 999) //throw out_of_range;
       throw(out_of_range("out of range"));
    
   if(b>4200000)//throw exception
      throw (out_of_range("out of range"));
	     
   if(an > 111999999 || an <0 )//throw out_of_range
      throw (out_of_range("out of range"));
  
   
}
