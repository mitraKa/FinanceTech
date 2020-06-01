//******************************************************************************
// Filename: Credit.cc
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:
// Notes: 
//******************************************************************************
#include<iostream>
#include<string>
#include "Credit.h"
#include "Account.h"

/// Default Constructor
Credit::Credit()
{
   duedate_= 20170130;
   spending_limit_= 0;
   min_payment_=0;
}
///constructor of Credit class   
Credit::Credit(int id, int b,int an,int d,int sl, int mp)
   :Account(id,b,an),duedate_{d},spending_limit_{sl},min_payment_{mp}
{

}

