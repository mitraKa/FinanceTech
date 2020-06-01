//******************************************************************************
// Filename:Savings.cc
// Author(s): FinanceTech
// Date created: Nov 8,2017
// Purpose: Implementation of Savings class.
// Notes: 
//*****************************************************************************

#include <stdexcept>

#include "Savings.h"

Savings::Savings()
{
   
}

Savings::Savings(int id,int b,int an)
   : Debit(id,b,an)
{
}


