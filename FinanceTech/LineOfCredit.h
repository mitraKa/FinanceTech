//******************************************************************************
// Filename: LineOfCredit.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose: LineOfCredit derived from Credit
// Notes: 
//******************************************************************************
#ifndef LineOfCredit_H
#define LineOfCredit_H

#include <iostream>
#include<string>

#include "Credit.h"

using namespace std;

///\brief derived class of Credit.
///\author FinanceTech
///\date Oct 25,2017
class LineOfCredit : public Credit
{
  public:
   ///Line of credit constructor
   LineOfCredit();
   LineOfCredit(int id,int b,int an,int d,int sl,int mp);
      

};

#endif

