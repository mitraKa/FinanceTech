//******************************************************************************
// Filename: AccountFactory.h
// Author(s): FinanceTech
// Date created: Oct 24,2017
// Purpose:AccountFactory class,responsible of making diffrent accounts 
// Notes: 
//******************************************************************************
#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_h


#include<string>
using namespace std;

///​\brief Account Factory class is a class to implement factory pattern,We also
///had to make it singelton pattern since we wanted to keep the amount of
///the private members
///\author FinanceTech
///\date Oct 26,2017
class AccountFactory
{
  private:
   int last_chequing_ = 10000001;
   int last_saving_ = 101000010;
   int last_credit_card_ = 11000001;
   int last_line_credit_ = 11100001;
   
  public:
   AccountFactory();
   //static AccountFactory* getInstance();
   //static AccountFactory* account_factory_ptr_;
   void makeAccount(int input,Customer* customer);
   
};

#endif
