
//******************************************************************************
// Filename: CreditCardTest.h
// Author(s): FinanceTech
// Date created: Nov 9,2017
// Purpose:It tests the CreditCard class and its base classes. 
// Notes: Since all functions are inherited from base class therefore nothing
// is passed by withinthose functions since all those functions can access the
// private data members of the base class Therefore the test cases were hard
// to conduct for those specific functions. Hence we created the constructor
// test cases. If the value passed by via constructor will be stored in its
// private data members and they does not satisfy the condition then an
// exception is thrown.
//******************************************************************************
#ifndef CREDITCARDTEST_H
#define CREDITCARDTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include "CreditCard.h"

class CreditCardTest: public CppUnit::TestFixture
{
   ///macros to create test suite
   CPPUNIT_TEST_SUITE(CreditCardTest);
   
   CPPUNIT_TEST(constructorTest1);
   CPPUNIT_TEST(constructorTest2);
   CPPUNIT_TEST(constructorTest3);
   CPPUNIT_TEST(constructorTest4);
   CPPUNIT_TEST(constructorTest5);
   CPPUNIT_TEST(constructorTest6);
  
  
   CPPUNIT_TEST_SUITE_END();

  public:
   /// setUp
   /// Sets up the testing environment
   void setUp();
   
   /// tearDown
   /// Clears memory and destructs the testing environment
   void tearDown();

   /// test for incorrect balance
   void constructorTest1();
   /// test for incorrect min_payment_
   void constructorTest2();
   /// test for incorrect duedate_
   void constructorTest3();
    /// test for incorrect spending_limit
   void constructorTest4();
   /// test for incorrect account_number_
   void constructorTest5();
   /// test for incorrect interest_rate_
   void constructorTest6();

  private:
   CreditCard *i;

   int id;
   int dueDate;
   int spendLimit; 
   int minPay;
   int bal;
   //int mb;
   int accountNum;
   //int ir;
   int errid;
   int errdueDate;
   int errspendLimit;
   int errminPay;
   int errbal;
   //int errmb;
   int erraccountNum;
   //int errir;
      
};
#endif
