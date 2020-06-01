//******************************************************************************
// Filename: CreditCard.cc
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:CreditCard derived from Credit
// Notes: 
//******************************************************************************
#include <stdexcept>
#include "CreditCard.h"
#include "Credit.h"

CreditCard:: CreditCard()
{
  
}

CreditCard::CreditCard(int id, int b,int an,int d,int sl, int mp)
   :Credit(id,b,an,d,sl,mp)
{
     
   //Cppunit Testing!
   if(id>1999 || id< 999) //throw out_of_range;
      throw(out_of_range("out of range"));
   
   if(b>40000000 || b< 0) //throw out_of_range;
     throw(out_of_range("out of range"));
     
   if( an > 111999999 || an <000000000)  // throw out_of_range;
      throw (out_of_range("out of range"));
   
	    
   if( d% 2 !=0)      //throw out_of_range;
      throw (out_of_range("out of range"));
   
   if(sl > 100000)    //throw out_of_range;
      throw (out_of_range("out of range"));
   
   if(mp >100000)     // throw out_of_range;
      throw (out_of_range("out of range"));
   
}
