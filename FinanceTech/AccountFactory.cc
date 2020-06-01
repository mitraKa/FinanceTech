//******************************************************************************
// Filename: AccountFactory.c
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:AccountFactory class,responsible of making diffrent accounts 
// Notes: 
//******************************************************************************

#include "Account.h"
#include "Customer.h"

#include "Debit.h"
#include "Chequing.h"
#include "Savings.h"

#include "Credit.h"
#include "CreditCard.h"
#include "LineOfCredit.h"

#include "AccountFactory.h"

///​Account Factory
///\author FinanceTech
///\date Oct 26,2017

AccountFactory::AccountFactory()
// :last_chequing_{lc},last_saving_{ls},last_credit_card_{lcc}, last_line_credit_{llc}
{
   
   last_chequing_ = 100000010;
   last_saving_ = 101000010;
   last_credit_card_ = 110000010;
   last_line_credit_ = 111000010;
   
   }

//AccountFactory* AccountFactory::account_factory_ptr_ = NULL;
/*
AccountFactory* AccountFactory::getInstance()
{
   if (account_factory_ptr_ == nullptr)
   {
      account_factory_ptr_ = new AccountFactory();
   }
   return account_factory_ptr_;
}
*/
void AccountFactory::makeAccount(int input, Customer* customer)
{
   switch(input)
   {
      case 1:
      {
	 last_chequing_++;
	 Chequing* c= new Chequing();
	 c->account_number_ = last_chequing_;
	 customer->account_vector_.push_back(c);
	 break;
      }
   
      case 2:
      {
	 last_saving_++;
	 Savings* s = new Savings();
	 s->account_number_ = last_saving_;
	 customer->account_vector_.push_back(s);
	 break;
      }
 
      case 3:
      {
	  last_credit_card_++;
	 CreditCard* cc = new CreditCard();
	 cc->account_number_ = last_credit_card_;
	 customer->account_vector_.push_back(cc);
	 break;
      }

      case 4:
      {
	 last_line_credit_++;
	 LineOfCredit* lof = new LineOfCredit();
	 lof->account_number_ = last_line_credit_;
	 customer->account_vector_.push_back(lof);
	 break;
      }
   
      default:
	 cout<<"the choice entered is wrong please try again"<<endl;
	 break;
   }
}
