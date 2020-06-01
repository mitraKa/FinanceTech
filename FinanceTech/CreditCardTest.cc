
//******************************************************************************
// Filename: CreditCardTest.cc
// Author(s): FinanceTech
// Date created: Nov 9,2017
// Purpose:CreditCard derived from Credit
// Notes: Since all functions are inherited from base class therefore nothing
// is passed by withinthose functions since all those functions can access the
// private data members of the base class Therefore the test cases were hard
// to conduct for those specific functions. Hence we created the constructor
// test cases. If the value passed by via constructor will be stored in its
// private data members and they does not satisfy the condition then an
// exception is thrown.
//******************************************************************************
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <vector>
#include <stdexcept>
#include "CreditCard.h"
#include "CreditCardTest.h"

//********************************************
// setUp
// Sets up the testing environment
//********************************************
void CreditCardTest:: setUp()
{
   i= new CreditCard;
   id= 1001;
   bal=3000000;
   accountNum=111000001;
   dueDate=20170102;
   spendLimit=400000;
   minPay=5000;

   errid= 10001;
   errbal=300000000;
   erraccountNum=999999999;
   errdueDate=20170117;
   errspendLimit=400000;
   errminPay=500000;
   
   
}
//********************************************
// tearDown
// Clears memory and destructs the testing environment
//********************************************
void CreditCardTest::tearDown()
{
   //delete i;

}

//********************************************
// constructorTest1
// Tests balance out of range
// It tests the value of balance passed in a
// constructor which further gets checks in the
// functions it is used in. 
//********************************************

void CreditCardTest :: constructorTest1()
{
   //CreditCard* a;
   CPPUNIT_ASSERT_THROW(CreditCard i(id,errbal,accountNum,dueDate,spendLimit,minPay), out_of_range);

}
//********************************************
// constructorTest2
// Tests min payment error
// It test the value of min_payment_ passed in a
// constructor which further gets checks in the
// functions it is used in. 
//********************************************

void CreditCardTest :: constructorTest2()
{
   CPPUNIT_ASSERT_THROW(CreditCard i(id,bal,accountNum,dueDate,spendLimit,errminPay), out_of_range);

}


//********************************************
// constructorTest4
// Tests due date
// It tests the value of duedate_ passed in a
// constructor which further gets checks in the
// functions it is used in. 
//********************************************
void CreditCardTest :: constructorTest3()
{
   
   CPPUNIT_ASSERT_THROW(CreditCard i(id,bal,accountNum,errdueDate,spendLimit,minPay), out_of_range);
   
}
//********************************************
// constructorTest5
// Tests error in spending limit
// It test the value of spending_limit passed in a
// constructor which further gets checked in the
// functions it is used in. 
//********************************************

void CreditCardTest :: constructorTest4()
{
   CPPUNIT_ASSERT_THROW(CreditCard i(id,bal,accountNum,dueDate,errspendLimit,minPay), out_of_range);
  
}
//********************************************
// constructorTest6
// Tests error in account number
// It test the value of account_number_ passed in a
// constructor which further gets checks in the
// functions it is used in. 
//********************************************
void CreditCardTest :: constructorTest5()
{
   CPPUNIT_ASSERT_THROW(CreditCard i(id,bal,erraccountNum,dueDate,spendLimit,minPay), out_of_range);
}
//********************************************
// constructorTest7
// Tests error in id
// It test the value of interest_rate_ passed in a
// constructor which further gets checks in the
// functions it is used in. 
//********************************************

void CreditCardTest :: constructorTest6()
{
   CPPUNIT_ASSERT_THROW(CreditCard i(errid,bal,accountNum,dueDate,spendLimit,minPay), out_of_range);
}

