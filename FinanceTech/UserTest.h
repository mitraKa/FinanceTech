//******************************************************************************
// Filename: UserTest.h                                                        
// Author(s): FinanceTech                                                       
// Date created: Nov 7, 2017                                                 
// Purpose: Header file for UserTest.cc
// Notes:                                                                       
//*****************************************************************************

#ifndef USER_TEST_H
#define USER_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../Customer.h"
#include "../Administrator.h"
#include "../Chequing.h"

/// \author FinanceTech
/// \date Nov 29, 2017
/// \brief User cppunit test fixture
class UserTest: public CppUnit::TestFixture
{
   /// macros to create Test Suite
   CPPUNIT_TEST_SUITE(UserTest);
   CPPUNIT_TEST(editProfileAdminIDTest);
   CPPUNIT_TEST(editProfileNegativeIDTest);
   CPPUNIT_TEST(editProfileLargeIDTest);
   
   CPPUNIT_TEST(editNullAccountTest);
   CPPUNIT_TEST(deleteCustomerNoExistTest);
   CPPUNIT_TEST(openAccountInvalidIDTest);
   CPPUNIT_TEST(closeAccountNoExistTest);
   CPPUNIT_TEST(writeTest);
   CPPUNIT_TEST(readTest);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Sets up the testing environment to test User class and its derived
   /// classes Customer and Administrator
   void setUp();

   /// Tears down the User testing environment, clears memory
   void tearDown();

   /// Tests the editProfile function with invalid int Admin ID
   void editProfileAdminIDTest();

   /// Tests the editProfile function with invalid negative int ID
   void editProfileNegativeIDTest();

   /// Tests the editProfile with large invalid int ID
   void editProfileLargeIDTest();
   
   /// Tests the editAccount function with invalid ID
   void editNullAccountTest();

   /// Tests the deleteCustomer function with a null customer
   void deleteCustomerNoExistTest();

   /// Tests the openAccount function with an invalid int ID
   void openAccountInvalidIDTest();

   /// Tests the closeAccount function with a null account
   void closeAccountNoExistTest();

   /// Tests the write function, makes sure it can write customer info
   /// to a file
   void writeTest();

   /// Tests the read function, makes sure it can read valid customer info
   /// from a file
   void readTest();

  private:
   Customer *customer_1;
   Customer *customer_2;
   Customer *customer_3;
   
   Administrator *admin_1;
   
   Account *acct;

   int id_1, id_2, id_3;

   string pass_1, pass_2;
   string name_1, name_2;
   string add_1, add_2;
   string email_1, email_2;
   string phone_1, phone_2;
   map<char,int> dob_1, dob_2;

};

#endif
