//******************************************************************************
// Filename: UserTest.cc                                                        
// Author(s): FinanceTech                                                       
// Date created: Nov 7,2017                                                    
// Purpose:To test User class and its derived classes Customer and Administrator
// Notes:                                                                       
//*****************************************************************************

#include "UserTest.h"

// Sets up the testing environment to test User class and its derived
// classes Customer and Administrator
void UserTest::setUp()
{
   
   Profile prof(name_1, add_1, email_1, phone_1, dob_1);
   
   customer_1 = new Customer(pass_1, prof);
   customer_2 = new Customer(pass_2, prof);
   customer_3 = nullptr;

   acct = nullptr;

}

// Tears down the User testing environment, clears memory
void UserTest::tearDown()
{
   delete customer_1;
   delete customer_2;
   delete customer_3;
   delete admin_1;
   delete acct;
}

// Tests the editProfile function with invalid int Admin ID
void UserTest::editProfileAdminIDTest();
{
   CPPUNIT_ASSERT_THROW(admin_1->editProfile(0000), invalid_argument);
}

// Tests the editProfile function with invalid negative int ID
void UserTest::editProfileNegativeIDTest();
{
   CPPUNIT_ASSERT_THROW(admin_1->editProfile(-1), invalid_argument);
}

// Tests the editProfile with large invalid int ID
void UserTest::editProfileLargeIDTest();
{
   CPPUNIT_ASSERT_THROW(admin_1->editProfile(9999), invalid_argument);
}

// Tests the editAccount function with invalid ID
void UserTest::editNullAccountTest()
{
   CPPUNIT_ASSERT_THROW(admin1->editAccount(acct), custom_exception);
}

// Tests the deleteCustomer function with a null customer
void UserTest::deleteCustomerNoExistTest()
{
   CPPUNIT_ASSERT_THROW(admin_1->deleteCustomer(0000), invalid_argument);
}

// Tests the openAccount function with an invalid int ID
void UserTest::openAccountInvalidIDTest()
{
   CPPUNIT_ASSERT_THROW(admin_1->deleteCustomer(0000), invalid_argument);
}

// Tests the closeAccount function with a null account
void UserTest::closeAccountNoExistTest()
{
   CPPUNIT_ASSERT_THROW(admin1->closeAccount(acct), custom_exception);
}

// Tests the write function, makes sure it can write customer info
// to a file
void UserTest::writeTest()
{
    CPPUNIT_ASSERT();
}
// Tests the read function, makes sure it can read valid customer info
// from a file
void UserTest::readTest()
{
    CPPUNIT_ASSERT();
}

